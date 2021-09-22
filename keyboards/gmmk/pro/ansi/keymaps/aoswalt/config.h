#pragma once

// NOTE(adam): turn off rgb after suspend or 20 minutes
#ifdef RGB_MATRIX_ENABLE
  #define RGB_DISABLE_WHEN_USB_SUSPENDED
  #define RGB_DISABLE_TIMEOUT 1200000     // 20 minutes (20 * 60 * 1000ms)
#endif
