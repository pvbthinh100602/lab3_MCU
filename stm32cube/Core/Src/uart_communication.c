/*
 * uart_communication.c
 *
 *  Created on: Dec 7, 2022
 *      Author: phamv
 */
#include "uart_communication.h"

void uart_communication_fsm(){
	switch(uart_status){
	case WAIT_FOR_SENDING:
		if(ok_flag == 1){
			ok_flag = 0;
		}
		if(sending_flag == 1){
			sending_flag = 0;
			setTimer1(2000);
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit_IT(&huart2, (void*)str, sprintf(str,"\r\nADC=%d\r\n",ADC_value));
			uart_status = WAIT_FOR_RESPONSE;
		}
		break;
	case WAIT_FOR_RESPONSE:
		if(sending_flag == 1){
			sending_flag = 0;
		}
		if(ok_flag == 1){
			uart_status = WAIT_FOR_SENDING;
			setTimer1(0);
		}
		if(timer1_flag){
			HAL_UART_Transmit_IT(&huart2, (void*)str, sprintf(str,"\r\nADC=%d\r\n",ADC_value));
			setTimer1(2000);
		}
		break;
	default:
		break;
	}
}

