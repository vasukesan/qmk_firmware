#include QMK_KEYBOARD_H

enum vas_layers {
    _QWERTY,
    _FNC,
    _VIM
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
        DM_RSTP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, DM_REC1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, TG(_VIM), \
        KC_CAPS, RGB_RMOD,RGB_VAD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, MD_BOOT, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_VOLU, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            KC_MPLY,                            XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT  \
    ),
    
    [_VIM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_VIM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_VIM), \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_UP, KC_DOWN, KC_LEFT, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    
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
    // rgb_matrix_decrease_speed();

};

void rgb_matrix_indicators_user(void){
    uint8_t layer = biton32(layer_state);

    // INSERT CODE HERE: turn off all leds

    switch (layer) {
        case _QWERTY:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_1
            break;
        case _FNC:
            rgb_matrix_set_color_all(0, 0, 0);

            //Hidden normal functionality
            for(uint8_t i=1;i<13;i++){ 
                rgb_matrix_set_color(i,0xFF, 0xFF, 0xFF); //Fn keys

            }
            rgb_matrix_set_color(30 , 0xFF, 0xFF, 0xFF); //KC_CAPS

            //Dynamic macro
            rgb_matrix_set_color(0, 0x7A, 0x00, 0xFF);  //KC_GESC 
            rgb_matrix_set_color(19, 0x7A, 0x00, 0xFF); //KC_R
            rgb_matrix_set_color(25, 0x7A, 0x00, 0xFF); //KC_P

            //RGB controls
            rgb_matrix_set_color(17, 0xFF, 0xD9, 0x00); //KC_W
            rgb_matrix_set_color(31, 0xFF, 0xD9, 0x00); //KC_A
            rgb_matrix_set_color(32, 0xFF, 0xD9, 0x00); //KC_S
            rgb_matrix_set_color(33, 0xFF, 0xD9, 0x00); //KC_D
            rgb_matrix_set_color(45, 0xFF, 0xD9, 0x00); //KC_Z

            //Media
            rgb_matrix_set_color(66, 0x00, 0xFF, 0xFF); //KC_RIGHT
            rgb_matrix_set_color(65, 0x00, 0xFF, 0xFF); //KC_DOWN
            rgb_matrix_set_color(64, 0x00, 0xFF, 0xFF); //KC_LEFT
            rgb_matrix_set_color(61, 0x00, 0xFF, 0xFF); //KC_SPACE
            rgb_matrix_set_color(56, 0x00, 0xFF, 0xFF); //KC_UP
            rgb_matrix_set_color(51, 0x00, 0xFF, 0xFF); //KC_M

            //Device firmware update mode
            rgb_matrix_set_color(49, 0xFF, 0x00, 0x00); // KC_B
            
            
            break;
        case _VIM:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(23, 0x00, 0xFF, 0x00); //KC_I
            rgb_matrix_set_color(36, 0x47, 0x6E, 0x6A); //KC_H
            rgb_matrix_set_color(37, 0x47, 0x6E, 0x6A); //KC_J
            rgb_matrix_set_color(38, 0x47, 0x6E, 0x6A); //KC_K
            rgb_matrix_set_color(39, 0x47, 0x6E, 0x6A); //KC_L




    }
}


LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leader_end();
        leading = false;

        SEQ_ONE_KEY(KC_0) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
        }
        SEQ_TWO_KEYS(KC_LSFT, KC_4) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
        }
        SEQ_TWO_KEYS(KC_G, KC_G) {
            SEND_STRING(SS_TAP(X_HOME));    
        }

        SEQ_TWO_KEYS(KC_LSFT, KC_G) {
            SEND_STRING(SS_TAP(X_END));
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RGHT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_LGUI));

        }
        SEQ_TWO_KEYS(KC_D, KC_W) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RGHT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_LALT));
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
