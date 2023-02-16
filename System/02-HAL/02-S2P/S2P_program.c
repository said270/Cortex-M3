/***********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     S2P */
/* Version: V01 */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "S2P_interface.h"
#include "S2P_private.h"
#include "S2P_config.h"

void HS2P_voidSendSynchronus(u8 Copy_u8DataToSend){
	s8 Local_u8Counter ;
	u8 Local_u8Bit;
for (Local_u8Counter =7 ; Local_u8Counter>=0 ; Local_u8Counter--){
/* Send bit by bit starting from MSB */
Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_u8Counter);
GPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
/* Send Pulse to Shift Clock ( > 100 ns ) */
GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,PIN_HIGH);
MSYSTICK_voidSetBusyWait(1);
GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,PIN_LOW);
MSYSTICK_voidSetBusyWait(1);
}
/* Send Pulse To Storage Clock */
GPIO_voidSetPinValue(HSTP_STORE_CLOCK,PIN_HIGH);
MSYSTICK_voidSetBusyWait(1);
GPIO_voidSetPinValue(HSTP_STORE_CLOCK,PIN_LOW);
MSYSTICK_voidSetBusyWait(1);
}
