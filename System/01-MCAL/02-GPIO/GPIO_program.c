/***********************************************************************************/
/* Author : Saied Kamara
/* SWC:     GPIO
/* Version: V01
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8PORT ,u8 Copy_u8PIN ,u8 Copy_u8MODE){
	switch (Copy_u8PORT){
	case GPIOA :
		if (Copy_u8PIN <= 7){
			/* Clear the mode of the required pin */
			GPIOA_CRL &= ~ ( (0b1111) << (Copy_u8PIN * 4) );
			/* Set mode for PIN */
			GPIOA_CRL |=  ( (Copy_u8MODE) << (Copy_u8PIN * 4) );
		}
		else if (Copy_u8PIN > 7 && Copy_u8PIN <= 15){
			/* Clear the mode of the required pin */
			GPIOA_CRH &= ~ ( (0b1111) << ((Copy_u8PIN-8) * 4) );
			/* Set mode for PIN */
			GPIOA_CRH |=  ( (Copy_u8MODE) << ((Copy_u8PIN-8) * 4) );
		}
		break;
	case GPIOB :
		if (Copy_u8PIN <= 7){
			/* Clear the mode of the required pin */
			GPIOB_CRL &= ~ ( (0b1111) << (Copy_u8PIN * 4) );
			/* Set mode for PIN */
			GPIOB_CRL |=  ( (Copy_u8MODE) << (Copy_u8PIN * 4) );
		}
		else if (Copy_u8PIN > 7 && Copy_u8PIN <= 15){
			/* Clear the mode of the required pin */
			GPIOB_CRH &= ~ ( (0b1111) << ((Copy_u8PIN-8) * 4) );
			/* Set mode for PIN */
			GPIOB_CRH |=  ( (Copy_u8MODE) << ((Copy_u8PIN-8) * 4) );
		}
		break;
	case GPIOC :
		if (Copy_u8PIN <= 7){
			/* Clear the mode of the required pin */
			GPIOC_CRL &= ~ ( (0b1111) << (Copy_u8PIN * 4) );
			/* Set mode for PIN */
			GPIOC_CRL |=  ( (Copy_u8MODE) << (Copy_u8PIN * 4) );
		}
		else if (Copy_u8PIN > 7 && Copy_u8PIN <= 15){
			/* Clear the mode of the required pin */
			GPIOC_CRH &= ~ ( (0b1111) << ((Copy_u8PIN-8) * 4) );
			/* Set mode for PIN */
			GPIOC_CRH |=  ( (Copy_u8MODE) << ((Copy_u8PIN-8) * 4) );
		}
		break;
	}

}

void GPIO_voidSetPinValue(u8 Copy_u8PORT ,u8 Copy_u8PIN ,u8 Copy_u8Value){
	switch (Copy_u8PORT){
	case GPIOA:
		if(Copy_u8Value == PIN_HIGH){
			SET_BIT(GPIOA_ODR,Copy_u8PIN);
		}
		else if(Copy_u8Value == PIN_LOW){
			CLR_BIT(GPIOA_ODR,Copy_u8PIN);
		}
		break;
	case GPIOB:
		if(Copy_u8Value == PIN_HIGH){
			SET_BIT(GPIOB_ODR,Copy_u8PIN);
		}
		else if(Copy_u8Value == PIN_LOW){
			CLR_BIT(GPIOB_ODR,Copy_u8PIN);
		}
		break;
	case GPIOC:
		if(Copy_u8Value == PIN_HIGH){
			SET_BIT(GPIOC_ODR,Copy_u8PIN);
		}
		else if(Copy_u8Value == PIN_LOW){
			CLR_BIT(GPIOC_ODR,Copy_u8PIN);
		}
		break;
	default :   break;
	}
}
void GPIO_voidSetPortValue(u8 Copy_u8PORT ,u16 Copy_u16Value){
	switch (Copy_u8PORT){
	case GPIOA:
		GPIOA_ODR=Copy_u16Value;
		break;
	case GPIOB:
		GPIOB_ODR=Copy_u16Value;
		break;
	case GPIOC:
		GPIOC_ODR=Copy_u16Value;
		break;
	default :   break;
	}
}

void GPIO_voidLockPin(u8 Copy_u8PORT ,u8 Copy_u8PIN){
	switch (Copy_u8PORT){
	case GPIOA:
		GPIOA_LCK |= ( 1<< Copy_u8PIN);
		SET_BIT(GPIOA_LCK,16);
		CLR_BIT(GPIOA_LCK,16);
		SET_BIT(GPIOA_LCK,16);
		while(GET_BIT(GPIOA_LCK,16)!=0);
		break;
	case GPIOB:
		GPIOB_LCK |= ( 1<< Copy_u8PIN);
		SET_BIT(GPIOB_LCK,16);
		CLR_BIT(GPIOB_LCK,16);
		SET_BIT(GPIOB_LCK,16);
		while(GET_BIT(GPIOB_LCK,16)!=0);
		break;

	case GPIOC:
		GPIOC_LCK |= ( 1<< Copy_u8PIN);
		SET_BIT(GPIOC_LCK,16);
		CLR_BIT(GPIOC_LCK,16);
		SET_BIT(GPIOC_LCK,16);
		while(GET_BIT(GPIOC_LCK,16)!=0);
		break;

	}
}
u8 GPIO_voidGetPinValue(u8 Copy_u8PORT ,u8 Copy_u8PIN){
	u8 Local_u8Result=0;
	switch (Copy_u8PORT){
	case GPIOA:
		Local_u8Result=GET_BIT(GPIOA_IDR,Copy_u8PIN);
		break;
	case GPIOB:
		Local_u8Result=GET_BIT(GPIOB_IDR,Copy_u8PIN);
		break;
	case GPIOC:
		Local_u8Result=GET_BIT(GPIOC_IDR,Copy_u8PIN);
		break;
	default : break;
	}
	return Local_u8Result;
}
