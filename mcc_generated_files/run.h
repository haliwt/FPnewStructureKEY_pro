#ifndef __RUN_H__
#define __RUN_H__
#include "../mcc_generated_files/mcc.h"
#include"delay.h"


typedef struct {

   uint8_t lampColor;
   uint8_t Power_On ;
   uint8_t eusartTx_Num;
   uint8_t eusartTx_flag;
   uint8_t ADD_flag;
   uint8_t SUB_flag;
   uint8_t batteryStatus;
   uint8_t autoShutOff_flag;
   uint8_t InputOrder[2];
 }RUN_T;

RUN_T run_t;

typedef enum{

    noColor,
	Red = 0x52,
	Green=0x47,
	Blue=0x42,
	White=0x57

}Color;

void CheckMode(uint8_t value);
void CheckRun(void);
void EUSART_InputCmd_Run(void);







#endif 