<?php
// $Id:$

/**
 * @file
 * Administrative page callbacks for the image formatters module.
 */

/**
 * Menu callback for settings page.
 */
function image_formatters_admin_settings_form(&$form_state) {
  $form = array();
  $form['if'] = array(
    '#type' => 'fieldset',
    '#title' => t('Main + Thumbnails imagecache preset settings'),
  );

  $f = _content_field_types();
  $formatters = $f['filefield']['formatters'];
//  dpm($formatters);
  $options = array();
  foreach ($formatters as $key => $data) {
    $options[$key] = $data['label'];
  }

  $form['if']['image_formatters_main'] = array(
    '#type' => 'select',
    '#title' => t('Main imagecache preset'),
    '#default_value' => variable_get('image_formatters_main', 'product_default'),
    '#options' => $options,
    '#description' => t('The imagecache preset for the main image.'),
  );
  $form['if']['image_formatters_thumbnails'] = array(
    '#type' => 'select',
    '#title' => t('Thumbnails imagecache preset'),
    '#default_value' => variable_get('image_formatters_thumbnails', 'product_default'),
    '#options' => $options,
    '#description' => t('The imagecache preset for the thumbnail images.'),
  );
  $form['if']['image_formatters_single_image'] = array(
    '#type' => 'select',
    '#title' => t('Single image imagecache preset'),
    '#default_value' => variable_get('image_formatters_single_image', 'product_default'),
    '#options' => $options,
    '#description' => t('The imagecache preset is for single images.'),
  );

  return system_settings_form($form);
}
