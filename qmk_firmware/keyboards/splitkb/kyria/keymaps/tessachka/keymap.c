/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


enum layers {
    QWERTY = 0,
    LOWER,
    RAISE,
    ADJUST
};

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
    KC_RACL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | BSPC   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | TAB/ADJ|   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | ENTER  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSHIFT |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | F16    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | Space|  | MYCM | Calc | F15  |      |      |
 *                        |      |      | Ctrl | LAlt | Lower|  | Raise|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      KC_ESC,            KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      LT(ADJUST,KC_TAB), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
      KC_LSFT,           KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_F16,
            XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, LT(LOWER,KC_SPC),   LT(RAISE,KC_MYCM), KC_CALC, KC_F15, XXXXXXX, XXXXXXX
    ),
/*
 * Lower Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | `      | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                              | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | DEL    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CAPS   | - _  | = +  | [ {  | ] }  |      |                              |      |      |      |      | ' "  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSHIFT | TAB  |      |      |      |      |      |      |  |      |      | Home | PgDn | PgUp | End  | \ |  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | Space|  | Space|      |      |      |      |
 *                        |      |      | Ctrl | LAlt | Lower|  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LOWER] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
      KC_CAPS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_QUOT, KC_NO,
      KC_LSFT, KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS, KC_NO,
                                 _______, _______, _______, _______, _______, KC_SPC,  KC_NO,   KC_NO, _______, _______
    ),
/*
 * Raise Layer: Function Keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   | F2   | F3   | F4   | F5   |                              | F6   | F7   | F8   | F9   | F10  | F11    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |EEPRST|      |      |      |                              |      |      |      |      |      | F12    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSHIFT | TAB  | RESET|      |      |      |      |      |  |      |      | Play |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | Space|  | MYCM | Prev | Next  |      |      |
 *                        |      |      | Ctrl | LAlt |      |  | Raise|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RAISE] = LAYOUT(
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_NO,   KC_NO,   EEP_RST, KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
      KC_LSFT, KC_TAB,  RESET,   KC_NO,   KC_NO,   KC_NO,   _______, _______, _______, _______, KC_MPLY, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, _______, _______, KC_SPC , KC_MPRV, KC_MNXT, _______, _______, _______
    ),
/*
 * Adjust Layer: Arrow keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | BTN2 | Up   | BTN1 |RGBMOD|RGBTOG|                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Left | Down | Right|RGBSAI|RGBHUI|                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | RGBRST |      |RGBVAI|RGBVAD|RGBSAD|RGBHUD|      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | WBAK | BTN3 | WFWD |  | MYCM | Calc | F15  |      |      |
 *                        |      |      |      |      |      |  | Raise|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [ADJUST] = LAYOUT(
      KC_NO,   KC_BTN2, KC_UP,   KC_BTN1, RGB_MOD, RGB_TOG,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, RGB_SAI, RGB_HUI,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      RGBRST,  KC_NO,   RGB_VAI, RGB_VAD, RGB_SAD, RGB_HUD, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 _______, _______, KC_WBAK, KC_BTN3, KC_WFWD, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MyCustomKeycode:
//             if (record->event.pressed) {
//                 // What to do if the button was pressed
//             } else {
//                 // What to do if the button was released
//             }
//             break;
//     }
//     return true;
// }

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_tessachka_logo(void) {
    static const char PROGMEM Tessachka_OLED_Logo_Inverted[] =
        {
              0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 192, 192, 192, 192, 192, 192, 192,
            192, 192, 192,  64,   0,   0, 128, 128, 192, 192, 192, 192, 192, 192, 64,    0,   0,
            128, 192, 192, 192, 192, 192, 192, 192, 192, 192,  64,   0,   0, 128, 192, 192, 192,
            192, 192, 192, 192, 192, 192,  64,   0,   0,   0,   0,   0,   0, 192, 192,   0,   0,
              0,   0,   0,   0,   0, 128, 192, 192, 192, 192, 192, 192, 192, 192, 128,   0,   0,
            192, 128,   0,   0,   0,   0,   0,   0,   0,   0, 128, 192,   0, 192, 128,   0,   0,
              0,   0, 128, 192, 192, 128,   0,   0,   0,   0,   0,   0,   0, 192, 192,   0,   0,
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
              1,   1,   1,   1, 255, 255, 255, 127,   1,   1,   1,   0,  24, 126, 255, 255, 219,
            219, 153, 153, 153, 137, 128, 128,   0, 135, 143, 159, 153, 153, 153, 153, 153, 153,
            249, 240, 224,   0, 135, 143, 159, 153, 153, 153, 153, 153, 153, 249, 240, 224,   0,
              0, 192, 240, 252, 159, 135, 135, 159, 124, 240, 192,   0,  60, 255, 255, 231, 195,
            129,   0,   0,   0, 129, 195, 195, 195,   0, 255, 255, 255,  24,  24,  24,  24,  24,
             24, 255, 255, 255,   0, 255, 255, 255,  28,  62, 127, 247, 227, 193, 128,   0,   0,
              0, 192, 240, 252, 159, 135, 135, 159, 124, 240, 192,   0,   0,   0,   0,   0,   0,
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   1,   0,   0,
              0,   0,   0,   0,   0,   0,   0,   1,   1,   3,   3,   3,   3,   3,   1,   0,   0,
              0,   1,   3,   3,   3,   3,   3,   3,   3,   3,   1,   0,   0,   0,   1,   3,   3,
              3,   3,   3,   3,   3,   3,   1,   0,   0,   3,   3,   3,   3,   3,   3,   1,   0,
              0,   1,   3,   3,   0,   0,   1,   3,   3,   3,   3,   3,   3,   3,   3,   1,   0,
              0,   0,   1,   3,   0,   0,   0,   0,   0,   0,   3,   1,   0,   0,   0,   1,   3,
              0,   0,   0,   0,   1,   3,   3,   1,   0,   3,   3,   3,   3,   3,   3,   1,   0,
              0,   1,   3,   3,   0,   0,   0,   0,   0,   0
        };
    oled_write_raw_P(Tessachka_OLED_Logo_Inverted, sizeof(Tessachka_OLED_Logo_Inverted));
    oled_advance_page(false);
    oled_advance_page(false);
    oled_advance_page(false);
}

static void render_status(void) {
    // Logo and version information
    render_tessachka_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif
