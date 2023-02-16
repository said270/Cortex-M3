/***********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     OS Scheduler */
/* Version: V01 */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"

#include "OS_private.h"
#include "OS_interface.h"
#include "OS_config.h"

static Task OS_TASKS[NUM_OF_TASKS]={NULL};                 /* Array of Tasks (struct)*/
static volatile u16 TickCounts=0;

void SOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_16Periodicity, u16 Copy_u16FirstDelay , void (*TaskFunc)(void)){
OS_TASKS[Copy_u8Priority].Periodicity = Copy_16Periodicity;
OS_TASKS[Copy_u8Priority].ptf         = TaskFunc;
OS_TASKS[Copy_u8Priority].FirstDelay  = Copy_u16FirstDelay;
OS_TASKS[Copy_u8Priority].State       = Task_Ready;
}

void Scheduler (void){

	for (u8 i = 0 ; i < NUM_OF_TASKS ; i++){
		if (OS_TASKS[i].ptf !=NULL && OS_TASKS[i].State == Task_Ready)
		{
		if (OS_TASKS[i].FirstDelay == 0){
			OS_TASKS[i].ptf();
			OS_TASKS[i].FirstDelay=OS_TASKS[i].Periodicity;
		}
		else {
			OS_TASKS[i].FirstDelay--;
		}
	}
	else {
		/* Do nothing */
	}
	}
}

void SOS_voidStart(void){
/* Intialization */
MSYSTICK_voidInit();
/* TickTime = 1msec */
MSYSTICK_voidSetIntervalPeriodic(1000,Scheduler);
}


