/* Copyright 2019 Julia Ebert and Jennifer Shum
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _QWERTY,
    _Q_FN,
    _C_FN,
    _C_SYMB,
    _Q_EMOJI,
    _C_EMOJI
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    US_FLAG
};

enum unicode_names {
    // Reference: https://graphemica.com/
    F_1_2, F_2_3, F_1_3, F_1_4, HEX, F_3_4, F_1_8, F_1_9, F_1_10,
    BANG, DEG, EURO, POUND, SQUARED, CUBED, BULL, TIMES, EMPTY, ENDASH, PLUSMIN, LANG, RANG,
    EXISTS, TM, UNION, IN, OMEGA, PROP, PI, EQISH,
    ALPHA, SIGMA, FORALL, LAMBDA, THEREFOR, CDOTS, RET,
    CHECK, BALX, COPY, BETA, MU, LEQ, GEQ, DIV, NEQ, UP,
    CDOT, LEFT, DOWN, RIGHT,

    // Reference: https://unicode.org/emoji/charts/full-emoji-list.html
    BOMB, COW, ELEPHANT, DOG, MOUSE, CAT, LLAMA, SHEEP, SPIDER, OWL, MONKEY, PANDA, BADGER, TRASH, WARNING,
    LAPTOP, THERM, PLANE, MONEY, SNEK, CHEESE, OCTO, ASTX, GIFT, CURLING, FINGX, ABACUS, SAD, HAPPY,
    THINK, WAVE, EYEROLL, ROBOT, TREX, HUH, SURP, SHRUG, OK, TONGUE, EGGPLANT, PEACH, NEUTRAL, RAINBOW,
    ANGRY, SNOWFLAKE, HAPPYD, FIRE, GLOBE, HANDS, DIAMOND, KISS, HEART, SADEYE, PARTY, NOENT, STRONG,
    HAPPYC, ZZZ, XX, CLAP, BIGEYE, BIKE, NOSE, MUSIC, FIST, ANGFACE, KEYBOARD, HOME, THUMBUP, XFLAG,
    PENGUIN, POOP, ROCKET, POINTL, THUMBDN, POINTR
};

const uint32_t PROGMEM unicode_map[] = {
    // Function layer
    [F_1_2] = 0x00BD, // ½
    [F_2_3] = 0x2154, // ⅔
    [F_1_3] = 0x2153, // ⅓
    [F_1_4] = 0x00BC, // ¼
    [F_3_4] = 0x00BE, // ¾
    [HEX] = 0x2B21, // ⬡
    [F_1_8] = 0x215B, // ⅛
    [F_1_9] = 0x2151, // ⅑
    [F_1_10] = 0x2152, // ⅒

    [BANG] = 0x203D, // ‽
    [DEG] = 0x00B0, // °
    [SQUARED] = 0x00B2, // ²
    [CUBED] = 0x00B3, // ³
    [EURO] = 0x20AC, // €
    [POUND] = 0x00A3, // £
    [BULL] = 0x2022, // •
    [TIMES] = 0x00D7, // ×
    [EMPTY] = 0x2205, // ∅
    [ENDASH] = 0x2013, // –
    [PLUSMIN] = 0x00B1, // ±
    [LANG] = 0x2329, // 〈
    [RANG] = 0x232A, // 〉

    [EXISTS] = 0x2203, // ∃
    [TM] = 0x2122, // ™
    [UNION] = 0x222A, // ∪
    [IN] = 0x2208, // ∈
    [OMEGA] = 0x03A9, // Ω
    [PROP] = 0x221D, // ∝
    [PI] = 0x03C0, // π
    [EQISH] = 0x2248, // ≈

    [ALPHA] = 0x03B1, // α
    [SIGMA] = 0x03A3, // Σ
    [FORALL] = 0x2200, // ∀
    [LAMBDA] = 0x03BB, // λ
    [THEREFOR] = 0x2234, // ∴
    [CDOTS] = 0x22EF, // ⋯
    [RET] = 0x23CE, // ⏎

    [CHECK] = 0x2713, // ✓
    [BALX] = 0x2717, // ✗
    [COPY] = 0x00A9, // ©
    [BETA] = 0x03B2, // β
    [MU] = 0x00B5, // µ
    [LEQ] = 0x2264, // ≤
    [GEQ] = 0x2265, // ≥
    [DIV] = 0x00F7, // ÷
    [NEQ] = 0x2260, // ≠
    [UP] = 0x2191, // ↑

    [CDOT] = 0x22C5, // ⋅
    [LEFT] = 0x2190, // ←
    [DOWN] = 0x2193, // ↓
    [RIGHT] = 0x2192, // →

    // Row 0
    [BOMB]  = 0X1F4A3, // 💣
    [COW]   = 0X1F404, // 🐄
    [ELEPHANT] = 0X1F418, // 🐘
    [DOG] = 0X1F415, // 🐕
    [MOUSE] = 0X1F401, // 🐁
    [CAT] = 0X1F408, // 🐈
    [LLAMA] = 0X1F999, // 🦙
    [SHEEP] = 0X1F411, // 🐑
    [SPIDER] = 0X1F577, // 🕷
    [OWL] = 0X1F989, // 🦉
    [MONKEY] = 0X1F435, // 🐵
    [PANDA] = 0X1F43C, // 🐼
    [BADGER] = 0X1F9A1, // 🦡
    [TRASH] = 0X1F5D1, // 🗑
    [WARNING] = 0X26a0, // ⚠

    // Row 1
    [LAPTOP] = 0X1F4BB, // 💻
    [THERM] = 0X1F321, // 🌡
    [PLANE] = 0X2708, // ✈
    [MONEY] = 0X1F4B8, // 💸
    [SNEK]  = 0x1F40D, // 🐍
    [CHEESE] = 0X1F9C0, // 🧀
    [OCTO] = 0X1F419, // 🐙
    [ASTX] = 0X2733, // ✳
    [GIFT] = 0X1F381, // 🎁
    [CURLING] = 0X1F94C, // 🥌
    [FINGX] = 0X1F91E, // 🤞
    [ABACUS] = 0X1F9EE, // 🧮
    [SAD] = 0X2639, // ☹
    [HAPPY] = 0X1F642, // 🙂

    // Row 2
    [THINK] = 0X1F914, // 🤔
    [WAVE] = 0X1F44B, // 👋
    [EYEROLL] = 0X1F644, // 🙄
    [ROBOT] = 0X1F916, // 🤖
    [TREX] = 0X1F996, // 🦖
    [HUH] = 0X1F928, // 🤨
    [SURP] = 0X1F632, // 😲
    [SHRUG] = 0X1F937, // 🤷
    [OK] = 0X1F44C, // 👌
    [TONGUE] = 0X1F61B, // 😛
    [EGGPLANT] = 0X1F346, // 🍆
    [PEACH] = 0X1F351, // 🍑
    [NEUTRAL] = 0X1F610, // 😐
    [RAINBOW] = 0X1F308, // 🌈

    // Row 3
    // ANGRY, SNOWFLAKE, HAPPYD, FIRE, GLOBE, HANDS, DIAMOND, KISS, HEART, SADEYE, PARTY, NOENT, STRONG,
    [ANGRY] = 0X1F620, // 😠
    [SNOWFLAKE] = 0X2744, // ❄
    [HAPPYD] = 0X1F600, // 😀
    [FIRE] = 0X1F525, // 🔥
    [GLOBE] = 0X1F30D, // 🌎
    [HANDS] = 0X1F64C, // 🙌
    [DIAMOND] = 0X1F48E, // 💎
    [KISS] = 0X1F618, // 😘
    [HEART] = 0X2764, // ❤
    [SADEYE] = 0X1F97A, // 🥺
    [PARTY] = 0X1F389, // 🎉
    [NOENT] = 0X26D4, // ⛔
    [STRONG] = 0X1F4AA, // 💪

    // Row 4
    [HAPPYC] = 0X1F60A, // 😊
    [ZZZ] = 0X1F4A4, // 💤
    [XX] = 0X274C, // ❌
    [CLAP] = 0X1F44F, // 👏
    [BIGEYE] = 0X1F633, // 😳
    [BIKE] = 0X1F6B4, // 🚴
    [NOSE] = 0X1F443, // 👃
    [MUSIC] = 0X1F3B5, // 🎵
    [FIST] = 0X1F91B, // 🤛
    [ANGFACE] = 0X1F615, // 😕
    [KEYBOARD] = 0X2328, // ⌨
    [HOME] = 0X1F3E0, // 🏠
    [THUMBUP] = 0X1F44D, // 👍
    [XFLAG] = 0X1F3C1, // 🏁

    // Row 5
    [PENGUIN] = 0X1F427, // 🐧
    [POOP] = 0X1F4A9, // 💩
    [ROCKET] = 0X1F680, // 🚀
    [POINTL] = 0X1F448, // 👈
    [THUMBDN] = 0X1F44E, // 👎
    [POINTR] = 0X1F449, // 👉

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ ESC│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10│ F11│ F12│BKSP│PTSC│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │  ` │  1 │  2 │  3 │  4 │  5 │  6 │  7 │  8 │  9 │  0 │  - │  = │  ( │  ) │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │ TAB│  Q │  W │  F │  P │  G │  J │  L │  U │  Y │  ; │  [ │  ] │  \ │PGUP│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │  _ │  A │  R │  S │  T │  D │  H │  N │  E │  I │  O │  ' │  ENTER  │PGDN│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │BKSP│  Z │  X │  C │  V │  B │  K │  M │  , │  . │  / │MENU│HOME│ UP │ END│
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │CTRL│LALT│ GUI│ DEL│  LSHIFT │ SPACE/FN│ FN │RALT│EMOJ│CAPS│LEFT│DOWN│RGHT│
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_COLEMAK] = LAYOUT(  /* Colemak layer -- base */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5, KC_F6,  KC_F7, KC_F8,      KC_F9,   KC_F10,        KC_F11,  KC_F12,  KC_BSPC, KC_PSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,   KC_7,  KC_8,       KC_9,    KC_0,          KC_MINS, KC_EQL,  S(KC_9), S(KC_0),
        KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,    KC_G,  KC_J,   KC_L,  KC_U,       KC_Y,    KC_SCLN,       KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_UNDS, KC_A,    KC_R,    KC_S,   KC_T,    KC_D,  KC_H,   KC_N,  KC_E,       KC_I,    KC_O,          KC_QUOT, KC_ENT,           KC_PGDN,
        KC_BSPC, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_K,   KC_M,  KC_COMM,    KC_DOT,  KC_SLSH,       KC_APP,  KC_HOME, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI, KC_DEL, KC_LSFT,        LT(_C_FN, KC_SPC),        OSL(_C_SYMB), KC_RALT, MO(_C_EMOJI),  KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ ESC│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10│ F11│ F12│BKSP│PTSC│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │  ` │  1 │  2 │  3 │  4 │  5 │  6 │  7 │  8 │  9 │  0 │  - │  = │  ( │  ) │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │ TAB│  Q │  W │  E │  R │  T │  Y │  U │  I │  O │  P │  [ │  ] │  \ │PGUP│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │  _ │  A │  S │  D │  F │  G │  H │  J │  K │  L │  ; │  ' │  ENTER  │PGDN│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │BKSP│  Z │  X │  C │  V │  B │  N │  M │  , │  . │  / │MENU│HOME│ UP │ END│
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │CTRL│LALT│ GUI│ DEL│  LSHIFT │  SPACE  │ FN │RALT│EMOJ│CAPS│LEFT│DOWN│RGHT│
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_QWERTY] = LAYOUT(  /* QWERTY layer */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5, KC_F6,  KC_F7, KC_F8,       KC_F9,   KC_F10,       KC_F11,  KC_F12,  KC_BSPC, KC_PSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,   KC_7,  KC_8,        KC_9,    KC_0,         KC_MINS, KC_EQL,  S(KC_9), S(KC_0),
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,   KC_U,  KC_I,        KC_O,    KC_P,         KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_UNDS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,   KC_J,  KC_K,        KC_L,    KC_SCLN,      KC_QUOT, KC_ENT,           KC_PGDN,
        KC_BSPC, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_N,   KC_M,  KC_COMM,     KC_DOT,  KC_SLSH,      KC_APP,  KC_HOME, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI, KC_DEL, KC_LSFT,        KC_SPC,        OSL(_Q_FN),  KC_RALT, MO(_Q_EMOJI), KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ SLP│  ½ │  ⅔ │  ⅓ │  ¼ │  ¾ │    │    │  ⅛ │  ⅑ │1/10│    │    │CLMK│RSET│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │CALC│  ‽ │  ° │    │  € │    │    │  • │  × │    │  ∅ │  – │  ± │  ⟨ │  ⟩ │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │MODE│    │    │  ∃ │    │  ™ │    │  ∪ │  ∈ │  Ω │  ∝ │    │    │  ≈ │VLUP│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │    │  α │  ∑ │  ° │  ∀ │    │    │    │    │  λ │  ∴ │  ⋯ │    ↵    │VLDN│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │    │  ✓ │  ✗ │  © │    │  β │    │  μ │  ≤ │  ≥ │  ÷ │    │    │  ↑ │MUTE│
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │    │    │    │    │         │    ⋅    │    │    │    │  ≠ │  ← │  ↓ │  → │
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_Q_FN] = LAYOUT(  /* QWERTY function layer */
        KC_SLEP, X(F_1_2), X(F_2_3), X(F_1_3),  X(F_1_4),  X(F_3_4), _______, _______,  X(F_1_8), X(F_1_9),  X(F_1_10),   _______,   _______,    DF(_COLEMAK),  RESET,
        KC_CALC, X(BANG),  X(DEG),   _______,   X(EURO),   _______,  _______, X(BULL),  X(TIMES), _______,   X(EMPTY),    X(ENDASH), X(PLUSMIN), X(LANG),       X(RANG),
        UC_MOD,  _______,  _______,  X(EXISTS), _______,   X(TM),    _______, X(UNION), X(IN),    X(OMEGA),  X(PROP),     _______,   _______,    X(EQISH),      KC_VOLU,
        _______, X(ALPHA), X(SIGMA), X(DEG),    X(FORALL), _______,  _______, _______,  _______,  X(LAMBDA), X(THEREFOR), X(CDOTS),  X(RET),                    KC_VOLD,
        _______, X(CHECK), X(BALX),  X(COPY),   _______,   X(BETA),  _______, X(MU),    X(LEQ),   X(GEQ),    X(DIV),      _______,   _______,    X(UP),         KC_MUTE,
        _______, _______,  _______,  _______,   _______,             X(CDOT),           _______,  _______,   _______,     X(NEQ),    X(LEFT),    X(DOWN),       X(RIGHT)
    ),
    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ SLP│    │    │    │    │    │    │    │    │    │    │    │    │QWTY│RSET│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │CALC│    │    │    │    │    │    │    │    │    │    │    │    │    │    │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │MODE│    │    │    │    │    │    │WH_L│WH_D│WH_U│WH_R│    │    │    │VOLU│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │  - │  [ │  ] │  ( │  ) │  = │    │LEFT│DOWN│ UP │RGHT│    │         │VOLD│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │    │  { │  } │    │    │    │    │HOME│PGDN│PGUP│ END│    │    │    │MUTE│
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │WAKE│    │    │    │  SPACE  │         │    │WBAK│WFWD│    │MPRV│PLAY│MNXT│
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_C_FN] = LAYOUT(  /* Colemak function/navigation layer, including keys useful for programming */
        KC_SLEP, _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, DF(_QWERTY), RESET,
        KC_CALC, _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,     _______,
        UC_MOD,  _______,    _______,    _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  _______, _______, _______,     KC_VOLU,
        KC_MINS, KC_LBRC,    KC_RBRC,    S(KC_9), S(KC_0), KC_EQL,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,              KC_VOLD,
        _______, S(KC_LBRC), S(KC_RBRC), _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, _______, _______,     KC_MUTE,
        KC_WAKE, _______,    _______,    _______, MT(MOD_LSFT, KC_SPC) ,          _______,          _______, KC_WBAK, KC_WFWD,  _______, KC_MPRV, KC_MPLY,     KC_MNXT
    ),
    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ SLP│  ½ │  ⅔ │  ⅓ │  ¼ │  ¾ │  ⬡ │    │  ⅛ │  ⅑ │1/10│    │    │QWTY│RSET│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │CALC│  ‽ │  ² │  ³ │  € │  £ │  ° │  • │  × │  ⋅ │  ∅ │  – │  ± │  ⟨ │  ⟩ │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │MODE│  ∈ │  ∃ │  ∀ │  ∪ │  π │  Ω │HOME│PGDN│PGUP│ END│  ∴ │  ≠ │  ≈ │VOLU│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │  - │  [ │  ] │  ( │  ) │  = │  ∝ │LEFT│DOWN│ UP │RGHT│  ⋯ │    ↵    │VOLD│
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │    │  ✓ │  ✗ │  © │  ™ │  β │  λ │  μ │  ≤ │  ≥ │  ÷ │    │    │  ↑ │MUTE│
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │WAKE│    │    │    │         │PLAY/PAUS│    │SCRD│SCRU│    │  ← │  ↓ │  → │
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_C_SYMB] = LAYOUT(  /* Colemak symbol layer */
        KC_SLEP, X(F_1_2), X(F_2_3),   X(F_1_3),  X(F_1_4), X(F_3_4), X(HEX),    _______, X(F_1_8), X(F_1_9),       X(F_1_10),   _______,     _______,    DF(_QWERTY), RESET,
        KC_CALC, X(BANG),  X(SQUARED), X(CUBED),  X(EURO),  X(POUND), X(DEG),    X(BULL), X(TIMES), X(CDOT),        X(EMPTY),    X(ENDASH),   X(PLUSMIN), X(LANG),     X(RANG),
        UC_MOD,  X(IN),    X(EXISTS),  X(FORALL), X(UNION), X(PI),    X(OMEGA),  KC_HOME, KC_PGDN,  KC_PGUP,        KC_END,      X(THEREFOR), X(NEQ),     X(EQISH),    KC_VOLU,
        KC_MINS, KC_LBRC,  KC_RBRC,    S(KC_9),   S(KC_0),  KC_EQL,   X(PROP),   KC_LEFT, KC_DOWN,  KC_UP,          KC_RIGHT,    X(CDOTS),    X(RET),                  KC_VOLD,
        _______, X(CHECK), X(BALX),    X(COPY),   X(TM),    X(BETA),  X(LAMBDA), X(MU),   X(LEQ),   X(GEQ),         X(DIV),      _______,     _______,    X(UP),       KC_MUTE,
        KC_WAKE, _______,  _______,    _______,   _______,            KC_MPLY,            _______,  KC_MS_WH_DOWN,  KC_MS_WH_UP, _______,     X(LEFT),    X(DOWN),     X(RIGHT)
    ),
    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ 💣 │ 🐄 │ 🐘 │ 🐕 │ 🐁 │ 🐈 │ 🦙 │ 🐑 │ 🕷 │ 🦉 │ 🐵 │ 🐼 │ 🦡 │ 💩 │ ⚠ │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │ 💻 │ 🇺🇸 │ 🌡 │  ✈ │ 💸 │ 🐍 │ 🧀 │ 🐙 │ ✳ │ 🎁 │ 🥌 │ 🤞 │ 🧮 │  ☹ │ 🙂 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │    │ 🤔 │ 👋 │ 🙄 │ 🤖 │ 🦖 │ 🤨 │ 😲 │ 🤷 │ 👌 │ 😛 │ 🍆 │ 🍑 │ 😐 │ 🌈 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │    │ 😠 │  ❄ │ 😀 │ 🔥 │ 🌍 │ 🙌 │ 💎 │ 😘 │ ❤ │ 🥺 │ 🎉 │    ⛔   │ 💪 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │ 💩 │ 💤 │ ❌ │ 👏 │ 😳 │ 🚴 │ 👃 │ 🎵 │ 🤛 │ 🤞 │ 😕 │    │ 🏠 │ 👍 │ 🏁 │
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │    │    │ 🐧 │ 🗑 │    😊   │    🚀   │    │    │    │  ⌨ │ 👈 │ 👎 │ 👉 │
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_Q_EMOJI] = LAYOUT(  /* QWERTY emoji layer */
        X(BOMB),   X(COW),   X(ELEPHANT),  X(DOG),     X(MOUSE),  X(CAT),    X(LLAMA),  X(SHEEP),   X(SPIDER), X(OWL),   X(MONKEY),   X(PANDA),    X(BADGER), X(POOP),   X(WARNING),
        X(LAPTOP), US_FLAG,  X(THERM),     X(PLANE),   X(MONEY),  X(SNEK),   X(CHEESE), X(OCTO),    X(ASTX),   X(GIFT),  X(CURLING),  X(FINGX),    X(ABACUS), X(SAD),     X(HAPPY),
        _______,   X(THINK), X(WAVE),      X(EYEROLL), X(ROBOT),  X(TREX),   X(HUH),    X(SURP),    X(SHRUG),  X(OK),    X(TONGUE),   X(EGGPLANT), X(PEACH),  X(NEUTRAL), X(RAINBOW),
        _______,   X(ANGRY), X(SNOWFLAKE), X(HAPPYD),  X(FIRE),   X(GLOBE),  X(HANDS),  X(DIAMOND), X(KISS),   X(HEART), X(SADEYE),   X(PARTY),    X(NOENT),              X(STRONG),
        X(POOP),   X(ZZZ),   X(XX),        X(CLAP),    X(BIGEYE), X(BIKE),   X(NOSE),   X(MUSIC),   X(FIST),   X(FINGX),  X(ANGFACE), _______,     X(HOME),   X(THUMBUP), X(XFLAG),
        _______,   _______,  X(PENGUIN),   X(TRASH),   X(HAPPYC),            X(ROCKET),             _______,   _______,  _______,     X(KEYBOARD), X(POINTL), X(THUMBDN), X(POINTR)
    ),
    /*
     * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     * │ 💣 │ 🐄 │ 🐘 │ 🐕 │ 🐁 │ 🐈 │ 🦙 │ 🐑 │ 🕷 │ 🦉 │ 🐵 │ 🐼 │ 🦡 │ 💩 │ ⚠ │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │ 💻 │ 🇺🇸 │ 🌡 │  ✈ │ 💸 │ 🐍 │ 🧀 │ 🐙 │  ✳ │ 🎁 │ 🥌 │ 🤞 │ 🧮 │ ☹ │ 🙂 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │    │ 🤔 │ 👋 │ 🔥 │ 😛 │ 🌍 │ 💎 │ ❤ │ 😲 │ 🤨 │ 🥺 │ 🍆 │ 🍑 │ 😐 │ 🌈 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┴────┼────┤
     * │    │ 😠 │ 🤖 │ ❄ │ 🦖 │ 😀 │ 🙌 │ 👃 │ 🙄 │ 🤷 │ 👌 │ 🎉 │    ⛔   │ 💪 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┬────┼────┤
     * │ 💩 │ 💤 │ ❌ │ 👏 │ 😳 │ 🚴 │ 😘 │ 🎵 │ 🤛 │ 🤞 │ 😕 │    │ 🏠 │ 👍 │ 🏁 │
     * ├────┼────┼────┼────┼────┴────┼────┴────┼────┼────┼────┼────┼────┼────┼────┤
     * │    │    │ 🐧 │ 🗑 │    😊   │    🚀   │    │    │    │  ⌨ │ 👈 │ 👎 │ 👉 │
     * └────┴────┴────┴────┴─────────┴─────────┴────┴────┴────┴────┴────┴────┴────┘
     */
    [_C_EMOJI] = LAYOUT(  /* Colemak emoji layer */
        X(BOMB),   X(COW),   X(ELEPHANT), X(DOG),       X(MOUSE),  X(CAT),    X(LLAMA),   X(SHEEP), X(SPIDER),  X(OWL),   X(MONKEY),  X(PANDA),    X(BADGER), X(POOP),   X(WARNING),
        X(LAPTOP), US_FLAG,  X(THERM),    X(PLANE),     X(MONEY),  X(SNEK),   X(CHEESE),  X(OCTO),  X(ASTX),    X(GIFT),  X(CURLING), X(FINGX),    X(ABACUS), X(SAD),     X(HAPPY),
        _______,   X(THINK), X(WAVE),     X(FIRE),      X(TONGUE), X(GLOBE),  X(DIAMOND), X(HEART), X(SURP),    X(HUH),   X(SADEYE),  X(EGGPLANT), X(PEACH),  X(NEUTRAL), X(RAINBOW),
        _______,   X(ANGRY), X(ROBOT),    X(SNOWFLAKE), X(TREX),   X(HAPPYD), X(HANDS),   X(NOSE),  X(EYEROLL), X(SHRUG), X(OK),      X(PARTY),    X(NOENT),              X(STRONG),
        X(POOP),   X(ZZZ),   X(XX),       X(CLAP),      X(BIGEYE), X(BIKE),   X(KISS),    X(MUSIC), X(FIST),    X(FINGX), X(ANGFACE), _______,     X(HOME),   X(THUMBUP), X(XFLAG),
        _______,   _______,  X(PENGUIN),  X(TRASH),     X(HAPPYC),            X(ROCKET),            _______,    _______,  _______,    X(KEYBOARD), X(POINTL), X(THUMBDN), X(POINTR)
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
        case US_FLAG:
            if (record->event.pressed) {
                send_unicode_hex_string("1f1fA");
                send_unicode_hex_string("1f1f8");
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}
/*
void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/