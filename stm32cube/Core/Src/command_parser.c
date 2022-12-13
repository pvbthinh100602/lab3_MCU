/*
 * command_parser.c
 *
 *  Created on: Dec 7, 2022
 *      Author: phamv
 */
#include "command_parser.h"

//char command[][] = {
//		""
//};

void command_parser_fsm(){
	switch(cmd_status){
	case WAIT_FOR_BEGIN_CMD:
//		HAL_UART_Transmit_IT(&huart2,(void*) str, sprintf(str, "Received !\n"));
		if(temp == '!') {
			cmd_status = WAIT_FOR_END_CMD;
//			HAL_UART_Transmit_IT(&huart2,(void*) str, sprintf(str, "Received !\n"));
		}
		break;
	case WAIT_FOR_END_CMD:
//		HAL_UART_Transmit_IT(&huart2, (void*)&temp, 1);
		if(temp == '#') {
			if(strlen(command_buffer) == 3 && strncmp(command_buffer,"RST",3) == 0) sending_flag = 1;
			else if(strlen(command_buffer) == 2 && strncmp(command_buffer,"OK",2) == 0) ok_flag = 1;

//			if(sending_flag == 1){
//				if(strlen(command_buffer) == 2 && strncpy(command_buffer,"OK",2) == 0){
//					sending_flag = 0;
//				}
//			} else{
//				if(strlen(command_buffer) == 3 && strncpy(command_buffer,"RST",3) == 0) sending_flag = 1;
//			}
			strcpy(command_buffer,"");
			cmd_status = WAIT_FOR_BEGIN_CMD;
		} else {
			strncat(command_buffer, &temp, 1);
//			HAL_UART_Transmit(&huart2, (void*)command_buffer, strlen(command_buffer), 50);
		}
		break;
	default:
		break;
	}
}

