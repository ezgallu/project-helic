#ifndef _PARAM_H
#define _PARAM_H

#include "stm32f4xx_hal.h"
//parameters
static const double g = 9.81;
static const double m_heli = 0.459;
static const double l_cm = 0.005;
static const double K_pp = 0.0488;
static const double K_i[2][6] = {
{16.66843166, -0.89938213, 8.93299809, -0.04059189, 7.73654432, -0.42225613},
{0.71175748, 15.72863737, 0.65749140, 6.24134442, 0.38194504, 8.55307156}};
static const double max_u = 3.5;
static const double Tr_p = 1.0;
static const double Tr_y = 1.0;

//derivative filter
static const double wcf = 125.6637;
static const double zetaf = 0.85;
static const double bias = -1.0472;

//treba odredit T procesora
static const double dt = 0.001;

//max duty cycle
static const double max_duty = 45.0;

#endif
