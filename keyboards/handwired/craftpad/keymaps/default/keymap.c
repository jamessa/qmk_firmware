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


// layout variations
enum{_BASIC};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASIC] LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,
      KC_L,    KC_Q,    KC_W,    KC_E,    KC_5,
      KC_LSFT, KC_A,    KC_S,    KC_D,    CTL_T(KC_6),
      KC_F3,   KC_9,    KC_8,    SFT_T(KC_7),    KC_SPC
    )
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
}
