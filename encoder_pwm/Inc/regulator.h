#ifndef _REGULATOR_H
#define _REGULATOR_H

#include "stm32f4xx_hal.h"

float feed_forward(float theta_d);
void proporcional(float pitch_err, float yaw_err, float speed_pitch, float speed_yaw, float* u_pitch, float* u_yaw);
float integral_control(float pitch_err, float yaw_err, float *integral, float *anti_windup, uint8_t type);

#endif
