/*
 * bluetooth.h
 *
 *  Created on: Oct 11, 2024
 *      Author: USER
 */

#ifndef INC_BLUETOOTH_H_
#define INC_BLUETOOTH_H_

#include "main.h"


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t rxBufferSize);

#endif /* INC_BLUETOOTH_H_ */
