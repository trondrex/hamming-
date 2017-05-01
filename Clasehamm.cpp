#include "Clasehamm.h"

Clasehamm::Clasehamm()
{
    i=0;

}

void Clasehamm::setConvert(char char_ref,unsigned int conta)
{

    printf("\n");
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
    
unsigned int comparador=3;

for(conta; conta < 9; conta<<=1)
{
    printf("\n");
    i=0;
    comparador=3;
    for(comparador;comparador<=12;comparador++)
    {
        if(comparador != 4 && comparador != 8)
        {
        
            if(conta & comparador)
            {
                printf("%d",comparador);
            }
            else
            {
                printf(" ");

            }
        
        }

        else
        {
            printf(" ");
        }

        i++;
    }


}


}







int Clasehamm::getConvert()
{

    return dec;
}


