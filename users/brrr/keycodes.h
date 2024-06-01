#pragma once
#include "quantum_keycodes.h"

enum userspace_keycodes {
    BR_BRRR = QK_USER, // QK_USER avoids collisions with existing keycodes
    BR_RARW,  // ascii right arrow =>|
    BR_MAIL,  // daniele.salvagni@gmail.com
    BR_CLOG,  // console.log(|);
    BR_MPRN,  // (|)
    BR_MBRC,  // [|]
    BR_MCBR,  // {|}
    BR_SRCH,  // search selected in new tab
};

#define ___x___ KC_NO

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)

// Matching brackets
#define KC_MPRN LT(0, BR_MPRN) // (|)
#define KC_MBRC LT(0, BR_MBRC) // [|]
#define KC_MCBR LT(0, BR_MCBR) // {|}

// Virtual Desktop
#define DESK_LT C(G(KC_LEFT))
#define DESK_RT C(G(KC_RGHT))

// Task Manager
#define TASK_MG C(S(KC_ESC))

// Symbols
#define SYM_EUR ALGR(KC_5)    // €
#define SYM_DGR ALGR(KC_COLN) // °
#define SYM_CRS ALGR(KC_EQL)  // ×
#define SYM_EMP ALGR(KC_L)    // ø
#define SYM_LQT ALGR(KC_LBRC) // «
#define SYM_RQT ALGR(KC_RBRC) // »
#define SYM_FRA ALGR(KC_PLUS) // ÷

