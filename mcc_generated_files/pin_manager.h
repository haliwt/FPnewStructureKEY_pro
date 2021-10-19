/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K40
        Driver Version    :  2.11
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set KEY_R aliases
#define KEY_R_TRIS                 TRISAbits.TRISA0
#define KEY_R_LAT                  LATAbits.LATA0
#define KEY_R_PORT                 PORTAbits.RA0
#define KEY_R_WPU                  WPUAbits.WPUA0
#define KEY_R_OD                   ODCONAbits.ODCA0
#define KEY_R_ANS                  ANSELAbits.ANSELA0
#define KEY_R_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define KEY_R_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define KEY_R_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define KEY_R_GetValue()           PORTAbits.RA0
#define KEY_R_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define KEY_R_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define KEY_R_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define KEY_R_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define KEY_R_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define KEY_R_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define KEY_R_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define KEY_R_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set KEY_G aliases
#define KEY_G_TRIS                 TRISAbits.TRISA1
#define KEY_G_LAT                  LATAbits.LATA1
#define KEY_G_PORT                 PORTAbits.RA1
#define KEY_G_WPU                  WPUAbits.WPUA1
#define KEY_G_OD                   ODCONAbits.ODCA1
#define KEY_G_ANS                  ANSELAbits.ANSELA1
#define KEY_G_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define KEY_G_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define KEY_G_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define KEY_G_GetValue()           PORTAbits.RA1
#define KEY_G_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define KEY_G_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define KEY_G_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define KEY_G_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define KEY_G_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define KEY_G_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define KEY_G_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define KEY_G_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set KEY_B aliases
#define KEY_B_TRIS                 TRISAbits.TRISA2
#define KEY_B_LAT                  LATAbits.LATA2
#define KEY_B_PORT                 PORTAbits.RA2
#define KEY_B_WPU                  WPUAbits.WPUA2
#define KEY_B_OD                   ODCONAbits.ODCA2
#define KEY_B_ANS                  ANSELAbits.ANSELA2
#define KEY_B_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define KEY_B_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define KEY_B_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define KEY_B_GetValue()           PORTAbits.RA2
#define KEY_B_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define KEY_B_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define KEY_B_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define KEY_B_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define KEY_B_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define KEY_B_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define KEY_B_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define KEY_B_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set KEY_W aliases
#define KEY_W_TRIS                 TRISAbits.TRISA3
#define KEY_W_LAT                  LATAbits.LATA3
#define KEY_W_PORT                 PORTAbits.RA3
#define KEY_W_WPU                  WPUAbits.WPUA3
#define KEY_W_OD                   ODCONAbits.ODCA3
#define KEY_W_ANS                  ANSELAbits.ANSELA3
#define KEY_W_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define KEY_W_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define KEY_W_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define KEY_W_GetValue()           PORTAbits.RA3
#define KEY_W_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define KEY_W_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define KEY_W_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define KEY_W_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define KEY_W_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define KEY_W_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define KEY_W_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define KEY_W_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set KEY_ADD aliases
#define KEY_ADD_TRIS                 TRISAbits.TRISA4
#define KEY_ADD_LAT                  LATAbits.LATA4
#define KEY_ADD_PORT                 PORTAbits.RA4
#define KEY_ADD_WPU                  WPUAbits.WPUA4
#define KEY_ADD_OD                   ODCONAbits.ODCA4
#define KEY_ADD_ANS                  ANSELAbits.ANSELA4
#define KEY_ADD_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define KEY_ADD_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define KEY_ADD_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define KEY_ADD_GetValue()           PORTAbits.RA4
#define KEY_ADD_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define KEY_ADD_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define KEY_ADD_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define KEY_ADD_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define KEY_ADD_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define KEY_ADD_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define KEY_ADD_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define KEY_ADD_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set KEY_SUB aliases
#define KEY_SUB_TRIS                 TRISAbits.TRISA5
#define KEY_SUB_LAT                  LATAbits.LATA5
#define KEY_SUB_PORT                 PORTAbits.RA5
#define KEY_SUB_WPU                  WPUAbits.WPUA5
#define KEY_SUB_OD                   ODCONAbits.ODCA5
#define KEY_SUB_ANS                  ANSELAbits.ANSELA5
#define KEY_SUB_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define KEY_SUB_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define KEY_SUB_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define KEY_SUB_GetValue()           PORTAbits.RA5
#define KEY_SUB_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define KEY_SUB_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define KEY_SUB_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define KEY_SUB_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define KEY_SUB_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define KEY_SUB_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define KEY_SUB_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define KEY_SUB_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set KEY_P aliases
#define KEY_P_TRIS                 TRISAbits.TRISA6
#define KEY_P_LAT                  LATAbits.LATA6
#define KEY_P_PORT                 PORTAbits.RA6
#define KEY_P_WPU                  WPUAbits.WPUA6
#define KEY_P_OD                   ODCONAbits.ODCA6
#define KEY_P_ANS                  ANSELAbits.ANSELA6
#define KEY_P_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define KEY_P_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define KEY_P_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define KEY_P_GetValue()           PORTAbits.RA6
#define KEY_P_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define KEY_P_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define KEY_P_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define KEY_P_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define KEY_P_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define KEY_P_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define KEY_P_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define KEY_P_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISBbits.TRISB0
#define LED1_LAT                  LATBbits.LATB0
#define LED1_PORT                 PORTBbits.RB0
#define LED1_WPU                  WPUBbits.WPUB0
#define LED1_OD                   ODCONBbits.ODCB0
#define LED1_ANS                  ANSELBbits.ANSELB0
#define LED1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LED1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LED1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LED1_GetValue()           PORTBbits.RB0
#define LED1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LED1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISBbits.TRISB1
#define LED2_LAT                  LATBbits.LATB1
#define LED2_PORT                 PORTBbits.RB1
#define LED2_WPU                  WPUBbits.WPUB1
#define LED2_OD                   ODCONBbits.ODCB1
#define LED2_ANS                  ANSELBbits.ANSELB1
#define LED2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED2_GetValue()           PORTBbits.RB1
#define LED2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISBbits.TRISB2
#define LED3_LAT                  LATBbits.LATB2
#define LED3_PORT                 PORTBbits.RB2
#define LED3_WPU                  WPUBbits.WPUB2
#define LED3_OD                   ODCONBbits.ODCB2
#define LED3_ANS                  ANSELBbits.ANSELB2
#define LED3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED3_GetValue()           PORTBbits.RB2
#define LED3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISBbits.TRISB3
#define LED4_LAT                  LATBbits.LATB3
#define LED4_PORT                 PORTBbits.RB3
#define LED4_WPU                  WPUBbits.WPUB3
#define LED4_OD                   ODCONBbits.ODCB3
#define LED4_ANS                  ANSELBbits.ANSELB3
#define LED4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LED4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LED4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LED4_GetValue()           PORTBbits.RB3
#define LED4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LED4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set ADP_5V_EN aliases
#define ADP_5V_EN_TRIS                 TRISCbits.TRISC1
#define ADP_5V_EN_LAT                  LATCbits.LATC1
#define ADP_5V_EN_PORT                 PORTCbits.RC1
#define ADP_5V_EN_WPU                  WPUCbits.WPUC1
#define ADP_5V_EN_OD                   ODCONCbits.ODCC1
#define ADP_5V_EN_ANS                  ANSELCbits.ANSELC1
#define ADP_5V_EN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define ADP_5V_EN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define ADP_5V_EN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define ADP_5V_EN_GetValue()           PORTCbits.RC1
#define ADP_5V_EN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define ADP_5V_EN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define ADP_5V_EN_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define ADP_5V_EN_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define ADP_5V_EN_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define ADP_5V_EN_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define ADP_5V_EN_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define ADP_5V_EN_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set ADP_12V_EN aliases
#define ADP_12V_EN_TRIS                 TRISCbits.TRISC2
#define ADP_12V_EN_LAT                  LATCbits.LATC2
#define ADP_12V_EN_PORT                 PORTCbits.RC2
#define ADP_12V_EN_WPU                  WPUCbits.WPUC2
#define ADP_12V_EN_OD                   ODCONCbits.ODCC2
#define ADP_12V_EN_ANS                  ANSELCbits.ANSELC2
#define ADP_12V_EN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define ADP_12V_EN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define ADP_12V_EN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define ADP_12V_EN_GetValue()           PORTCbits.RC2
#define ADP_12V_EN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define ADP_12V_EN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define ADP_12V_EN_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define ADP_12V_EN_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define ADP_12V_EN_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define ADP_12V_EN_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define ADP_12V_EN_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define ADP_12V_EN_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/