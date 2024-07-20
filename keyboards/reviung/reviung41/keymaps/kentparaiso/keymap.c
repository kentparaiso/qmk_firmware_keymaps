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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_reviung41(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LT(4,KC_F), KC_G, KC_H, LT(5,KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, LT(7,KC_V), KC_B, KC_N, LT(6,KC_M), KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), MO(3), MO(1), LSFT_T(KC_SPC), MO(2), MO(12)),
    [1] = LAYOUT_reviung41(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_PLY2, KC_TRNS),
    [2] = LAYOUT_reviung41(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LT, KC_GT, KC_QUES, KC_TRNS, KC_TRNS, DM_PLY1, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT_reviung41(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, DM_REC1, KC_TRNS, DM_REC2, KC_TRNS),
    [4] = LAYOUT_reviung41(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MC_GTLT, MC_DBLPAREN, MC_DBLSBRKT, MC_DBLCBRKT, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HASH, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [5] = LAYOUT_reviung41(KC_TRNS, MC_BACKTICKS, MC_SINQUOT, KC_ESC, MC_DBLQUOT, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AT, KC_DLR, KC_AMPR, KC_BSPC, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PERC, KC_ASTR, KC_CIRC, KC_TRNS, KC_EXLM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [6] = LAYOUT_reviung41(KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, KC_TRNS, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_NO, KC_WBAK, KC_BTN1, KC_WFWD, KC_NO),
    [7] = LAYOUT_reviung41(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUM, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT),
    [8] = LAYOUT_reviung41(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, MO(9), KC_SPC, MO(10), MO(11)),
    [9] = LAYOUT_reviung41(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [10] = LAYOUT_reviung41(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LT, KC_GT, KC_QUES, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS),
    [11] = LAYOUT_reviung41(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DF(0), KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PAUS, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS),
    [12] = LAYOUT_reviung41(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_NO, DF(8), KC_NO, KC_SCRL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
