#ifndef Clasehamm_h
#define Clasehamm_h
#include <stdio.h>
#include <string.h>

class Clasehamm
{    
    public:

        Clasehamm();
        int getConvert();
        void setConvert(char,unsigned int);
        void Paridad(unsigned int);
        void Codificacion();
    
    private:

        int i,paridad[4],data_palabra[8],aux,sum;
        int codif_palabra[12];
        char conv;
};
#endif

