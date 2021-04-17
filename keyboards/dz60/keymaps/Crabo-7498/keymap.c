#include QMK_KEYBOARD_H

/*----------------------*/
/*------- ENUMS --------*/
/*----------------------*/
enum unicode_names
{
    B,
};

enum tap_dance_names
{
    TD_SWITCH_LAYERS
};

/*----------------------*/
/*----- FUNCTIONS ------*/
/*----------------------*/

void td_toggle_layers(qk_tap_dance_state_t *state, void *user_data)
{
    switch (state->count)
    {
    case 2:
        register_code16(TO(2));
        break;

    case 3:
        register_code16(TO(3));
        break;

    default:
        register_code16(TO(0));
        break;
    }
}

/*----------------------*/
/*---- DEFINITIONS -----*/
/*----------------------*/
const uint32_t PROGMEM unicode_map[] = {
    [B] = 0x1F171,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SWITCH_LAYERS] = ACTION_TAP_DANCE_FN(td_toggle_layers),
};

/*----------------------*/
/*------ KEYMAPS -------*/
/*----------------------*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty Base layer
    * ,-----------------------------------------------------------------------------------------.
    * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
    * |-----------------------------------------------------------------------------------------+
    * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
    * |-----------------------------------------------------------------------------------------+
    * | CAPS    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Right Shift   |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl  |  CMD  |  Alt  |               Space               | Right |  FN  | Left | Ctrl  |
    *  `----------------------------------------------------------------------------------------'
    */

    LAYOUT(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, XXXXXXX,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_LEFT, MO(1), KC_RIGHT, KC_RCTL),

    /* FN Layer
    * ,-----------------------------------------------------------------------------------------.
    * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 |  F10 |  F11 |  F12 | Delete |
    * |-----------------------------------------------------------------------------------------+
    * |  ~     | TOG |     |     |     |     |     |     |     |     |     |     | PSCR | Reset |
    * |-----------------------------------------------------------------------------------------+
    * |         |     |     |     |     |     |     |     |     |     |     |     |             |
    * |-----------------------------------------------------------------------------------------+
    * |           |     |     |     |     |     | VOL- | VOL+ | PLY | PRV | NXT |               |
    * |-----------------------------------------------------------------------------------------+
    * |       |       |       |                                   |  Up   |  FN  | Down | Ctrl  |
    *  `----------------------------------------------------------------------------------------'
    */
    LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL,
        KC_ZKHK, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCREEN, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, KC_DOWN, _______),

    // DEV Layout
    LAYOUT(
        TO(0), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS),

    // The funne B
    LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, X(B), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, X(B), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};
