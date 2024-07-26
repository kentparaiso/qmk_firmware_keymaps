/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef LED_BRIGHTNESS_DEFAULT
#define LED_BRIGHTNESS_DEFAULT (LED_BRIGHTNESS_LO)

#define ORYX_CONFIGURATOR

#undef DEBOUNCE
#define DEBOUNCE 20

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 40

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 2

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 40

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 500

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 90

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define DYNAMIC_MACRO_NO_NESTING
