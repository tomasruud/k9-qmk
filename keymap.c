/* Copyright 2023 @ Keychron (https://www.keychron.com)
 * Copyright 2024 @ Tomas Ruud
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

enum layers {
    MAC_BASE,
    WIN_BASE,
    SYMBOL,
    NAVIGATION,
    MAC_FN,
    WIN_FN,
    L_FN1,
};

// clang-format off

#define XX_F    LT(NAVIGATION, KC_F)
#define XX_D    LT(SYMBOL, KC_D)
#define XX_ESC  MT(MOD_LCTL, KC_ESC)
#define XX_LSFT LSFT_T(KC_GRV)
#define XX_PIPE A(KC_7)
#define XX_BSLS S(A(KC_7))
#define XX_LCBR S(A(KC_8))
#define XX_RCBR S(A(KC_9))
#define XX_LPRN S(KC_8)
#define XX_RPRN S(KC_9)
#define XX_LBRC A(KC_8)
#define XX_RBRC A(KC_9)
#define XX_SLSH S(KC_7)
#define XX_LT   KC_GRV
#define XX_GT   S(KC_GRV)
#define XX_TILD A(KC_RBRC)
#define XX_CIRC S(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_61_ansi(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,  KC_BSPC,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC, KC_BSLS,
    XX_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
    KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_RALT,MO(MAC_FN),MO(L_FN1)),

[WIN_BASE] = LAYOUT_61_ansi(
    KC_NUBS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    XX_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
    XX_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
    KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_LWIN,  KC_RALT, MO(WIN_FN),MO(L_FN1)),

[SYMBOL] = LAYOUT_61_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  XX_SLSH,  XX_LCBR,  XX_RCBR,  XX_TILD,  XX_CIRC,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  XX_PIPE,  XX_LPRN,  XX_RPRN,  XX_LT,    XX_GT,    _______,            _______,
    _______,            _______,  _______,  _______,  _______,  XX_BSLS,  XX_LBRC,  XX_RBRC,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

[NAVIGATION] = LAYOUT_61_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

[MAC_FN] = LAYOUT_61_ansi(
    KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  KC_UP,    KC_SNAP,  KC_PGDN,  KC_END,             _______,
    _______,            RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

[WIN_FN] = LAYOUT_61_ansi(
    KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  KC_APP,   KC_SCRL,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  KC_UP,    KC_PSCR,  KC_PGDN,  KC_END,             _______,
    _______,            RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

[L_FN1] = LAYOUT_61_ansi(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            QK_BOOT,
    _______,            _______,  _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};
