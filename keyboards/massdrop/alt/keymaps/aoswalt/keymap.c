#include QMK_KEYBOARD_H

enum alt_layers {
  _DEFAULT,
  _FN,
  _MEDIA,
  _GAME,
  _GAME_FN,
  _GAME_MACRO,
};

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE,  //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,               //USB Toggle Automatic GCR control
    DBG_TOG,                //DEBUG Toggle On / Off
    DBG_MTRX,               //DEBUG Toggle Matrix Prints
    DBG_KBD,                //DEBUG Toggle Keyboard Prints
    DBG_MOU,                //DEBUG Toggle Mouse Prints
    MD_BOOT,                //Restart into bootloader after hold timeout
    NMS_BLD,
    NMS_SEL,
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
#define L_GAME TG(_GAME)
#define M_GFN MO(_GAME_FN)
#define M_MEDIA MO(_MEDIA)
#define M_MACRO MO(_GAME_MACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_65_ansi_blocker(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME, \
        CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP, \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_PGDN, \
        MO(_FN),  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  M_MEDIA,  KC_LEFT,  KC_DOWN,  KC_RGHT  \
    ),
    [_FN] = LAYOUT_65_ansi_blocker(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  _______,  KC_PAUS,  _______,  KC_END,  \
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,            _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_PGUP,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  KC_HOME,  KC_PGDN,  KC_END   \
    ),
    [_GAME] = LAYOUT_65_ansi_blocker(
        KC_ESC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        KC_LCTL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        M_GFN,    M_MACRO,    _______,                                _______,                                _______,  _______,  _______,  _______,  _______  \
    ),
    [_GAME_FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______  \
    ),
    [_GAME_MACRO] = LAYOUT_65_ansi_blocker(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        NMS_BLD,  NMS_SEL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______  \
    ),
    [_MEDIA] = LAYOUT_65_ansi_blocker(
        KC_MSTP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE, \
        _______,  RGB_MOD,  RGB_SPI,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  RGB_RMOD, RGB_SPD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,  _______,            KC_MSEL,  _______, \
        _______,  RGB_TOG,  _______,  _______,  _______,  MD_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,            KC_VOLU,  _______, \
        _______,  _______,  _______,                                KC_MPLY,                                L_GAME,   _______,  KC_MPRV,  KC_VOLD,  KC_MNXT  \
    ),
    /*
    [X] = LAYOUT_65_ansi_blocker(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______  \
    ),
    */
};

uint32_t desired;

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
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
      if (prev != _GAME && prev != _GAME_FN && prev != _GAME_MACRO) {
        desired = rgb_matrix_get_mode();
      }
      /* rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH); */
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_GAME);
      /* rgblight_mode_noeeprom(1); */
      break;
    case _GAME_FN:
      if (prev != _GAME && prev != _GAME_FN && prev != _GAME_MACRO) {
        desired = rgb_matrix_get_mode();
      }
      rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
      /* rgblight_mode_noeeprom(1); */
      break;
    case _GAME_MACRO:
      if (prev != _GAME && prev != _GAME_FN && prev != _GAME_MACRO) {
        desired = rgb_matrix_get_mode();
      }
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_GAME2);
      /* rgblight_mode_noeeprom(1); */
      break;
    default: //  for any other layers, or the default layer
      if (prev == _GAME || prev == _GAME_FN || prev == _GAME_MACRO) {
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
        // glitch build placement
        case NMS_BLD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTRL) SS_DELAY(5000) SS_UP(X_LCTRL) SS_DELAY(9));
                register_code(KC_BTN1);
                CLK_delay_ms(17);
                unregister_code(KC_BTN1);
            }
            return false;
        // sell food for nanties
        case NMS_SEL:
            if (record->event.pressed) {
                for(int i = 0; i < 50; i++) {
                  SEND_STRING(SS_DOWN(X_E) SS_DELAY(2500) SS_UP(X_E) SS_DELAY(9));
                  for(int j = 0; j < 125; j++) {
                    register_code(KC_BTN1);
                    CLK_delay_ms(17);
                    unregister_code(KC_BTN1);
                    CLK_delay_ms(17);
                    /* SEND_STRING(SS_DOWN(X_BTN1) SS_DELAY(17) SS_UP(X_BTN1)); */
                  }
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
