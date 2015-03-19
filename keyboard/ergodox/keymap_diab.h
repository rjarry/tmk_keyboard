/* id for user defined functions & macros */
enum function_id {
	TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
#define KC_FTEE KC_FN0 // FN0  - Teensy key
	[0]  = ACTION_FUNCTION(TEENSY_KEY),
#define KC_FLSH KC_FN1 // FN1  - One-shot tap lshift
	[1]  = ACTION_MODS_ONESHOT(MOD_LSFT),
#define KC_FRSH KC_FN2 // FN2  - One-shot tap rshift
	[2]  = ACTION_MODS_ONESHOT(MOD_RSFT),

#define KC_FTL0 KC_FN3 // FN3  - Toggle layer 0
	[3]  = ACTION_LAYER_MOMENTARY(0),
#define KC_FTL1 KC_FN4 // FN4  - Toggle layer 1
	[4]  = ACTION_LAYER_MOMENTARY(1),
#define KC_FTL2 KC_FN5 // FN5  - Toggle layer 2
	[5]  = ACTION_LAYER_MOMENTARY(2),
#define KC_FCL0 KC_FN3 // FN3  - Change to layer 0 (reset)
	[3]  = ACTION_LAYER_CLEAR(ON_RELEASE),
#define KC_FCL1 KC_FN4 // FN4  - Change layer 1
	[4]  = ACTION_LAYER_ON(1, ON_RELEASE),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// print("action_function called\n");
	// print("id  = "); phex(id); print("\n");
	// print("opt = "); phex(opt); print("\n");

	switch (id) {
	case TEENSY_KEY:
		clear_keyboard();
		print("\n\nJump to bootloader... ");
		_delay_ms(50);
		bootloader_jump(); // should not return
		print("not supported.\n");
		break;
	}
}

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Default Layer: Workman
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `     |   1  |   2  |   3  |   4  |   5  |   [  |           |   ]  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   q  |   d  |   r  |   w  |   b  |  Esc |           | BkSp |   j  |   f  |   u  |   p  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   a  |   s  |   h  |   t  |   g  |------|           |------|   y  |   n  |   e  |   o  |   i  |   -    |
 * |--------+------+------+------+------+------|  Tab |           | Enter|------+------+------+------+------+--------|
 * | LCtrl  |   z  |   x  |   m  |   c  |   v  |      |           |      |   k  |   l  |   ,  |   .  |  Up  |  Del   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   \  |   /  |                                       | Home |  End |  Lft |  Dn  | Rght |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  ~L1 |  +L1 |       | LAlt | ~L1  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Ins |       | PgUp |      |      |
 *                                 | LShft| BkSp |------|       |------| RShft| Space|
 *                                 |      |      | LGui |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * Default Layer: Workman / with Shift
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ~     |   !  |   @  |   #  |   $  |   %  |   {  |           |   }  |   ^  |   &  |   *  |   (  |   )  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   D  |   R  |   W  |   B  |  Esc |           | BkSp |   J  |   F  |   U  |   P  |   :  |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   _    |
 * |--------+------+------+------+------+------|  Tab |           | Enter|------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   <  |   >  |  Up  |  Del   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   |  |   ?  |                                       | Home |  End |  Lft |  Dn  | Rght |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  ~L1 |  +L1 |       | LAlt | ~L1  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Ins |       | PgUp |      |      |
 *                                 | LShft| BkSp |------|       |------| RShft| Space|
 *                                 |      |      | LGui |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * Layer 1: Function keys + Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   NO   |  F1  |  F2  |  F3  |  F4  |  F5  |  NO  |           | NumLk|  NO  |  K7  |  K8  |  K9  |  K-  |   K*   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   NO   |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |  NO  |  K4  |  K5  |  K6  |  K+  |   K/   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   NO   |  F11 |  F12 |  F13 |  F14 |  F15 |------|           |------|  NO  |  K1  |  K2  |  K3  |  =   |   NO   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  NO  |  NO  |  NO  |  NO  |  NO  |      |           |      |  NO  |  K0  |   ,  |  K.  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |  NO  |  NO  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  ~L0 |  =L0 |       | Mute | ~L0  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Vol+ |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       | Vol- |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
	// Layer0
	KEYMAP(
		// left hand
		GRV, 1,   2,   3,   4,   5,   LBRC,
		NO,  Q,   D,   R,   W,   B,   ESC,
		NO,  A,   S,   H,   T,   G,
		LCTL,Z,   X,   M,   C,   V,   TAB,
		NO,  NO,  NO,  BSLS,SLSH,
		                         FTL1,FCL1,
		                              INS,
		                    FLSH,BSPC,LGUI,
		// right hand
		     RBRC,6,   7,   8,   9,   0,   EQL,
		     BSPC,J,   F,   U,   P,   SCLN,QUOT,
		          Y,   N,   E,   O,   I,   MINS,
		     ENT, K,   L,   COMM,DOT, UP,  DEL,
		               HOME,END, LEFT,DOWN,LEFT,
		LALT,FTL1,
		PGUP,
		PGDN,FRSH,SPC
	),

	// Layer1
	KEYMAP(
		// left hand
		NO,  F1,  F2,  F3,  F4,  F5,  NO,
		TRNS,F6,  F7,  F8,  F9,  F10, TRNS,
		TRNS,F11, F12, F13, F14, F15,
		TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
		FTL2,TRNS,TRNS,NO,  NO,
		                         FTL0,FCL0,
		                              TRNS,
		                    TRNS,TRNS,TRNS,
		// right hand
		     NLCK,NO,  P7,  P8,  P9,  PMNS,PSLS,
		     TRNS,NO,  P4,  P5,  P6,  PPLS,PAST,
		          NO,  P1,  P2,  P3,  PEQL,NO,
		     TRNS,NO,  P0,  PCMM,PDOT,TRNS,TRNS,
		               TRNS,TRNS,TRNS,TRNS,TRNS,
		MUTE,FTL0,
		VOLU,
		VOLD,TRNS,TRNS
	),

	// Layer2: teensy bootloader key (only accessible from layer 1)
	KEYMAP(
		// left hand
		NO,  NO,  NO,  NO,  NO,  NO,  NO,
		NO,  NO,  NO,  NO,  NO,  NO,  NO,
		NO,  NO,  NO,  NO,  NO,  NO,
		NO,  NO,  NO,  NO,  NO,  NO,  NO,
		NO,  NO,  NO,  NO,  NO,
		                         NO,  NO,
		                              NO,
		                    NO,  NO,  NO,
		// right hand
		     NO,  NO,  NO,  NO,  NO,  NO,  NO,
		     NO,  NO,  NO,  NO,  NO,  NO,  NO,
		          NO,  NO,  NO,  NO,  NO,  NO,
		     NO,  NO,  NO,  NO,  NO,  NO,  NO,
		               NO,  NO,  NO,  NO,FTEE,
		NO,  NO,
		NO,
		NO,  NO,  NO
	),
};
