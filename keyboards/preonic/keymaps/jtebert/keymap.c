/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  BACKLIT
};

enum unicode_names {
    BANG, SQUARED, CUBED, EURO, POUND, DEG, BULL, TIMES, CDOT, NEQ,
    HEART, PI, THUMBUP, SAD, CDOTS, NEUTRAL,
    ENDASH, PROP, ROBOT, SIGMA, THEREFOR, HAPPY, SHRUG, ANGFACE,
    POOP, CHECK, TM, COPY, BETA, LEQ, GEQ, PLUSMIN, EQISH,
    LEFT, DOWN, UP, RIGHT
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]    = 0x203D,  // ‽
    [SQUARED] = 0x00B2,  // ²
    [CUBED]   = 0x00B3,  // ³
    [EURO]    = 0x20AC,  // €
    [POUND]   = 0x00A3,  // £
    [DEG]     = 0x00B0,  // °
    [BULL]    = 0x2022,  // •
    [TIMES]   = 0x00D7,  // ×
    [CDOT]    = 0x22C5,  // ⋅
    [NEQ]     = 0x2260,  // ≠

    [HEART]   = 0X2764,   // ❤
    [PI]      = 0x03C0,   // π
    [THUMBUP] = 0X1F44D,  // 👍
    [SAD]     = 0X2639,   // ☹
    [CDOTS]   = 0x22EF,   // ⋯
    [NEUTRAL] = 0X1F610,  // 😐

    [ENDASH]   = 0x2013,   // –
    [PROP]     = 0x221D,   // ∝
    [ROBOT]    = 0X1F916,  // 🤖
    [SIGMA]    = 0x03A3,   // Σ
    [THEREFOR] = 0x2234,   // ∴
    [HAPPY]    = 0X1F642,  // 🙂
    [SHRUG]    = 0X1F937,  // 🤷
    [ANGFACE]  = 0X1F615,  // 😕

    [POOP]    = 0X1F4A9,  // 💩
    [CHECK]   = 0x2713,   // ✓
    [TM]      = 0x2122,   // ™
    [COPY]    = 0x00A9,   // ©
    [BETA]    = 0x03B2,   // β
    [LEQ]     = 0x2264,   // ≤
    [GEQ]     = 0x2265,   // ≥
    [PLUSMIN] = 0x00B1,   // ±
    [EQISH]   = 0x2248,   // ≈

    [LEFT]  = 0x2190,  // ←
    [DOWN]  = 0x2193,  // ↓
    [UP]    = 0x2191,  // ↑
    [RIGHT] = 0x2192,  // →
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  RGB | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Colemak
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │  ESC │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  TAB │   Q  │   W  │   F  │   P  │   G  │   J  │   L  │   U  │   Y  │   ;  │   =  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   -  │   A  │   R  │   S  │   T  │   D  │   H  │   N  │   E  │   I  │   O  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ BKSP │   Z  │   X  │   C  │   V  │   B  │   K  │   M  │   ,  │   .  │   /  │ENTER │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ CTRL │  DEL │  ALT │  OS  │ LOWER│ SHIFT│ SPACE│ RAISE│ LEFT │ DOWN │  UP  │ RIGHT│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,  \
  KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, \
  KC_MINS, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,  \
  KC_BSPC, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  KC_LCTL, KC_DEL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │   ‽  │   ²  │   ³  │   €  │   £  │   °  │   •  │   ×  │   ⋅  │   ≠  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │   |  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   _  │   [  │   ]  │   (  │   )  │      │      │   -  │   =  │   +  │      │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   {  │   }  │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │ **** │      │      │      │ Home │ Pg Dn│ Pg Up│  End │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, X(BANG), X(SQUARED), X(CUBED), X(EURO), X(POUND), X(DEG),  X(BULL), X(TIMES), X(CDOT), X(NEQ),  _______, \
  _______, _______, _______,   _______,   _______, _______,  _______, _______, _______,  _______, _______, KC_PIPE, \
  KC_UNDS, KC_LBRC, KC_RBRC,   KC_LPRN,   KC_RPRN, _______,  _______, KC_MINS, KC_EQL,   KC_PLUS, _______, KC_BSLS, \
  _______, KC_LCBR, KC_RCBR,   _______,   _______, _______,  _______, _______, _______,  _______, _______, _______, \
  _______, _______, _______,   _______,   _______, _______,  _______, _______, KC_HOME,  KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ RESET│      │      │   ❤  │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │   π  │      │      │  👍  │   ☹  │      │   ⋯  │  😐  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   –  │   ∝  │  🤖  │   ∑  │   ∴  │   °  │  🙂  │      │      │  🤷  │      │  😕  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   💩 │   ✓  │   ™  │   ©  │      │   β  │      │      │   ≤  │   ≥  │   ±  │   ≈  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │ **** │ CAPS │      │ **** │   ←  │   ↓  │   ↑  │  →   │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  RESET,   _______,  _______,  X(HEART), _______,     _______, _______,  _______,    _______, _______,  _______,    _______, \
  _______,   _______,  _______,  _______,  X(PI),       _______, _______,  X(THUMBUP), X(SAD),  _______,  X(CDOTS),   X(NEUTRAL), \
  X(ENDASH), X(PROP),  X(ROBOT), X(SIGMA), X(THEREFOR), X(DEG),  X(HAPPY), _______,    _______, X(SHRUG), _______,    X(ANGFACE), \
  X(POOP),   X(CHECK), X(TM),    X(COPY),  _______,     X(BETA), _______,  _______,    X(LEQ),  X(GEQ),   X(PLUSMIN), X(EQISH), \
  _______,   _______,  _______,  _______,  _______,     KC_CAPS, _______,  _______,    X(LEFT), X(DOWN),  X(UP),      X(RIGHT)
),

/* Raise
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ SLEEP│  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │  F10 │ CALC │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │UCMode│  HUE │      │      │PrntSc│      │      │Scr Lt│Scr Dn│Scr Up│Scr Rt│      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Colemk│  SAT │      │WEB BK│WEB FD│      │      │ Left │ Down │  Up  │ Right│      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │QWERTY│  VAL │      │Tab Lt│Tab Rt│      │      │ Home │ Pg Dn│ Pg Up│  End │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  RGB │      │      │      │      │      │ Play │ **** │ Mute │ Vol -│ Vol +│ Next │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_SLEP, KC_F1,   KC_F2,   KC_F3,      KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_CALC, \
  UC_MOD,  RGB_HUI, _______, _______,    KC_PSCR,    _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  _______, \
  COLEMAK, RGB_SAI, _______, KC_WBAK,    KC_WFWD,    _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, \
  QWERTY,  RGB_VAI, _______, C(KC_PGUP), C(KC_PGDN), _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, \
  RGB_TOG, _______, _______, _______,    _______,    _______, KC_MPLY, _______, KC_MUTE, KC_VOLD, KC_VOLU,  KC_MNXT
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        /* case DVORAK:
        //   if (record->event.pressed) {
        //     set_single_persistent_default_layer(_DVORAK);
        //   }
        //   return false;
        //   break;*/
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 *
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 *
 * For more ideas, see:
 * https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
 */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            // tap_code(KC_PGDN);
            // tap_code(KC_VOLU);
            tap_code16(C(KC_PGDN));
        } else { /* counterclockwise */
            // tap_code(KC_PGUP);
            // tap_code(KC_VOLD);
            tap_code16(C(KC_PGUP));
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
