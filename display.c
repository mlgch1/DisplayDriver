/*
                         UART.c
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mcc_generated_files/spi1.h"

void display(char*);

//bool SPI2_Open(spi2_modes_t spi2UniqueConfiguration);
//void SPI2_WriteByte(uint8_t byte);




int rec_char_posn = 0;
int rec_chars_recv = 0;
extern const int total_digits;

void display(char *p_input_arr){

    SPI1_Open(SPI1_DEFAULT);
    
    int i;
    
    for(i = 0; i < 9; ++i){
        
        SPI1_ExchangeByte(p_input_arr[i]); 

        __delay_ms(100);



    }
    
    NOP();
    
    
    
    
    
    
    
    SPI1_Close();
    
}




