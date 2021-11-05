/**
  EUSART Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart.c

  @Summary
    This is the generated driver implementation file for the EUSART driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for EUSART.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K40
        Driver Version    :  2.1.1
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45
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

/**
  Section: Included Files
*/
#include "eusart.h"

/**
  Section: Macro Declarations
*/

#define EUSART_TX_BUFFER_SIZE 8
#define EUSART_RX_BUFFER_SIZE 8
#define MAX_LIGHT_NUMBER      8


/**
  Section: Global Variables
*/
volatile uint8_t eusartTxHead = 0;
volatile uint8_t eusartTxTail = 0;
volatile uint8_t eusartTxBuffer[EUSART_TX_BUFFER_SIZE];
volatile uint8_t eusartTxBufferRemaining;

volatile uint8_t eusartRxHead = 0;
volatile uint8_t eusartRxTail = 0;
volatile uint8_t eusartRxBuffer[EUSART_RX_BUFFER_SIZE];
volatile eusart_status_t eusartRxStatusBuffer[EUSART_RX_BUFFER_SIZE];
volatile uint8_t eusartRxCount;
volatile eusart_status_t eusartRxLastError;
volatile uint8_t outputBuf[EUSART_TX_BUFFER_SIZE];
volatile uint8_t transOngoingFlag;
static uint8_t inputBuf[4];
static uint8_t InputCmd[2];

/**
  Section: EUSART APIs
*/
void (*EUSART_TxDefaultInterruptHandler)(void);
void (*EUSART_RxDefaultInterruptHandler)(void);

void (*EUSART_FramingErrorHandler)(void);
void (*EUSART_OverrunErrorHandler)(void);
void (*EUSART_ErrorHandler)(void);

void EUSART_DefaultFramingErrorHandler(void);
void EUSART_DefaultOverrunErrorHandler(void);
void EUSART_DefaultErrorHandler(void);

void EUSART_Initialize(void)
{
    // disable interrupts before changing states
    PIE3bits.RCIE = 0;
    EUSART_SetRxInterruptHandler(EUSART_Receive_ISR);
    PIE3bits.TXIE = 0;
    EUSART_SetTxInterruptHandler(EUSART_Transmit_ISR);
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUD1CON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RC1STA = 0x90;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TX1STA = 0x24;

    // SP1BRGL 207; 
    SP1BRGL = 0xCF;

    // SP1BRGH 0; 
    SP1BRGH = 0x00;


    EUSART_SetFramingErrorHandler(EUSART_DefaultFramingErrorHandler);
    EUSART_SetOverrunErrorHandler(EUSART_DefaultOverrunErrorHandler);
    EUSART_SetErrorHandler(EUSART_DefaultErrorHandler);

    eusartRxLastError.status = 0;

    // initializing the driver state
    eusartTxHead = 0;
    eusartTxTail = 0;
    eusartTxBufferRemaining = sizeof(eusartTxBuffer);

    eusartRxHead = 0;
    eusartRxTail = 0;
    eusartRxCount = 0;

    // enable receive interrupt
    PIE3bits.RCIE = 1;
}

bool EUSART_is_tx_ready(void)
{
    return (eusartTxBufferRemaining ? true : false);
}

bool EUSART_is_rx_ready(void)
{
    return (eusartRxCount ? true : false);
}

bool EUSART_is_tx_done(void)
{
    return TX1STAbits.TRMT;
}

eusart_status_t EUSART_get_last_status(void){
    return eusartRxLastError;
}

uint8_t EUSART_Read(void)
{
    uint8_t readValue  = 0;
    
    while(0 == eusartRxCount)
    {
    }

    eusartRxLastError = eusartRxStatusBuffer[eusartRxTail];

    readValue = eusartRxBuffer[eusartRxTail++];
    if(sizeof(eusartRxBuffer) <= eusartRxTail)
    {
        eusartRxTail = 0;
    }
    PIE3bits.RCIE = 0;
    eusartRxCount--;
    PIE3bits.RCIE = 1;

    return readValue;
}

void EUSART_Write(uint8_t txData)
{
    while(0 == eusartTxBufferRemaining)
    {
    }

    if(0 == PIE3bits.TXIE)
    {
        TX1REG = txData;
    }
    else
    {
        PIE3bits.TXIE = 0;
        eusartTxBuffer[eusartTxHead++] = txData;
        if(sizeof(eusartTxBuffer) <= eusartTxHead)
        {
            eusartTxHead = 0;
        }
        eusartTxBufferRemaining--;
    }
    PIE3bits.TXIE = 1;
}


void EUSART_Transmit_ISR(void)
{

    // add your EUSART interrupt custom code
    if(sizeof(eusartTxBuffer) > eusartTxBufferRemaining)
    {
        TX1REG = eusartTxBuffer[eusartTxTail++];
        if(sizeof(eusartTxBuffer) <= eusartTxTail)
        {
            eusartTxTail = 0;
        }
        eusartTxBufferRemaining++;
    }
    else
    {
        PIE3bits.TXIE = 0;
    }
}

void EUSART_Receive_ISR(void)
{
    
    eusartRxStatusBuffer[eusartRxHead].status = 0;

    if(RC1STAbits.FERR){
        eusartRxStatusBuffer[eusartRxHead].ferr = 1;
        EUSART_FramingErrorHandler();
    }

    if(RC1STAbits.OERR){
        eusartRxStatusBuffer[eusartRxHead].oerr = 1;
        EUSART_OverrunErrorHandler();
    }
    
    if(eusartRxStatusBuffer[eusartRxHead].status){
        EUSART_ErrorHandler();
    } else {
        EUSART_RxDataHandler();
    }
    
    // or set custom function using EUSART_SetRxInterruptHandler()
}

