/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     EXTI */
/* Version: V01  */
/***********************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Line Options */
#define EXTI0     0
#define EXTI1     1
#define EXTI2     2
#define EXTI3     3
#define EXTI4     4

#define RISING    0
#define FALLING   1
#define ONCHANGE  2

void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);

void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

void MEXTI_voidSwTrigger(u8 Copy_u8Line);

void MEXTI_voidSetCallBack(u8 Copy_u8Line ,void (* Copy_pfCallBackFunc)(void));

#endif
