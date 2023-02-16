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
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"

/* Toggle LED1 */
void task1 (void){
static u8 flag1=0;
		if(flag1 == 0){
			GPIO_voidSetPinValue(GPIOA,PIN1,PIN_HIGH);
			flag1=1;
		}
		else {
			GPIO_voidSetPinValue(GPIOA,PIN1,PIN_LOW);
						flag1=0;
		}
}
/* Toggle LED2 */
void task2 (void){
static u8 flag2=0;
		if(flag2 == 0){
			GPIO_voidSetPinValue(GPIOA,PIN2,PIN_HIGH);
			flag2=1;
		}
		else {
			GPIO_voidSetPinValue(GPIOA,PIN2,PIN_LOW);
						flag2=0;
		}
}
/* Toggle LED3 */
void task3 (void){
static u8 flag3=0;
		if(flag3 == 0){
			GPIO_voidSetPinValue(GPIOA,PIN3,PIN_HIGH);
			flag3=1;
		}
		else {
			GPIO_voidSetPinValue(GPIOA,PIN3,PIN_LOW);
						flag3=0;
		}
}
void main (void){

/* RCC intialization */
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,2);
RCC_voidEnableClock(RCC_APB2,3);
RCC_voidEnableClock(RCC_APB2,4);

/* Pin init */
GPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
GPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP); /*Red*/
GPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_10MHZ_PP); /*Green*/
GPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_10MHZ_PP); /*Blue*/
GPIO_voidSetPinValue(GPIOA,PIN1,PIN_LOW);
GPIO_voidSetPinValue(GPIOA,PIN2,PIN_LOW);
GPIO_voidSetPinValue(GPIOA,PIN3,PIN_LOW);

/* NVIC init */
MNVIC_voidEnableInterrupt(6);  /* EXTI0 : 6 */


/*SYStick init */
MSYSTICK_voidInit();   /* Enable on HSE/8 : 1 MHZ */

/* OS init */
SOS_voidCreateTask(0,1000,1000,&task1);
SOS_voidCreateTask(1,2000,3000,&task2);
SOS_voidCreateTask(2,3000,0,&task3);

SOS_voidStart();
while (1){

}

}




