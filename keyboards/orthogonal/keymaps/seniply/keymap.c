/* Copyright 2021 James Sa
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
    _BASE,
    _SYM,   // Symbol
    _EXT,   // Extend
    _FUN    // Function
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_M,   KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                        KC_LSFT,MO(_EXT),   MO(_SYM), KC_SPC
    ),
    [_SYM] = LAYOUT(
        KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,   KC_EQL,  KC_7, KC_8,   KC_9, KC_PLUS,
        KC_SCLN,KC_COLN,KC_LCBR,KC_LPRN,KC_LBRC,   KC_ASTR, KC_4, KC_5,   KC_6, KC_MINS,
        KC_CIRC,KC_AMPR,KC_RCBR,KC_RPRN,KC_RBRC,   KC_0,    KC_1, KC_2,   KC_3, KC_SLSH,
                                KC_LSFT,KC_NO,     KC_NO, KC_NO
    ),
    [_EXT] = LAYOUT(
        KC_ESC, LALT(KC_LEFT), G(KC_F), LALT(KC_RGHT),KC_INS,                    KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS,
        OSM(MOD_LALT), KC_LGUI, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
        G(KC_Z), G(KC_X), G(KC_C), KC_TAB, G(KC_V),                              KC_ENT, KC_BSPC, KC_RCTL, KC_LALT, KC_APP,
                                    KC_NO,KC_NO,                                 KC_NO, KC_ENT
    ),
    [_FUN] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_M,   KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                             KC_LSFT,TO(_EXT),   KC_ENT, KC_ENT
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
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
}
