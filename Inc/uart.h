/*
 * uart.h
 *
 *  Created on: Jan 17, 2023
 *      Author: pusedu03
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"

void initUart(UART_HandleTypeDef *huart);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

// 글자를 가져오는 함수
uint8_t getRxBuffer();

#endif /* INC_UART_H_ */
