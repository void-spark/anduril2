// Emisar D1v2 config options for Anduril (D1 w/ D4v2 driver)
// ATTINY: 1634
// same as Emisar D4v2, mostly
#include "cfg-emisar-d4v2.h"

// there are no aux LEDs on a D1
#undef USE_AUX_RGB_LEDS
// ... and no button LED
#undef USE_BUTTON_LED
// no aux LEDs means no need for sleep ticks
#undef TICK_DURING_STANDBY

// stop panicking at ~75% power or ~1000 lm (D1 has a decent power-to-thermal-mass ratio)
#ifdef THERM_FASTER_LEVEL
#undef THERM_FASTER_LEVEL
#endif
#define THERM_FASTER_LEVEL (RAMP_SIZE*9/10)  // throttle back faster when high
