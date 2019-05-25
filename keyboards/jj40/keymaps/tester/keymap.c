/* Copyright 2018 Noah Frederick
 *
 * Ts program is free software: you can redistribute it and/or modify
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

enum user_layers {
    COLEMAK,
    QWERTY,
    NUM,
    WINMAN,
    MACRO,
    KEEB
};


enum custom_keycodes {
  MY_MAIL = SAFE_RANGE,
  UNI_ID,
  AARLEKS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_MAIL:
      if (record->event.pressed) {
        // when keycode MY_MAIL is pressed
        SEND_STRING("Aarleks@gmail.com");
      } else {
        // when keycode MY_MAIL is released
      }
      break;
    case UNI_ID:
      if (record->event.pressed) {
	  // send the sting
	  SEND_STRING("30031443");
      } else {
	  // do nothing
      }
      break;
    case AARLEKS:
      if (record->event.pressed) {
	  // send the sting
	  SEND_STRING("Aarleks");
      } else {
	  // do nothing
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (COLEMAK)
   *                     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *  Hold for Setting-- │ Tab │  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │ BSpc│
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Hold for LGui   -- │ Esc │  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │  O  │  '  │ -- Hold for WinMan
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Hold for Shift  -- │  (  │  Z  │  X  │  C  │  V  │  B  │  K  │  M  │  ,  │  .  │  /  │  )  │ -- Hold for Shift
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────-─────┼─────┼─────┼─────┼─────┤
   *  Hold for CTL    -- │  ~  │Macro│  ⌥  │ Alt │ Shft│ Num │   Space   │ Ent │  ⌥  │Macro│  \  │ -- Hold for CTL
   *                     └─────┴─────┴─────┴─────┴─────┴─────┴─────-─────┴─────┴─────┴─────┴─────┘
   *                            / Tap for Del/                                         /
   *       Tap for ] [ --------'-----------------------------------------------------'
   */
  [COLEMAK] = LAYOUT_planck_1x2uR(\
    LT(KEEB, KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPACE,\
    LGUI_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, LT(WINMAN, KC_QUOT),\
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,\
    LCTL_T(KC_GRV), LT(MACRO, KC_LBRC), KC_EQUAL, LALT_T(KC_DELETE), LSFT_T(KC_NO), MO(NUM), KC_SPC, KC_ENT, KC_RALT, LT(NUM, KC_RBRC), RCTL_T(KC_BSLASH)\
  ),

  /* Base layer (QWERTY)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [QWERTY] = LAYOUT_planck_1x2uR(\
    _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, _______,\
    _______, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, _______,\
    _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
  ),

  /* Numbers and Symbols Layer (NUM)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  \  │Home │ End │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  F1 │ F2  │  F3 │  F4 │  F5 │  F6 │  F7 │  F8 │  F9 │ F10 │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NUM] = LAYOUT_planck_1x2uR(\
    _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,\
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLASH, KC_HOME, KC_END,\
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
    ),

  /* Windows Manager (WINMAN)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  W1 │  W2 │  W3 │  W4 │  W5 │  W6 │  W7 │  W8 │  W9 │  W10│     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ MW1 │ MW2 │ MW3 │ MW4 │ MW5 │ MW6 │ MW7 │ MW8 │ MW9 │ MW10│     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
*/
  [WINMAN] = LAYOUT_planck_1x2uR(
    _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______,\
    _______, LSFT(LGUI(KC_1)), LSFT(LGUI(KC_2)), LSFT(LGUI(KC_3)), LSFT(LGUI(KC_4)), LSFT(LGUI(KC_5)), LSFT(LGUI(KC_6)), LSFT(LGUI(KC_7)), LSFT(LGUI(KC_8)), LSFT(LGUI(KC_9)), LSFT(LGUI(KC_0)), _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
  ),

  /* GUI (window management/mouse/media controls) layer
   *
   *         Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Ms B2│Ms Up│Ms B1│Ms WD│     │     │Prev │ NW  │  N  │ NE  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms L │Ms Dn│Ms R │Ms WU│     │     │Full │  W  │Centr│  E  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Undo │ Cut │Copy │Paste│     │     │Next │ SW  │  S  │ SE  │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃Prev │Play │Next │Brig-│Sleep│Wake │Brig+│Mute │Vol- │Vol+ ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   *                         \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
*/
  [MACRO] = LAYOUT_planck_1x2uR(
     _______, _______, UNI_ID, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
     _______, AARLEKS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
     _______, _______, _______, _______, _______, _______, _______, MY_MAIL, _______, _______, _______, _______,\
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
  ),


  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *     Firmware -- │     │Reset│Make │     │     │     │     │     │     │     │Vers │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *          RGB -- │Qwert│     │     │Mode-│Mode+│Hue -│Hue +│Sat -│Sat +│     │Play1│Rec 1│ -- Record/play macro 1
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *        Audio -- │Colem│Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│Aud +│Aud -│     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │Steno│     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Toggl│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [KEEB] = LAYOUT_planck_1x2uR(\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,\
    QWERTY,  XXXXXXX, XXXXXXX, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX,\
    COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
  )

};
