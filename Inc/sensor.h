/*
 * sensor.h
 *
 *  Created on: Oct 10, 2024
 *      Author: USER
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#include "tim.h"
#include <stdio.h>
#include "main.h"


//void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
//void HCSR04_read();
//void HCSR04_set();
void echo_set();
void echo_get();
void trigger_set();

#endif /* INC_SENSOR_H_ */
