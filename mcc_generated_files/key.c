#include "key.h"

/****************************************************************************
    *
    * Function Name: void UNIPOLAR_MOTOR_Init(void)
    * Function :Initial motor for GPIO 
    * Input Ref:NO
    * Return Ref: key value
    * 
 ****************************************************************************/
uint8_t   KEY_Scan(void)
{
    static uint16_t  k1=0 ;
    static uint16_t  k2=0 ;
    static uint16_t  k3=0 ;
    static uint16_t  k4=0 ;
    static uint16_t  k5=0 ;
	static uint16_t  k6=0 ;
    //static uint8_t   k7=0;
    uint8_t cnt;
    

    
    if(KEY_RED() ==0){
        if(k1<181)
        k1++;   
    }
    else {  
      k1=0;  
    }
    
    if(KEY_GREEN() ==0){
       if(k2<181)
        k2++; 
       
    }
    else{
        
        k2=0; 
    }  
    
    if(KEY_BLUE() ==0){
       if(k3<181)
        k3++; 
       
    }
    else{
        
        k3=0; 
    } 
    
    if(KEY_WHITE() ==0){
       if(k4<181)
        k4++; 
       
    }
    else{
        
        k4=0; 
    }  
    
    if(KEY_ADD() ==0){ //"+"
       if(k5<181)
        k5++; 
       
    }
    else{
        
        k5=0; 
    } 

	if(KEY_SUB() ==0){ //"-"
       if(k6<181)
        k6++; 
       
    }
    else{
        
        k6=0; 
    } 
	
    /***************************/
  
    if(k1==180){
       cnt= 0x1  ;  //KEY_White
      // k1=0; //BUG
       return cnt ;
    } 
    if(k2==180){
        cnt= 0x2  ; //KEY_GEEN
       // k2=0;
        return cnt ;
    }
    if(k3==180){
        cnt= 0x4  ;  //KEY_BLUE
       // k3=0;
        return cnt ;
    }
    if(k4==180){
	  cnt =0x08;      //KEY_RED
	 // k6=0;
      return cnt ;
	}
    if(k5==180){
        cnt= 0x20  ;  //KEY_ADD +
     //   k4=0;
        return cnt ;
    }
    if(k6==180){
        cnt= 0x10 ;   //KEY_SUB -
      //  k5=0;
        return cnt ;
    }
	
    return 0 ;
    
}