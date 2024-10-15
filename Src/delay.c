/*
 * delay.c
 *
 *  Created on: Oct 11, 2024
 *      Author: USER
 */


#include "delay.h"


void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim11, 0);
	while((__HAL_TIM_GET_COUNTER(&htim11)) < us);
}
