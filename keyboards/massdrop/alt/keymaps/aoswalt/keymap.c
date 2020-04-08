#include QMK_KEYBOARD_H

enum alt_layers {
  _DEFAULT,
  _FN,
  _MEDIA,
  _GAME,
  _GAME_FN,
};

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE,  //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,               //USB Toggle Automatic GCR control
    DBG_TOG,                //DEBUG Toggle On / Off
    DBG_MTRX,               //DEBUG Toggle Matrix Prints
    DBG_KBD,                //DEBUG Toggle Keyboard Prints
    DBG_MOU,                //DEBUG Toggle Mouse Prints
    MD_BOOT,                //Restart into bootloader after hold timeout
};
// led direction and breathing?

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

// predefined
// KC_TRNS == _______ == transparent == passthrough
// KC_NO == XXXXXXX == NOOP == no action
// KC_MNXT = KC_MEDIA_NEXT_TRACK
// KC_MPRV = KC_MEDIA_PRV_TRACK

#define CTL_ESC CTL_T(KC_ESC)  // tap esc - hold ctrl
#define L_DFLT TO(_DEFAULT)
#define L_GAME TO(_GAME)
#define M_GFN MO(_GAME_FN)

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS, KC_HOME, \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,             KC_UP,   KC_PGDN, \
        MO(_FN), KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MEDIA), KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FN] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [_MEDIA] = LAYOUT_65_ansi_blocker(
        KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, L_GAME,  _______, _______, _______, _______, _______, _______,          KC_MSEL, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU, _______, \
        _______, _______, _______,                            KC_MPLY,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT  \
    ),
    [_GAME] = LAYOUT_65_ansi_blocker(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        M_GFN,   KC_NO,   _______,                            _______,                            _______, L_DFLT,  _______, _______, _______  \
    ),
    [_GAME_FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

uint32_t desired = RGB_MATRIX_RAINBOW_MOVING_CHEVRON;

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_mode(desired);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

uint8_t prev = _DEFAULT;

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _GAME:
      if (prev != _GAME && prev != _GAME_FN) {
        desired = rgb_matrix_get_mode();
      }
      /* rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH); */
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_GAME);
      /* rgblight_mode_noeeprom(1); */
      break;
    case _GAME_FN:
      if (prev != _GAME && prev != _GAME_FN) {
        desired = rgb_matrix_get_mode();
      }
      rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
      /* rgblight_mode_noeeprom(1); */
      break;
    default: //  for any other layers, or the default layer
      if (prev == _GAME || prev == _GAME_FN) {
        rgb_matrix_mode(desired);
      }
      break;
  }

  prev = biton32(state);
  return state;
}

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
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
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
