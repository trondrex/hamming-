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
        void dec_error(unsigned int);
        void mierror();
        void dec_setMensaje();
        void det_error();
        void dec_getMensaje(int palabra[]);
        void convert();

    private:

        int i,paridad[4],data_palabra[8],aux,sum;
        int codif_palabra[12],sinc_palabra[20]={0,0,0,0,0,0,0,1},error;
        int conver;
        char conv;
};
#endif

