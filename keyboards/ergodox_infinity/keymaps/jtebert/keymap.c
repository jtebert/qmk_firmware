#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define FUNC1 4  // Function layer (F_ keys)
#define FUNC2 5 // Function layer 2

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE LAYER (QWERTY)
 *
 * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
 * │  ESC │  1 │  2 │  3 │  4 │  5 │ F3 │              │ F2 │  6 │  7 │  8 │  9 │  0 │  -_  │
 * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
 * │  TAB │  Q │  W │  E │  R │  T │ =+ │              │  ( │  Y │  U │  I │  O │  P │  [{  │
 * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
 * │   _  │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  ; │   '  │
 * ├──────┼────┼────┼────┼────┼────┤ F1 │              │  ) ├────┼────┼────┼────┼────┼──────┤
 * │LShift│  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │ /? │  ]}  │
 * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
 *   │LCtl│LAlt│ `~ │ \| │LGUI│                                  │Left│Down│ Up │Rght│Caps│
 *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
 *                                 │Calc│LTog│    │RAlt│RCtl│
 *                            ┌────┼────┼────┤    ├────┼────┼────┐
 *                            │    │    │Home│    │PgUp│    │    │
 *                            │Bksp│ Del├────┤    ├────┤Entr│ [] │
 *                            │    │    │ End│    │PgDn│    │    │
 *                            └────┴────┴────┘    └────┴────┴────┘
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,    KC_2,   KC_3,    KC_4,    KC_5,   MO(FUNC2),
        KC_TAB,     KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,   KC_EQL,
        S(KC_MINS), KC_A,    KC_S,   KC_D,    KC_F,    KC_G,
        KC_LSFT,    KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,   MO(FUNC1),
        KC_LCTL,    KC_LALT, KC_GRV, KC_BSLS, KC_LGUI,
                                              KC_CALC, RGB_TOG,
                                                       KC_HOME,
                                     KC_SPC,  KC_BSPC, KC_END,
        // right hand
             MO(FUNC2),  KC_6,     KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
             S(KC_9), KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,     KC_LBRC,
                      KC_H,     KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
             S(KC_0), KC_N,     KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RBRC,
                                KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_CAPS,
             KC_RALT, KC_RCTRL,
             KC_PGUP,
             KC_PGDN, KC_ENT,   KC_SPC
    ),

/* FUNC1 LAYER: Function keys
 * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
 * │      │ F1 │ F2 │ F3 │ F4 │ F5 │    │              │ F12│ F6 │ F7 │ F8 │ F9 │ F10│  F11 │
 * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
 * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │  F12 │
 * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
 * │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
 * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
 * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
 * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
 *   │    │    │    │    │    │                                  │    │    │    │    │    │
 *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
 *                                 │    │    │    │    │    │
 *                            ┌────┼────┼────┤    ├────┼────┼────┐
 *                            │    │    │    │    │    │    │    │
 *                            │    │    ├────┤    ├────┤    │    │
 *                            │    │    │    │    │    │    │    │
 *                            └────┴────┴────┘    └────┴────┴────┘
 */
[FUNC1] = LAYOUT_ergodox(
        // left hand
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       KC_F12,  KC_F6,   KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,
       _______, _______, _______, _______, _______, _______, KC_F12,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* FUNC2: Miscellaneous Keys/Characters and media keys 
 * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
 * │ FLASH│    │  ° │    │    │    │    │              │    │    │    │  × │    │    │   –  │
 * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
 * │      │    │    │    │    │    │  ± │              │    │    │    │    │    │    │   ≈  │
 * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
 * │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
 * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
 * │      │    │    │    │    │    │    │              │    │    │    │  ≤ │  ≥ │  ÷ │   ≠  │
 * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
 *   │    │    │    │    │    │                                  │LOff│LED-│LED+│ LOn│    │
 *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
 *                                 │    │    │    │Prev│Next│
 *                            ┌────┼────┼────┤    ├────┼────┼────┐
 *                            │    │    │    │    │Vol+│    │    │
 *                            │Slep│Wake├────┤    ├────┤Mute│Play│
 *                            │    │    │    │    │Vol-│    │    │
 *                            └────┴────┴────┘    └────┴────┴────┘
 */
[FUNC2] = LAYOUT_ergodox(
        // left hand
       RESET,   _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  KC_SLEP, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       KC_MPRV, KC_MNXT,
       KC_VOLU,
       KC_VOLD, KC_MUTE, KC_MPLY
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
