#include QMK_KEYBOARD_H

enum vas_layers {
    _QWERTY,
    _FNC
};

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    VAS_CAPS
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RGUI, MO(_FNC),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FNC] = LAYOUT_65_ansi_blocker(
        DM_RSTP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
        _______, _______, RGB_VAI, _______, DM_REC1, _______, _______, _______, _______,_______, DM_PLY1, _______, _______, _______, _______, \
        KC_CAPS, RGB_RMOD,RGB_VAD, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, _______, KC_MUTE, _______, _______, _______, _______,          KC_VOLU, _______, \
        _______, _______, _______,                            KC_MPLY,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // SEND_STRING(SS_TAP(X_SPD) SS_TAP(X_SPD) SS_TAP(X_SPD) SS_TAP(X_SPD) SS_TAP(X_SPD) SS_TAP(X_SPD) SS_TAP(X_SPD));
    // tap_keycode();
    // register_code(RGB_SPD);
    // unregister_code(RGB_SPD);
    rgb_matrix_decrease_speed();
    rgb_matrix_decrease_speed();
    rgb_matrix_decrease_speed();
    rgb_matrix_decrease_speed();
    rgb_matrix_decrease_speed();

};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leader_end();
        leading = false;

        // SEQ_ONE_KEY(KC_F) {
        //   // Anything you can do in a macro.
        //   SEND_STRING("QMK is awesome.");
        // }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RGHT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_LGUI));

        }
        SEQ_TWO_KEYS(KC_D, KC_W) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RGHT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_LALT));
        }

        SEQ_TWO_KEYS(KC_G, KC_G) {
            SEND_STRING(SS_TAP(X_HOME));    
        }

        SEQ_TWO_KEYS(KC_LSFT, KC_G) {
            SEND_STRING(SS_TAP(X_END));
        }

        SEQ_TWO_KEYS(KC_Y, KC_Y) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RGHT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_UP(X_LSFT) "x" SS_UP(X_LGUI));

        }

        SEQ_TWO_KEYS(KC_Y, KC_W) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RGHT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_LGUI("x"));    
        }
        // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
        //   SEND_STRING("https://start.duckduckgo.com\n");
        // }
        // SEQ_TWO_KEYS(KC_A, KC_S) {
        //   register_code(KC_LGUI);
        //   register_code(KC_S);
        //   unregister_code(KC_S);
        //   unregister_code(KC_LGUI);
        // }
    }
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            // if (record->event.pressed) {
            //     key_timer = timer_read32();
            // } else {
            //     if (timer_elapsed32(key_timer) >= 500) {
            //         reset_keyboard();
            //     }
            // }
            if (record->event.pressed) {
                 key_timer = timer_read32();
          } else {
                if(get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    if (timer_elapsed32(key_timer) >= 500) {
                        reset_keyboard();
                    }
                }
                
          }
            return false;
        case VAS_CAPS:
            if (record->event.pressed) {
                SEND_STRING("asdf");
            } else{
                //release
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
