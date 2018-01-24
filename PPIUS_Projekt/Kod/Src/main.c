#include "main.h"
#include "stm32f4xx_hal.h"
#include "math.h"
#include "regulator.h"
#include "parametri.h"

/* Adresa LCD-a */
#define LCD_ADDRESS_W		0x7E

/* Postavljanje handle varijabli */
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

/* Prototipovi inicijalizacijskih funkcija */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
static void MX_I2C1_Init(void);
static void MX_ADC1_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
   
/* Prototipovi funkcija za LCD */
void lcd_send_cmd(char cmd);
void lcd_send_data (char data);
void lcd_init(void);
void lcd_send_string (char *str);
void lcd_write_deg (char *deg, uint8_t pos);

/* Globalne varijable */
int dutyCycle1, dutyCycle2;
double deg1, deg2, ref1, ref2, err1, err2, pitch_int, yaw_int, anti_windup_pitch, anti_windup_yaw;
double	u_int1, u_int2, u_p1, u_p2, u_pff, u_pitch, u_yaw;
//(k), (k-1), (k-2)
double speed_pitch[3] = {0.0, 0.0, 0.0};
double speed_yaw[3] = {0.0, 0.0, 0.0};
//(k-1), (k-2)
double pitch[2] = {0.0, 0.0};
double yaw[2] = {0.0, 0.0};
double test[3] = {1.0, 2.0, 3.0};
uint8_t potentiometer[2];
int pot2deg[2];
char pitch_buffer[4];
char yaw_buffer[4];
uint8_t lcd_pos[2] = {0xc3,0xcc};
GPIO_PinState button, last_State;


int main(void)
{

  /* Inicijalizacija */
	ref1 = 0.0;
	ref2 = 0.0;
	
	pitch_int = 0.0;
	yaw_int = 0.0;
	anti_windup_pitch = 0.0;
	anti_windup_yaw = 0.0;
	
	last_State = 1;
		
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_I2C1_Init();
  MX_ADC1_Init();

  /* Postavljanje smjera vrtnje motora */
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,(GPIO_PinState)0);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,(GPIO_PinState)0);
	/* PWM timer start */
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	/* Encoder timer start */
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	/* Start main loop */
	HAL_TIM_Base_Start_IT(&htim4);
	/* Potentiometer start */
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)potentiometer, 2);
	
	lcd_init();
	
	/* Pocetni ispis na LCD zaslonu */
	lcd_send_string("PITCH:   YAW:   ");

  while (1)
  {
		//Prazna petlja
		//Program se izvršava svake 1ms u prekidnoj funkciji
  }

}

/* Slanje komande na LCD */
void lcd_send_cmd(char cmd)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = cmd&0xf0; //select upper nibble
	data_l = (cmd<<4)&0xf0; //select lower nibble
	data_t[0] = data_u|0x04;  //en=1, rs=0
	data_t[1] = data_u;  //en=0, rs=0
	data_t[2] = data_l|0x04;  //en=1, rs=0
	data_t[3] = data_l;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, LCD_ADDRESS_W, data_t, 4, 50);
}

/* Slanje podataka za ispis na LCD */
void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = data&0xf0;    // upper data nibble
	data_l = (data<<4)&0xf0;    // lower data nibble
	data_t[0] = data_u|0x05;  //en=1, rs=1
	data_t[1] = data_u|0x01;  //en=0, rs=1
	data_t[2] = data_l|0x05;  //en=1, rs=1
	data_t[3] = data_l|0x01;  //en=0, rs=1
	HAL_I2C_Master_Transmit (&hi2c1, LCD_ADDRESS_W, data_t, 4, 100);
}

/* LCD inicijalizacija */
void lcd_init(void)
{
	lcd_send_cmd(0x01); //clear display
	lcd_send_cmd(0x02);	//return home
	lcd_send_cmd(0x28); // 4 bits, 2 lines
	lcd_send_cmd(0x0c); // display on, cursor off
}

/* Slanje stringa na LCD */
void lcd_send_string (char *str)
{
	uint8_t i = 0;
	while (*str) {
		lcd_send_data(*str++);
		i++;
	}
	if(i == 2){
		lcd_send_data(' ');
	}
}

