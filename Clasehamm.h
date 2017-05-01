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
    
    private:

        int i,dec,data_palabra[8];
        char conv;
};
#endif

