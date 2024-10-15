/*
 * bluetooth.c
 *
 *  Created on: Oct 11, 2024
 *      Author: USER
 */


#include "bluetooth.h"

int speed = 600;
uint8_t str_peri[1];
static uint16_t speedIndex = 0;
static uint16_t speedState[] = {600, 800, 1000};

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t rxBufferSize)
{
	if (huart == &huart1)	// else if
	{
		if (rxBufferSize)
		{
			str_peri[rxBufferSize] = 0;	// trans char
		}
		HAL_UARTEx_ReceiveToIdle_IT(&huart1, str_peri, sizeof(str_peri));


		if(str_peri[0] == 'F')
		{
			__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, speed);
			Forward();

		}
		else if(str_peri[0] == 'L')
		{
			__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, speed);
			Left();
		}
		else if(str_peri[0] == 'B')
		{
			__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, speed);
			Backward();
		}
		else if(str_peri[0] == 'R')
		{
			__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, speed);
			Right();
		}
		else if(str_peri[0] == 'P')
		{
			STOP();
		}
		else if(str_peri[0] == 'A')
		{
			speedIndex = (speedIndex +1) % (sizeof(speedState) / sizeof(speedState[0]));
			speed = speedState[speedIndex];
			__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, speed);
		}


	}

}
