#pragma once
#include QMK_KEYBOARD_H

enum userspace_layers {
    _QWERTY, // default layer
    _LOWER,  // numbers and symbold
    _RAISE,  // extra synbols
    _FUNCT,  // special functions
    _ADJUST, // keyboard functions
};
