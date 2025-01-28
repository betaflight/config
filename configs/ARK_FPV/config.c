#include "drivers/io.h"

void configTargetPreInit(void)
{
    ioPreinitByIO(IOGetByTag(IO_TAG(VDD_3V3_SENSORS1_EN)), IOCFG_OUT_PP, PREINIT_PIN_STATE_HIGH);
    ioPreinitByIO(IOGetByTag(IO_TAG(VDD_3V3_SD_CARD_EN)), IOCFG_OUT_PP, PREINIT_PIN_STATE_HIGH);
}
