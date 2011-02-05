<?php
// $Id: apply_for_role_views_handler_field_role_name.inc,v 1.1.2.1 2011/01/16 07:22:25 sorenjones Exp $
/**
 * Field handler to provide simple renderer that allows using a themed user link
 */
class apply_for_role_views_handler_field_role_name extends views_handler_field {
  function render($values) {
    $name = db_query("SELECT name FROM {role} WHERE rid = :rid", array(':rid' => $values->{$this->field_alias}))->fetchField();
    return check_plain($name);
  }
}
