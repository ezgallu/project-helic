#include "parametri.h"
#include <math.h>
#include <stdlib.h>
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

void Get_Speed(float* speed, float* position){
	
	//save the new speed value to speed pointer and move past steps
	float temp_speed;
		
	//calculate speed(k)
	temp_speed = (*(speed + 1)*(float)1.793 - *(speed + 2)*(float)0.8076 + (*position - *(position + 1))*(float)14.18);
	
	//put speed(k) on the beginnig of speed array and move past speeds
	*(speed + 2) = *(speed + 1);
	*(speed + 1) = *(speed);
	*(speed) = temp_speed;
	
	return;	
}

float Get_Encoder_Pos(TIM_HandleTypeDef *htim){
	
	uint32_t i;
	float temp_deg, deg;
	
	i = (*htim).Instance->CNT;
	temp_deg = 2*3.1415926*i/2400.0;
	if(temp_deg > (3.1415926/2.0)){
		deg = 2*3.1415926 - temp_deg;
	}else{
		deg = temp_deg * -1;
	}
	return deg;
}

void Set_Pose(float* angle, float new_angle, float theta_0){
	
	*(angle + 1) = *angle;
	*angle = new_angle + theta_0;
	
	return;
}

void Set_Duty_Cycle(uint8_t motor, int dutyCycle, TIM_HandleTypeDef *htim){
	
	GPIO_PinState pin_state;
	if (abs(dutyCycle) > max_duty){
		dutyCycle = max_duty*dutyCycle/abs(dutyCycle);	
	}
	if (dutyCycle < 0){
		pin_state = (GPIO_PinState) 1;
		dutyCycle = 100 + dutyCycle;
	}else{
		pin_state = (GPIO_PinState) 0;
	}
	switch(motor){
		case 1:
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, pin_state);
			(*htim).Instance->CCR1 = dutyCycle;
			break;
		case 2: 
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, pin_state);
			(*htim).Instance->CCR2 = dutyCycle;
			break;
		default:
			break;
	}
	return;
}

void Set_Speed(uint8_t motor, float u, TIM_HandleTypeDef *htim){
	
	int dutyCycle;
	
	dutyCycle = round(u*max_duty/max_u);
	Set_Duty_Cycle(motor, dutyCycle, htim);
	
	return;
}
