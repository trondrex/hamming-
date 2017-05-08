#ifndef Clasehamm_h
#define Clasehamm_h
#include <stdio.h>
#include <string.h>
#include <math.h>
class Clasehamm
{    
    public:

        Clasehamm();
        int getConvert();
        void setConvert(char,unsigned int);
        void Paridad(unsigned int);
        void Codificacion();
        void Sincronizacion();
        // termina la codificacion
        void dec_error(unsigned int);
        void mierror();
        void dec_setMensaje();
        void det_error();


    private:

        int i,paridad[4],data_palabra[8],aux,sum;
        int codif_palabra[12],sinc_palabra[20]={0,0        ,0,0,0,0,0,1},error;
        char conv;
};
#endif

