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
    int aux,i=0,size;

    printf("ingrese el mensaje : ");
    gets(mensaje);
    size=strlen(mensaje);

    for(i=0;i<strlen(mensaje);i++)
        
        {
            hamming.setConvert(mensaje[i],128);
            hamming.Paridad(1);
            hamming.Codificacion();
           // aux=hamming.getConvert();
           // printf("%d \n",aux);
    
        }





}
