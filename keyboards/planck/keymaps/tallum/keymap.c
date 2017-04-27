#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"

#include "config.h"

extern keymap_config_t keymap_config;

// Based on the Callum layout.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LANG 1
#define _LNGS 2
#define _MOVE 3
#define _SYMB 4
#define _FUNC 5

// Shortcut for the layer matrixes
#define _L _LANG

enum planck_keycodes {
  BASE = SAFE_RANGE,
  MOVE,
  SYMB,
  FUNC,
  LANG,
  LINUX,
  MAC
};

// tap modfiers hack, part 1
enum {
  CT_LAC,
  CT_RAC
};

// tap modfiers hack, part 1
enum {
  CT_LAC,
  CT_RAC
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | RCtr |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LShft|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  | RAlt | GUI  | LAlt | Symb |    Space    | Move | GUI  | RAlt | RShft|   "  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_TAB,     KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC},
  {KC_RCTL,    KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT },
  {KC_LSPO,    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT},
  {KC_BSLS, KC_RALT, MT(MOD_LGUI, KC_LBRACKET), TD(CT_LAC),  SYMB, KC_SPC, KC_SPC,  MOVE, TD(CT_RAC), MT(MOD_RGUI, KC_RBRACKET), KC_RSPC, KC_MINS}
},

/* LANG:SWE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  [Å  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  ;Ö  |  "Ä  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |   /  |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_LANG] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH}
},
*/
[_LANG] = {
  {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
  {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UC(0xe5),  _______},
  {MO(_LNGS), _______, _______, _______, _______, _______, _______, _______, _______, _______, UC(0xf6), UC(0xe4)},
  {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,MO(_LNGS),  KC_SLSH}
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |Pg Up | Home |  Up  | End  |      |      | Home |  Up  | End  |Pg Up | Esc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |Pg Dn | Left | Down |Right |      |      | Left | Down |Right |Pg Dn | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Pg Up |Pg Dn |      |      |Pg Dn |Pg Up |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {KC_ESC,  KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_ESC},
  {KC_DEL,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  KC_DEL},
  {_______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |   +  |   =  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   [  |   (  |   )  |   ]  |   }  |      |   ~  |   `  |   \  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = {
  {KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL},
  {_______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,  KC_EQL},
  {_______, KC_LCBR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_TILD,  KC_GRV, KC_BSLS, KC_PIPE},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |-----------------------------------------------------------------------------------.
 * | LANG | Prev | Play | Next | BL+  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LINUX| Mute | Vol- | Vol+ | BL-  | LANG |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MAC  |      |      |      |      |             |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11},
  {TG(_L), KC_MPRV, KC_MPLY, KC_MNXT, KC_PAUS, _______, _______, _______, _______, _______, _______, _______},
  { LINUX, KC_MUTE, KC_VOLD, KC_VOLU, KC_SLCK,    LANG, _______, _______, _______, _______, _______, _______},
  {   MAC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RESET}
},

/* Shifted lang layer. */
#define _S LSFT
[_LNGS] = {
  {    _______, _S(KC_Q), _S(KC_W), _S(KC_E), _S(KC_R), _S(KC_T), _S(KC_Y), _S(KC_U),    _S(KC_I),   _S(KC_O),  _S(KC_P),     KC_BSPC},
  {    KC_RCTL, _S(KC_A), _S(KC_S), _S(KC_D), _S(KC_F), _S(KC_G), _S(KC_H), _S(KC_J),    _S(KC_K),   _S(KC_L),  UC(0xc5),      KC_ENT},
  {    _______, _S(KC_Z), _S(KC_X), _S(KC_C), _S(KC_V), _S(KC_B), _S(KC_N), _S(KC_M), _S(KC_COMM), _S(KC_DOT),  UC(0xd6),    UC(0xc4)},
  {_S(KC_BSLS),  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,    _______,   _______, _S(KC_SLSH)}
}

};

typedef struct {
  bool alt;
  bool finished_once;
  uint16_t keycode;
} td_state_t;

void _td_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state_t *s = (td_state_t *)user_data;
  
  if (s->finished_once)
    return;
    
  s->finished_once = true;
  if (state->pressed) {
    s->alt = true;
    register_code (KC_LALT);
  } else {
    s->alt = false;
    register_code (KC_LSFT);
    register_code (s->keycode);
  }
}

void _td_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_state_t *s = (td_state_t *)user_data;

  if (s->alt) {
    unregister_code (KC_LALT);
  } else {
    unregister_code (s->keycode);
    unregister_code (KC_LSFT);
  }
  
  s->finished_once = false;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_LAC]  = {
    .fn = { NULL, _td_finished, _td_reset },
    .user_data = (void *)&((td_state_t) { false, false, KC_LBRACKET })
  },
  [CT_RAC]  = {
    .fn = { NULL, _td_finished, _td_reset },
    .user_data = (void *)&((td_state_t) { false, false, KC_RBRACKET })
  }
};

void matrix_init_user() {
  set_unicode_input_mode(UC_LNX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      } else {
        layer_off(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    case LANG:
      if (record->event.pressed) {
	/*
	register_code(KC_LGUI);
	register_code(KC_SPC);
	unregister_code(KC_SPC);
	unregister_code(KC_LGUI);
	*/
	layer_invert(_LANG);
      }
      return false;
      break;
    case LINUX:
      if (record->event.pressed) {
	set_unicode_input_mode(UC_LNX);
      }
      return false;
      break;
    case MAC:
      if (record->event.pressed) {
	set_unicode_input_mode(UC_OSX);
      }
      return false;
      break;
  }
  return true;
}