/* Upis stupnjeva na odgovarajuce pozicije LCD-a */
void lcd_write_deg (char *deg, uint8_t pos)
{
	lcd_send_cmd(pos);
	lcd_send_string(deg);
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
  hadc1.Init.Resolution = ADC_RESOLUTION_8B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM1 init function */
static void MX_TIM1_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 15;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 100;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim1);

}

/* TIM2 init function */
static void MX_TIM2_Init(void)
{

  TIM_Encoder_InitTypeDef sConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 2400;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 15;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 15;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM3 init function */
static void MX_TIM3_Init(void)
{

  TIM_Encoder_InitTypeDef sConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 2400;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 15;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 15;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM4 init function */
static void MX_TIM4_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 15;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 1000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE10 PE12 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

}

/* 	
		Glavna prekidna funkcija
		Izvrsava se svake 1ms
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  UNUSED(htim);
  
	//Ucitanje vrijednosti potenciometara i pretvorba u raspon -30 do 30 stupnjeva
	pot2deg[0] = round(((255 - potentiometer[0])/4.25 - 30.0));
	pot2deg[1] = round(((255 - potentiometer[1])/4.25 - 30.0));
	
	//Postavljanje predznaka reference za prikaz na LCD-u
	if(pot2deg[0]<0){
		pitch_buffer[0] = '-';
	}else{
		pitch_buffer[0] = ' ';
	}
	if(pot2deg[1]<0){
		yaw_buffer[0] = '-';
	}else{
		yaw_buffer[0] = ' ';
	}
	
	//Konverzija integera u char array za prikaz reference na LCD-u
	snprintf(pitch_buffer+1, 10, "%d", abs(pot2deg[0]));
	snprintf(yaw_buffer+1, 10, "%d", abs(pot2deg[1]));
	//Zapis zadanih stupnjeva na LCD
	lcd_write_deg(pitch_buffer, *lcd_pos);
	lcd_write_deg(yaw_buffer, *(lcd_pos+1));
	
	
	//Dohvat pozicija enkodera
	deg1 = Get_Encoder_Pos(&htim3);
	deg2 = - Get_Encoder_Pos(&htim2);
	
	//Postavljanje nove pozicije u polje pozicija (zadnje dvije)
	Set_Pose(pitch, deg1, bias); //Kod pitch-a zadajemo bias koji odgovara pocetnom kutu
	Set_Pose(yaw, deg2, 0.0);
	
	//Izracun pogreske pozicije
	err1 = ref1 - *pitch;
	err2 = ref2 - deg2;		
	
	//Izracun napona integralnog dijela regulatora
	u_int1 = integral_control(err1, err2, &pitch_int, &anti_windup_pitch, 0);
	u_int2 = integral_control(err1, err2, &yaw_int, &anti_windup_yaw, 1);
	
	//Izracun napona proporcionalnog dijela regulatora
	//Spremanje napona u u_p1 i u_p2 preko pointera
	proporcional(err1, err2, *speed_pitch, *speed_yaw, &u_p1, &u_p2);
	
	//Izracun feed forward napona za pitch
	u_pff = feed_forward(*pitch);
	
	//Upravljacki napon za pitch i yaw motor	
	u_pitch = u_int1 + u_p1 + u_pff;
	u_yaw = u_int2 + u_p2;
	
  //Postavljanje brzine vrtnje motora
	Set_Speed(1, u_pitch, &htim1);
	Set_Speed(2, u_yaw, &htim1);
	
	//Izracun kutne brzine
	Get_Speed(speed_pitch, pitch);
	Get_Speed(speed_yaw, yaw);
	
	//Citanje gumba za postavljanje reference
	button = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1);
	//Detekcija rastuceg brida i postavljanje reference
	if(button == 0 & last_State == 1){
		ref1 = pot2deg[0]*(3.14159/180.0);
		ref2 = pot2deg[1]*(3.14159/180.0); 
	}
	last_State = button;
	return;
}

void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

