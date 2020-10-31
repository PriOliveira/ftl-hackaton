#include "msp.h"
#include "movement.h"
#include "sensor.h"

void main(void) {
    mov_Initialize();
    uint8_t linePosition;
    uint8_t i;
    uint8_t milestone = 0;
    
    while (1) {
        // mov_TurnInPlace(360, 0, 2);
        // __delay_cycles(10000000);
        
        for(i = 0 ; i < 3 || linePosition == LINE_BLACK; i++) {
            linePosition = sens_GetLineStatus();
        }
        if (linePosition == LINE_WHITE) {
            /* if (milestone == 0) {
                mov_WalkFor(1, 50000, 1);
            } else if(milestone >= 1 || milestone <= 3) {
                mov_WalkFor(1, 10000, 1);
                mov_TurnInPlace(90, 0, 1);
                mov_WalkFor(1, 10000, 1);
            } else if(milestone == 4) {
                mov_WalkFor(1, 10000, 1);
                mov_TurnInPlace(90, 1, 1);
                mov_WalkFor(1, 10000, 1);

            } else {
                mov_TurnInPlace(180, 1, 1);

            }
            milestone
            mov_TurnInPlace(180, 1, 1);*/
            mov_WalkFor(0, 750, 1);
            
        }
        else if(linePosition == LINE_BLACK) {
            mov_WalkFor(0, 200, 1);
        }
        else if (linePosition == LINE_LEFT_1) {
            mov_TurnInPlace(1, 1, 1);
        }
        else if (linePosition == LINE_RIGHT_1) {
            mov_TurnInPlace(1, 0, 1);
        }
        else if (linePosition == LINE_MIDDLE) {
            mov_WalkFor(2, 200, 1);
        }


    }
    
}