<?php
// $Id: apply_for_role.admin.inc,v 1.3.4.5 2011/01/15 22:44:08 sorenjones Exp $

/**
 * @file
 * Administration forms for the Apply for Role (AFR) module.
 */

/**
 * Module settings page.
 */

/**
 *
 */
function apply_for_role_settings_form($form, $form_state) {
  $selected_roles = variable_get('users_apply_roles', array());

  if (!empty($selected_roles)) {
    foreach ((array)$selected_roles as $rid => $value) {
      if ($rid > 2) {
        $selected_rids[] = $rid;
      }
    }
  }
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Apply for role options'),
  );
  $form['options']['multiple'] = array(
    '#type' => 'radios',
    '#title' => t('Allow multiple roles per application'),
    '#options' => array(t('No'), t('Yes')),
    '#default_value' => variable_get('apply_for_role_multiple', 0),
    '#description' => t("Chosing 'no' will limit users to applying for only one role per role application. Choosing 'yes' will allow users to apply for multiple roles per role application."),
    '#required' => TRUE,
  );
  $form['options']['register'] = array(
    '#type' => 'radios',
    '#title' => t('Apply for role on registration'),
    '#options' => array(t('No'), t('Optional'), t('Required')),
    '#default_value' => variable_get('apply_for_role_register', 0),
    '#description' => t("Choosing 'optional' will allow users to apply for roles when creating a new account. Choosing 'required' will require users to apply for roles when creating a new account."),
    '#required' => TRUE,
  );
  $form['options']['display_approved'] = array(
    '#type' => 'radios',
    '#title' => t('Display approved roles in an application form'),
    '#options' => array(t('No'), t('Yes')),
    '#default_value' => variable_get('apply_for_role_display_approved', 0),
    '#description' => t("Choosing 'yes' will allow a user to see which role applications where approved."),
    '#required' => TRUE,
  );
  $roles = user_roles(TRUE);
  unset($roles[DRUPAL_AUTHENTICATED_RID]);
  $form['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#default_value' => isset($selected_rids) ? $selected_rids : array(2),
    '#options' => $roles,
    '#description' => t('Select the roles that users will be able to apply for.'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  return $form;
}

/**
 *
 */
function apply_for_role_settings_form_submit($form, &$form_state) {
  $roles = user_roles(TRUE);
  foreach ($form_state['values']['roles'] as $key => $value) {
    if ($value) {
      $selected_roles[$value] = $roles[$value];
    }
  }

  variable_set('users_apply_roles', $selected_roles);
  variable_set('apply_for_role_multiple', $form['options']['multiple']['#value']);
  variable_set('apply_for_role_register', $form['options']['register']['#value']);
  variable_set('apply_for_role_display_approved', $form_state['values']['display_approved']);
  drupal_set_message(t('Apply for role settings have been saved.'));

  $form_state['redirect'] = 'admin/config/people/apply_for_role';
  return;
}

/**
 * User management
 */

/**
 *
 */
function apply_for_role_admin_form($form, $form_state) {
  $roles = array_map('check_plain', user_roles(TRUE));

  $select = db_select('users_roles_apply', 'a');
  $select->fields('a', array('uid', 'rid', 'approved', 'apply_date', 'approve_date'));
  $select->join('users', 'u', 'a.uid = u.uid');

  $results = $select->execute();
  if (!empty($results)) {
    foreach ($results as $row) {
      $user = user_load($row->uid);
      $form['apps'][$row->uid][$row->rid]['user'] = array(
        '#markup' => theme('username', array('account' => $user)),
      );
      $form['apps'][$row->uid][$row->rid]['role'] = array(
        '#markup' => isset($roles[$row->rid]) ? check_plain($roles[$row->rid]) : t('<em>Invalid Role</em>'),
      );
      $current_roles = array_slice($user->roles, 1);
      $form['apps'][$row->uid][$row->rid]['current_roles'] = array(
        '#markup' => filter_xss_admin(implode('<br />', $current_roles)),
      );
      $form['apps'][$row->uid][$row->rid]['apply_date'] = array(
        '#markup' => format_date($row->apply_date),
      );
      $form['apps'][$row->uid][$row->rid]['status'] = array(
        '#markup' => theme('apply_for_role_status', array('status' => $row->approved)),
      );
      $form['apps'][$row->uid][$row->rid]['approve_date'] = array(
        '#markup' => empty($row->approve_date) ? '' : format_date($row->approve_date),
      );
      if (!empty($row->uid) && isset($roles[$row->rid])) {
        if (($row->approved != APPLY_FOR_ROLE_APPROVED) && (user_access('approve role applications'))) {
          $form['apps'][$row->uid][$row->rid]['approve'] = array(
            '#markup' => l(t('Approve'), 'admin/people/apply_for_role/approve/' . $row->uid . '/' . $row->rid, array('title' => t('Approve this user'))),
          );
        }
        if (($row->approved != APPLY_FOR_ROLE_DENIED) && (user_access('deny role applications'))) {
          $form['apps'][$row->uid][$row->rid]['deny'] = array(
            '#markup' => l(t('Deny'), 'admin/people/apply_for_role/deny/' . $row->uid . '/' . $row->rid, array('title' => t('Deny this user'))),
          );
        }
      }
      if (user_access('delete role applications')) {
        $form['apps'][$row->uid][$row->rid]['delete'] = array(
          '#markup' => l(t('Delete'), 'admin/people/apply_for_role/remove/' . $row->uid . '/' . $row->rid, array('title' => t('Remove application'))),
        );
      }
    }
  }

  return $form;
}

/**
 *
 */
function theme_apply_for_role_admin_form($variables) {
  $form = $variables['element'];

  $header = array(
    array('data' => t('Username'), 'field' => 'u.name'),
    array('data' => t('Current Roles')),
    array('data' => t('Applying For'), 'field' => 'rid'),
    array('data' => t('Applied'), 'field' => 'apply_date', 'sort' => 'desc'),
    array('data' => t('Status'), 'field' => 'approved'),
    array('data' => t('Processed'), 'field' => 'approve_date'),
    array('data' => t('Operations'), 'colspan' => 3),
  );

  if (!empty($form['apps'])) {
    $rows = array();
    foreach (element_children($form['apps']) as $uid) {
      foreach (element_children($form['apps'][$uid]) as $rid) {
        $rows[] = array(
          array('data' => drupal_render($form['apps'][$uid][$rid]['user'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['current_roles'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['role'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['apply_date'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['status'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['approve_date'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['approve'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['deny'])),
          array('data' => drupal_render($form['apps'][$uid][$rid]['delete'])),
        );
      }
    }
  }
  else {
    $rows[] = array(array('data' => '<em>' . t('There are currently no applications.') . '</em>', 'colspan' => 9));
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

/**
 *
 */
function apply_for_role_approve_form($form, $form_state, $user, $rid) {
  $form['user'] = array('#type' => 'value', '#value' => $user);
  $form['rid'] = array('#type' => 'value', '#value' => $rid);

  $roles = array_map('check_plain', user_roles(TRUE));
  return confirm_form($form, t('Do you want to approve the application from user %username for role %role', array('%username' => $user->name, '%role' => $roles[$rid])), 'admin/people/apply_for_role', t('The role will be automatically assigned to the user.'), t('Approve'));
}

/**
 *
 */
function apply_for_role_approve_form_submit($form, &$form_state) {
  if (apply_for_role_approve_apply($form_state['values']['user'], $form_state['values']['rid'])) {
    drupal_set_message(t('The application was approved and the user was added to the role.'));
  }
  else {
    drupal_set_message(t('Error approving application. Please try again!'), 'error');
  }
  cache_clear_all();
  $form_state['redirect'] = 'admin/people/apply_for_role';
}

/**
 *
 */
function apply_for_role_deny_form($form, $form_state, $user, $rid) {
  $form['user'] = array('#type' => 'value', '#value' => $user);
  $form['rid'] = array('#type' => 'value', '#value' => $rid);

  $roles = array_map('check_plain', user_roles(TRUE));
  return confirm_form($form, t('Do you want to deny the application from user %username for role %role', array('%username' => $user->name, '%role' => $roles[$rid])), 'admin/people/apply_for_role', t('The role will not be assigned to the user and the user will not be able to apply again.'), t('Deny'));
}

/**
 *
 */
function apply_for_role_deny_form_submit($form, &$form_state) {
  if (apply_for_role_deny_apply($form_state['values']['user'], $form_state['values']['rid'])) {
    drupal_set_message(t('The application was denied .'));
  }
  else {
    drupal_set_message(t('Error denying application. Please try again!'), 'error');
  }
  cache_clear_all();
  $form_state['redirect'] = 'admin/people/apply_for_role';
}

/**
 *
 */
function apply_for_role_remove_form($form, $form_state, $user, $rid) {
  $form['user'] = array('#type' => 'value', '#value' => $user);
  $form['rid'] = array('#type' => 'value', '#value' => $rid);

  $roles = array_map('check_plain', user_roles(TRUE));
  return confirm_form($form, t('Do you want to remove the application from user %username for role %role', array('%username' => $user->name, '%role' => isset($roles[$rid]) ? $roles[$rid] : t('Invalid role'))), 'admin/people/apply_for_role', t('The role will be automatically deleted from the user and they will be allowed to re-apply for the role.'), t('Delete'));
}

/**
 *
 */
function apply_for_role_remove_form_submit($form, &$form_state) {
  if (apply_for_role_remove_apply($form_state['values']['user'], $form_state['values']['rid'])) {
    drupal_set_message(t('The application was deleted.'));
  }
  else {
    drupal_set_message(t('Error deleting application. Please try again!'), 'error');
  }
  cache_clear_all();
  $form_state['redirect'] = 'admin/people/apply_for_role';
}
