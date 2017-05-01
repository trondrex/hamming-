    //  Codificacion y decodificacion Hamming
    //  Presentado por: Deimer Andres Morales Herrera
    //                  Juan Camilo Montilla Orjuela
    //                  Daniela Matallana Caballero
    //  Creado para las asignaturas de campos 2 y 
    //  microprocesadores.
    //  Armenia, Quindio 30 de abril de 2017
    //  #FreeSoftware.

#include <stdio.h>
#include <string.h>
int main()
{
    char mensaje[20];
    int aux,i=0;

    printf("ingrese el mensaje : ");
    scanf("%s",&mensaje);

    for(i=0;i<strlen(mensaje);i++)
        {
            aux=mensaje[i];
            printf("%d \n",aux);
    
        }





}
