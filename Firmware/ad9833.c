
typedef enum {
    _bit_FSELECT = 0x00,
    _bit_D1 = 0x00,
    _bit_MODE = 0x0002,
    _bit_DIV2 = 0x0008,
    _bit_OPBITEN = 0x0020,
    _bit_SLEEP12 = 0x0040,
    _bit_SLEEP1 = 0x0080,
    _bit_RESET = 0x0100,
    _bit_PSELECT = 0x0400,
    _bit_FSELECT = 0x0800,
    _bit_HLB = 0x1000,
    _bit_B28 = 0x2000
}bit_t;

void _writeControlRegister(ad9833_t *device, uint16_t entry)
{
    // mask entry to prevent writing to reserved bits
    spiWrite16bit(device->spiCH, (entry & 0x3DEA));
}

void ad9833_init(
    ad9833_t *device,
    ad9833_sleepMode_t sleepMode,
    uint16_t f0,
    uint16_t f1,
    uint16_t p0,
    uint16_t p1);
{
    // perform init sequence according to Figure 27.
    spiWrite16bit(device->spiCH, _bit_RESET);
    spiWrite16bit(device->spiCH, 0);
    

    // set device directly in full powerdown mode, sinosoidal output 
    device->ctrlReg = _bit_SLEEP1 | _bit_SLEEP12;
    spiWrite16bit(device->ctrlReg);
}

void ad9833_setRefFrequency(
    ad9833_t *device,
    float fref);
{
    
}

void ad9833_reset(
    ad9833_t *device);
{

}

void ad9833_setSleepMode(
    ad9833_t *device,
    ad9833_sleepMode_t sleepMode);
{
    
}

void ad9833_setOutputSinosoidal(
    ad9833_t *device);
{
    
}

void ad9833_setOutputTrangle(
    ad9833_t *device);
{
    
}

void ad9833_setOutputMSBofDACData(
    ad9833_t *device);

{
    
}

void ad9833_setFrequency0(
    ad9833_t *device,
    uint16_t f0);
{
    
}

void ad9833_setFrequency1(
    ad9833_t *device,
    uint16_t f1)
{

}

void ad9833_setPhase0(
    ad9833_t *device,
    uint32_t p0)
{

}

void ad9833_setPhase1(
    ad9833_t *device,
    uint32_t p1)
{
    
}