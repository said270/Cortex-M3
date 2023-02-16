/***********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     OS Scheduler */
/* Version: V01 */
/***********************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_16Periodicity, u16 Copy_u16FirstDelay , void (*TaskFunc)(void));
void SOS_voidStart(void);

#endif
