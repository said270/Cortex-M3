/***********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     OS Scheduler */
/* Version: V01 */
/***********************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct {
u16 Periodicity ;
u16 FirstDelay  ;
u8  State       ;
void (* ptf)(void);

}Task;

#define Task_Ready       1
#define Task_Suspended   2
#endif
