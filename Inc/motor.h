/*
 * motor.h
 *
 *  Created on: Aug 1, 2024
 *      Author: USER
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"

void Forward();
void Backward();
void Right();
void Right_slow();
void Left();
void Left_slow();
void STOP();
void motor_power(uint32_t right_value, uint32_t left_value);

#endif /* INC_MOTOR_H_ */
