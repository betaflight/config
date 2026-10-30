#include <string.h>

#include "platform.h"

#include "config/config.h"
#include "io/ledstrip.h"
#include "pg/gps.h"
#include "pg/vtx_table.h"

// Runs on a config reset only. A stored config keeps its own LED layout, GNSS setting and VTX table.
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
#ifdef USE_VTX_TABLE
    // Power values 0, 1, 2 are the RTC6705_DYNAMIC_POWER_CTRL external codes 00, 01, 10.
    static const uint16_t frequency[5][8] = {
        { 5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725 },
        { 5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866 },
        { 5705, 5685, 5665,    0, 5885, 5905,    0,    0 },
        { 5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880 },
        { 5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917 },
    };
    static const char *const bandNames[5] = { "BOSCAM A", "BOSCAM B", "BOSCAM E", "FATSHARK", "RACEBAND" };
    static const char bandLetters[5] = { 'A', 'B', 'E', 'F', 'R' };
    static const char *const powerLabels[3] = { "25 ", "100", "MAX" };

    vtxTableConfig_t *table = vtxTableConfigMutable();
    table->bands = 5;
    table->channels = 8;
    for (int band = 0; band < 5; band++) {
        for (int channel = 0; channel < 8; channel++) {
            table->frequency[band][channel] = frequency[band][channel];
        }
        strcpy(table->bandNames[band], bandNames[band]);
        table->bandLetters[band] = bandLetters[band];
    }
    for (int channel = 0; channel < 8; channel++) {
        table->channelNames[channel][0] = '1' + channel;
        table->channelNames[channel][1] = '\0';
    }
    table->powerLevels = 3;
    for (int level = 0; level < 3; level++) {
        table->powerValues[level] = level;
        strcpy(table->powerLabels[level], powerLabels[level]);
    }
#endif
}
