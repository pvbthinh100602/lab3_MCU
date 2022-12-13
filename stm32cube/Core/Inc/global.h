/*
 * global.h
 *
 *  Created on: Dec 13, 2022
 *      Author: phamv
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>



#define WAIT_FOR_BEGIN_CMD	1
#define WAIT_FOR_END_CMD	2

#define WAIT_FOR_SENDING	1
#define WAIT_FOR_RESPONSE	2


extern char temp;
extern char	str[];
extern char command_buffer[];
extern uint8_t buffer_flag;
extern int cmd_status;
extern int uart_status;
extern uint8_t ok_flag;
extern uint8_t sending_flag;
extern int ADC_value;
#endif /* INC_GLOBAL_H_ */
