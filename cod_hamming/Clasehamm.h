#ifndef Clasehamm_h
#define Clasehamm_h
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Arduino.h"
class Clasehamm
{    
    public:

        Clasehamm();
        void setConvert(char,unsigned int);
        void Paridad(unsigned int);
        void Codificacion();
        void Sincronizacion();
        


    private:

        int i,paridad[4],data_palabra[8],aux,sum;
        int pin_interrupt,pin_datos,lector,pin_fin;
        int codif_palabra[12],sinc_palabra[20]={0,0,0,0,0,0,0,1},error;
        char conv;
};
#endif

