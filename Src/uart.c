/*
 * uart.c
 *
 *  Created on: Jan 17, 2023
 *      Author: pusedu03
 */

#include "uart.h"

#define rxBufferMax 200
uint8_t rxChar;
uint8_t rxBuffer[rxBufferMax];
int			rxBufferGp;	// rxBuffer Get(Read) Pointer
int			rxBufferPp;	// rxBuffer Put(Write) Pointer

void initUart(UART_HandleTypeDef *huart) {
	HAL_UART_Receive_IT(huart, &rxChar, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	// 수신 버퍼에 저장
	rxBuffer[rxBufferPp++] = rxChar;
	rxBufferPp %= rxBufferMax;
	// 인터럽트 재설정
	HAL_UART_Receive_IT(huart, &rxChar, 1);
}

// 글자를 가져오는 함수
uint8_t getRxBuffer() {
	uint8_t result;
	if(rxBufferPp == rxBufferGp) return 0;
	result = rxBuffer[rxBufferGp++];
	rxBufferGp %= rxBufferMax;
	return result;
}
