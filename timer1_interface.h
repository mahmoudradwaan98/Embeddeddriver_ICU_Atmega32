/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : Timers  / Timer 1    *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef TIMER1_interface_H_

 #define TIMER1_interface_H_


	#define ICU_RISING_EDGE             1
	#define ICU_FALLING_EDGE            0
 
	void TIMER1_voidInit(void);
	
	void ICU_voidInit(void);

	void ICU_voidSetTriggerEdge(u8 copy_u8edge);

	void ICU_EnableInterrupt(void);

	void ICU_DisableInterrupt(void);

	u16 ICU_u16ReadInputCapture(void);

	void TIMER1_voidSetTimerValue(u16 copy_u16Value);
	
    void TIMER1_voidSetTopValue(u16 copy_u16TopValue);

    void TIMER1_voidSetCompareMatchValueChannel_1A(u16 copy_u16CompValue1A);

    void TIMER1_voidSetCompareMatchValueChannel_1B(u16 copy_u16CompValue1B);
	
    u8 TIMER1_u8SetCallbackFunc(void(*copy_ptrvoidfunc)(void));

    u8 ICU_u8SetCallbackFunc(void(*copy_pvFunc)(void));

	u16 TIMER1_u16GetTimerReadValue(void);
		
#endif
