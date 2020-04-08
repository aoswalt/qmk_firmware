RGB_MATRIX_EFFECT(GAME)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
enum leds {
  ALT_LED_ESC = 0,
  ALT_LED_1,
  ALT_LED_2,
  ALT_LED_3,
  ALT_LED_4,
  ALT_LED_5,
  ALT_LED_6,
  ALT_LED_7,
  ALT_LED_8,
  ALT_LED_9,
  ALT_LED_0,
  ALT_LED_MINUS,
  ALT_LED_EQUALS,
  ALT_LED_BACKSPACE,
  ALT_LED_DELETE,
  ALT_LED_TAB,
  ALT_LED_Q,
  ALT_LED_W,
  ALT_LED_E,
  ALT_LED_R,
  ALT_LED_T,
  ALT_LED_Y,
  ALT_LED_U,
  ALT_LED_I,
  ALT_LED_O,
  ALT_LED_P,
  ALT_LED_LBRK,
  ALT_LED_RBRK,
  ALT_LED_BSLASH,
  ALT_LED_HOME,
  ALT_LED_CAPS,
  ALT_LED_A,
  ALT_LED_S,
  ALT_LED_D,
  ALT_LED_F,
  ALT_LED_G,
  ALT_LED_H,
  ALT_LED_J,
  ALT_LED_K,
  ALT_LED_L,
  ALT_LED_SEMI,
  ALT_LED_QUOTE,
  ALT_LED_ENTER,
  ALT_LED_PGUP,
  ALT_LED_LSHIFT,
  ALT_LED_Z,
  ALT_LED_X,
  ALT_LED_C,
  ALT_LED_V,
  ALT_LED_B,
  ALT_LED_N,
  ALT_LED_M,
  ALT_LED_COMMA,
  ALT_LED_PERIOD,
  ALT_LED_SLASH,
  ALT_LED_RSHIFT,
  ALT_LED_UP,
  ALT_LED_PGDN,
  ALT_LED_LCTRL,
  ALT_LED_LMETA,
  ALT_LED_LALT,
  ALT_LED_SPACE,
  ALT_LED_RALT,
  ALT_LED_FN,
  ALT_LED_LEFT,
  ALT_LED_DOWN,
  ALT_LED_RIGHT,
  ALT_LED_UNDER01,
  ALT_LED_UNDER02,
  ALT_LED_UNDER03,
  ALT_LED_UNDER04,
  ALT_LED_UNDER05,
  ALT_LED_UNDER06,
  ALT_LED_UNDER07,
  ALT_LED_UNDER08,
  ALT_LED_UNDER09,
  ALT_LED_UNDER10,
  ALT_LED_UNDER11,
  ALT_LED_UNDER12,
  ALT_LED_UNDER13,
  ALT_LED_UNDER14,
  ALT_LED_UNDER15,
  ALT_LED_UNDER16,
  ALT_LED_UNDER17,
  ALT_LED_UNDER18,
  ALT_LED_UNDER19,
  ALT_LED_UNDER20,
  ALT_LED_UNDER21,
  ALT_LED_UNDER22,
  ALT_LED_UNDER23,
  ALT_LED_UNDER24,
  ALT_LED_UNDER25,
  ALT_LED_UNDER26,
  ALT_LED_UNDER27,
  ALT_LED_UNDER28,
  ALT_LED_UNDER29,
  ALT_LED_UNDER30,
  ALT_LED_UNDER31,
  ALT_LED_UNDER32,
  ALT_LED_UNDER33,
  ALT_LED_UNDER34,
  ALT_LED_UNDER35,
  ALT_LED_UNDER36,
  ALT_LED_UNDER37,
  ALT_LED_UNDER38
};

static bool is_underglow(int index) {
  return index >= ALT_LED_UNDER01;
}

static bool GAME(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (uint8_t i = led_min; i < led_max; i++) {
    if (is_underglow(i)) {
      rgb_matrix_set_color(i, 0x00, 0xff, 0xff);
    } else {
      rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
    }
    rgb_matrix_set_color(ALT_LED_ESC, 0xff, 0x00, 0x00);
    rgb_matrix_set_color(ALT_LED_W, 0xff, 0x00, 0x00);
    rgb_matrix_set_color(ALT_LED_A, 0xff, 0x00, 0x00);
    rgb_matrix_set_color(ALT_LED_S, 0xff, 0x00, 0x00);
    rgb_matrix_set_color(ALT_LED_D, 0xff, 0x00, 0x00);
    rgb_matrix_set_color(ALT_LED_SPACE, 0xff, 0x00, 0x00);
    rgb_matrix_set_color(ALT_LED_FN, 0xff, 0x00, 0x00);
  }

  return led_max < DRIVER_LED_TOTAL;
}

#endif
