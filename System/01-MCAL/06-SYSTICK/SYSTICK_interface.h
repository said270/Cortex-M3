/**********************************************************************************/
/* Author : Saied Kamara
/* SWC:     SYSTICK
/* Version: V01
/***********************************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/*Applay clock choice of config file */
/*Disable Systick */
/*Disable interrupt */
void MSYSTICK_voidInit(void);

void MSYSTICK_voidSetBusyWait(u32 Copy_u32Ticks);

void MSYSTICK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (* Copy_pfNotFunc) (void));

void MSYSTICK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (* Copy_pfNotFunc) (void));

void MSYSTICK_voidStopTimer(void);

u32 MSYSTICK_u32GetElapsedTime(void);

u32 MSYSTICK_u32GetRemainingTime(void);

#endif
