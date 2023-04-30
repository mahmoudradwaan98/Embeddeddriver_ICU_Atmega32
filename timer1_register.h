/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : Timers / Timer 1       *******************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/





#ifndef Timer1_register_H_

 #define Timer1_register_H_ 
 
	#define TCCR1A              *((volatile u8*)0x4F)   /* Timer/Counter 1 A control REGISTER */
	
	#define TCCR1A_WGM10         0                       /* waveform generation mode Bit 0 */
	#define TCCR1A_WGM11         1                       /*  waveform generation mode Bit 1 */  


	#define TCCR1A_COM1B0        4                       /* Compare Output Mode for Channel B Bit  0 */
	#define TCCR1A_COM1B1        5                       /* Compare Output Mode for Channel B Bit  1 */ 
	#define TCCR1A_COM1A0        6                       /* Compare Output Mode for Channel A  Bit 0 */
	#define TCCR1A_COM1A1        7                       /* Compare Output Mode for Channel A  Bit 1 */  	

	
	#define TCCR1B              *((volatile u8*)0x4E)   /* Timer/Counter 1 B control REGISTER */

	#define TCCR1B_WGM12         3                       /* waveform generation mode Bit  3 */
	#define TCCR1B_WGM13         4                       /*  waveform generation mode Bit 4 */

	#define TCCR1B_CS10          0                       /*  prescaler Bit 0 */
	#define TCCR1B_CS11          1                       /*  prescaler Bit 1 */
	#define TCCR1B_CS12          2                       /*  prescaler Bit 2 */
	#define TCCRB1_ICES1         6                       /*  Input Capture Edge Select */
    #define TCCRB1_ICNC1         7                       /*  Input Capture Noise Canceler */
	
	#define ICR1                *((volatile u16*)0x46)   /*   Timer/Counter1 Input Capture Register Low Byte */
	
	#define OCR1A               *((volatile u16*)0x4A)    /*  Timer/Counter1 A Output Compare Register A Low Byte */
	#define OCR1B               *((volatile u16*)0x48)    /*  Timer/Counter1 B Output Compare Register B Low Byte */
	
	#define TCNT1               *((volatile u16*)0x4C)    /*  Timer/Counter1 Counter Register Low Byte */

	#define TIMSK               *((volatile u8*)0x59)      /* Timer / counter interrupt mask register */
    #define TIMSK_TICIE1        5                          /* Timer/Counter1, Input Capture Interrupt Enable */
	#define TIMSK_OCIE0         1                          /* output compare 0 Interrupt Enable  */
	
#endif
