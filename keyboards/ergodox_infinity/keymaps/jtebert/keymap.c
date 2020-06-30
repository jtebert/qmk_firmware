#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"

// #define _QWERTY 0   // default QWERTY base layer
// #define _COLEMAK 6 // Colemak base layer
// #define _SYMB 1   // symbols
// #define _MDIA 2   // media keys
// #define _FUNC1 4  // Function layer (F_ keys)
// #define _FUNC2 5  // Function layer 2

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    COLEMAK,
    QWERTY
};

enum unicode_names {
    // LEFT HAND
    SQUARED, CUBED, PLUSMIN,
    // RIGHT HAND
    DEG, TIMES, ENDASH, EQISH, LEQ, GEQ, DIV, NEQ,
    LEFT, DOWN, UP, RIGHT
};

const uint32_t PROGMEM unicode_map[] = {
    // LEFT HAND
    [SQUARED] = 0x00B2,  // ²
    [CUBED]   = 0x00B3,  // ³
    [PLUSMIN] = 0x00B1,  // ±
    // RIGHT HAND
    [DEG]     = 0x00B0,  // °
    [TIMES]   = 0x00D7,  // ×
    [ENDASH]  = 0x2013,  // –
    [EQISH]   = 0x2248,  // ≈
    [LEQ]     = 0x2264,  // ≤
    [GEQ]     = 0x2265,  // ≥
    [DIV]     = 0x00F7,  // ÷
    [NEQ]     = 0x2260,  // ≠
    [LEFT]  = 0x2190,  // ←
    [DOWN]  = 0x2193,  // ↓
    [UP]    = 0x2191,  // ↑
    [RIGHT] = 0x2192,  // →
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE LAYER (COLEMAK)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │  ESC │  1 │  2 │  3 │  4 │  5 │Calc│              │QWER│  6 │  7 │  8 │  9 │  0 │  -_  │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │  TAB │  Q │  W │  F │  P │  G │ =+ │              │  ( │  J │  L │  U │  Y │  ; │  [{  │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │   _  │  A │  R │  S │  T │  D ├────┤              ├────┤  H │  N │  E │  I │  O │   '  │
     * ├──────┼────┼────┼────┼────┼────┤ F1 │              │  ) ├────┼────┼────┼────┼────┼──────┤
     * │LShift│  Z │  X │  C │  V │  B │    │              │    │  K │  M │  , │  . │ /? │  ]}  │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LAlt│ `~ │ \| │LGUI│                                  │Left│Down│ Up │Rght│Caps│
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │ F2 │LTog│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │Home│    │PgUp│    │    │
     *                            │Bksp│ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │ End│    │PgDn│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_COLEMAK] = LAYOUT_ergodox(  // Colemak persistent layer (default)
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5, KC_CALC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,      KC_G, KC_EQL,
        KC_UNDS, KC_A,    KC_R,    KC_S,    KC_T,      KC_D,
        KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B, MO(_FUNC),
        KC_LCTL, KC_LALT, KC_GRV,  KC_BSLS, KC_LGUI,
                                            MO(_SYMB), RGB_TOG,
                                                       KC_HOME,
                                   KC_LSFT, KC_DEL,    KC_END,
        // right hand
        QWERTY,  KC_6,     KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS,
        KC_LPRN, KC_J,     KC_L,    KC_U,     KC_Y,    KC_SCLN,  KC_LBRC,
                 KC_H,     KC_N,    KC_E,     KC_I,    KC_O,     KC_QUOT,
        KC_RPRN, KC_K,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RBRC,
                           KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_CAPS,
        KC_RALT, KC_RCTRL,
        KC_PGUP,
        KC_PGDN, KC_ENT,   KC_SPC),

    /* BASE LAYER (QWERTY)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │  ESC │  1 │  2 │  3 │  4 │  5 │Calc│              │CLMK│  6 │  7 │  8 │  9 │  0 │  -_  │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │  TAB │  Q │  W │  E │  R │  T │ =+ │              │  ( │  Y │  U │  I │  O │  P │  [{  │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │   _  │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  ; │   '  │
     * ├──────┼────┼────┼────┼────┼────┤ F1 │              │  ) ├────┼────┼────┼────┼────┼──────┤
     * │Backsp│  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │ /? │  ]}  │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LAlt│ `~ │ \| │LGUI│                                  │Left│Down│ Up │Rght│Caps│
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │ F2 │LTog│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │Home│    │PgUp│    │    │
     *                            │LSft│ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │ End│    │PgDn│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_QWERTY] = LAYOUT_ergodox(  // QWERTY persistent layer
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_CALC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_EQL,
        KC_UNDS, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,
        KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    MO(_FUNC),
        KC_LCTL, KC_LALT, KC_GRV,  KC_BSLS, KC_LGUI,
                                            MO(_SYMB), RGB_TOG,
                                                       KC_HOME,
                                   KC_LSFT, KC_DEL,    KC_END,
        // right hand
        COLEMAK, KC_6,     KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS,
        KC_LPRN, KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
                 KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_RPRN, KC_N,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RBRC,
                           KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_CAPS,
        KC_RALT, KC_RCTRL,
        KC_PGUP,
        KC_PGDN, KC_ENT,   KC_SPC),

    /* FUNCTION LAYER: Function keys and interaction
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │PrtScr│ F1 │ F2 │ F3 │ F4 │ F5 │    │              │Mode│ F6 │ F7 │ F8 │ F9 │ F10│  F11 │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │ScLt│ScDn│ScUp│ScRt│  F12 │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    ├────┤              ├────┤    │Left│Down│ Up │Rght│      │
     * ├──────┼────┼────┼────┼────┼────┤!!!!│              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │Home│PgDn│PgUp│ End│      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │LOff│LED-│LED+│ LOn│    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │WbBk│WbFd│    │Prev│Next│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │TabL│    │Vol+│    │    │
     *                            │Slep│    ├────┤    ├────┤Mute│Play│
     *                            │    │    │TabR│    │Vol-│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_FUNC] = LAYOUT_ergodox(
        // left hand
        KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                     C(KC_PGUP),
                                   KC_SLEP, _______, C(KC_PGDN),
        // right hand
        UC_MOD,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
        _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_F12,
                 _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,
                          BL_OFF,  BL_DEC,  BL_INC,  BL_ON,    _______,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),

    /* SYMBOL: Miscellaneous Symbols/Characters
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ FLASH│    │  ² │  ³ │    │    │    │              │    │  ° │    │  × │    │    │   –  │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │  ± │              │    │    │    │    │    │    │   ≈  │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │    │  ≤ │  ≥ │  ÷ │   ≠  │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │!!!!│    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_SYMB] = LAYOUT_ergodox(
        // left hand
        RESET,   _______, X(SQUARED), X(CUBED), _______, _______, _______,
        _______, _______, _______,    _______,  _______, _______, X(PLUSMIN),
        _______, _______, _______,    _______,  _______, _______,
        _______, _______, _______,    _______,  _______, _______, _______,
        _______, _______, _______,    _______,  _______,
                                                _______, _______,
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        _______, X(DEG),  _______, X(TIMES), _______, _______, X(ENDASH),
        _______, _______, _______, _______,  _______, _______, X(EQISH),
                 _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, X(LEQ),   X(GEQ),  X(DIV),  X(NEQ),
                          _______, X(LEFT),  X(DOWN), X(UP),   X(RIGHT),
        _______, _______,
        _______,
        _______, _______, _______),

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
    [_MEDIA] = LAYOUT_ergodox(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______, _______,
                            // right hand
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, KC_WBAK),
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
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){
    // Start in Linux mode for unicode input    
    set_unicode_input_mode(UC_LNX);
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

// BLANK LAYER

// ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
// │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
// ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
// │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
// ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
// │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
// ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
// │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
// └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
//   │    │    │    │    │    │                                  │    │    │    │    │    │
//   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
//                                 │    │    │    │    │    │
//                            ┌────┼────┼────┤    ├────┼────┼────┐
//                            │    │    │    │    │    │    │    │
//                            │    │    ├────┤    ├────┤    │    │
//                            │    │    │    │    │    │    │    │
//                            └────┴────┴────┘    └────┴────┴────┘
