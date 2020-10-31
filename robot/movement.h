#ifndef MOVEMENT_H
#define MOVEMENT_H

void mov_Initialize();
void mov_SetMotorDirection(char forward_left, char forward_right);
void mov_TurnOnMotors(char speed_left, char speed_right);
void mov_TurnInPlace(char degrees, char clock_wise, char speed);
void mov_WalkFor(char speed, uint16_t cycles, char direction);

#endif