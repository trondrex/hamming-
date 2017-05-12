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
String mensajex = "";
int i;
char mensaje[20];  
void setup()
{
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  digitalWrite(3,HIGH);
  //delay(1000);
  //Serial.print("Establecida comunicaacion con el transmisor . . .");
  //Serial.println(" ");
}

void loop()
{
   
  if (Serial.available())
  {
    mensajex = Serial.readString();
    mensajex.toCharArray(mensaje,sizeof(mensaje));
      for(i=0;i<strlen(mensaje);i++)
  {
  
  hamming.setConvert(mensaje[i],128);
  hamming.Paridad(1);
  hamming.Codificacion();
  hamming.Sincronizacion();
  }
  
  }
  
delay(100);
}

