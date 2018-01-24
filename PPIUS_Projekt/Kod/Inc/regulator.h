#ifndef _REGULATOR_H
#define _REGULATOR_H

#include "stm32f4xx_hal.h"

//Regulacijske komande
double feed_forward(double theta_d);
void proporcional(double pitch_err, double yaw_err, double speed_pitch, double speed_yaw, double* u_pitch, double* u_yaw);
double integral_control(double pitch_err, double yaw_err, double *integral, double *anti_windup, uint8_t type);

//Komande citanja i zadavanja brzina i pozicija
void Get_Speed(double* speed, double* position);
double Get_Encoder_Pos(TIM_HandleTypeDef *htim);
void Set_Pose(double* angle, double new_angle, double theta_0);
void Set_Duty_Cycle(uint8_t motor, int dutyCycle, TIM_HandleTypeDef *htim);
void Set_Speed(uint8_t motor, double u, TIM_HandleTypeDef *htim);


#endif
