/***********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     SYSTICK */
/* Version: V01 */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

static void (*CallBackFunc)(void)=NULL;
static u8 IntervalSource=0;

void MSYSTICK_voidInit(void){
	STK_CTRL = 0;
#if CLK_SOURCE == AHB_DIV_8
	CLR_BIT(STK_CTRL,2);
#elif  CLK_SOURCE == AHB
	SET_BIT(STK_CTRL,2);
#endif

}

void MSYSTICK_voidSetBusyWait(u32 Copy_u32Ticks){
	STK_LOAD = Copy_u32Ticks;
		SET_BIT(STK_CTRL, 0);

		while((GET_BIT(STK_CTRL, 16)) == 0);
		CLR_BIT(STK_CTRL, 16);

}

void MSYSTICK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (* Copy_pfNotFunc) (void)){
	CallBackFunc=Copy_pfNotFunc;
	IntervalSource=0;
	SET_BIT(STK_CTRL,1);
	STK_LOAD=Copy_u32Ticks;
	SET_BIT(STK_CTRL,0);
}

void MSYSTICK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (* Copy_pfNotFunc) (void)){
	CallBackFunc=Copy_pfNotFunc;
		IntervalSource=1;
		SET_BIT(STK_CTRL,1);
		STK_LOAD=Copy_u32Ticks;
		SET_BIT(STK_CTRL,0);
}

void MSYSTICK_voidStopTimer(void){
	CLR_BIT(STK_CTRL,0);
}

u32 MSYSTICK_u32GetElapsedTime(void){
	return (STK_LOAD-STK_VAL);
	
}

u32 MSYSTICK_u32GetRemainingTime(void){
return STK_VAL;
}

void SysTick_Handler(void){
	if(IntervalSource==1){
		/*Periodic */
		CallBackFunc();
	}
	else if(IntervalSource==0){
			/*Signle*/
			CallBackFunc();
			STK_LOAD=0;
			CLR_BIT(STK_CTRL,1);
			CLR_BIT(STK_CTRL,0);
		}
}
