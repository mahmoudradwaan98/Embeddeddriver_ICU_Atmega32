/*
 *  Application : main.c
 *
 *  Created on : April 28, 2023
 *  Author     : Mahmoud Radwan
 *	version    : 1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "PORT_interface.h"
#include "DIO_interface.h"

#include "timer0_interface.h"
#include "timer1_interface.h"
#include "GIE_interface.h"


static u16 PeriodTimeTicks = 0;
static u16 ONTimeTicks = 0;

void ICU_HW(void);

void main (void){

	PORT_voidInit();

	ICU_voidInit();

	ICU_u8SetCallbackFunc(&ICU_HW);

	TIMER0_voidInit();

	TIMER1_voidInit();

	GIE_voidEnable();

	while(1){
		
	}

	
}

void ICU_HW(void){

	static u16 Read1,Read2,Read3;

	static u8 Local_u8counter =0;

	Local_u8counter++;

	if(Local_u8counter==1){

		Read1 = ICU_u16ReadInputCapture();
	}

	else if(Local_u8counter==2){

		Read2 = ICU_u16ReadInputCapture();

		PeriodTimeTicks = Read2 - Read1;

		ICU_voidSetTriggerEdge(ICU_FALLING_EDGE);
	}

	else if(Local_u8counter==3){

		Read3 = ICU_u16ReadInputCapture();

		ONTimeTicks = Read3 - Read2;

		ICU_DisableInterrupt();

	}


}
