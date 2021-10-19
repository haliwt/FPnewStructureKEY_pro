#ifndef __LED_H__
#define __LED_H__
#include "mcc.h"

#define LED_40_SetHigh()            do { LATBbits.LATB0 = 1; } while(0) //LED1 
#define LED_40_SetLow()             do { LATBbits.LATB0 = 0; } while(0)


#define LED_60_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)  //LED2
#define LED_60_SetLow()             do { LATBbits.LATB1 = 0; } while(0)

#define LED_80_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)  //LED3
#define LED_80_SetLow()             do { LATBbits.LATB2 = 0; } while(0)

#define LED_100_SetHigh()            do { LATBbits.LATB3 = 1; } while(0) //LED4
#define LED_100_SetLow()             do { LATBbits.LATB3 = 0; } while(0)



//#define MP3428A_DISABLE_SetHigh()           do { LATCbits.LATC3 = 1; } while(0)
//#define MP3428A_ENABLE_SetLow()             do { LATCbits.LATC3 = 0; } while(0)

typedef enum{

    battery_20,
	battery_40,  //
	battery_60,
	battery_80,
	battery_100,
	battery_full

}battery_id;














#endif 