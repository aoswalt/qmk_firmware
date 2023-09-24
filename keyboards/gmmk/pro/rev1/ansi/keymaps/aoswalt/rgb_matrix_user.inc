RGB_MATRIX_EFFECT(GAME)
RGB_MATRIX_EFFECT(GAME2)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// {{{1 leds
// RGB led number layout, function of the key

//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08                                                                                                                                                                      92, led 19

enum leds {
  KB_LED_ESC = 0,
  KB_LED_TILDE,
  KB_LED_TAB,
  KB_LED_CAPS,
  KB_LED_LSHIFT,
  KB_LED_LCTRL,
  KB_LED_F1,
  KB_LED_1,
  KB_LED_Q,
  KB_LED_A,
  KB_LED_Z,
  KB_LED_LMETA,
  KB_LED_F2,
  KB_LED_2,
  KB_LED_W,
  KB_LED_S,
  KB_LED_X,
  KB_LED_LALT,
  KB_LED_F3,
  KB_LED_3,
  KB_LED_E,
  KB_LED_D,
  KB_LED_C,
  KB_LED_F4,
  KB_LED_4,
  KB_LED_R,
  KB_LED_F,
  KB_LED_V,
  KB_LED_F5,
  KB_LED_5,
  KB_LED_T,
  KB_LED_G,
  KB_LED_B,
  KB_LED_SPACE,
  KB_LED_F6,
  KB_LED_6,
  KB_LED_Y,
  KB_LED_H,
  KB_LED_N,
  KB_LED_F7,
  KB_LED_7,
  KB_LED_U,
  KB_LED_J,
  KB_LED_M,
  KB_LED_F8,
  KB_LED_8,
  KB_LED_I,
  KB_LED_K,
  KB_LED_COMMA,
  KB_LED_RALT,
  KB_LED_F9,
  KB_LED_9,
  KB_LED_O,
  KB_LED_L,
  KB_LED_PERIOD,
  KB_LED_FN,
  KB_LED_F10,
  KB_LED_0,
  KB_LED_P,
  KB_LED_SEMI,
  KB_LED_SLASH,
  KB_LED_F11,
  KB_LED_MINUS,
  KB_LED_LBRKT,
  KB_LED_QUOTE,
  KB_LED_RCTRL,
  KB_LED_F12,
  KB_LED_LSIDE_1,
  KB_LED_RSIDE_1,
  KB_LED_PRTSC,
  KB_LED_LSIDE_2,
  KB_LED_RSIDE_2,
  KB_LED_HOME,
  KB_LED_LSIDE_3,
  KB_LED_RSIDE_3,
  KB_LED_PAGEUP,
  KB_LED_LSIDE_4,
  KB_LED_RSIDE_4,
  KB_LED_EQUALS,
  KB_LED_RIGHT,
  KB_LED_LSIDE_5,
  KB_LED_RSIDE_5,
  KB_LED_END,
  KB_LED_LSIDE_6,
  KB_LED_RSIDE_6,
  KB_LED_BACKSPACE,
  KB_LED_PAGEDN,
  KB_LED_LSIDE_7,
  KB_LED_RSIDE_7,
  KB_LED_RBRKT,
  KB_LED_RSHIFT,
  KB_LED_LSIDE_8,
  KB_LED_RSIDE_8,
  KB_LED_BACKSLASH,
  KB_LED_UP,
  KB_LED_LEFT,
  KB_LED_ENTER,
  KB_LED_DOWN
};
// }}}

// {{{1 is_sidebar
static bool is_sidebar(int led) {
  int side_leds[16] = {
    KB_LED_LSIDE_1,
    KB_LED_RSIDE_1,
    KB_LED_LSIDE_2,
    KB_LED_RSIDE_2,
    KB_LED_LSIDE_3,
    KB_LED_RSIDE_3,
    KB_LED_LSIDE_4,
    KB_LED_RSIDE_4,
    KB_LED_LSIDE_5,
    KB_LED_RSIDE_5,
    KB_LED_LSIDE_6,
    KB_LED_RSIDE_6,
    KB_LED_LSIDE_7,
    KB_LED_RSIDE_7,
    KB_LED_LSIDE_8,
    KB_LED_RSIDE_8,
  };

  for (int i = 0; i < 16; i++) {
    if (led == side_leds[i]) return true;
  }

  return false;
}
// }}}

static void breathe(int index) {
  HSV hsv = rgb_matrix_config.hsv;
  uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v) * .66;
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

static void background(int index) {
  HSV hsv = rgb_matrix_config.hsv;
  hsv.s *= .5;
  hsv.v *= .5;
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

static void highlight(int index) {
  HSV hsv = rgb_matrix_config.hsv;
  hsv.h += 128;
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

static bool GAME(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (uint8_t i = led_min; i < led_max; i++) {
    if (is_sidebar(i)) {
      breathe(i);
    } else {
      background(i);
    }
  }

  highlight(KB_LED_W);
  highlight(KB_LED_A);
  highlight(KB_LED_S);
  highlight(KB_LED_D);
  highlight(KB_LED_ESC);
  highlight(KB_LED_SPACE);
  highlight(KB_LED_FN);

  return led_max < RGB_MATRIX_LED_COUNT;
}

static bool GAME2(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (uint8_t i = led_min; i < led_max; i++) {
    if (is_sidebar(i)) {
      highlight(i);
    } else {
      background(i);
    }
  }

  highlight(KB_LED_W);
  highlight(KB_LED_A);
  highlight(KB_LED_S);
  highlight(KB_LED_D);
  highlight(KB_LED_ESC);
  highlight(KB_LED_SPACE);
  highlight(KB_LED_FN);

  return led_max < RGB_MATRIX_LED_COUNT;
}

#endif

// vim:foldmethod=marker
