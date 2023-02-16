/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     EXTI */
/* Version: V01  */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


static void (*CallBackFunc0)(void)=NULL;
static void (*CallBackFunc1)(void)=NULL;
static void (*CallBackFunc2)(void)=NULL;
static void (*CallBackFunc3)(void)=NULL;
static void (*CallBackFunc4)(void)=NULL;


void MEXTI_voidInit(void){
#if EXTI_LINE  == LINE0
	SET_BIT(EXTI->IMR,0);
#elif EXTI_LINE  == LINE1
	SET_BIT(EXTI->IMR,1);
#elif EXTI_LINE  == LINE2
	SET_BIT(EXTI->IMR,2);
#elif EXTI_LINE  == LINE3
	SET_BIT(EXTI->IMR,3);
#elif EXTI_LINE  == LINE4
	SET_BIT(EXTI->IMR,4);
#else
#error("WRONG EXTI LINE")

#endif

#if EXTI_MODE == RISING
	SET_BIT(EXTI->RTSR , EXTI_LINE);
#elif EXTI_MODE == FALLING
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
#elif EXTI_MODE == ONCHANGE
	SET_BIT(EXTI -> RTSR , EXTI_LINE);
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
#endif

/*Disable Interrupt */

}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line){
SET_BIT(EXTI->IMR,Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line){
	CLR_BIT(EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line){
	SET_BIT(EXTI->SWIER,Copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode){
switch (Copy_u8Mode){
case RISING:
	SET_BIT(EXTI->RTSR , Copy_u8Line);
	CLR_BIT(EXTI -> FTSR , Copy_u8Line);
	break;
case FALLING:
	SET_BIT(EXTI -> FTSR , Copy_u8Line);
	CLR_BIT(EXTI -> RTSR , Copy_u8Line);
	break;
case ONCHANGE:
	SET_BIT(EXTI -> RTSR , Copy_u8Line);
	SET_BIT(EXTI -> FTSR , Copy_u8Line);
		break;
}
SET_BIT(EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidSetCallBack(u8 Copy_u8Line ,void (* Copy_pfCallBackFunc)(void)){
	switch (Copy_u8Line){
	case EXTI0:CallBackFunc0=Copy_pfCallBackFunc; break;
	case EXTI1:CallBackFunc1=Copy_pfCallBackFunc; break;
	case EXTI2:CallBackFunc2=Copy_pfCallBackFunc; break;
	case EXTI3:CallBackFunc3=Copy_pfCallBackFunc; break;
	case EXTI4:CallBackFunc4=Copy_pfCallBackFunc; break;
	}
}
void EXTI0_IRQHandler(void){
	CallBackFunc0();
	/* clear pending bit */
	SET_BIT(EXTI->PR,0);
}
void EXTI1_IRQHandler(void){
	CallBackFunc1();

	SET_BIT(EXTI->PR,1);
}
void EXTI2_IRQHandler(void){
	CallBackFunc2();
	SET_BIT(EXTI->PR,2);
}
void EXTI3_IRQHandler(void){
	CallBackFunc3();
	SET_BIT(EXTI->PR,3);
}
void EXTI4_IRQHandler(void){
	CallBackFunc4();
	SET_BIT(EXTI->PR,4);
}
