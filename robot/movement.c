#include "msp.h"
#include "movement.h"

void mov_Initialize() {
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer
    P5->DIR = 0b00110000; // P5.4 and P5.5 as output
    P2->DIR = 0b11000000; // P2.6 and P2.7 as output
    P3->DIR = 0b11000000; // P3.6 and P3.7 as output
    P3->OUT = 0b11000000; // Disable sleep mode for left (P3.7) and right (3.6) motors
}

void mov_SetMotorDirection(char forward_left, char forward_right) {
    // 0 is forward and 1 is backwards
    P5->OUT = 0b00000000 
    | (!forward_left  ? 0b00010000 : 0) // left motor direction (P5.4)
    | (!forward_right ? 0b00100000 : 0); // right motor direction (P5.5)
}

void mov_TurnOnMotors(char speed_left, char speed_right) {
    
    uint8_t i;
    for(i = 0 ; i < 10 ; i++) {
        __delay_cycles(1);
        P2->OUT = 0b00000000 
        | (i < speed_left  ? 0b01000000 : 0)
        | (i < speed_right ? 0b10000000 : 0);
    }
}


void mov_TurnInPlace(char degrees, char clock_wise, char speed) {
    mov_SetMotorDirection(clock_wise==0, clock_wise==1);
    int cycles;
    if (speed == 1) cycles = degrees * 128;
    if (speed == 2) cycles = degrees * 49;
    
    for(; cycles > 0 ; cycles--) mov_TurnOnMotors(speed, speed);
}

void mov_WalkFor(char speed, uint16_t cycles, char direction) {
    mov_SetMotorDirection(direction, direction);
    for(; cycles > 0 ; cycles--) mov_TurnOnMotors(speed, speed);
}

