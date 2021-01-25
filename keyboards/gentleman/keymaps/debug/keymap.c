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
    _BASE,  // Colemak mod DH
    _KAI,   // beginner, no modifier on home row
    _PUNC,  // puncuation
    _FN     // function
};

#define _C(X) CTL_T(X)
#define _A(X) ALT_T(X)
#define _S(X) SFT_T(X)
#define _G(X) GUI_T(X)
#define FN_TAB LT(_FN, KC_TAB)
#define PN_BS LT(_PUNC, KC_BSPC)
// macOS shortcut
#define MSNCTL  C(KC_DOWN)
#define WKSPLF  C(KC_LEFT)
#define WKSPRT  C(KC_RGHT)
#define COPY    G(KC_C)
#define PSTE    G(KC_V)
#define CUT     G(KC_X)
#define UNDO    G(KC_Z)
#define REDO    G(S(KC_Z))
#define SCNSHOT S(G(KC_4))
// window management utility
#define DIVVY   G(KC_G)
// puncuation
#define KC_DQOT S(KC_QUOT)  // "

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] LAYOUT(
    KC_ESC, _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, KC_BSPC,
    KC_TAB, _C(KC_A),_A(KC_R),_S(KC_S),_G(KC_T),KC_G,    KC_QUOT,    KC_M, _G(KC_N),_S(KC_E),_A(KC_I),_C(KC_O),         KC_ENT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MINS,  KC_EQL,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL,  _______,   KC_LCTL, KC_LGUI,  PN_BS,  FN_TAB,  KC_CAPS, KC_SPC,   KC_LEFT,    KC_DOWN,    KC_UP,  KC_RGHT
    ),
    // [_KAI] LAYOUT(
    //     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_QUOT,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    //     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_LBRC,    KC_RBRC,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    //     _S(KC_Z),KC_X,    KC_C,    KC_D,    KC_V,    KC_MINS,TO(_BASE),KC_EQL,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    //     _C(KC_ESC), _A(KC_UP), _G(KC_DOWN), PN_BS,  FN_TAB,  KC_ENT,  KC_CAPS, KC_SPC,  KC_LEFT, KC_RGHT, KC_BSLS
    // ),
    // [_PUNC] LAYOUT(
    //     KC_PERC, KC_CIRC, KC_AMPR, KC_DLR,  _______,          _______,          _______, KC_7,    KC_8,    KC_9,    KC_PLUS,
    //     KC_EXLM, KC_AT,   KC_HASH, KC_DQOT, KC_LPRN,    _______,    _______,    KC_RPRN, KC_4,    KC_5,    KC_6,    KC_MINS,
    //     _______, _______, _______, KC_QUOT, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ASTR,
    //              _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_COMM, KC_DOT,  KC_SLSH
    // ),
    [_FN] LAYOUT(
    // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______,    _______,   _______, _______,   _______,   _______, _______, _______, _______

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, COPY,    PSTE,   _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,    _______,   _______, _______,   _______,   _______, _______, _______, _______
    //
    // _______, _______, _______, SCNSHOT,   DIVVY,   _______,   _______,    _______,    _______,    _______,    KC_UP,   KC_VOLD, KC_VOLU, _______, _______,
    //     _______,    UNDO,       CUT,    COPY,      PSTE,   _______,    _______,    _______,      KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    //             _______,    REDO,    WKSPLF,    MSNCTL,     WKSPRT,  _______, _______,_______,, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    //              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
}
