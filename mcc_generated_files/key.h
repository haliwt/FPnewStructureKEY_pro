#ifndef __KEY_H__
#define __KEY_H__

#include "mcc.h"

//#define IO_RA0_GetValue()           PORTAbits.RA0
#define KEY_RED()    				PORTAbits.RA0
#define KEY_GREEN()					PORTAbits.RA1
#define KEY_BLUE()					PORTAbits.RA2
#define KEY_WHITE()					PORTAbits.RA3
#define KEY_ADD()					PORTAbits.RA4
#define KEY_SUB()					PORTAbits.RA5
#define KEY_POWER()                 PORTAbits.RA6  //POWER -KEY INPUT-new PCB

uint8_t   KEY_Scan(void);






#endif 