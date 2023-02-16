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
#include "EXTI_interface.h"
#include "LEDMRX_interface.h"

volatile u8  startflag =0;    /* volatile caz it is changing inside interrutp */
volatile u32 u32framedata[50] ={0};
volatile u8  u8edgecount      =0;
volatile u8  data              =0;

void voidPlay(void){
	switch (data){
	case 69: GPIO_voidSetPinValue(GPIOA,PIN1,PIN_HIGH); break;
	case 70: GPIO_voidSetPinValue(GPIOA,PIN2,PIN_HIGH); break;
	}
}
void voidTakeAction(void){
	u8 i;
	data=0;
	/* checking start bit */
	if(u32framedata[0] >= 9000 && u32framedata[0] <= 15000 )
	{
		/* Valid frame */
	/* saving data we got from IR */
	for (i=0;i<8;i++){
		if (u32framedata[17+i] >= 2000 && u32framedata[17+i] <=2300){
			SET_BIT(data,i);
		}
		else {
			CLR_BIT(data,i);
		}
	}
	voidPlay();
	}

	else{
		/* not Valid frame */
	}
	/* Ready to restart frame again */
	startflag=0;
	u32framedata[0]=0;
	u8edgecount=0;
}
/*void test(void){
	GPIO_voidSetPinValue(GPIOA,PIN1,PIN_HIGH);
}*/

void voidGetFrame(void){

if (startflag==0){
	/* Start bit begins */
	/* start timer */
	MSYSTICK_voidSetIntervalSingle(1000000,&voidTakeAction);
	startflag=1;
}
else{
	u32framedata[u8edgecount]= MSYSTICK_u32GetElapsedTime();
	MSYSTICK_voidSetIntervalSingle(1000000,&voidTakeAction);
	u8edgecount++;
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

/* NVIC init */
MNVIC_voidEnableInterrupt(6);  /* EXTI0 : 6 */

/* EXTI init */
MEXTI_voidSetCallBack(EXTI0,&voidGetFrame);
MEXTI_voidInit();
MEXTI_voidSetSignalLatch(EXTI0,FALLING);
MEXTI_voidEnableEXTI(0);

/*SYStick init */
MSYSTICK_voidInit();   /* Enable on HSE/8 : 1 MHZ */

while (1){

}

}




