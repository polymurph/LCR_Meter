#ifndef _AD9833_H_
#define _AD9833_H_

#include <stdint.h>
#include "spi.h"

typedef struct {

} ad9833_t;

void ad9833_init(ad9833_t *device);

void ad9833_setMainClockSleepMode(ad9833_t *device, uint8_t logic);

void ad9833_


#endif // _AD9833_H_
