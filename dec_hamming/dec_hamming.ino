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
volatile int i=0;
volatile int ax=0;
volatile int codif_palabra[12];
void setup()
{
  Serial.begin(9600);
  //delay(1000);
  //Serial.print("Establecida comunicaacion con el receptor . . .");
  //Serial.println(" ");
  attachInterrupt(1,cambio,FALLING);
  attachInterrupt(3,cambio2,FALLING);    
}

void loop()
{
  if(ax!=0)
  {
    hamming.dec_getMensaje(codif_palabra);
    hamming.dec_error(1);
    hamming.det_error();
    hamming.dec_setMensaje();
    hamming.convert();
    ax=0; 
  }
}
void cambio()
{
  if(digitalRead(4)==LOW)
  {
  codif_palabra[i]=0;  
  }
  else
  {
  codif_palabra[i]=1;
  }
  if(i==11)
  {
    ax=1;
  }
  i++;
  
}
void cambio2()
{
  i=0;
  ax=0;
  Serial.println(" ");
}

