/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     TFT */
/* Version: V01  */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TFT_config.h"
#include "TFT_interface.h"
#include "TFT_private.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

static u16 TFT_FillColour;
void HTFT_voidInit(void){
	/* Reset Pulse */
	GPIO_voidSetPinValue(TFT_RST_PIN,PIN_HIGH);
	MSYSTICK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(TFT_RST_PIN,PIN_HIGH);
	MSYSTICK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,PIN_HIGH);
	MSYSTICK_voidSetBusyWait(120000);
	/* Send SleepOut command */
	voidWriteCommand(0x11);
	MSYSTICK_voidSetBusyWait(150000);
	/*Colour mode command */
	voidWriteCommand(0x3A);
	voidWriteData(0x05);   //RGB64K
	/*Display ON */
	voidWriteCommand(0x29);
}


void HTFT_voidDisplayImage(const u16 * Copy_pu16Image){
	u16 Counter ;
	/* Set x Address */
	voidWriteCommand(0x2A);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(0);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(127);

	/* Set y Address */
	voidWriteCommand(0x2B);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(0);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(159);

	/* RAM write command */
	voidWriteCommand(0x2C);
for (Counter=0 ; Counter <20480 ; Counter++){
	/* write high of image */
voidWriteData(Copy_pu16Image[Counter] >> 8);
/*write low of image */
voidWriteData(Copy_pu16Image[Counter] &0x00ff);
}

}

void HTFT_voidFillColour(u16 Copy_u16Colour){
	u16 Counter ;
	TFT_FillColour=Copy_u16Colour;
	/* Set x Address */
	voidWriteCommand(0x2A);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(0);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(127);

	/* Set y Address */
	voidWriteCommand(0x2B);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(0);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(159);

	/* RAM write command */
	voidWriteCommand(0x2C);
for (Counter=0 ; Counter <20480 ; Counter++){
	/* write high of image */
voidWriteData(Copy_u16Colour >> 8);
/*write low of image */
voidWriteData(Copy_u16Colour &0x00ff);
}

}
void HTFT_voidWriteChar(u8 Copy_u8x , u8 Copy_u8y ,u8 Copy_u8Char,u16 Copy_u16Colour){
	u16 Counter ;
	u16 Size = 35;
	/* Set x Address */
	voidWriteCommand(0x2A);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8x);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8x+4);

	/* Set y Address */
	voidWriteCommand(0x2B);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8y);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8y+6);

	/* RAM write command */
	voidWriteCommand(0x2C);
for (Counter=0 ; Counter < Size ; Counter++){
	if (Copy_u8Char == ' '){
		/* write high of image */
				voidWriteData(TFT_FillColour >> 8);
				/*write low of image */
				voidWriteData(TFT_FillColour &0x00ff);
	}
	else{
	if (Characters[Copy_u8Char-65][Counter] == 1){
	/* write high of image */
voidWriteData(Copy_u16Colour >> 8);
/*write low of image */
voidWriteData(Copy_u16Colour &0x00ff);
	}
	else{
		/* write high of image */
		voidWriteData(TFT_FillColour >> 8);
		/*write low of image */
		voidWriteData(TFT_FillColour &0x00ff);
	}
	}
}

}

void HTFT_voidDrawRect(u8 Copy_u8x1 , u8 Copy_u8x2 , u8 Copy_u8y1 , u8 Copy_u8y2 ,u16 Copy_u16Colour){
	u16 Counter ;
	u16 Size = (Copy_u8x2 - Copy_u8x1) * (Copy_u8y2 - Copy_u8y1);
	/* Set x Address */
	voidWriteCommand(0x2A);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8x1);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8x2);

	/* Set y Address */
	voidWriteCommand(0x2B);
	/*Start 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8y1);
	/*End 2 bytes */
	voidWriteData(0);
	voidWriteData(Copy_u8y2);

	/* RAM write command */
	voidWriteCommand(0x2C);
for (Counter=0 ; Counter < Size ; Counter++){
	/* write high of image */
voidWriteData(Copy_u16Colour >> 8);
/*write low of image */
voidWriteData(Copy_u16Colour &0x00ff);
}

}

void HTFT_voidWriteString(u8 Copy_u8x , u8 Copy_u8y ,u8 *Copy_u8String,u16 Copy_u16Colour){
u8 X_Counter = Copy_u8x;
u8 Counter=0;
while ( Copy_u8String[Counter] != '\0')
{
HTFT_voidWriteChar(X_Counter,Copy_u8y,Copy_u8String[Counter],Copy_u16Colour);
X_Counter=X_Counter-5;
Counter++;
}
}

void HTFT_voidWriteNumber(u8 Copy_u8x , u8 Copy_u8y ,u16 Copy_u16Number,u16 Copy_u16Colour){
u8 Digit;
u8 ArrayofNumers[10];
s8 NumCounter=0;
u8 Counter =0;
u16 Size = 35;

do{
	Digit=Copy_u16Number%10;
	Copy_u16Number=Copy_u16Number/10;
	ArrayofNumers[NumCounter]=Digit;
	NumCounter++;
}while(Copy_u16Number != 0 );


for (s8 i = NumCounter-1 ; i >= 0 ;i--)
{
	/* Set x Address */
		voidWriteCommand(0x2A);
		/*Start 2 bytes */
		voidWriteData(0);
		voidWriteData(Copy_u8x);
		/*End 2 bytes */
		voidWriteData(0);
		voidWriteData(Copy_u8x+4);

		/* Set y Address */
		voidWriteCommand(0x2B);
		/*Start 2 bytes */
		voidWriteData(0);
		voidWriteData(Copy_u8y);
		/*End 2 bytes */
		voidWriteData(0);
		voidWriteData(Copy_u8y+6);

		/* RAM write command */
		voidWriteCommand(0x2C);

for (Counter=0 ; Counter < Size ; Counter++){
	if (Numbers[ArrayofNumers[i]][Counter] == 1){
	/* write high of image */
voidWriteData(Copy_u16Colour >> 8);
/*write low of image */
voidWriteData(Copy_u16Colour &0x00ff);
	}
	else {
		/* write high of image */
				voidWriteData(TFT_FillColour >> 8);
				/*write low of image */
				voidWriteData(TFT_FillColour &0x00ff);
	}
}
Copy_u8x=Copy_u8x-5;
}
}




static voidWriteCommand(u8 Copy_u8Command){
	u8 Local_u8Temp;
	/* Set A0 pin to low */
	GPIO_voidSetPinValue(TFT_A0_PIN,PIN_LOW);
	/* Send Command over SPI */
	MSPI1_voidSendReciveSynchronus(Copy_u8Command,&Local_u8Temp);
}
static  voidWriteData(u8 Copy_u8Data){
	u8 Local_u8Temp;
	/* Set A0 pin to HIGH */
	GPIO_voidSetPinValue(TFT_A0_PIN,PIN_HIGH);
	MSPI1_voidSendReciveSynchronus(Copy_u8Data,&Local_u8Temp);
}
