/**

  File Name:
    pin_manager.c

*/

#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x01;
    LATD = 0x80;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x0A;

    /**
    TRISx registers
    */
    TRISE = 0x0E;
    TRISA = 0xFF;
    TRISB = 0xF5;
    TRISC = 0xAF;
    TRISD = 0x7F;

    /**
    ANSELx registers
    */
    ANSELD = 0xFF;
    ANSELC = 0x75;
    ANSELB = 0xFC;
    ANSELE = 0x06;
    ANSELA = 0xFF;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;
	
    SSP2DATPPS = 0x08;   //RB0->MSSP2:SDI2;    
    RB1PPS = 0x17;   //RB1->MSSP2:SCK2;    
    RB3PPS = 0x18;   //RB3->MSSP2:SDO2;    
    RC6PPS = 0x0F;   //RC6->EUSART1:TX1;    
    SSP2CLKPPS = 0x09;   //RB1->MSSP2:SCK2;    
    RX1DTPPS = 0x17;   //RC7->EUSART1:RX1;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/