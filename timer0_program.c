/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan        **********************/
/****************    Layer     : MCAL                  *********************/
/****************    SWC       : Timers  / Timer 0     ********************/
/****************    version   : 1.0                   *******************/
/************************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "timer0_config.h"
#include "timer0_private.h"
#include "timer0_interface.h"
#include "timer0_register.h"

static void(*TIMER0_pvcallbackdfunc)(void) = NULL;

void TIMER0_voidSetCompareMatchValue(u8 copy_u8Value){
	
	OCR0 = copy_u8Value;
}

void TIMER0_voidInit(void){
	
	/* Choose Fast PWM mode */
	
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	/* Choose CTC mode */

	//SET_BIT(TCCR0,TCCR0_WGM01);

	//CLR_BIT(TCCR0,TCCR0_WGM00);

	/* output compare match interrupt enable*/

	//SET_BIT(TIMSK,TIMSK_OCIE0);

	/* set compare match to 64 with duty cycle 25% */

	OCR0 = 64;

	/* prescaler : division by 64 */

	//SET_BIT(TCCR0,TCCR0_CS00);

	//SET_BIT(TCCR0,TCCR0_CS01);

	//CLR_BIT(TCCR0,TCCR0_CS02);
	
	/* another approach : prescaler  division by 8  choices (0,1,2,3,4) ---> (no div,1,8,64,256)*/
	u8 prescaler_mask = 0b11111000;
	TCCR0 &= prescaler_mask;
	TCCR0 |= 2;
	/* Non inverted mode : Clear on Compare Match , Set on Top 
	
		                set bit COM01 , clear bit COM00
	
	   Inverted mode : set on Compare Match , clear on Top 
	
	                    set both bits COM00 ,COM01
	*/
	
	SET_BIT(TCCR0,TCCR0_COM01);

	CLR_BIT(TCCR0,TCCR0_COM00);

}
	
u8 TIMER0_u8setcallback(void(*copy_ptrvoidfunc)(void)){
	
	u8 Local_errorstate = OK;
	if(copy_ptrvoidfunc!=NULL){

		TIMER0_pvcallbackdfunc = copy_ptrvoidfunc;

	}
	else{
		Local_errorstate = NULLPOINTER;
	}


	return Local_errorstate;
}
	
void __vector_10(void)  __attribute((signal));

void __vector_10(void){

	if(TIMER0_pvcallbackdfunc!=NULL){

		TIMER0_pvcallbackdfunc();

	}
	else{
		//Do Nothing
	}
}
