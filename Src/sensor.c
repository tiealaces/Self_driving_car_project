/*
 * sensor.c
 *
 *  Created on: Oct 10, 2024
 *      Author: USER
 */

#include "sensor.h"

extern uint32_t echo_left_time, echo_center_time, echo_right_time;
extern uint32_t echo_left_rise_time, echo_left_fall_time;
extern uint32_t echo_center_rise_time, echo_center_fall_time;
extern uint32_t echo_right_rise_time, echo_right_fall_time;
//#define CH_1_TRIG_PORT 	GPIOA
//#define CH_1_TRIG_PIN	GPIO_PIN_5
//#define CH_2_TRIG_PORT 	GPIOC
//#define CH_2_TRIG_PIN	GPIO_PIN_8
//#define CH_3_TRIG_PORT 	GPIOC
//#define CH_3_TRIG_PIN	GPIO_PIN_6

//uint16_t CH1_IC_VALUE1 	= 0;	//rising edge
//uint16_t CH1_IC_VALUE2 	= 0;	//falling edge
//uint16_t CH2_IC_VALUE1 	= 0;
//uint16_t CH2_IC_VALUE2 	= 0;
//uint16_t CH3_IC_VALUE1 	= 0;
//uint16_t CH3_IC_VALUE2 	= 0;
//uint16_t ch1_echoTime 	= 0;	//falling time - rising time
//uint16_t ch2_echoTime 	= 0;
//uint16_t ch3_echoTime 	= 0;
//uint8_t ch1_captureFlag = 0;	//capture ?
//uint8_t ch2_captureFlag = 0;
//uint8_t ch3_captureFlag = 0;
//uint8_t ch1_distance 	= 0;
//uint8_t ch2_distance 	= 0;
//uint8_t ch3_distance 	= 0;

//void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
//{
//	if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
//	{
//		if(ch1_captureFlag == 0)
//		{
//			CH1_IC_VALUE1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
//			ch1_captureFlag = 1;
//			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
//		}
//		else if(ch1_captureFlag == 1)
//		{
//			CH1_IC_VALUE2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
//			__HAL_TIM_SetCounter(&htim3, 0);
//
//			if(CH1_IC_VALUE2 > CH1_IC_VALUE1)
//			{
//				ch1_echoTime = CH1_IC_VALUE2 - CH1_IC_VALUE1;
//			}
//			else if(CH1_IC_VALUE1 > CH1_IC_VALUE2)
//			{
//				ch1_echoTime = (0xffff - CH1_IC_VALUE1) + CH1_IC_VALUE2;
//			}
//			ch1_distance = ch1_echoTime/58;
//			ch1_captureFlag = 0;
//			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
//			__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
//		}
//	}
//	else if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
//		{
//			if(ch2_captureFlag == 0)
//			{
//				CH2_IC_VALUE1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
//				ch2_captureFlag = 1;
//				__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
//			}
//			else if(ch2_captureFlag == 1)
//			{
//				CH2_IC_VALUE2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
//				__HAL_TIM_SetCounter(&htim3, 0);
//
//				if(CH2_IC_VALUE2 > CH2_IC_VALUE1)
//				{
//					ch2_echoTime = CH2_IC_VALUE2 - CH2_IC_VALUE1;
//				}
//				else if(CH2_IC_VALUE1 > CH2_IC_VALUE2)
//				{
//					ch2_echoTime = (0xffff - CH2_IC_VALUE1) + CH2_IC_VALUE2;
//				}
//				ch2_distance = ch2_echoTime/58;
//				ch2_captureFlag = 0;
//				__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
//				__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
//			}
//		}
//	else if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
//			{
//				if(ch3_captureFlag == 0)
//				{
//					CH3_IC_VALUE1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_3);
//					ch3_captureFlag = 1;
//					__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
//				}
//				else if(ch3_captureFlag == 1)
//				{
//					CH3_IC_VALUE2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_3);
//					__HAL_TIM_SetCounter(&htim3, 0);
//
//					if(CH3_IC_VALUE2 > CH3_IC_VALUE1)
//					{
//						ch3_echoTime = CH3_IC_VALUE2 - CH3_IC_VALUE1;
//					}
//					else if(CH3_IC_VALUE1 > CH3_IC_VALUE2)
//					{
//						ch3_echoTime = (0xffff - CH3_IC_VALUE1) + CH3_IC_VALUE2;
//					}
//					ch3_distance = ch3_echoTime/58;
//					ch3_captureFlag = 0;
//					__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
//					__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
//				}
//			}
//}

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
	if (echo_left_fall_time > echo_left_rise_time) echo_left_time = echo_left_fall_time - echo_left_rise_time;
	if (echo_center_fall_time > echo_center_rise_time) echo_center_time = echo_center_fall_time - echo_center_rise_time;
	if (echo_right_fall_time > echo_right_rise_time) echo_right_time = echo_right_fall_time - echo_right_rise_time;

	HAL_Delay(100);
}

void trigger_set()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}


//void HCSR04_read()	// trig func
//{
//	HAL_GPIO_WritePin(CH_1_TRIG_PORT, CH_1_TRIG_PIN, 1);
//	HAL_GPIO_WritePin(CH_2_TRIG_PORT, CH_2_TRIG_PIN, 1);
//	HAL_GPIO_WritePin(CH_3_TRIG_PORT, CH_3_TRIG_PIN, 1);
//	delay_us(15);
//	HAL_GPIO_WritePin(CH_1_TRIG_PORT, CH_1_TRIG_PIN, 0);
//	HAL_GPIO_WritePin(CH_2_TRIG_PORT, CH_2_TRIG_PIN, 0);
//	HAL_GPIO_WritePin(CH_3_TRIG_PORT, CH_3_TRIG_PIN, 0);
//
//	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_CC1);
//}

//void HCSR04_set(){
//	HAL_TIM_Base_Start(&htim11);	//for delay func
//    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);	//for ultrasonic
//    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
//    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_3);
//}



