#ifndef _AD9833_H_
#define _AD9833_H_

#include <stdint.h>
#include "spi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    spi_ch_t *spiCH;
} ad9833_t;

typedef enum{
    INACTIVE,
    DAC_POWERDOWN,
    INTERNAL_CLK_DISSABLE,
    DAC_AND_INT_CLK_DISSABLE
}ad9833_sleepMode_t;

/**
 * @brief 
 * 
 * @param device 
 * @param sleepMode 
 */
void ad9833_init(
    ad9833_t *device,
    ad9833_sleepMode_t sleepMode);

/**
 * @brief 
 * 
 * @param device 
 * @param fref 
 */
void ad9833_setRefFrequency(
    ad9833_t *device,
    float fref);

/**
 * @brief Reset Device
 * 
 * The reset function resets appropriate internal registers to 0 to provide an
 * analog output of midscale. Reset does not reset the phase, frequency, or
 * control registers. When the AD9833 is powered up, the part should be reset.
 * To reset the AD9833, set the reset bit to 1. To take the part out of reset,
 * set the bit to 0. A signal appears at the DAC to output eight MCLK cycles
 * after reset is set to 0.
 * 
 * the latter was quoted from datasheet ad9833 Rev.D from Analog Devices
 * @param device 
 */
void ad9833_reset(
    ad9833_t *device);

/**
 * @brief Set different different sections in powerdown mode
 * 
 * Different Sections can be put into powerdown to save power.
 * 
 * The following modes can be set:
 * 
 *  No power-down                   = INACTIVE
 *  DAC powered down                = DAC_POWERDOWN
 *  Internal clock disabled         = INTERNAL_CLK_DISSABLE
 *  Both the DAC powered down       = DAC_AND_INT_CLK_DISSABLE
 *  and the internal clock disabled
 * @param device 
 * @param sleepMode 
 */
void ad9833_setSleepMode(
    ad9833_t *device,
    ad9833_sleepMode_t sleepMode);

/**
 * @brief 
 * 
 * @param device 
 */
void ad9833_setOutputSinosoidal(
    ad9833_t *device);

/**
 * @brief 
 * 
 * @param device 
 */
void ad9833_setOutputTrangle(
    ad9833_t *device);

/**
 * @brief 
 * 
 * @param device 
 */
void ad9833_setOutputMSBofDACData(
    ad9833_t *device);

/**
 * @brief 
 * 
 * @param device 
 * @param f0 
 */
void ad9833_setFrequency0(
    ad9833_t *device,
    uint16_t f0);

/**
 * @brief 
 * 
 * @param device 
 * @param f1 
 */
void ad9833_setFrequency1(
    ad9833_t *device,
    uint16_t f1);

/**
 * @brief 
 * 
 * @param device 
 * @param p0 
 */
void ad9833_setPhase0(
    ad9833_t *device,
    uint32_t p0);

/**
 * @brief 
 * 
 * @param device 
 * @param p1 
 */
void ad9833_setPhase1(
    ad9833_t *device,
    uint32_t p1);

#ifdef __cplusplus
}
#endif

#endif // _AD9833_H_
