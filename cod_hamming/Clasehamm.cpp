#include "Clasehamm.h"

Clasehamm::Clasehamm()
{
pin_interrupt=3;
pin_fin=5;
pin_datos=4;
pinMode(pin_interrupt,OUTPUT);
pinMode(pin_datos,OUTPUT);
pinMode(pin_fin,OUTPUT);
}

void Clasehamm::setConvert(char char_ref,unsigned int conta)
{

    i=0;
    for(conta;conta>0;conta>>=1)
   { 
   
       if(conta & char_ref)
       {
           data_palabra[i]=1;
       
       }
   
       else
       {
           data_palabra[i]=0;
       } 
      
       i++;
   }

}


void Clasehamm::Paridad(unsigned int conta)
{
sum=0; 
unsigned int comparador;
for(conta; conta < 9; conta<<=1)
{
    i=0;
    aux=0;
    for(comparador=3;comparador<=12;comparador++)
    {
        if(comparador != 4 && comparador != 8)
        {
        
            if(conta & comparador)
            {
                aux += data_palabra[i];
            }

            i++;
        }
    }
   if(aux%2==0)
   {
       paridad[sum]=0;
   
   }
   else
    {
        paridad[sum]=1;
    
    }
   sum++;

}

}

void Clasehamm::Codificacion()
{
sum=0;
aux=0;
for(i=0;i<12;i++)
{
    if(i==0 || i==1 || i==3 || i==7)
    {
        codif_palabra[i]=paridad[sum];
        sum++;  
    }
    else
    {
        codif_palabra[i]=data_palabra[aux];
        aux++;
    }

}

}

void Clasehamm::Sincronizacion()
{
sum=0;
lector=0;
aux=0;
for(i=8;i<20;i++)
{
    sinc_palabra[i]=codif_palabra[sum];
    sum++;
    
}

for(i=0;i<20;i++)
{  digitalWrite(pin_interrupt,HIGH);
   digitalWrite(pin_fin,HIGH);
  
  if(sinc_palabra[i]==0 && lector == 0)
  {
    aux++;
    Serial.print("0");
  }
  else if(sinc_palabra[i]==1 && aux==7)
  {
    aux=0;
    lector=1;
    digitalWrite(pin_fin,LOW);
    Serial.print("1");
  }
  else
  { 
    if(sinc_palabra[i]==0)
    {
      digitalWrite(pin_interrupt,LOW);
      digitalWrite(pin_datos,LOW);
      Serial.print("0");
    }
    else
    {
      
      digitalWrite(pin_interrupt,LOW);
      digitalWrite(pin_datos,HIGH);
      Serial.print("1");
    }
  
  
  }
 delay(50);   
}

            Serial.println(" ");

}

