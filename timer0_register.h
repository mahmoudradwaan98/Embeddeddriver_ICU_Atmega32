/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : Timers / Timer 0       *******************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/





#ifndef Timers_register_H_

 #define Timers_register_H_ 

	#define TCNT0               *((volatile u8*)0x52)   /* Timer/Counter 0 REGISTER */
	
	#define TCCR0               *((volatile u8*)0x53)   /* Timer/Counter 0 control REGISTER */
	
	#define TCCR0_WGM00         6                        /* waveform generation mode Bit 0 */
	#define TCCR0_WGM01         3                       /*  waveform generation mode Bit 1 */
	
	#define TCCR0_COM00         4                       /* compare match output mode Bit 0 */
	#define TCCR0_COM01         5                       /* compare match output mode Bit 1 */	
	
	#define TCCR0_CS02          2                       /*  prescaler Bit 2 */
	#define TCCR0_CS01          1                       /*  prescaler Bit 1 */
	#define TCCR0_CS00          0                        /* prescaler Bit 0 */
	
	#define OCR0                *((volatile u8*)0x5C)  /* Output compare REGISTER 0 */
	
	#define TIFR                *((volatile u8*)0x58)  /* Timer/Counter 0 interrupt flag register */
	
	#define TIMSK               *((volatile u8*)0x59)  /* Timer/Counter 0 interrupt mask register */
	
	#define TIMSK_TOIE0         0                       /* Timer/Counter 0 overflow Interrupt Enable */
	#define TIMSK_OCIE0         1                       /* Output compare 0 Interrupt Enable */ 
	
	
	
#endif