void EUSART_RxDataHandler(void){
    // use this default receive interrupt handler code
    eusartRxBuffer[eusartRxHead++] = RC1REG;
    if(sizeof(eusartRxBuffer) <= eusartRxHead)
    {
        eusartRxHead = 0;
    }
    eusartRxCount++;
}

void EUSART_DefaultFramingErrorHandler(void){}

void EUSART_DefaultOverrunErrorHandler(void){
    // EUSART error - restart

    RC1STAbits.CREN = 0;
    RC1STAbits.CREN = 1;

}

void EUSART_DefaultErrorHandler(void){
    EUSART_RxDataHandler();
}

void EUSART_SetFramingErrorHandler(void (* interruptHandler)(void)){
    EUSART_FramingErrorHandler = interruptHandler;
}

void EUSART_SetOverrunErrorHandler(void (* interruptHandler)(void)){
    EUSART_OverrunErrorHandler = interruptHandler;
}

void EUSART_SetErrorHandler(void (* interruptHandler)(void)){
    EUSART_ErrorHandler = interruptHandler;
}

void EUSART_SetTxInterruptHandler(void (* interruptHandler)(void)){
    EUSART_TxDefaultInterruptHandler = interruptHandler;
}

void EUSART_SetRxInterruptHandler(void (* interruptHandler)(void)){
    EUSART_RxDefaultInterruptHandler = interruptHandler;
}
/******************************************************************************
 * 
 *Function Name: EUSART_TxData(uint8_t index) 
 * 
 * 
 *****************************************************************************/
void EUSART_CommandTxData(uint8_t index)
{
   

	outputBuf[0]='F'; //0x46
	outputBuf[1]='P'; //0x50
    outputBuf[2]='O'; //0x4F ->order
	outputBuf[3]=index; 
//	outputBuf[3]=index+0x30;	// change to ascii number for decimal number 0~9
   if(run_t.eusartTx_flag ==0){
   	   PIE3bits.TXIE=0;
      if(transOngoingFlag==0){
            TX1REG = outputBuf[run_t.eusartTx_Num];
	        run_t.eusartTx_Num++;
            
       }
	   transOngoingFlag=1;
	   if(run_t.eusartTx_Num==4)run_t.eusartTx_flag=1;
	    PIE3bits.TXIE=1;
   	}
   
}
/******************************************************************************
 * 
 *Function Name: void TxData_PowerOff(void)
 * 
 * 
 *****************************************************************************/
void  EUSART_BightnessTxData(uint8_t index)
{
  
	outputBuf[0]='F'; //0x46
	outputBuf[1]='P'; //0x50
    outputBuf[2]='B'; //0X42 -> brightness
    outputBuf[3]=index;
	
   if(run_t.eusartTx_flag ==0){
   	   PIE3bits.TXIE=0;
      if(transOngoingFlag==0){
            TX1REG = outputBuf[run_t.eusartTx_Num];
	        run_t.eusartTx_Num++;
            
       }
	   transOngoingFlag=1;
	   if(run_t.eusartTx_Num==4)run_t.eusartTx_flag=1;
	    PIE3bits.TXIE=1;
   	}

}
/*****************************************************
 * 
 *Function Name: void RxData_EUSART(void)
 *Receive Interrupt EUSART of data
 *
 *
*****************************************************/
void RxData_EUSART(void)
{
    static uint8_t i;
    PIE3bits.RC1IE = 0;
        
        
        inputBuf[i]=RC1REG;
        PIE3bits.TX1IE = 0;
		if(i==0){
			
			if(inputBuf[0]=='B'){ //0X42
	            // TX1REG = inputBuf[0];//recdata[i]; // ???????? // ??
                 
			}
			else i=0;
		}
		else if(i==1){
            
	        if(inputBuf[1]=='A'){ //0X41
	           //  TX1REG = inputBuf[1];//recdata[i]; // ???????? // ??
            }
            else i=0;
		}
        else if(i==2){
            if(inputBuf[2]=='T'){ //0X54
	           //  TX1REG = inputBuf[1];//recdata[i]; // ???????? // ??
            }
            else i=0;
            
        }
		else if(i==3){
            if(inputBuf[2]=='W'){ //0X57//battery
	           //  TX1REG = inputBuf[1];//recdata[i]; // ???????? // ??
                run_t.InputOrder[0]=inputBuf[3];
                run_t.batteryStatus = 0;
            }
            else if(inputBuf[2]=='T'){//0X54 //battery + adapter
                 run_t.InputOrder[0]=inputBuf[3];
                 run_t.batteryStatus =1 ;
            }
            else if(inputBuf[2]=='A'){ //0X41//adapter
                 run_t.InputOrder[0]=inputBuf[3];
            }
            else i=0;
	            // TX1REG = inputBuf[2];//recdata[i]; // ???????? // ??
            
        }
        else if(i==4){
            
            run_t.InputOrder[1]=inputBuf[4]-0x30;
            
        }
	    i++;
		if(i==5)i=0;
        
     PIE3bits.RC1IE = 1; 
     PIE3bits.TX1IE = 1;
      
    
    
}
/**
  End of File
*/
