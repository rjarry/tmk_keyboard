/* vim: set sw=4 sts=4 ts=4 et: */

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

#define KC_FML1 KC_FN1 // FN1 - Momentary layer 1
    [1]  = ACTION_LAYER_MOMENTARY(1),
#define KC_FML2 KC_FN2 // FN2  - Momentary layer 2
    [2]  = ACTION_LAYER_MOMENTARY(2),
#define KC_FTL1 KC_FN3 // FN3  - Toggle layer 1 on/off
    [3]  = ACTION_LAYER_TOGGLE(1),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
 * Default Layer: QWERTY
 *
 * ,------------------------------------.  ,------------------------------------.
 * | Esc  |  1 |  2 |  3 |  4 |  5 |  - |  |  ] |  6 |  7 |  8 |  9 |  0 |   =  |
 * |------+----+----+----+----+---------|  |----+----+----+----+----+----+------|
 * | Tab  |  Q |  W |  E |  R |  T | Ins|  |PgUp|  Y |  U |  I |  O |  P |   [  |
 * |------+----+----+----+----+----|    |  |    |----+----+----+----+----+------|
 * |AltGr |  A |  S |  D |  F |  G |----|  |----|  H |  J |  K |  L |  ; |   '  |
 * |------+----+----+----+----+----|Slck|  |PgDn|----+----+----+----+----+------|
 * |LShift|  Z |  X |  C |  V |  B |    |  |    |  N |  M |  , |  . |  / |RShift|
 * `------+----+----+----+----+---------'  `---------+----+----+----+----+------'
 *   |LCtl|LAlt|  \ |  ` |  # |                      |Left| Up |Down|Rght| End|
 *   `------------------------'                      `------------------------'
 *                            ,---------.  ,---------.
 *                            | ~L1| +L1|  | Del| ~L1|
 *                       ,----+----+----|  |----+----+----.
 *                       |    |    |Paus|  |Mute|    |    |
 *                       |Spac|Entr|----|  |----|BkSp|Spac|
 *                       |    |    |RGUI|  |Home|    |    |
 *                       `--------------'  `--------------'
 */
    KEYMAP(
        // left hand
        ESC, 1,   2,   3,   4,   5,   NUHS,
        TAB, Q,   W,   E,   R,   T,   INS,
        RALT,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   SLCK,
        LCTL,LALT,NUBS,GRV, RBRC,
                                 FML1,FTL1,
                                      PAUS,
                            SPC, ENT, RGUI,
        // right hand
        MINS,6,   7,   8,   9,   0,   EQL,
        PGUP,Y,   U,   I,   O,   P,   LBRC,
             H,   J,   K,   L,   SCLN,QUOT,
        PGDN,N,   M,   COMM,DOT, SLSH,RSFT,
                  LEFT,UP,  DOWN,RGHT,END,
        DEL, FML1,
        MUTE,
        HOME,BSPC,SPC
    ),

/*
 * Layer 1: Function keys + Numpad
 *
 * ,------------------------------------.  ,------------------------------------.
 * |      | F1 | F2 | F3 | F4 | F5 | NO |  |NLck| NO | K7 | K8 | K9 | K- |  K*  |
 * |------+----+----+----+----+---------|  |----+----+----+----+----+----+------|
 * |      | F6 | F7 | F8 | F9 | F10|    |  |Vol+| NO | K4 | K5 | K6 | K+ |  K/  |
 * |------+----+----+----+----+----|    |  |    |----+----+----+----+----+------|
 * |  NO  | F11| F12| F13| F14| F15|----|  |----| NO | K1 | K2 | K3 | =  | KENT |
 * |------+----+----+----+----+----|    |  |Vol-|----+----+----+----+----+------|
 * |      | NO | NO | NO | NO | NO |    |  |    | NO | K0 |  , | K. | NO |  NO  |
 * `------+----+----+----+----+---------'  `---------+----+----+----+----+------'
 *   |    |    | NO | NO |~L2 |                      |    |    |    |    |    |
 *   `------------------------'                      `------------------------'
 *                            ,---------.  ,---------.
 *                            |    |    |  |Prev|Next|
 *                       ,----+----+----|  |----+----+----.
 */
    KEYMAP(
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  NO,
        TRNS,F6,  F7,  F8,  F9,  F10, TRNS,
        NO,  F11, F12, F13, F14, F15,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,NO,NO,FML2,
                                 TRNS,TRNS,
                                      TRNS,
                            TRNS,TRNS,TRNS,
        // right hand
        NLCK,NO,  P7,  P8,  P9,  PMNS,PEQL,
        VOLU,NO,  P4,  P5,  P6,  PPLS,NO,
             NO,  P1,  P2,  P3,  PAST,PENT,
        VOLD,NO,  P0,  PCMM,PDOT,PSLS,NO,
                  TRNS,TRNS,TRNS,TRNS,TRNS,
        MPRV,MNXT,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    // Layer2: teensy bootloader key (only accessible from layer 1)
    KEYMAP(
        // left hand
        NO,  NO,  NO,  NO,  NO,  NO,  NO,
        NO,  NO,  NO,  NO,  NO,  NO,  NO,
        NO,  NO,  NO,  NO,  NO,  NO,
        NO,  NO,  NO,  NO,  NO,  NO,  NO,
        NO,  NO,  NO,  NO,  TRNS,
                                 NO,  NO,
                                      NO,
                            NO,  NO,  NO,
        // right hand
        NO,  NO,  NO,  NO,  NO,  NO,  NO,
        NO,  NO,  NO,  NO,  NO,  NO,  NO,
             NO,  NO,  NO,  NO,  NO,  NO,
        NO,  NO,  NO,  NO,  NO,  NO,  NO,
                  FTEE,NO,  NO,  NO,  NO,
        NO,  NO,
        NO,
        NO,  NO,  NO
    ),
};
