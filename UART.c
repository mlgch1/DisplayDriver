#include "mcc_generated_files/mcc.h"

/*
                         UART.c
 */

#include "mcc_generated_files/pin_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mcc_generated_files/eusart1.h"

char temp;
char input_arr[9];
int rec_char_posn = 0;
int rec_chars_recv = 0;
extern int total_digits;

char lane = 'l'; // Left Lane - Replace with switch.

void display(char[]);
bool EUSART1_is_rx_ready(void);

void UART1_Command_INT(void) {
    if (EUSART1_DataReady) {

    temp = EUSART1_Read(); // read a byte for RX

//        EUSART1_Write(temp); // send a byte to TX  (from Rx)

        switch(rec_char_posn) {
            case 0:
            {
                if (temp == 'H') {
                    rec_char_posn++;
                } else {
                    rec_char_posn = 0;
                }
                break;
            }
            case 1:
            {
                if (temp == 'P') {
                    rec_char_posn++;
                } else {
                    rec_char_posn = 0;
                }
                break;
            }
            case 2:
            {
                if (temp == 'R') {
                    rec_char_posn++;
                } else {
                    rec_char_posn = 0;
                }
                break;
            }
            case 3:
            {
                if (temp == 'l') {
                    rec_char_posn++;
                } else {
                   rec_char_posn = 0;
                }
                break;
            }
            case 4:
            {
                input_arr[rec_chars_recv] = temp;

                rec_chars_recv++;

                if (rec_chars_recv == total_digits) {

                    LED_SetLow();
                    
                    __delay_ms(500);
                    
                    LED_SetHigh();
                    
                    
                    
                    
                    
                    display(input_arr);

                    rec_chars_recv = 0;
                    rec_char_posn = 0;
//                    memset(input_arr, ' ', total_digits);
                }
            }
        }
    }
}
