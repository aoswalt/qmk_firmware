/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
  _CONTROL,
  _FN,
  _MEDIA,
  _GAME,
  _GAME_FN,
  _GAME_MACRO,
};

enum custom_keycodes {
    FOO = SAFE_RANGE,
    NMS_ADJ,
    NMS_WIR,
    NMS_CAC,
    NMS_SEL,
    MD_BOOT
};


// predefined
// KC_TRNS == _______ == transparent == passthrough
// KC_NO == XXXXXXX == NOOP == no action
// KC_MNXT = KC_MEDIA_NEXT_TRACK
// KC_MPRV = KC_MEDIA_PRV_TRACK


#define CTL_ESC CTL_T(KC_ESC)  // tap esc - hold ctrl
#define RGB_RMD RGB_RMOD
#define L_DFLT TO(_DEFAULT)
#define L_GAME TG(_GAME)
#define M_CTRL MO(_CONTROL)
#define M_MEDIA MO(_MEDIA)
#define M_FN MO(_FN)
#define M_GFN MO(_GAME_FN)
#define M_MACRO MO(_GAME_MACRO)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in. Also, holding SPACE+B when plugging the usb cable in puts the keyboard into bootloader mode.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.

    [_DEFAULT] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        M_CTRL,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, M_FN,   M_MEDIA, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_CONTROL] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_HOME,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          RGB_TOG, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            L_GAME,  _______, _______, RGB_SPD, RGB_RMD, RGB_SPI
    ),

    [_MEDIA] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MUTE,
        _______, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MSEL,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, _______,
        _______, _______, _______,                            KC_MPLY,                            _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        M_GFN,  M_MACRO,  _______,                            _______,                            _______, _______,  _______, _______, _______, _______
    ),

    [_GAME_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_GAME_MACRO] = LAYOUT(
        _______, NMS_WIR, NMS_CAC, _______, NMS_ADJ, NMS_SEL, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

/*  [_] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ), */

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif // ENCODER_ENABLE


uint32_t desired;

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

uint8_t prev = _DEFAULT;

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    /* case _FN: */
      /* if (prev != _GAME && prev != _GAME_FN && prev != _GAME_MACRO) { */
      /*   desired = rgb_matrix_get_mode(); */
      /* } */
      /*   rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
      /*   break; */
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
        // adj glitch
        case NMS_ADJ:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_E));
                register_code(KC_BTN1);
                wait_ms(17);
                unregister_code(KC_BTN1);
                SEND_STRING(SS_UP(X_E));
            }
            return false;
        // wire glitch
        case NMS_WIR:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_Q));
                register_code(KC_BTN1);
                wait_ms(17);
                unregister_code(KC_BTN1);
                SEND_STRING(SS_UP(X_Q));
            }
            return false;
        // cache glitch piece
        case NMS_CAC:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_Q) SS_DOWN(X_C) SS_DELAY(17) SS_UP(X_C) SS_UP(X_Q));
            }
            return false;
        // sell food for nanties
        case NMS_SEL:
            if (record->event.pressed) {
                for(int i = 0; i < 5; i++) {
                  SEND_STRING(SS_DOWN(X_E) SS_DELAY(2500) SS_UP(X_E) SS_DELAY(9) SS_DOWN(X_1) SS_DELAY(125) SS_UP(X_1));
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
