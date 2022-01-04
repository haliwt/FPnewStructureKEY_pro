#include "run.h"


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
	static uint8_t powerFirst_flag=0;
    static uint8_t    	inputkey_red,inputkey_green,inputkey_blue,inputkey_white;

	switch(keyvalue){
       case 0:

	     if(!keyvalue)
		  	return ;
		break;
	   case 0x1: //KEY_WHITE
	  
	        inputkey_white = inputkey_white ^ 0x01;
	        if(inputkey_white ==1){
	            run_t.lampColor=White;
	            inputkey_green=0;
	            inputkey_blue=0;
	            inputkey_red=0;
                run_t.gWhite_key++;
	        }
	        else{
	             
	           run_t.lampColor = 0x80;  
               run_t.gPower_id++;
	        
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
                  run_t.gGreen_key++;
			}
			else{
				 run_t.lampColor = 0x80;  
                 run_t.gPower_id++;
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
                     run_t.gBlue_key++;
				}
				else{
				    run_t.lampColor = 0x80;
                    run_t.gPower_id++;
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
                     run_t.gRed_key++;
                }
                else{
				    run_t.lampColor = 0x80; 
                    run_t.gPower_id++;
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
	tim0_t.tim0_30s =0;
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
    
	static uint8_t firstflag_red=0xff,firstflag_green=0xff,firstflag_blue=0xff,firstflag_white=0xff,
	               firstflag_power;
//	static uint8_t red_id,green_id,blue_id,white_id,power_id;
	switch(run_t.lampColor){
	case 0: //turn off lamp 
		
			
	break;

    case Red: //KEY_RED
         
	      if(firstflag_red != run_t.gRed_key){
			    firstflag_red = run_t.gRed_key;
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
			}
          
           EUSART_CommandTxData(0x52);
		    DELAY_microseconds(5);
            
     break;

	case Green: //KEY_GREEN
	  if(firstflag_green !=run_t.gGreen_key){
		        firstflag_green = run_t.gGreen_key;
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
		}
		EUSART_CommandTxData(0x47);
		 DELAY_microseconds(5);
	    

	break;

	case Blue://KEY_BLUE
	    if(firstflag_blue !=run_t.gBlue_key){
			    firstflag_blue = run_t.gBlue_key;
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
        }
		
		EUSART_CommandTxData(0x42);
		 DELAY_microseconds(5);
			

	break;

	case White://KEY_WHITE
	    if(firstflag_white != run_t.gWhite_key){
			    firstflag_white = run_t.gWhite_key;
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
			
			
		 }
		
		 EUSART_CommandTxData(0x57);
		  DELAY_microseconds(5);
     
	break;


	case 0x20: //KEY_ADD "+"
	         if(run_t.ADD_flag==1){
	                run_t.ADD_flag =0;
                    run_t.eusartTx_flag=0;
				    run_t.eusartTx_Num=0;
				    
                    
               }
			
			 EUSART_BightnessTxData(0X32);
			  DELAY_microseconds(5);
            
             
    break;

	case 0x10: //KEY_SUB "-"
	    if(run_t.SUB_flag==1){
	             run_t.SUB_flag =0;
                 run_t.eusartTx_flag=0;
				 run_t.eusartTx_Num=0;
				
                    
           }
		 EUSART_BightnessTxData(0x31);
         DELAY_microseconds(5);
           
           
    break;
	
	case 0x80: //lamp off
	     if(firstflag_power !=run_t.gPower_id){
			    firstflag_power = run_t.gPower_id;
				run_t.eusartTx_flag=0;
				run_t.eusartTx_Num=0;
			
		}
		 EUSART_CommandTxData(0X3f);
         DELAY_microseconds(5);
	  
	
	break;
	
	
	default:
    

	break;
    

   }
  if(led_t.gCharging==1)
        //DisplayBattery_Power_Estimate();
    tim0_t.tim0_30s =0;
}
void EUSART_InputCmd_Run(void)
{
	if(run_t.InputOrder[0]=='W'){
		
		
	
		//TX1REG = 'W';
	}	
	else if(run_t.InputOrder[0]=='T'){
	
		 
		 // TX1REG = 'T';
		
	}
   else if(run_t.InputOrder[0]=='A'){
		
	
		
		//TX1REG = 'A';
	}
	
}
static void AdapterWorks_Status(void)
{
	 LED_100_SetLow() ;
	 LED_40_SetLow();
	 LED_60_SetLow();
     LED_80_SetLow();
	
}
	
