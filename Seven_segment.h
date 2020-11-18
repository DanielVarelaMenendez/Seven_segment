//Developed by Daniel Varela Menendez on 18/11/2020
//https://github.com/DanielVarelaMenendez

#include <Arduino.h>

#ifndef Seven_segment_h
#define Seven_segment_h


class Seven_segment {
     private:
        int output[];
     
     public:

        Seven_segment (int pinA, int pinB, int pinC, int pinD, int pinE ,int pinF, int pinG,
         int pinDot, int pinDig1,int pinDig2, int pinDig3, int pinDig4);
        void setup();
        void print_number (int numb);
        void show_number (int number, int digit );

};

#endif

