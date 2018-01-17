#include "parametri.h"
float pitch_integral = 0.0;
float yaw_integral = 0.0;
float feed_forward(float theta_d){
    u_ff = l_cm * m_heli * g / K_pp * cos(theta_d);
    return u_ff;
}

float integral_control(float pitch_err, float yaw_err, float *integral, float *anti_windup, uint8_t type){
    //type = 0 --> pitch integral
    //type = 1 --> yaw integral
    float Kp, Ky, T_r, u_i;
    switch(type){
        case 0:
            Kp = K_i[1][5];
            Ky = K_i[1][6];
            T_r = Tr_p; 
            break;
        case 1:
            Kp = K_i[2][5];
            Ky = K_i[2][6];
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
