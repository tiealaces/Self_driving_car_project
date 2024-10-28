/*
 * sensor.c
 *
 *  Created on: Oct 10, 2024
 *      Author: USER
 */

#include "sensor.h"

uint32_t echo_left_time, echo_center_time, echo_right_time;
uint32_t echo_left_rise_time, echo_left_fall_time;
uint32_t echo_center_rise_time, echo_center_fall_time;
uint32_t echo_right_rise_time, echo_right_fall_time;

uint32_t right_value, left_value;

void echo_set()
{
	HAL_TIM_IC_Start_DMA(&htim3, TIM_CHANNEL_1, &echo_left_rise_time, 1);
	HAL_TIM_IC_Start_DMA(&htim3, TIM_CHANNEL_2, &echo_left_fall_time, 1);
	HAL_TIM_IC_Start_DMA(&htim3, TIM_CHANNEL_3, &echo_center_rise_time, 1);
	HAL_TIM_IC_Start_DMA(&htim3, TIM_CHANNEL_4, &echo_center_fall_time, 1);
	HAL_TIM_IC_Start_DMA(&htim4, TIM_CHANNEL_1, &echo_right_rise_time, 1);
	HAL_TIM_IC_Start_DMA(&htim4, TIM_CHANNEL_2, &echo_right_fall_time, 1);
}

void echo_get()
{
	if (echo_left_fall_time > echo_left_rise_time){
		echo_left_time = echo_left_fall_time - echo_left_rise_time;
	}
	if (echo_center_fall_time > echo_center_rise_time) {
		echo_center_time = echo_center_fall_time - echo_center_rise_time;
	}
	if (echo_right_fall_time > echo_right_rise_time){
		echo_right_time = echo_right_fall_time - echo_right_rise_time;
	}

}

void trigger_set()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}


