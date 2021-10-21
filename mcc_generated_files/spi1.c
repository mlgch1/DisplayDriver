/**
  SPI1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    spi1.c

*/

#include "spi1.h"
#include <xc.h>

typedef struct { 
    uint8_t con1; 
    uint8_t stat;
    uint8_t add;
    uint8_t operation;
} spi1_configuration_t;

//con1 == SSPxCON1, stat == SSPxSTAT, add == SSPxADD, operation == Master/Slave
static const spi1_configuration_t spi1_configuration[] = {   
    { 0x2, 0x40, 0x1, 0 }
};

void SPI1_Initialize(void)
{
    //Setup PPS Pins
    SSP1CLKPPS = 19;
    SSP1DATPPS = 19;
    RC3PPS    = 21;
    //SPI setup
    SSP1STAT = 0x40;
    SSP1CON1 = 0x02;
    SSP1ADD = 0x01;
    TRISCbits.TRISC3 = 0;
    SSP1CON1bits.SSPEN = 0;
}

bool SPI1_Open(spi1_modes_t spi1UniqueConfiguration)
{
    if(!SSP1CON1bits.SSPEN)
    {
        SSP1STAT = spi1_configuration[spi1UniqueConfiguration].stat;
        SSP1CON1 = spi1_configuration[spi1UniqueConfiguration].con1;
        SSP1CON2 = 0x00;
        SSP1ADD  = spi1_configuration[spi1UniqueConfiguration].add;
        TRISCbits.TRISC3 = spi1_configuration[spi1UniqueConfiguration].operation;
        SSP1CON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

void SPI1_Close(void)
{
    SSP1CON1bits.SSPEN = 0;
}

uint8_t SPI1_ExchangeByte(uint8_t data)
{
    SSP1BUF = data;
    while(!PIR3bits.SSP1IF);
    PIR3bits.SSP1IF = 0;
    return SSP1BUF;
}

void SPI1_ExchangeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SSP1BUF = *data;
        while(!PIR3bits.SSP1IF);
        PIR3bits.SSP1IF = 0;
        *data++ = SSP1BUF;
    }
}

// Half Duplex SPI Functions
void SPI1_WriteBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI1_ExchangeByte(*data++);
    }
}

void SPI1_ReadBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = SPI1_ExchangeByte(0);
    }
}

void SPI1_WriteByte(uint8_t byte)
{
    SSP1BUF = byte;
}

uint8_t SPI1_ReadByte(void)
{
    return SSP1BUF;
}