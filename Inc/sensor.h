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

extern uint32_t echo_left_time, echo_center_time, echo_right_time;
extern uint32_t echo_left_rise_time, echo_left_fall_time;
extern uint32_t echo_center_rise_time, echo_center_fall_time;
extern uint32_t echo_right_rise_time, echo_right_fall_time;

void echo_set();
void echo_get();
void trigger_set();

#endif /* INC_SENSOR_H_ */
