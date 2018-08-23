#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define QWERTY 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE (detected as JIS)
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab  |   /  |   ,  |   .  |   F  |   Q  |  [   |   |  ]   |   M  |   R  |   D  |   Y  |   P  |  @   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   I  |   U  |  (   |   |  )   |   G  |   T  |   K  |   S  |   N  |  :   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   W  |  {   |   |  }   |   B  |   H  |   J  |   L  |   ;  |¥/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Alt  | GUI  |  App |Esc/  | 英数 |Space/|Tab/  |   |Back  |Enter/| かな | Del  |=>QWER|=>SYMB|  _   |
 * |      |      |      |~SYMB |      |Cmd   |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  KC_TAB,   KC_SLSH, KC_COMM,KC_DOT,           KC_F,     KC_Q,          KC_RBRC,       KC_NUHS,    KC_M,             KC_R,     KC_D,     KC_Y,     KC_P,     KC_LBRC, \
  KC_LCTRL, KC_A,    KC_O,   KC_E,             KC_I,     KC_U,          S(KC_8),       S(KC_9),    KC_G,             KC_T,     KC_K,     KC_S,     KC_N,     KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,             KC_V,     KC_W,          S(KC_RBRC),    S(KC_BSLS), KC_B,             KC_H,     KC_J,     KC_L,     KC_SCLN,  SFT_T(KC_BSLS), \
  KC_LALT, KC_LGUI, KC_APP, LT(SYMB, KC_ESC), KC_LANG2, GUI_T(KC_SPC), SFT_T(KC_TAB), KC_BSPC,    LT(META, KC_ENT), KC_LANG1, KC_DELT,  TG(QWERTY), TG(SYMB), KC_INT1 \
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |  [   |   |  ]   |   7  |   8  |   9  |   0  |   -  |  ^   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |  F1  |      |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      | PWR  |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |Reset |=>QWER|=>SYMB|  \   |
 * |      |      |      |      |~SYMB |Ctrl  |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = KEYMAP( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    _______, _______, KC_7,    KC_8,    KC_9,  KC_0,    KC_MINS, KC_EQL, \
  _______, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, LSFT(LCTL(KC_PWR)), \
  _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  SFT_T(KC_RO), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______ \
),

/* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |   &  |  [   |   |  ]   |   '  |   (  |   )  |   ~  |   =  |  ~   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   +  |  *   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>QWER|=>SYMB|  \   |
 * |      |      |      |      |~SYMB |Ctrl  |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = KEYMAP( \
  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______, _______, S(KC_7), S(KC_8), S(KC_9),    S(KC_0),   S(KC_MINS), S(KC_EQL), \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   S(KC_SCLN), S(KC_QUOT), \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______ \
),

/* QWERTY
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |   |Back  |Enter | Del  |PrtSc |=>QWER|=>SYMB|  \   |
 * |      |      |      |      |      |      |      |   |Space |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */
[QWERTY] = KEYMAP( \
  KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_RBRC,    KC_BSLS,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, \
  KC_LALT,  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,   S(KC_8),    S(KC_9),    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   S(KC_RBRC), S(KC_BSLS), KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_RO), \
  KC_LCTRL, KC_LGUI, KC_APP, KC_PSCR, KC_ESC, KC_SPC, KC_TAB,     KC_BSPC,    KC_ENT, KC_DELT, KC_PSCR,  _______, _______, KC_JYEN \
)

};

