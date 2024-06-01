#include QMK_KEYBOARD_H
#include "brrr.c"

// clang-format off

#define LAYOUT_planck_wrapper(...)    LAYOUT_ortho_4x12_1x2uC(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_wrapper(
    __QRT_R1,
    __QRT_R2,
    __QRT_R3,
    __QRT_R4b
),

[_LOWER] = LAYOUT_planck_wrapper(
    __LOW_R1,
    __LOW_R2,
    __LOW_R3,
    __LOW_R4b
),

[_RAISE] = LAYOUT_planck_wrapper(
    __RAI_R1,
    __RAI_R2,
    __RAI_R3,
    __RAI_R4b
),

[_FUNCT] = LAYOUT_planck_wrapper(
    __FUN_R1,
    __FUN_R2,
    __FUN_R3,
    __FUN_R4b
),

// todo: move adjust layer to common keymaps.h
/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

};

// clang-format on
