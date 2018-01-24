#include "parametri.h"
#include <math.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"

/* FUNKCIJE KORIŠTENE U PROGRAMU */

/* Feed forward kontrola pitch zakreta */
double feed_forward(double theta_d){
	double u_ff;
  u_ff = l_cm * m_heli * g / K_pp * cos(theta_d);
	return u_ff;
}

/* Proporcionalni dio regulatora */
void proporcional(double pitch_err, double yaw_err, double speed_pitch, double speed_yaw, double* u_pitch, double* u_yaw){
	
	*u_pitch = K_i[0][0]*pitch_err + K_i[0][1]*yaw_err - K_i[0][2]*speed_pitch - K_i[0][3]*speed_yaw;
	*u_yaw = K_i[1][0]*pitch_err + K_i[1][1]*yaw_err - K_i[1][2]*speed_pitch - K_i[1][3]*speed_yaw;
	return;
}

/* Integralni dio regulatora */
double integral_control(double pitch_err, double yaw_err, double *integral, double *anti_windup, uint8_t type){
    //type = 0 --> pitch integral
    //type = 1 --> yaw integral
    double Kp, Ky, T_r, u_i;
    switch(type){
        case 0:
            Kp =  K_i[0][4];
            Ky =  K_i[0][5];
            T_r = Tr_p;
            break;
        case 1:
            Kp =  K_i[1][4];
            Ky =  K_i[1][5];
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

/* Izracun brzine iz zadnje dvije brzine i promjene pozicije */
void Get_Speed(double* speed, double* position){
	
	//save the new speed value to speed pointer and move past steps
	double temp_speed;
		
	//calculate speed(k) using derivational filter
	temp_speed = *(speed + 1)*1.793 - *(speed + 2)*0.8076 + (*position - *(position + 1))*14.18;
	if (temp_speed < 0.00001)
		temp_speed = 0;
	else if (temp_speed > 10000)
		temp_speed = 10000;
	
	//put speed(k) on the beginnig of speed array and move past speeds
	*(speed + 2) = *(speed + 1);
	*(speed + 1) = *(speed);
	*(speed) = temp_speed;
	
	return;	
}

/* Dohvat pozicije enkodera i preracun u radijane */
double Get_Encoder_Pos(TIM_HandleTypeDef *htim){
	
	uint32_t i;
	double temp, rad;
	
	i = (*htim).Instance->CNT;
	temp = 2*3.1415926*i/2400.0;
	if(temp > (3.1415926/2.0)){
		rad = 2*3.1415926 - temp;
	}else{
		rad = temp * -1;
	}
	return rad;
}

/* Postavljanje novog kuta i pomak prethodnog */
void Set_Pose(double* angle, double new_angle, double theta_0){
	
	*(angle + 1) = *angle;
	*angle = new_angle + theta_0;
	
	return;
}

/* Postavljanje duty cyclea PWM-a */
void Set_Duty_Cycle(uint8_t motor, int dutyCycle, TIM_HandleTypeDef *htim){
	
	GPIO_PinState pin_state;
	
	//limitiramo duty cyce na max_duty
	if (abs(dutyCycle) > max_duty){
		dutyCycle = max_duty*dutyCycle/abs(dutyCycle);	
	}
	//ovisno o predznaku postavljamo smjer vrtnje motora
	if (dutyCycle < 0){
		pin_state = (GPIO_PinState) 1;
		dutyCycle = 100 + dutyCycle;
	}else{
		pin_state = (GPIO_PinState) 0;
	}
	//odabir motora
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

/* Postavljanje brzine i smjera motora */
void Set_Speed(uint8_t motor, double u, TIM_HandleTypeDef *htim){
	
	int dutyCycle;
	
	dutyCycle = round(u*max_duty/max_u);
	Set_Duty_Cycle(motor, dutyCycle, htim);
	
	return;
}

