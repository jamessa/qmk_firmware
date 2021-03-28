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

//Tap Dance Definitions
enum{TD_1, TD_2, TD_3, TD_4, TD_5};

qk_tap_dance_action_t tap_dance_actions[] = {
   [TD_1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_6),
   [TD_2]  = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_7),
   [TD_3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_8),
   [TD_4]  = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_9),
   [TD_5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_0)};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] LAYOUT(
      KC_ESC,  TD(TD_2),TD(TD_3),TD(TD_4),TD(TD_5),
  SFT_T(KC_Q), TD(TD_1),KC_W,    KC_E,    KC_R,
      KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,
      KC_LCTL, KC_F2,   KC_F3,   KC_F5,   KC_SPC
    )
};
