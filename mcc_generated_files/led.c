#include "led.h"

LED_T led_t;
static void ChargingBattery_BlinkPower(battery_id batid);
static void NoCharingBattery_Power(battery_id batid);
/**************************************************************
	*
	*Function Name:void DispalayBattery_Power(uint8_t)
	*Function: display battery power qunantity
	*
	*
	*
**************************************************************/
static void ChargingBattery_BlinkPower(battery_id batid)
{

      
      switch(batid){

         case battery_20://detected low votlage don't run
			
			
			    if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					
					LED_40_SetLow();
					
		
				}
            LED_60_SetHigh();
		    LED_80_SetHigh();
			LED_100_SetHigh();
			
		 
		 break;

		 case battery_40: //40% battery power
		    
				if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_40_SetLow() ;
		
				}
			
		
			LED_60_SetHigh();
		    LED_80_SetHigh();
			LED_100_SetHigh();
         
		 break;

		 case battery_60:
			
					if(tim0_t.tim0_falg >49){
						LED_60_SetHigh() ;
						if(tim0_t.tim0_falg >99)
							tim0_t.tim0_falg = 0;
					}
					else{
						LED_60_SetLow() ;
					
				}
			
			
			LED_40_SetLow() ;
		
		    LED_80_SetHigh();
			LED_100_SetHigh();

		 break;

		 case battery_80:
			
				if(tim0_t.tim0_falg >49){
					LED_80_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_80_SetLow() ;
				}
		   
		
			LED_40_SetLow() ;
			LED_60_SetLow();
            
			LED_100_SetHigh();
			
		 

		 break;

		 case battery_100: //WT.EDIT 2021.09.23
			
				if(tim0_t.tim0_falg >49){
					LED_100_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
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
static void NoCharingBattery_Power(battery_id batid)
{

      
      switch(batid){

         case battery_20://detected low votlage don't run
			
			
			    if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
	
					LED_40_SetLow();
				}
                LED_60_SetHigh();
		    LED_80_SetHigh();
			LED_100_SetHigh();
			
		 
		 break;

		 case battery_40: //40% battery power
		
			LED_40_SetLow() ;
			
			LED_60_SetHigh();
		    LED_80_SetHigh();
			LED_100_SetHigh();
         
		 break;

		 case battery_60:
		
			LED_60_SetLow() ;
			
			LED_40_SetLow() ;
		
		    LED_80_SetHigh();
			LED_100_SetHigh();

		 break;

		 case battery_80:

		    LED_80_SetLow() ;

		   
			LED_40_SetLow() ;
			LED_60_SetLow();
			LED_100_SetHigh();
			
		 

		 break;

		 case battery_100: //WT.EDIT 2021.09.23
		
		
		    LED_100_SetLow() ;
            
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
void CharingBattery_Power_Blink(void)//void DisplayBattery_Power_Estimate(void)
{
    if(adc_t.adcValue < 35  ){ //half of battery value 37*2=7.4v
	   ChargingBattery_BlinkPower(20);//(battery_20);
      
   }
   else if(adc_t.adcValue < 37  && adc_t.adcValue >=35){ //half of battery value 37*2=7.4v
		ChargingBattery_BlinkPower(40);//(battery_40);

   }
   else if(adc_t.adcValue >=37 && adc_t.adcValue <39){ // 39*2=7.8V
	   ChargingBattery_BlinkPower(60);//(battery_60);

   }
   else if(adc_t.adcValue >=39 && adc_t.adcValue <41){//
		 ChargingBattery_BlinkPower(80);//(battery_80);

   }
   else if(adc_t.adcValue >=41 && adc_t.adcValue < 42 ){
		 ChargingBattery_BlinkPower(90);//(battery_90);

   }
   else if(adc_t.adcValue ==42){
	    ChargingBattery_BlinkPower(100);//(battery_100);
	}
    else if(adc_t.adcValue >42){
	    ChargingBattery_BlinkPower(110);//(battery_100);
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
void NoCharingBattery_Estimate(void)
{
     if(adc_t.adcValue < 35  ){ //half of battery value 37*2=7.4v
          NoCharingBattery_Power(20);
   }
   else if(adc_t.adcValue < 37  && adc_t.adcValue >=35){ //half of battery value 37*2=7.4v
        NoCharingBattery_Power(40);

   }
   else if(adc_t.adcValue >=37 && adc_t.adcValue <39){ // 39*2=7.8V
	    NoCharingBattery_Power(60); //(battery_60);

   }
   else if(adc_t.adcValue >=39 && adc_t.adcValue <41){//
		
        NoCharingBattery_Power(80);
   }
   else if(adc_t.adcValue >=41 && adc_t.adcValue < 42 ){
		
         NoCharingBattery_Power(90);
   }
   else if(adc_t.adcValue ==42){
	  
        NoCharingBattery_Power(100);
	}
    else if(adc_t.adcValue >42){
	  
         NoCharingBattery_Power(110);
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
    if(adc_t.adcValue>41 && adc_t.adcValue<43){
          led_t.gbatteryQuantity =0;
    }
	else if((adc_t.adcValue > 30) || (adc_t.adcValue <= 25 && adc_t.adcValue >15)){ //5V -> has a 5V adapter don't have PD protocol
		 
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

