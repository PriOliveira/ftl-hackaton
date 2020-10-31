#include "msp.h"
#include "movement.h"
#include "sensor.h"
#include "picomm.h"


/*
    picomm_Initialize();

        char data = picomm_ReceiveOneByte();
        if (data != 0) {
            mov_WalkFor(1, 10000, 1);
        } else {
            mov_WalkFor(1, 10000, 0);
        }
        */
        
uint8_t getPosition() {
    uint8_t i, linePosition;
    for(i = 0 ; i < 3 || linePosition == LINE_BLACK; i++) {
        linePosition = sens_GetLineStatus();
    }
    return linePosition;
}

void main(void) {
    mov_Initialize();
    sens_Initialize();
    uint8_t i, linePosition;
    uint8_t target = 2;
    uint8_t next_stop = 0;
    int wait_time = 100000;
    uint8_t lap = 0;

    while(1) {
            linePosition = getPosition();
            if (linePosition == LINE_WHITE) {
                if (next_stop == target && target != 0) {
                    mov_WalkFor(0, 20000, 1);
                    mov_WalkFor(2, 2000, 1);
                    target = 0;
                }
                if (next_stop == target && target == 0) {
                    if (lap == 0) {
                        target = 1;
                        lap++;
                        mov_WalkFor(0, 20000, 1);
                    } else {
                        mov_WalkFor(0, 10000000, 1);
                    }
                }
                mov_WalkFor(2, 8000, 1);
                next_stop = (next_stop + 1) % 3;
            }
            else if(linePosition == LINE_BLACK) {
                mov_WalkFor(0, 200, 1);
            }
            else if (linePosition == LINE_LEFT_1) {
                mov_TurnInPlace(2, 1, 1);
            }
            else if (linePosition == LINE_RIGHT_1) {
                mov_TurnInPlace(2, 0, 1);
            }
            else if (linePosition == LINE_MIDDLE) {
                mov_WalkFor(2, 200, 1);
            }

    }
}