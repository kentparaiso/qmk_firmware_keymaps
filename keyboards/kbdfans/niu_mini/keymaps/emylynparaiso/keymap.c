#include QMK_KEYBOARD_H

/*
Turn on numlock (if it's off) whenever we switch to numlock layer 7.

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  switch (layer) {

  case 7:
    if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
      tap_code(KC_NUMLOCK);
    }
    break;

  default:
    break;
  }

  return state;
};
*/

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_mit(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LT(4,KC_F), KC_G, KC_H, LT(5,KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, LT(7,KC_V), KC_B, KC_N, LT(6,KC_M), KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), KC_LCTL, KC_LGUI, KC_LALT, MO(3), MO(1), LSFT_T(KC_SPC), MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [1] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_PLY2, KC_HOME, KC_PGDN, KC_PGUP, KC_END),
    [2] = LAYOUT_planck_mit(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LT, KC_GT, KC_QUES, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_PLY1, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE),
    [3] = LAYOUT_planck_mit(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DF(8), RGB_MOD, KC_PSCR, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLCK, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_REC1, KC_TRNS, DM_REC2, RGB_TOG, KC_VOLD, KC_VOLU, KC_MUTE),
    [4] = LAYOUT_planck_mit(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MC_GTLT, MC_DBLPAREN, MC_DBLSBRKT, MC_DBLCBRKT, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HASH, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [5] = LAYOUT_planck_mit(KC_TRNS, MC_BACKTICKS, MC_SINQUOT, KC_ESC, MC_DBLQUOT, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AT, KC_DLR, KC_AMPR, KC_BSPC, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PERC, KC_ASTR, KC_CIRC, KC_TRNS, KC_EXLM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [6] = LAYOUT_planck_mit(KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK, KC_BTN1, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [7] = LAYOUT_planck_mit(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS),
    [8] = LAYOUT_planck_mit(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, MO(11), MO(9), KC_SPC, MO(10), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [9] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),
    [10] = LAYOUT_planck_mit(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LT, KC_GT, KC_QUES, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE),
    [11] = LAYOUT_planck_mit(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DF(0), RGB_MOD, KC_PSCR, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLCK, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_VOLD, KC_VOLU, KC_MUTE)
};
