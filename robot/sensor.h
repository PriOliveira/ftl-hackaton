#ifndef SENSOR_H
#define SENSOR_H

#define LINE_BLACK    0x0
#define LINE_WHITE    0xF

#define LINE_LEFT_1   0x01
#define LINE_LEFT_2   0x02
#define LINE_LEFT_3   0x03

#define LINE_RIGHT_1  0x11
#define LINE_RIGHT_2  0x12
#define LINE_RIGHT_3  0x13

#define LINE_MIDDLE  0x20


#define LINE_BLACK    0x0

void sens_Initialize();
uint8_t sens_GetLineStatus();

#endif