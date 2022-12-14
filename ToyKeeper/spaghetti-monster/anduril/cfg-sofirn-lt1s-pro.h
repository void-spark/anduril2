// Sofirn LT1S Pro
#define MODEL_NUMBER "0623"
#include "hwdef-Sofirn_LT1S-Pro.h"
// ATTINY: 1616
// this model requires some special code
#define OVERRIDES_FILE cfg-sofirn-lt1s-pro.c
#define OVERRIDE_SET_LEVEL
inline void set_level_override(uint8_t level);

// uses 4C action while On to switch between white and red channels (overrides lockout action)
#define USE_OUTPUT_MUX

// the button lights up
#define USE_INDICATOR_LED
// the button is visible while main LEDs are on
#define USE_INDICATOR_LED_WHILE_RAMPING
// off mode: high (1)
// lockout: blinking (3)
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 1)

// the lantern has two PWM channels, but they drive different sets of emitters
// (one channel for warm emitters, one channel for cold)
// so enable a special ramping mode which changes tint instead of brightness
#define USE_TINT_RAMPING
// how much to increase total brightness at middle tint
// (0 = 100% brightness, 64 = 200% brightness)
#define TINT_RAMPING_CORRECTION 10  // 115%

#ifdef RAMP_LENGTH
#undef RAMP_LENGTH
#endif

// level_calc.py 1 150 7135 1 30 800
#define RAMP_LENGTH 150
#define PWM1_LEVELS 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,11,11,12,13,13,14,15,15,16,17,18,18,19,20,21,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,43,44,45,46,48,49,50,51,53,54,56,57,58,60,61,63,64,66,67,69,70,72,74,75,77,79,80,82,84,85,87,89,91,93,95,97,98,100,102,104,106,108,111,113,115,117,119,121,124,126,128,130,133,135,137,140,142,145,147,150,152,155,157,160,163,165,168,171,173,176,179,182,185,188,190,193,196,199,202,205,209,212,215,218,221,224,228,231,234,238,241,245,248,251,255
#define MAX_1x7135 65
#define HALFSPEED_LEVEL 256 // red LEDs use a QX7138 chip which has max PWM speed of 10 kHz, so never run faster than halfspeed
#define QUARTERSPEED_LEVEL 5

// the default of 26 looks a bit flat, so increase it
#define CANDLE_AMPLITUDE 40

// override default ramp style
#undef RAMP_STYLE
#define RAMP_STYLE 1  // 0 = smooth, 1 = stepped
// set floor and ceiling as far apart as possible
// because this lantern isn't overpowered
#define RAMP_SMOOTH_FLOOR 1
#define RAMP_SMOOTH_CEIL  150
#define RAMP_DISCRETE_FLOOR 10
#define RAMP_DISCRETE_CEIL  RAMP_SMOOTH_CEIL
#define RAMP_DISCRETE_STEPS 5

// LT1S can handle heat well, so don't limit simple mode
#define SIMPLE_UI_FLOOR RAMP_DISCRETE_FLOOR
#define SIMPLE_UI_CEIL  RAMP_DISCRETE_CEIL
#define SIMPLE_UI_STEPS RAMP_DISCRETE_STEPS

// Allow 3C in Simple UI for switching between smooth and stepped ramping
#define USE_SIMPLE_UI_RAMPING_TOGGLE

// allow Aux Config and Strobe Modes in Simple UI
#define USE_EXTENDED_SIMPLE_UI

// enable 2 click turbo (Anduril 1 style)
#define DEFAULT_2C_STYLE 1

#define USE_SOS_MODE
#define USE_SOS_MODE_IN_BLINKY_GROUP

// the sensor (attiny) is nowhere near the emitters
// so thermal regulation can't work
#ifdef USE_THERMAL_REGULATION
#undef USE_THERMAL_REGULATION
#endif

// don't blink while ramping
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_FLOOR
#undef BLINK_AT_RAMP_FLOOR
#endif
#ifdef BLINK_AT_RAMP_CEIL
#undef BLINK_AT_RAMP_CEIL
#endif

#ifndef USE_SOFT_FACTORY_RESET
#define USE_SOFT_FACTORY_RESET
#endif