/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     NVIC */
/* Version: V01  */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <= 31){
	NVIC_ISER0 = 1 << Copy_u8IntNumber;
	}
	else if (Copy_u8IntNumber <= 59){
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = 1 << Copy_u8IntNumber;
		}
	else {
		//do nothing
	}
}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <= 31){
	NVIC_ICER0 = 1 << Copy_u8IntNumber;
	}
	else if (Copy_u8IntNumber <= 59){
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = 1 << Copy_u8IntNumber;
		}
	else {
		//do nothing
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <= 31){
	NVIC_ISPR0 = 1 << Copy_u8IntNumber;
	}
	else if (Copy_u8IntNumber <= 59){
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = 1 << Copy_u8IntNumber;
		}
	else {
		//do nothing
	}
}
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber){
	if (Copy_u8IntNumber <= 31){
	NVIC_ICPR0 = 1 << Copy_u8IntNumber;
	}
	else if (Copy_u8IntNumber <= 59){
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = 1 << Copy_u8IntNumber;
		}
	else {
		//do nothing
	}
}
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber){
	u8 Local_u8Result;
	if (Copy_u8IntNumber <= 31){
		Local_u8Result=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59){
		Copy_u8IntNumber -= 32;
		Local_u8Result=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
		}
	else {
		//do nothing
	}
	return Local_u8Result;
}

void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority  ){
	/*Assign Grouping System to SCB_AIRCR*/
#define SCB_AIRCR      *((volatile u32*)(0xE000ED00+0x0C))  //application interrupt and reset control register
	 SCB_AIRCR = NVIC_GroupingSystem ;

 /* EX :0x05FA0400 : 3 group and 1 sub
  *0x05FA0400-0x05FA0300=0x100 = 256
  *256/256=1
  *group << 1
  *sub | (group << 1)
  *shift left Group by 1 to take only 3 bits and 1 for sub
  *3 bits : group
  *1 bit : sub
  */
	u8 Local_u8Priority =  (Copy_u8SubPriority| (Copy_u8GroupPriority << ((NVIC_GroupingSystem - 0x05FA0300) / 256))) ;
	/* Check if i am core peripheral or external peripheral */
	if(Copy_s8IntID >= 0 && Copy_s8IntID < 60){
		/*External Peripheral */
		NVIC_IPR[Copy_s8IntID]= (Local_u8Priority << 4 );
	}
	else{
		//return error
	}

}
