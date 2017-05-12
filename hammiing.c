    //  Codificacion y decodificacion Hamming
    //  Presentado por: Deimer Andres Morales Herrera
    //                  Juan Camilo Montilla Orjuela
    //                  Daniela Matallana Caballero
    //  Creado para las asignaturas de campos 2 y 
    //  microprocesadores.
    //  Armenia, Quindio 30 de abril de 2017
    //  #FreeSoftware.

#include "Clasehamm.h"

Clasehamm hamming;

int main()
{
    char mensaje[20];
    int control=0,i;
    clock_t start,end;
    double cpu_time_used;
    start=clock();
    printf("ingrese el mensaje : ");
    gets(mensaje);

    for(i=0;i<strlen(mensaje);i++)
        
        {
            hamming.setConvert(mensaje[i],128);
            hamming.Paridad(1);
            hamming.Codificacion();
            hamming.Sincronizacion();
//termina la codificacion 
            
            hamming.dec_error(1);
            hamming.det_error();
            hamming.dec_setMensaje();
             
            
            printf("\n");
    
        }


    end=clock();
    cpu_time_used=((double)(end - start))/CLOCKS_PER_SEC;
    printf("tiempo invertido igual a %lf \n",cpu_time_used);


}

