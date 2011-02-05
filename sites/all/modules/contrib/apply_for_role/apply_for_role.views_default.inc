<?php
// $Id: apply_for_role.views_default.inc,v 1.1.2.1 2011/01/16 13:05:58 sorenjones Exp $
/**
 * @file
 * Contains default views for the Apply for Role module.
 */

/**
 * Implements hook_views_default_views().
 */
function apply_for_role_views_default_views() {
  $view = new view;
  $view->name = 'apply_for_role_admin';
  $view->description = 'Role applications';
  $view->tag = 'Apply for Role';
  $view->base_table = 'users_roles_apply';
  $view->human_name = 'apply_for_role_admin';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = TRUE; /* Edit this to FALSE to make a default view enabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view role applications';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'user_roles' => 'user_roles',
    'rid' => 'rid',
    'apply_date' => 'apply_date',
    'approved' => 'approved',
    'approve_date' => 'approve_date',
    'approve_application' => 'approve_application',
    'deny_application' => 'deny_application',
    'delete_application' => 'delete_application',
  );
  $handler->display->display_options['style_options']['default'] = 'apply_date';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'user_roles' => array(
      'align' => '',
      'separator' => '',
    ),
    'rid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'apply_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'approved' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'approve_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'approve_application' => array(
      'align' => '',
      'separator' => '',
    ),
    'deny_application' => array(
      'align' => '',
      'separator' => '',
    ),
    'delete_application' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Field: Apply for Role: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: Apply for Role: Current roles */
  $handler->display->display_options['fields']['user_roles']['id'] = 'user_roles';
  $handler->display->display_options['fields']['user_roles']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['user_roles']['field'] = 'user_roles';
  $handler->display->display_options['fields']['user_roles']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_roles']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_roles']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_roles']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_roles']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_roles']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_roles']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_roles']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_roles']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['user_roles']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_roles']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_roles']['empty_zero'] = 0;
  $handler->display->display_options['fields']['user_roles']['type'] = 'ul';
  /* Field: Apply for Role: Role */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['rid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rid']['empty_zero'] = 0;
  /* Field: Apply for Role: Date applied */
  $handler->display->display_options['fields']['apply_date']['id'] = 'apply_date';
  $handler->display->display_options['fields']['apply_date']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['apply_date']['field'] = 'apply_date';
  $handler->display->display_options['fields']['apply_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['apply_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['apply_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['apply_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['apply_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['apply_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['apply_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['apply_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['apply_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['apply_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['apply_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['apply_date']['empty_zero'] = 0;
  /* Field: Apply for Role: Status */
  $handler->display->display_options['fields']['approved']['id'] = 'approved';
  $handler->display->display_options['fields']['approved']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['approved']['field'] = 'approved';
  $handler->display->display_options['fields']['approved']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['approved']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['approved']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['approved']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['approved']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['approved']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['approved']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['approved']['alter']['html'] = 0;
  $handler->display->display_options['fields']['approved']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['approved']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['approved']['hide_empty'] = 0;
  $handler->display->display_options['fields']['approved']['empty_zero'] = 0;
  /* Field: Apply for Role: Date processed */
  $handler->display->display_options['fields']['approve_date']['id'] = 'approve_date';
  $handler->display->display_options['fields']['approve_date']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['approve_date']['field'] = 'approve_date';
  $handler->display->display_options['fields']['approve_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['approve_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['approve_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['approve_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['approve_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['approve_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['approve_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['approve_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['approve_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['approve_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['approve_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['approve_date']['empty_zero'] = 0;
  /* Field: Apply for Role: Approve link */
  $handler->display->display_options['fields']['approve_application']['id'] = 'approve_application';
  $handler->display->display_options['fields']['approve_application']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['approve_application']['field'] = 'approve_application';
  $handler->display->display_options['fields']['approve_application']['label'] = '';
  $handler->display->display_options['fields']['approve_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['approve_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['approve_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['approve_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['approve_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['approve_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['approve_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['approve_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['approve_application']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['approve_application']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['approve_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['approve_application']['empty_zero'] = 0;
  /* Field: Apply for Role: Deny link */
  $handler->display->display_options['fields']['deny_application']['id'] = 'deny_application';
  $handler->display->display_options['fields']['deny_application']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['deny_application']['field'] = 'deny_application';
  $handler->display->display_options['fields']['deny_application']['label'] = '';
  $handler->display->display_options['fields']['deny_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['deny_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['deny_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['deny_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['deny_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['deny_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['deny_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['deny_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['deny_application']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['deny_application']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['deny_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['deny_application']['empty_zero'] = 0;
  /* Field: Apply for Role: Delete link */
  $handler->display->display_options['fields']['delete_application']['id'] = 'delete_application';
  $handler->display->display_options['fields']['delete_application']['table'] = 'users_roles_apply';
  $handler->display->display_options['fields']['delete_application']['field'] = 'delete_application';
  $handler->display->display_options['fields']['delete_application']['label'] = '';
  $handler->display->display_options['fields']['delete_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_application']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['delete_application']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_application']['empty_zero'] = 0;

  /* Display: Role applications */
  $handler = $view->new_display('page', 'Role applications', 'apply_for_role_admin');
  $handler->display->display_options['path'] = 'admin/people/apply_for_role';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Role applications';
  $handler->display->display_options['menu']['weight'] = '10';
  $translatables['apply_for_role_admin'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('User'),
    t('Current roles'),
    t('Role'),
    t('Date applied'),
    t('Status'),
    t('Date processed'),
    t('Role applications'),
  );
  $views[$view->name] = $view;

  return $views;
}
