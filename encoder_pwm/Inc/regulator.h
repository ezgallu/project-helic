#ifndef _REGULATOR_H
#define _REGULATOR_H

#include "stm32f4xx_hal.h"

float feed_forward(float theta_d);
void proporcional(float pitch_err, float yaw_err, float speed_pitch, float speed_yaw, float* u_pitch, float* u_yaw);
float integral_control(float pitch_err, float yaw_err, float *integral, float *anti_windup, uint8_t type);
void Get_Speed(float* speed, float* position);
float Get_Encoder_Pos(TIM_HandleTypeDef *htim);
void Set_Pose(float* angle, float new_angle, float theta_0);
void Set_Duty_Cycle(uint8_t motor, int dutyCycle, TIM_HandleTypeDef *htim);
void Set_Speed(uint8_t motor, float u, TIM_HandleTypeDef *htim);

#endif
