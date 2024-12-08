#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
/* Basic Charybdis setup from https://github.com/Bastardkb/bastardkb-qmk bkb-master branch
 * Some modifications made to layers
 */

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// Keyboard layers
enum charybdis_keymap_layers {
    LAYER_DVORAK = 0,
    LAYER_FN,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LFUNC MO(LAYER_FN)
#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_SEMI LT(LAYER_POINTER, KC_SEMICOLON)
#define PT_Z LT(LAYER_POINTER, KC_Z)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE


/* Custom macros like window management
 * WM macros are for window Management using Rectangle. X_Y indicates the position and fractional value. E.g 1_3 is the
 * first 1/3rd of the screen. An appended C means 'corners' ie not split vertically
 * CGA_CMB is a LCtrl + LGui + LAlt combo
*/

enum custom_keycodes {
    LOCK_PC = SAFE_RANGE,
    WM_1_3,
    WM_2_3,
    WM_3_3,
    WM_1_6_C,
    WM_2_6_C,
    WM_3_6_C,
    WM_4_6_C,
    WM_5_6_C,
    WM_6_6_C,
    WM_1_4,
    WM_2_4,
    WM_3_4,
    WM_4_4,
    WM_1_4_C,
    WM_2_4_C,
    WM_3_4_C,
    WM_4_4_C,
    ONEPASS,
    SCRNSHOT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
   	case LOCK_PC:
		if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_Q) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
    // Actions upon release
        }
		break;
	case WM_1_3:
		if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_1) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_2_3:
		if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_2) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_3_3:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_3) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
        } else {
	// Actions upon release
		}
		break;
	case WM_1_6_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_5) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
        } else {
	// Actions upon release
		}
		break;
	case WM_2_6_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_6) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_3_6_C:
		if (record->event.pressed) {
        	SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_7) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
        } else {
	// Actions upon release
		}
		break;
	case WM_4_6_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_8) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_5_6_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_9) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_6_6_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_0) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_1_4_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LSFT));
		} else {
	// Actions upon release
		}
		break;
	case WM_2_4_C:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_RGHT) SS_UP(X_LGUI) SS_UP(X_LSFT));
		} else {
	// Actions upon release
		}
		break;
	case WM_3_4_C:
		if (record->event.pressed) {
	       SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_4_4_C:
		if (record->event.pressed) {
	       SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_RGHT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
    case WM_1_4:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_1) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_2_4:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_2) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_3_4:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_3) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case WM_4_4:
		if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_4) SS_UP(X_LSFT) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_LCTL));
		} else {
	// Actions upon release
		}
		break;
	case ONEPASS:
		if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI) SS_UP(X_LSFT));
		} else {
	// Actions upon release
		}
		break;
	case SCRNSHOT:
		if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI));
		} else {
	// Actions upon release
		}
		break;
    }
    return true;
};

/* Chronoloper Charybdis custom
 * https://github.com/chronoloper/charybdis_dv based on https://github.com/varbhat/qmk_userspace
 * Charybdis keyboard, a split keyboard with 4x6 column staggered keys, a 3 thumb key cluster, a 5 thumb key cluster, and an intergrated trackball.
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,---------------,
 *                         |       |       |       |       |       |       |
 *                         '-----------------------'       '---------------'
 *                                 |       |       |       |       |
 *                                 '---------------'       '-------'
 *
 */

// [_LAYER] = LAYOUT_charybdis_4x6(
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
//                                  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS
// ),

