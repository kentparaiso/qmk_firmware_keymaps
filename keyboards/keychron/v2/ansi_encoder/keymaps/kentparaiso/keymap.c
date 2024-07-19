#include QMK_KEYBOARD_H

#define TAPPING_TERM_HOME_ROW_OUTER 100
#define TAPPING_TERM_HOME_ROW_MID 40
#define TAPPING_TERM_HOME_ROW_INNER 20

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Home row ctrl keys
        case LCTL_T(KC_D):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_INNER;
        case RCTL_T(KC_K):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_INNER;

        // Home row alt keys
        case LALT_T(KC_S):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_MID;
        case RALT_T(KC_L):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_MID;
        // Home row alt keys (when on Mac mode)
        case LALT_T(KC_A):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_OUTER;
        case RALT_T(KC_SCLN):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_OUTER;

        // Home row gui keys
        case LGUI_T(KC_A):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_OUTER;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_OUTER;
        // Home row gui keys (when on Mac mode)
        case LGUI_T(KC_S):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_MID;
        case RGUI_T(KC_L):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_MID;

        // Spacebar shift
        case LSFT_T(KC_SPC):
            return TAPPING_TERM + TAPPING_TERM_HOME_ROW_MID;

        default:
            return TAPPING_TERM;
    }
}

/*--------------------------------*/

enum custom_keycodes {
  MC_DBLQUOT = SAFE_RANGE,
  MC_SINQUOT,
  MC_DBLPAREN,
  MC_DBLSBRKT,
  MC_DBLCBRKT,
  MC_BACKTICKS,
  MC_GTLT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case MC_DBLQUOT:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("\"\"" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;

  case MC_SINQUOT:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("\'\'" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;

  case MC_DBLPAREN:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("()" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;

  case MC_DBLSBRKT:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("[]" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;

  case MC_DBLCBRKT:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("{}" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;

  case MC_BACKTICKS:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("``" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;

  case MC_GTLT:
    if (record->event.pressed) {
      // when keycode is pressed.
      SEND_STRING("<>" SS_TAP(X_LEFT));
    } else {
      // when keycode is released.
    }
    break;
  }
  return true;
};
enum layers{
    BASE,
    HRM_BASE,
    SETTINGS,
    FKEYS,
    RMODE,
    LMODE,
    MOUSE,
    NUMPAD
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_67(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_HOME, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(2), MO(3), KC_LEFT, KC_DOWN, KC_RGHT),
    [HRM_BASE] = LAYOUT_ansi_67(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_CAPS, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LT(4,KC_F), KC_G, KC_H, LT(5,KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, KC_ENT, KC_HOME, KC_LSFT, KC_Z, KC_X, KC_C, LT(7,KC_V), KC_B, KC_N, LT(6,KC_M), KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, LSFT_T(KC_SPC), KC_RALT, MO(2), MO(3), KC_LEFT, KC_DOWN, KC_RGHT),
    [SETTINGS] = LAYOUT_ansi_67(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_REC1, DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_TRNS, KC_TRNS, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [FKEYS] = LAYOUT_ansi_67(KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_PLY1, DM_PLY2, KC_TRNS, KC_TRNS, KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_TRNS, KC_TRNS, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [RMODE] = LAYOUT_ansi_67(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MC_GTLT, MC_DBLPAREN, MC_DBLSBRKT, MC_DBLCBRKT, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HASH, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [LMODE] = LAYOUT_ansi_67(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MC_BACKTICKS, MC_SINQUOT, KC_ESC, MC_DBLQUOT, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AT, KC_DLR, KC_AMPR, KC_BSPC, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PERC, KC_ASTR, KC_CIRC, KC_TRNS, KC_EXLM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [MOUSE] = LAYOUT_ansi_67(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WBAK, KC_BTN1, KC_WFWD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [NUMPAD] = LAYOUT_ansi_67(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUM, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [HRM_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [SETTINGS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FKEYS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [RMODE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LMODE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MOUSE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NUMPAD] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
