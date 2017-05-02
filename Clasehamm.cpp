#include "Clasehamm.h"

Clasehamm::Clasehamm()
{
    i=0;

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
unsigned int comparador=3;
for(conta; conta < 9; conta<<=1)
{
    i=0;
    aux=0;
    comparador=3;
    for(comparador;comparador<=12;comparador++)
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

for(i=0;i<12;i++)
{
    printf("%d",codif_palabra[i]);
}

printf("\n");


}





int Clasehamm::getConvert()
{


}


