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
#define KC_FCL0 KC_FN6 // FN6  - Change to layer 0 (reset)
    [6]  = ACTION_LAYER_CLEAR(ON_BOTH),
#define KC_FCL1 KC_FN7 // FN7  - Change layer 1
    [7]  = ACTION_LAYER_ON(1, ON_BOTH),
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
 * Default Layer: QWERTY
 *
 * ,------------------------------------.  ,------------------------------------.
 * |  `   |  1 |  2 |  3 |  4 |  5 |  [ |  |  ] |  6 |  7 |  8 |  9 |  0 |   =  |
 * |------+----+----+----+----+---------|  |----+----+----+----+----+----+------|
 * |  \   |  Q |  W |  E |  R |  T | Esc|  |BkSp|  Y |  U |  I |  O |  P |   -  |
 * |------+----+----+----+----+----|    |  |    |----+----+----+----+----+------|
 * | LAlt |  A |  S |  D |  F |  G |----|  |----|  H |  J |  K |  L |  ; |   '  |
 * |------+----+----+----+----+----| Tab|  |Entr|----+----+----+----+----+------|
 * | LCtrl|  Z |  X |  C |  V |  B |    |  |    |  N |  M |  , |  . |  / |   #  |
 * `------+----+----+----+----+---------'  `---------+----+----+----+----+------'
 *   |RGUI|Home|PgDn|PgUp| End|                      |Left| Up |Down|Rght| Del|
 *   `------------------------'                      `------------------------'
 *                            ,---------.  ,---------.
 *                            | ~L1| +L1|  |Mute|~L1 |
 *                       ,----+----+----|  |----+----+----.
 *                       |    |    | Ins|  |SLck|    |    |
 *                       |LShf|BkSp|----|  |----|RShf|Spac|
 *                       |    |    |LGui|  |Paus|    |    |
 *                       `--------------'  `--------------'
 *
 * Layer 1: Function keys + Numpad
 *
 * ,------------------------------------.  ,------------------------------------.
 * |  NO  | F1 | F2 | F3 | F4 | F5 | NO |  |NLck| NO | K7 | K8 | K9 | K- |  K*  |
 * |------+----+----+----+----+---------|  |----+----+----+----+----+----+------|
 * |  NO  | F6 | F7 | F8 | F9 | F10|    |  |    | NO | K4 | K5 | K6 | K+ |  K/  |
 * |------+----+----+----+----+----|    |  |    |----+----+----+----+----+------|
 * |      | F11| F12| F13| F14| F15|----|  |----| NO | K1 | K2 | K3 | =  |  NO  |
 * |------+----+----+----+----+----|    |  |    |----+----+----+----+----+------|
 * |      | NO | NO | NO | NO | NO |    |  |    | NO | K0 |  , | K. | NO |  NO  |
 * `------+----+----+----+----+---------'  `---------+----+----+----+----+------'
 *   | ~L2|MPrv|Vol-|Vol+|MNxt|                      |    |    |    |    |    |
 *   `------------------------'                      `------------------------'
 *                            ,---------.  ,---------.
 *                            | ~L0| =L0|  |Mute| ~L0|
 *                       ,----|----|----|  |----+----+----.
 *                       |    |    |    |  |    |    |    |
 *                       |    |    |----|  |----|    |    |
 *                       |    |    |    |  |    |    |    |
 *                       `--------------'  `--------------'
 *
 */
    // Layer0
    KEYMAP(
        // left hand
        GRV, 1,   2,   3,   4,   5,   LBRC,
        NUBS,Q,   W,   E,   R,   T,   ESC,
        LALT,A,   S,   D,   F,   G,
        LCTL,Z,   X,   C,   V,   B,   TAB,
        RGUI,HOME,PGDN,PGUP,END,
                                 FTL1,FCL1,
                                      INS,
                            FLSH,BSPC,LGUI,
        // right hand
        RBRC,6,   7,   8,   9,   0,   EQL,
        BSPC,Y,   U,   I,   O,   P,   MINS,
             H,   J,   K,   L,   SCLN,QUOT,
        ENT, K,   L,   COMM,DOT, SLSH,NUHS,
                  LEFT,UP,  DOWN,RGHT,DEL,
        MUTE,FTL1,
        SLCK,
        PAUS,FRSH,SPC
    ),

    // Layer1
    KEYMAP(
        // left hand
        NO,  F1,  F2,  F3,  F4,  F5,  NO,
        NO,  F6,  F7,  F8,  F9,  F10, TRNS,
        TRNS,F11, F12, F13, F14, F15,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        FTL2,MPRV,VOLD,VOLU,MNXT,
                                 FTL0,FCL0,
                                      TRNS,
                            TRNS,TRNS,TRNS,
        // right hand
        NLCK,NO,  P7,  P8,  P9,  PMNS,PEQL,
        TRNS,NO,  P4,  P5,  P6,  PPLS,NO,
             NO,  P1,  P2,  P3,  PAST,NO,
        TRNS,NO,  P0,  PCMM,PDOT,PSLS,NO,
                  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,FTL0,
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
