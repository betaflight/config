#include "platform.h"

#include "config/config.h"
#include "io/ledstrip.h"
#include "pg/gps.h"

// Runs on a config reset only. A stored config keeps its own LED layout and GNSS setting.
void targetConfiguration(void)
{
#ifdef USE_LED_STRIP
    // Four GPS-status LEDs on one row.
    parseLedStripConfig(0, "0,0::G:0");
    parseLedStripConfig(1, "1,0::G:0");
    parseLedStripConfig(2, "2,0::G:0");
    parseLedStripConfig(3, "3,0::G:0");
#endif
#ifdef USE_GPS
    gpsConfigMutable()->gps_ublox_use_galileo = true;
#endif
}
