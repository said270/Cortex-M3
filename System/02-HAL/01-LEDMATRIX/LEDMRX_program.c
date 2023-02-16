/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     LEDMATRIX */
/* Version: V01  */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEDMRX_config.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

static void DisableALLCols(void){
	GPIO_voidSetPinValue(LEDMRX_COLUMN0_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN2_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN3_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN4_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN5_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN6_PIN,PIN_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN7_PIN,PIN_HIGH);
}

static void SetRowValues(u8 Copy_u8Data){
	u8 Local_u8BIT;

	Local_u8BIT=GET_BIT(Copy_u8Data,0);
	GPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,1);
	GPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,2);
	GPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,3);
	GPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,4);
	GPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,5);
	GPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,6);
	GPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8BIT);

	Local_u8BIT=GET_BIT(Copy_u8Data,7);
	GPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8BIT);
}

void HLEDMRX_voidInit(void){
	GPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinDirection(LEDMRX_COLUMN0_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN1_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN2_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN3_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN4_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN5_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN6_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN7_PIN,OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMRX_voidDisplay(u8 * Copy_u8Data){

	/* Disable all columns */
	DisableALLCols();

	/*Enable Column 0*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[0]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN0_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec


	/*Enable Column 1*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[1]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

	/*Enable Column 2*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[2]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN2_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

	/*Enable Column 3*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[3]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN3_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

	/*Enable Column 4*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[4]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN4_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

	/*Enable Column 5*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[5]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN5_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

	/*Enable Column 6*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[6]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN6_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

	/*Enable Column 7*/
	DisableALLCols();
	SetRowValues(Copy_u8Data[7]);
	GPIO_voidSetPinValue(LEDMRX_COLUMN7_PIN,PIN_LOW);
	MSYSTICK_voidSetBusyWait(2500); //2.5msec

}

