#ifndef _PARAM_H
#define _PARAM_H
//parameters
static const float g = 9.81;
static const float m_heli = 0.459;
static const float l_cm = 0.005;
static const float K_pp = 0.0488;
static const float K_i[2][6] = {
{16.66843166, -0.89938213, 8.93299809, -0.04059189, 7.73654432, -0.42225613},
{0.71175748, 15.72863737, 0.65749140, 6.24134442, 0.38194504, 8.55307156}};
static const float max_u = 3.5;
static const float Tr_p = 1.0;
static const float Tr_y = 1.0;

//derivative filter
static const float wcf = 125.6637;
static const float zetaf = 0.85;

//treba odredit T procesora
static const float dt = 0.00002;
#endif