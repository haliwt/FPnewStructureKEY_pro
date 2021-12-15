#ifndef __LED_H__
#define __LED_H__
#include "mcc.h"


#define Adapter_DetectedGetValue() 		   PORTCbits.RC4   //detected Adpdate if not

#define LED_40_SetHigh()            do { LATCbits.LATC3 = 1; } while(0) //LED1 
#define LED_40_SetLow()             do { LATCbits.LATC3 = 0; } while(0)


#define LED_60_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)  //LED2
#define LED_60_SetLow()             do { LATCbits.LATC2 = 0; } while(0)

#define LED_80_SetHigh()            do { LATCbits.LATC1 = 1; } while(0) //LED3
#define LED_80_SetLow()             do { LATCbits.LATC1 = 0; } while(0)

#define LED_100_SetHigh()            do { LATCbits.LATC0 = 1; } while(0) //LED4
#define LED_100_SetLow()             do { LATCbits.LATC0 = 0; } while(0)



//#define MP3428A_DISABLE_SetHigh()           do { LATCbits.LATC3 = 1; } while(0)
//#define MP3428A_ENABLE_SetLow()             do { LATCbits.LATC3 = 0; } while(0)

typedef enum{

    battery_20=20,
	battery_40=40,  //
	battery_60=60,
	battery_80=80,
	battery_100=100,
	battery_full=110

}battery_id;

typedef struct{

   uint8_t minute15_flag;
   uint8_t gbatteryQuantity;   //0 -> charging battery , 1-> don't chanrging battery
   uint8_t Power_On;
   uint8_t switch_dev; //0 -> has battery  1-> han't battery
   uint8_t Ledblink_flag;
	
}LED_T;

extern LED_T led_t;
	
void DisplayBattery_Power_Estimate(void);

void LowVotalge_Detected(void);

void BatteryWorks_QuantiyStatus(uint8_t);

//void (*BatteryQuantiy)(uint8_t);

void Battery_Detected(void);

void Adapter_Indicator(void);

void TurnOff_Lamp(void);
void NoCharingBattery_Estimate(void);





#endif 