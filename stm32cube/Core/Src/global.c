/*
 * global.c
 *
 *  Created on: Dec 13, 2022
 *      Author: phamv
 */
#include "global.h"


char temp = 0;
char str[50];
char command_buffer[50] = "";
uint8_t buffer_flag = 0;
int ADC_value = 0;
uint8_t ok_flag = 0;
uint8_t sending_flag = 0;

int uart_status = WAIT_FOR_SENDING;
int cmd_status = WAIT_FOR_BEGIN_CMD;
