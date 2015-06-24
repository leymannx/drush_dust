<?php

/**
 * Implements hook_drush_help().
 */
function drush_dust_drush_help($command) {
  switch ($command) {
    case 'drush:dust':
      return dt('Run drush dust MYMODULE to disable and uninstall a module in one step without prompt.');
  }
}

/**
 * Implements hook_drush_command().
 */
function drush_dust_drush_command() {
  $items = array();
  $items['dust'] = array(
    // The dt() function is used to provide string translations.
    // This is used in replacement of the Drupal t() function for Drush commands.
    'description' => dt('Run drush dust MYMODULE to disable and uninstall a module in one step without prompt.'),
    // An array of arguments can be used to accept user input from the command line.
    'arguments'   => array(
      'MYMODULE'    => dt('A module\'s machine name'),
    ),
    // An array of examples can be added to provide additional help to the user.
    'examples' => array(
      'Standard example' => 'drush dust MYMODULE',
    )
  );
  return $items;
}

/**
 * Callback function for drush dust. 
 * @param $MYMODULE - A module's machine name
 */
function drush_drush_dust_dust($MYMODULE = NULL) {

  // module_exists() only returns TRUE if the module is currently enabled
  if (module_exists($MYMODULE)) {

    module_disable(array($MYMODULE));
    drupal_uninstall_modules(array($MYMODULE));
    // log to the command line with an OK status
    drush_log(dt('Disabled and uninstalled ') . $MYMODULE, 'success');
  } else {
    drush_print(dt('Module already disabled or non-existent. Check for typos.'));
  }
}