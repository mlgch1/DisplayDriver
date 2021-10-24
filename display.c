/*
                         Display.c
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mcc_generated_files/spi2.h"

void display(char*);

int rec_char_posn = 0;
int rec_chars_recv = 0;
extern const int total_digits;

void display(char *p_input_arr){

    SPI2_Open(SPI2_DEFAULT);
    
    int i;
    
    for(i = 0; i < 9; ++i){
        
        switch(p_input_arr[i])
        {
            case '0':
                p_input_arr[i] = 0b00111111;
                break;
        
            case '1':
                p_input_arr[i] = 0b00000110;
                break;
        
            case '2':
                p_input_arr[i] = 0b01011011;
                break;
        
            case '3':
                p_input_arr[i] = 0b01001111;
                break;
        
            case '4':
                p_input_arr[i] = 0b01100110;
                break;
        
            case '5':
                p_input_arr[i] = 0b01101101;
                break;
        
            case '6':
                p_input_arr[i] = 0b01111100;
                break;
        
            case '7':
                p_input_arr[i] = 0b00000111;
                break;
        
            case '8':
                p_input_arr[i] = 0b01111111;
                break;
        
            case '9':
                p_input_arr[i] = 0b011100111;
                break;
        
            default:
                    p_input_arr[i] = 0b00000000;
                break;
        }

        SPI2_ExchangeByte(p_input_arr[i]); 
        
        

    }
    LATCH_SetLow();
    
    __delay_ms(.01);
    
    LATCH_SetHigh();
     
    SPI2_Close();
    
}