// clang-format off
// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* dvorak
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * | `~    |  1!   |   2@  |   3#  |  4$   |   5!  |       |   6^  |   7&  |   8*  |   9(  |   0)  |  /?   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | tab   |  '"   |   ,>  |  .>   |   p   |   y   |       |   f   |   g   |   c   |   r   |   l   |  \|   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | shift |   a   |   o   |   e   |   u   |   i   |       |   d   |   h   |   t   |   n   |   s   |  -_   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | ctrl  |  ;:   |   q   |   j   |   k   |   x   |       |   b   |   m   |   w   |   v   |   z   | shift |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,---------------,
    *                         |  gui  | space | lower |       | raise |bkspace|
    *                         '-----------------------|       |---------------'
    *                                 | super  | lalt |       |  ent  |
    *                                 '---------------'       '-------'
    */
    [LAYER_DVORAK] = LAYOUT_charybdis_4x6(
    KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    /**/ KC_6,     KC_7,   KC_8,   KC_9,  KC_0,  KC_SLSH,
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,  KC_P,    KC_Y,    /**/ KC_F,     KC_G,   KC_C,   KC_R,  KC_L,  KC_BSLS,
    KC_LSFT,  KC_A,     KC_O,     KC_E,    KC_U,    KC_I,    /**/ KC_D,     KC_H,   KC_T,   KC_N,  KC_S,  KC_MINS,
    KC_LCTL,  PT_SEMI,  KC_Q,     KC_J,    KC_K,    KC_X,    /**/ KC_B,     KC_M,   KC_W,   KC_V,  PT_Z,  KC_RSFT,
                                  LFUNC,   KC_SPC,  LOWER,   /**/ RAISE,    KC_BSPC,
                                           KC_LGUI, KC_LALT, /**/ KC_ENT
),


/* function layer
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * | esc   |       |       |       |       |       |       |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       | 1Pass |       |       |   {   |   7   |   8   |   9   |   }   |  =+   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |pasthru|       |       |       |       |       |       |   [   |   4   |   5   |   6   |   ]   |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |pasthru|       |       |       |       |       |       |   0   |   1   |   2   |   3   | period|       |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,---------------,
    *                         |pasthru|       |pasthru|       |       |pasthru|
    *                         '-----------------------|       |---------------'
    *                                 |pasthru|pasthru|       |pasthru|
    *                                 '---------------'       '-------'
    */
    [LAYER_FN] = LAYOUT_charybdis_4x6(
    KC_ESC,   KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
    KC_NO,    KC_NO,    KC_NO,  KC_NO,   ONEPASS, KC_NO,   /**/ KC_LCBR,  KC_7,   KC_8,   KC_9,   KC_RCBR, KC_EQL,
    KC_TRNS,  KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   /**/ KC_LBRC,  KC_4,   KC_5,   KC_6,   KC_RBRC, KC_NO,
    KC_TRNS,  KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   /**/ KC_0,     KC_1,   KC_2,   KC_3,   KC_DOT,  KC_NO,
                                KC_TRNS, KC_NO,   KC_TRNS, /**/ KC_NO,    KC_TRNS,
                                         KC_TRNS, KC_TRNS, /**/ KC_TRNS
),
/* lower layer
 * Mostly used for window management macros
    * ,-----------------------------------------------------,       ,-------------------------------------------------,
    * |       |       |         |         |         |       |       |       |        |        |        |       |LockMac|
    * |-------+-------+---------+---------+---------+-------|       |-------+--------+--------+--------+-------+-------|
    * |       |       |         |WM_2_4_C |         |       |       |       |        |        |        |       |       |
    * |-------+-------+---------+---------+---------+-------|       |-------+--------+--------+--------+-------+-------|
    * |       |       |WM_1_4_C |WM_3_4_C |WM_4_4_C |       |       |       |WM_1_6_C|WM_2_6_C|WM_3_6_C|       |       |
    * |-------+-------+---------+---------+---------+-------|       |-------+-------+---------+--------+-------+-------|
    * |       |       |         |         |         |       |       |       |WM_4_6_C|WM_5_6_C|WM_6_6_C|       |       |
    * '-----------------------------------------------------'       '--------------------------------------------------'
    *                               ,-----------------------,       ,---------------,
    *                               |pasthru|       |       |       |       |  del  |
    *                               '-----------------------|       |---------------'
    *                                       |pasthru|pasthru|       |scrnsht|
    *                                       '---------------'       '-------'
    */
    [LAYER_LOWER] = LAYOUT_charybdis_4x6(
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   /**/   KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,   LOCK_PC,
    KC_NO,  KC_NO,    KC_NO,    WM_2_4_C, KC_NO,    KC_NO,   /**/   KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_NO,  KC_NO,    WM_1_4_C, WM_3_4_C, WM_4_4_C, KC_NO,   /**/   KC_NO,    WM_1_6_C,  WM_2_6_C, WM_3_6_C, KC_NO,   KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   /**/   KC_NO,    WM_4_6_C,  WM_5_6_C, WM_6_6_C, KC_NO,   KC_NO,
                                KC_TRNS,  KC_NO,    KC_NO,   /**/   KC_NO,    KC_DEL,
                                          KC_TRNS,  KC_TRNS, /**/   SCRNSHOT
),
/* raise layer
 * Currently mostly for arrow key access and some window management
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * |       |       |       |       |       |       |       |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |       |       |   up  |       |       |       |       |       |WM_2_4 |       |       |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |       | left  |  down | right |       |       |       |WM_1_4 |WM_3_4 |WM_4_4 |       |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |       |       |       |       |       |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,---------------,
    *                         |pasthru|       |       |       |       |       |
    *                         '-----------------------|       |---------------'
    *                                 |pasthru|pasthru|       |       |
    *                                 '---------------'       '-------'
    */
    [LAYER_RAISE] = LAYOUT_charybdis_4x6(
    KC_NO,  KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_UP,   KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,   WM_2_4,  KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_NO,    KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,   /**/ KC_NO,    WM_1_4,  WM_3_4,  WM_4_4,  KC_NO,   KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                KC_TRNS, KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,
                                         KC_TRNS, KC_TRNS, /**/ KC_NO
),

/* pointer layer
 * Pointer layer for mouse buttons, scrolling, sniping, DPI changes
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * |QK_BOOT| EE_CLR|       |       |       |       |       |       |       |       |       | EE_CLR|QK_BOOT|
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |DPI_MOD|S_D_MOD|       |S_D_MOD|DPI_MOD|       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |       |pasthru|DRGSCRL|SNIPING|       |       |       |       |       |       |       |       |       |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,---------------,
    *                         |Right_M|Left_M |MiddleM|       |       |       |
    *                         '-----------------------|       |---------------'
    *                                 |       |       |       |       |
    *                                 '---------------'       '-------'
    */
    [LAYER_POINTER] = LAYOUT_charybdis_4x6(
    QK_BOOT,EE_CLR,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,   KC_NO,   KC_NO,  EE_CLR,  QK_BOOT,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,   DPI_MOD, S_D_MOD, /**/ S_D_MOD,  DPI_MOD, KC_NO,   KC_NO,  KC_NO,   KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
    KC_NO,  KC_TRNS,  DRGSCRL,  SNIPING, KC_NO,   KC_NO,   /**/ KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
                                KC_BTN2, KC_BTN1, KC_BTN3, /**/ KC_NO,    KC_NO,
                                         KC_BTN1, KC_NO,   /**/ KC_NO
),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif



