#include "led.h"

LED_T led_t;
static void LEDDispalayBattery_Power(battery_id batid);

/**************************************************************
	*
	*Function Name:void DispalayBattery_Power(uint8_t)
	*Function: display battery power qunantity
	*
	*
	*
**************************************************************/
static void LEDDispalayBattery_Power(battery_id batid)
{

      
      switch(batid){

         case battery_20://detected low votlage don't run
			
			
			    if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					LED_60_SetHigh();
					LED_80_SetHigh();
					LED_100_SetHigh();
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_100_SetLow() ;
					LED_40_SetLow();
					LED_60_SetLow();
					LED_80_SetLow();
		
				}
			
		 
		 break;

		 case battery_40: //40% battery power
		    if(led_t.gbatteryQuantity==1 &&  led_t.Ledblink_flag ==1){
				if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_40_SetLow() ;
		
				}
			}
			else{
			    LED_40_SetLow() ;
			}
			LED_60_SetHigh();
		    LED_80_SetHigh();
			LED_100_SetHigh();
         
		 break;

		 case battery_60:
			if(led_t.gbatteryQuantity==1 &&  led_t.Ledblink_flag ==1){
					if(tim0_t.tim0_falg >49){
						LED_60_SetHigh() ;
						if(tim0_t.tim0_falg >99)
							tim0_t.tim0_falg = 0;
					}
					else{
						LED_60_SetLow() ;
					
				}
			}
			else{
			    LED_60_SetLow() ;
			}
			LED_40_SetLow() ;
		
		    LED_80_SetHigh();
			LED_100_SetHigh();

		 break;

		 case battery_80:
			if(led_t.gbatteryQuantity==1 &&  led_t.Ledblink_flag ==1){
				if(tim0_t.tim0_falg >49){
					LED_80_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_80_SetLow() ;
				}
		   }
		   else{
				LED_80_SetLow() ;

		   }
			LED_40_SetLow() ;
			LED_60_SetLow();
			LED_100_SetHigh();
			
		 

		 break;

		 case battery_100: //WT.EDIT 2021.09.23
			if(led_t.gbatteryQuantity==1 &&  led_t.Ledblink_flag ==1){
				if(tim0_t.tim0_falg >49){
					LED_100_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_100_SetLow() ;
				}
		   }
		   else{
				LED_100_SetLow() ;
            }
			LED_40_SetLow() ;
			LED_60_SetLow();
			LED_80_SetLow();
			
		 break;
		 
		case battery_full:
		
		    LED_100_SetLow() ;
		    LED_40_SetLow();
			LED_60_SetLow();
		    LED_80_SetLow();
		    
		
		break;

		

		 default :
		 	 

		 break;



    }


}

/**************************************************************
	*
	*Function Name:void DispalayBattery_Power(uint8_t)
	*Function: display battery power qunantity
	*
	*
	*
**************************************************************/
void DisplayBattery_Power_Estimate(void)
{
    if(adc_t.adcValue < 35  ){ //half of battery value 37*2=7.4v
		LEDDispalayBattery_Power(20);//(battery_20);

   }
   else if(adc_t.adcValue < 37  && adc_t.adcValue >=35){ //half of battery value 37*2=7.4v
		LEDDispalayBattery_Power(40);//(battery_40);

   }
   else if(adc_t.adcValue >=37 && adc_t.adcValue <39){ // 39*2=7.8V
	   LEDDispalayBattery_Power(60);//(battery_60);

   }
   else if(adc_t.adcValue >=39 && adc_t.adcValue <41){//
		 LEDDispalayBattery_Power(80);//(battery_80);

   }
   else if(adc_t.adcValue >=41 && adc_t.adcValue < 42 ){
		 LEDDispalayBattery_Power(90);//(battery_90);

   }
   else if(adc_t.adcValue ==42){
	    LEDDispalayBattery_Power(100);//(battery_100);
	}
    else if(adc_t.adcValue >42){
	    LEDDispalayBattery_Power(110);//(battery_100);
	}
  
		
	



    
 }  
/**************************************************************
	*
	*Function Name:void Battery_Detected(void)
	*Function: To detected if has battery
	*
	*
	*
**************************************************************/
void Battery_Detected(void)
{
	ADC_Battery_ConversionValue_Voltage();
	if(adc_t.adcValue > 20 ){ //2V -> has a battery
		 
		 led_t.gbatteryQuantity =1;
		
	}
    else {
	   
       led_t.gbatteryQuantity =0;
	}
	
}

void Adapter_Indicator(void)
{
    
    LED_100_SetLow();
    LED_40_SetLow();
    LED_60_SetLow();
    LED_80_SetLow();
    
}

void TurnOff_Lamp(void)
{
	
	LED_40_SetHigh();
	LED_60_SetHigh();
	LED_80_SetHigh();
	LED_100_SetHigh();
	if(run_t.autoShutOff_flag==0){
		run_t.eusartTx_flag=0;
		run_t.eusartTx_Num=0;
		run_t.autoShutOff_flag++;
	}
	
}

