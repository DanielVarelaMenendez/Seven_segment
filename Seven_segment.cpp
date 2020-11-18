//Developed by Daniel Varela Menendez on 18/11/2020
//https://github.com/DanielVarelaMenendez

#include "Seven_segment.h"
#include <Arduino.h>

 Seven_segment :: Seven_segment (int pinA, int pinB, int pinC, int pinD, int pinE ,int pinF, int pinG,
  int pinDot, int pinDig1,int pinDig2, int pinDig3, int pinDig4  ){
    output[0]=pinDig1;
    output[1]=pinDig2;
    output[2]=pinDig3;
    output[3]=pinDig4;
    output[4]=pinA;
    output[5]=pinB;
    output[6]=pinC;
    output[7]=pinD;
    output[8]=pinE;
    output[9]=pinF;
    output[10]=pinG;
    output[11]=pinDot;
    

}
void Seven_segment:: setup(){
    for (int i =0; i<12 ;i++ ){
        pinMode(output[i],OUTPUT);
    }
}
void Seven_segment :: print_number(int numb){
    switch (numb)
    {
    case 0:
        
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],HIGH);
        digitalWrite(output[8],HIGH);
        digitalWrite(output[9],HIGH);
        digitalWrite(output[10],LOW);

        break;
    case 1:
 
        digitalWrite(output[4],LOW);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],LOW);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],LOW);
        digitalWrite(output[10],LOW);
        break;

     case 2:
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],LOW);
        digitalWrite(output[7],HIGH);
        digitalWrite(output[8],HIGH);
        digitalWrite(output[9],LOW);
        digitalWrite(output[10],HIGH);
        break;
     case 3:
     
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],HIGH);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],LOW);
        digitalWrite(output[10],HIGH);
        break;
    case 4:
        
        digitalWrite(output[4],LOW);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],LOW);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],HIGH);
        digitalWrite(output[10],HIGH);

        break;
    case 5:
 
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],LOW);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],HIGH);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],HIGH);
        digitalWrite(output[10],HIGH);
        break;

     case 6:
        
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],LOW);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],HIGH);
        digitalWrite(output[8],HIGH);
        digitalWrite(output[9],HIGH);
        digitalWrite(output[10],HIGH);
        break;
     case 7:
        
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],LOW);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],LOW);
        digitalWrite(output[10],HIGH);
        break;
        case 8:
        
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],HIGH);
        digitalWrite(output[8],HIGH);
        digitalWrite(output[9],HIGH);
        digitalWrite(output[10],HIGH);
        break;
     case 9:
        
        digitalWrite(output[4],HIGH);
        digitalWrite(output[5],HIGH);
        digitalWrite(output[6],HIGH);
        digitalWrite(output[7],LOW);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],HIGH);
        digitalWrite(output[10],HIGH);
        break;
   
    //special modes
    case 10: //all leds off
   
        digitalWrite(output[4],LOW);
        digitalWrite(output[5],LOW);
        digitalWrite(output[6],LOW);
        digitalWrite(output[7],LOW);
        digitalWrite(output[8],LOW);
        digitalWrite(output[9],LOW);
        digitalWrite(output[10],LOW);
        break;
    }

}
void Seven_segment :: show_number (int number, int digit){ //NUMBER --to show ||DIGIT-- which of the four 7 segment displays the least significant digit of the NUMBER
    
    int digits=0 ;
    int aux=number;
    while (aux){
        aux /=10;
        digits++; 
       
    }

    if (digits > digit ){
        Serial.println("The number you want to write is too much big");
    }
    else{
       
        for (int x=0 ; x< digits; x++){
            int numb=number/ pow(10,digits-1-x);
            print_number(10); //all lights off
            digitalWrite(output[0],x!=digits-digit);
            digitalWrite(output[1],x!=digits+1-digit);
            digitalWrite(output[2],x!=digits+2-digit);
            digitalWrite(output[3],x!=digits+3-digit);
            print_number(numb);
           
            
            number= number- numb* pow(10,digits-1-x);
            delayMicroseconds(1000);
        }

    
    }
    
    
}

