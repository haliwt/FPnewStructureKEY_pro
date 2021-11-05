/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    uint8_t keyValue;
    static uint8_t tm;
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
       // Add your application code
      
       if(Adapter_DetectedGetValue() ==1){//Adapter  if not -> 1. has + battery charging
                if(led_t.switch_dev==0 ){ //Display Battery of capacity
                  if(tim0_t.tim0_noBatt_s>120 ){
                       led_t.switch_dev++;
                  }  
                        Battery_Detected(); //
                        DisplayBattery_Power_Estimate();
                   
                }
                if(tim0_t.tim0_noBatt_s>240){ //4 minute
                    tim0_t.tim0_noBatt_s=0; 
                    Battery_Detected(); //  
                  if(led_t.gbatteryQuantity ==1){//has a battery + charing     
                    DisplayBattery_Power_Estimate();
                  }
                  else{ //han't battery ->LED lamp all turn on
                      Adapter_Indicator();
                  }
                }    
        }
        else{ // hasn't adapter only battery works
         
           if(tim0_t.getMinutes15_flag ==1){ 
                led_t.minute15_flag =1;
                TurnOff_Lamp();
                  tm++;
                  if(tm<5){
                    run_t.eusartTx_flag=0;
                    run_t.eusartTx_Num=0;
                    EUSART_CommandTxData(0xff);
                  }
                  if(tm >5)tm=7;

            }
            else{
              if(led_t.switch_dev==0 ){ //Display Battery of capacity
                  if(tim0_t.tim0_noBatt_s>120 ){
                       led_t.switch_dev++;
                  }
                    Battery_Detected(); //    
                    DisplayBattery_Power_Estimate();
                
              }
              if(tim0_t.tim0_noBatt_s>180){  //180s detected battery qunantity and update LED 
                  tim0_t.tim0_noBatt_s=0;
                  Battery_Detected(); //   
                  DisplayBattery_Power_Estimate();
                 
              }
            }
            
               
         }
       if(led_t.minute15_flag ==0){
          keyValue = KEY_Scan();
          CheckMode(keyValue);
          CheckRun();
          EUSART_SetRxInterruptHandler(RxData_EUSART);
          EUSART_InputCmd_Run();
       }
    }
}
/**
 End of File
*/