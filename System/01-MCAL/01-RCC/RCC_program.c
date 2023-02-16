/***********************************************************************************/
/* Author : Saied Kamara
/* SWC:     RCC
/* Version: V01
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void){
	#if   RCC_CLOCK_TYPE  == RCC_HSE_CRYSTAL
	RCC_CR   = 0x00010000;   //Enable HSEon with no BYPASS
	RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE  == RCC_HSE_RC
	RCC_CR   = 0x00050000;   //Enable HSEon with BYPASS
	RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE  == RCC_HSI
	RCC_CR   = 0x00000081;   //Enable HSIon + Triming = 0
	RCC_CFGR = 0x00000000;
	#elif RCC_CLOCK_TYPE  == RCC_PLL
	 #if RCC_PLL_INPUT == RCC_PLL_IN_HSE
	 RCC_CR   = 0x01010000;
	 RCC_CFGR =0x00010002;
	 #elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	 RCC_CR   = 0x01000001;
	 RCC_CFGR = 0x00000002;
	 #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	 RCC_CR   = 0x01010000;
	 RCC_CFGR = 0x00020002;
	 #endif
	
	#if RCC_PLL_MUL_VAL == 2
	RCC_CFGR |= 0x00000000;
	#elif RCC_PLL_MUL_VAL == 3
	RCC_CFGR |= 0x00040000;
	#elif RCC_PLL_MUL_VAL == 4
	RCC_CFGR |= 0x00080000;
	#elif RCC_PLL_MUL_VAL == 5
	RCC_CFGR |= 0x000C0000;
	#elif RCC_PLL_MUL_VAL == 6
	RCC_CFGR |= 0x00100000;
	#elif RCC_PLL_MUL_VAL == 7
	RCC_CFGR |= 0x00140000;
	#elif RCC_PLL_MUL_VAL == 8
	RCC_CFGR |= 0x00180000;
	#elif RCC_PLL_MUL_VAL == 9
	RCC_CFGR |= 0x001C0000;
	#elif RCC_PLL_MUL_VAL == 10
	RCC_CFGR |= 0x00200000;
	#elif RCC_PLL_MUL_VAL == 11
	RCC_CFGR |= 0x00240000;
	#elif RCC_PLL_MUL_VAL == 12
	RCC_CFGR |= 0x00280000;
	#elif RCC_PLL_MUL_VAL == 13
	RCC_CFGR |= 0x002C0000;
	#elif RCC_PLL_MUL_VAL == 14
	RCC_CFGR |= 0x00300000;
	#elif RCC_PLL_MUL_VAL == 15
	RCC_CFGR |= 0x00340000;
	#elif RCC_PLL_MUL_VAL == 16
	RCC_CFGR |= 0x00380000;
	
	#endif
	#else
		#error("Wrong Clock TYPE")
	
	#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PerID){
	if (Copy_u8PerID <=31 ){
		switch (Copy_u8BusID)
		{
			case RCC_AHB:  SET_BIT(RCC_AHBENR,Copy_u8PerID);  break;
			case RCC_APB1: SET_BIT(RCC_ABP1ENR,Copy_u8PerID); break;
			case RCC_APB2: SET_BIT(RCC_ABP2ENR,Copy_u8PerID); break;
		}
	}
	else{
		/*return error */
	}
}
void RCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PerID){
	if (Copy_u8PerID <=31 ){
		switch (Copy_u8BusID)
		{
			case RCC_AHB:  CLR_BIT(RCC_AHBENR,Copy_u8PerID);  break;
			case RCC_APB1: CLR_BIT(RCC_ABP1ENR,Copy_u8PerID); break;
			case RCC_APB2: CLR_BIT(RCC_ABP2ENR,Copy_u8PerID); break;
		}
	}
	else{
		/*return error */
	}
}