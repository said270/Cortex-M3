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
#include "SPI_interface.h"

#include "TFT_interface.h"

void main (void){
	/* Variables initialization */
	u8 Hours1;
	u8 Hours2;
	u8 Secs1;
	u8 Secs2;
	u8 Mins1;
	u8 Mins2;
	u8 State;
	u8 Day;
	u8 Weekday;
	/* RCC Initialization */
		RCC_voidInitSysClock();
		RCC_voidEnableClock(RCC_APB2,2);   /* GPIOA */
		RCC_voidEnableClock(RCC_APB2,12);  /* SPI1  */

		/* Pin Initializations */
		GPIO_voidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);  /* A0   */
		GPIO_voidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);  /* RST  */
		/* Alternative Function GPIOA for SPI pins */
		GPIO_voidSetPinDirection(GPIOA,5,OUTPUT_SPEED_10MHZ_AFPP);  /* CLK  */
		GPIO_voidSetPinDirection(GPIOA,7,OUTPUT_SPEED_10MHZ_AFPP);  /* MOSI */

		/* Init STK */
		MSYSTICK_voidInit();

		/* SPI Init */
		MSPI1_voidInitTFT();

		/* TFT Init */
		HTFT_voidInit();

		/*TFT colour */
		HTFT_voidFillColour(0xABCD);
        //HTFT_voidWriteNumber(80,100,1297,0x0000);
        //HTFT_voidWriteString(80,100,"WELCVME SAIED",0x0000);
		/* Display Image */
		//HTFT_voidDisplayImage(image);

		HTFT_voidWriteString(100,140,"DIGITAL CLOCK",0x4678);
		/* Intial value for Digital Clock */
		Hours1=0;
		Hours2=8;
		Mins1=1;
		Mins2=2;
		Secs2=0;
		Secs1=0;
		State=0;
        Day=1;
        Weekday=1;
		HTFT_voidWriteString(100,140,"DIGITAL CLOCK",0x2654);
		HTFT_voidWriteString(80,100,"JANUARY",0xf123);
		HTFT_voidWriteNumber(30,100,2023,0xf123);

while (1){

// State 0 : AM state 1 :PM
MSYSTICK_voidSetBusyWait(1000000);
Secs2++;
if (Secs2 == 10){
	Secs2=0;
	Secs1++;

}
if (Secs1 == 6){
	Secs1=0;
	Mins2++;
}
if (Mins2 == 10){
	Mins2=0;
Mins1++;
}
if(Mins1 == 6){
	Mins1=0;
	Hours2++;

}
if(Hours2 == 10){
	Hours2=0;
	Hours1++;

}
if ( Hours1 == 1 && Hours2 ==2){
	Hours1 =0;
		Hours2=0;
	State=~State;

}
if(Hours1== 1 && Hours2 == 2 && State ==1){
	Day++;
	Weekday++;
}
if(Weekday==8){
	Weekday=0;
}
/* Show hours */
HTFT_voidWriteNumber(100,120,Hours1,0x0000);
HTFT_voidWriteNumber(95,120,Hours2,0x0000);
/* Show mins */
HTFT_voidWriteNumber(80,120,Mins1,0x0000);
HTFT_voidWriteNumber(75,120,Mins2,0x0000);
/* Show secs */
HTFT_voidWriteNumber(60,120,Secs1,0x0000);
HTFT_voidWriteNumber(55,120,Secs2,0x0000);
/* Show Day */
HTFT_voidWriteNumber(100,100,Day,0xf123);
/* Show weekday */
switch (Weekday)
{
	case 0 : 		HTFT_voidWriteString(80,80,"FRIDAY",0x0234); break;
	case 1 : 		HTFT_voidWriteString(80,80,"SATURDAY",0x0234); break;
	case 2 : 		HTFT_voidWriteString(80,80,"SUNDAY",0x0234); break;
	case 3 : 		HTFT_voidWriteString(80,80,"MONDAY",0x0234); break;
	case 4 : 		HTFT_voidWriteString(80,80,"TUESDAY",0x0234); break;
	case 5 : 		HTFT_voidWriteString(80,80,"WEDNESDAY",0x0234); break;
	case 6 : 		HTFT_voidWriteString(80,80,"THURSDAY",0x0234); break;

}
/*Show state */
if (State == 0){
	HTFT_voidWriteString(40,120,"AM",0x0000);
}
else {
	HTFT_voidWriteString(40,120,"PM",0x0000);
}


}
}




