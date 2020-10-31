#include "msp.h"
#include "sensor.h"

void sens_Initialize() {
    
}

uint8_t sens_GetLineStatus() {
    uint32_t readout;

    P5->DIR = 0b111000;                 // set P5.3 (IR LED) as output
    P5->OUT = 0x08;                     // turn on P5.3 (IR LED)
    P9->OUT = 0x04;                     // turn on P9.2 (IR LED)
    P7->DIR = 0xFF;                     // P7.0 to P7.7 (IR Sensors) as output
    P7->OUT = 0xFF;                     // turn on P7 to charge caps
    __delay_cycles(10);                 // wait 10 x 1us before start
    P7->DIR = 0x00;                     // P7.0 to P7.7 (IR Sensors) as inputs
    __delay_cycles(2000);               // wait 1000 x 1us for caps to discharge
    readout = P7->IN;                   // read IR sensor values
    P5->OUT = 0x00;                     // turn off P5.3 (IR LED)
    
    uint8_t l4 = (readout >> 7) & 1;
    uint8_t l3 = (readout >> 6) & 1;
    uint8_t l2 = (readout >> 5) & 1;
    uint8_t l1 = (readout >> 4) & 1;
    uint8_t r1 = (readout >> 3) & 1;
    uint8_t r2 = (readout >> 2) & 1;
    uint8_t r3= (readout >> 1) & 1;
    uint8_t r4 = readout & 1;

    uint16_t num_on = l4 + l3 + l2 + l1 + r1 + r2 + r3 + r4;
    uint8_t left = l4 + l3 + l2 + l1;
    uint8_t right = r1 + r2 + r3 + r4;
    
    if (num_on == 8) return LINE_BLACK;
    if (num_on == 0) return LINE_WHITE;
    if (left + 1 == right || right + 1 == left) return LINE_MIDDLE;
    if (left > right) return LINE_RIGHT_1;
    if (right > left) return LINE_LEFT_1;

    return LINE_BLACK;
   
    
}