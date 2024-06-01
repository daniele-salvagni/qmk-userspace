#include "brrr.h"
#include "keycodes.h"
#include "keymaps.h"

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_enable();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv_noeeprom (0x01,  0x00, 0x00);
#endif

#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    // ............................................................ Qwerty Layer
    // case QWERTY:
    //   if (record->event.pressed) {
    //     print("mode just switched to qwerty\n");
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    // ............................................................. ASCII Arrow
    case BR_RARW:
      if (record->event.pressed) {
        //send_unicode_string(shifted ? "\xe2\x87\x92" : "\xe2\x86\x92");
        // todoo: fix this
        // SEND_STRING((get_mods() & MOD_MASK_SHIFT) ? "->" : "=>");
      }
      return false;
    // .............................................. daniele.salvagni@gmail.com
    case BR_MAIL:
      if (record->event.pressed) {
        SEND_STRING("daniele.salvagni@gmail.com");
      }
      return false;
    // .......................................................... console.log();
    case BR_CLOG:
      if (record->event.pressed) {
        SEND_STRING("console.log();"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      }
      return false;
    // ....................................................... PTT & Alt/GUI-Tab
    case KC_INT5: ;  // c needs a statement ";" after a label
      // Keep track of the registered to then unregister the correct one
      static uint8_t reg_kc = 0;

      if (record->event.pressed) { // MHEN key pressed
        // If ALT or GUI is pressed, send TAB instead of MHEN (PTT Key)
        reg_kc = (get_mods() & MOD_MASK_AG) ? KC_TAB : KC_INT5;
        add_key(reg_kc);
      } else { // MHEN key depressed
        if (reg_kc != 0) {
          del_key(reg_kc);
          reg_kc = 0;
        }
      }
      send_keyboard_report(); // bc we are bypassing register/unregister_code
      return false;
    // ................................................................. {} Pair
    case BR_MCBR: // todo: update this
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("{}"SS_TAP(X_LEFT));
          return false;
        }
        tap_code16(KC_LCBR);
      }
      return false;
    // ................................................................. [] Pair
    case BR_MBRC: // todo: update this
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("[]"SS_TAP(X_LEFT));
          return false;
        }
        tap_code16(KC_LBRC);
      }
      return false;
    // ................................................................. () Pair
    case BR_MPRN: // todo: update this
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("()"SS_TAP(X_LEFT));
          return false;
        }
        tap_code16(KC_LPRN);
      }
      return false;
    // ....................................................... Search in New Tab
    case BR_SRCH:  // Searches the current selection in a new tab.
      if (record->event.pressed) {
      // todo: on Mac change LCTL to LGUI.
      SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
    }
  return false;
  } // END SWITCH
  return true;
}
