#include "parametri.h"
#include <math.h>
#include "stm32f4xx_hal.h"

float feed_forward(float theta_d){
	float u_ff;
  u_ff = l_cm * m_heli * g / K_pp * cos(theta_d);
	return u_ff;
}

void proporcional(float pitch_err, float yaw_err, float speed_pitch, float speed_yaw, float* u_pitch, float* u_yaw){
	
	*u_pitch = K_i[0][0]*pitch_err + K_i[0][1]*yaw_err + K_i[0][2]*speed_pitch + K_i[0][3]*speed_yaw;
	*u_yaw = K_i[1][0]*pitch_err + K_i[1][1]*yaw_err + K_i[1][2]*speed_pitch + K_i[1][3]*speed_yaw;
	return;
}

float integral_control(float pitch_err, float yaw_err, float *integral, float *anti_windup, uint8_t type){
    //type = 0 --> pitch integral
    //type = 1 --> yaw integral
    float Kp, Ky, T_r, u_i;
    switch(type){
        case 0:
            Kp = K_i[0][4];
            Ky = K_i[0][5];
            T_r = Tr_p; 
            break;
        case 1:
            Kp = K_i[1][4];
            Ky = K_i[1][5];
            T_r = Tr_y;
            break;
        default:
            break;
    }
    *integral += (pitch_err * Kp + yaw_err * Ky + *anti_windup)*dt;
    
    if(*integral < -max_u){
        u_i = -max_u;
    }
    else if(*integral > max_u){
        u_i = max_u;
    }
    else{
        u_i = *integral;
    }
    *anti_windup = (u_i - *integral)/T_r;
    
    return u_i;    
}
