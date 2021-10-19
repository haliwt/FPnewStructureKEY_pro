#include "run.h"

static void ChargingBattery_Status(void);
static void AdapterWorks_Status(void);
/***************************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: The first input LED ON,the second input key LED OFF
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
****************************************************************************/
void CheckMode(uint8_t keyvalue)
{
	static uint16_t i=0;
    static uint8_t    	inputkey_red,inputkey_green,inputkey_blue,inputkey_white;

	switch(keyvalue){
       case 0:

	     if(!keyvalue)
		  	return ;
		  
		
	   break;
	   
	   case 0x40: //POWER ON and off
	            run_t.Power_On=0;
				run_t.lampColor = 0x40;
				 run_t.eusartTx_flag=0;
		         run_t.eusartTx_Num=0;	
					
	  break;
   
	  case 0x1: //KEY_WHITE
	  
	        inputkey_white = inputkey_white ^ 0x01;
	        if(inputkey_white ==1){
	            run_t.lampColor=White;
	            inputkey_green=0;
	            inputkey_blue=0;
	             inputkey_red=0;
	        }
	        else{
	             
	           run_t.lampColor = 0x80;   
	        
	        }
            DELAY_microseconds(10) ;
			    
	  break;
   
	   case 0x02: //KEY_GREEN
	        inputkey_green = inputkey_green ^ 0x01;
	        if(inputkey_green ==1){
			     run_t.lampColor = Green;
			     inputkey_white=0;
			     inputkey_blue=0;
			      inputkey_red=0;
			}
			else{
				 run_t.lampColor = 0x80;   
			}
			DELAY_microseconds(10) ;
			 
	  break;
   
	   case 0x04://KEY_BLUE
	            inputkey_blue = inputkey_blue ^ 0x01;
	            if(inputkey_blue==1){
				     run_t.lampColor = Blue;
				     inputkey_white=0;
				     inputkey_green=0;
				     inputkey_red=0;
				}
				else{
				    run_t.lampColor = 0x80;   
			    }
			    
				DELAY_microseconds(10) ;
   
	   break;
   
	   case 0x08://KEY_RED
		         inputkey_red= inputkey_red ^ 0x01;
		        if(inputkey_red==1){
                     run_t.lampColor = Red;
                     inputkey_blue=0;
                     inputkey_white=0;
				     inputkey_green=0;
                }
                else{
				    run_t.lampColor = 0x80;   
			     }
				DELAY_microseconds(10) ;
	  break;
   
   
	   case 0x10: //KEY_ADD "-"
         
	      run_t.lampColor = 0x10;
	      run_t.ADD_flag = 1;
		  run_t.eusartTx_flag=0;
		  run_t.eusartTx_Num=0;
   
	   break;
   
	   case 0x20: //KEY_SUB "+"
	    
          run_t.lampColor = 0x20 ;
          run_t.SUB_flag =1;
		  run_t.eusartTx_flag=0;
		  run_t.eusartTx_Num=0;
   
	   break;
	   
   
	   default:
   
   				
	   break;
   }
}
/**************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: 
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
**************************************************************/
void CheckRun(void)
{
    static uint8_t firstflag;
	switch(run_t.lampColor){
	case 0: //turn off lamp 
		
			
	break;

    case Red: //KEY_RED
        
	      if(firstflag==0 || firstflag ==4 || firstflag ==2||firstflag ==3||firstflag==5){
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
				firstflag =1;
			}
           
            EUSART_TxData(0x52);
            
     break;

	case Green: //KEY_GREEN
	  if(firstflag==0 || firstflag ==1 || firstflag ==4||firstflag ==3||firstflag==5){
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
				firstflag =2;
		}
		 EUSART_TxData(0x47);
	    

	break;

	case Blue://KEY_BLUE
	    if(firstflag==0 || firstflag ==1 || firstflag ==2 ||firstflag==4||firstflag==5){
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
				firstflag =3;
		}
		 EUSART_TxData(0x42);

	break;

	case White://KEY_WHITE
	    if(firstflag==0 || firstflag ==1 || firstflag ==2||firstflag ==3||firstflag==5){
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
				firstflag =4;
		 }
		 EUSART_TxData(0x57);
     
	break;


	case 0x20: //KEY_ADD "+"
	         if(run_t.ADD_flag==1){
	                run_t.ADD_flag =0;
                    run_t.eusartTx_flag=0;
				    run_t.eusartTx_Num=0;
				    
                    
               }
			 DELAY_microseconds(5);
			 EUSART_TxData(0X20);
               firstflag=0;
             
               
	      

	break;

	case 0x10: //KEY_SUB "-"
	    if(run_t.SUB_flag==1){
	             run_t.SUB_flag =0;
                 run_t.eusartTx_flag=0;
				 run_t.eusartTx_Num=0;
				
                    
           }
		 EUSART_TxData(0X10);
         DELAY_microseconds(5);
           firstflag=0;
           
              
         
		
	break;
	
	case 0x80: //lamp off
	     if(firstflag==0 || firstflag ==1 || firstflag ==2||firstflag ==3||firstflag==4){
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
				
				firstflag =5;
		 }
		 EUSART_TxData(0X3f);
         DELAY_microseconds(10);
	  
	
	break;
	
	case 0x40: //power off
	    if(firstflag==0 || firstflag ==1 || firstflag ==2||firstflag ==3||firstflag==4||firstflag==5){
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
				firstflag =6;
		 }
		 TxData_PowerOff();
	
	break;
	
	default:
    

	break;

   }

}
void EUSART_InputCmd_Run(void)
{
	

	if(run_t.InputOrder[0]=='W'){
		
		ChargingBattery_Status();
		//TX1REG = 'W';
	}	
	else if(run_t.InputOrder[0]=='T'){
		  ChargingBattery_Status();
		 // TX1REG = 'T';
		
	}
   else if(run_t.InputOrder[0]=='A'){
		
		AdapterWorks_Status();
		//TX1REG = 'A';
	}
	
}

static void ChargingBattery_Status(void)
{
	switch(run_t.InputOrder[1]){

         case 0x1://detected low votlage don't run
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

		 case 0x2: //60% battery power
		    if(run_t.batteryStatus==2){
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

		 case 0x3://80%
			 if(run_t.batteryStatus==2){
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

		 case 0x4: //90%
			 if(run_t.batteryStatus==2){
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

		 case 0X5: //100% WT.EDIT 2021.09.23
			 if(run_t.batteryStatus==2){
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
		 
		case 0x6:
		
		    LED_100_SetLow() ;
		    LED_40_SetLow();
			LED_60_SetLow();
		    LED_80_SetLow();
		    
		
		break;

		

		 default :
		 	 

		 break;



    }
	
	
}
static void AdapterWorks_Status(void)
{
	 LED_100_SetLow() ;
	 LED_40_SetLow();
	 LED_60_SetLow();
     LED_80_SetLow();
	
}
	
