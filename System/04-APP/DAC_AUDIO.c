/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: SAIED
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "song.h"        //Raw Files of song inclusion

#include "GPIO_private.h"

volatile u16 i=0;      //Var to loop around each element of song.h

void voidSetDAC(void){
GPIOA_ODR = Amaren_raw[i];     //output value of GPIOA
i++;
if(i == 39660){
	/* if max value is reached start again */
	i=0;
}
}
void main (void){

/* RCC intialization */
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,2);
RCC_voidEnableClock(RCC_APB2,3);
RCC_voidEnableClock(RCC_APB2,4);

/* Pin init */
GPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);


/*SYStick init */
MSYSTICK_voidInit();   /* Enable on HSE/8 : 1 MHZ */
MSYSTICK_voidSetIntervalPeriodic(125,voidSetDAC);
while (1){

}

}




