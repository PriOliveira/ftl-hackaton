#include "msp.h"
#include "picomm.h"

void picomm_Initialize() {
    P4->DIR = 0b00000000; // P8 to input, we are using P8.6
    // P4->REN = 0x00;
}

char picomm_ReceiveOneByte() {
    if (P4->IN & 0b00000001 == 0) return 0x00;
    else return 0xFF;
    
    uint8_t bit = 0;
    char data = 0;
    
    for(bit = 0 ; bit < 8 ; bit++) {
        uint32_t high_cycles = 0;
        uint32_t low_cycles = 0;
        
        while (P8->IN != 0) high_cycles++;
        while (P8->IN == 0) low_cycles++;
        
        data <<= 1;
        
        if (low_cycles >= high_cycles * 4) {
            data |= 1;
            
        }
    }
    
    return data;
};