#include "Clasehamm.h"

Clasehamm::Clasehamm()
{

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
for(i=8;i<20;i++)
{
    sinc_palabra[i]=codif_palabra[sum];
    sum++;
    
}


for(i=0;i<20;i++)
{
    printf("%d",sinc_palabra[i]);
}

            printf(" ");
}

// termina el codigo de la codifcacion



void Clasehamm::dec_error(unsigned int conta)
{ 
error=0;
unsigned int comparador;
int sum=0;
for(conta; conta < 9; conta<<=1)
{
    i=0;
    aux=0;
    for(comparador=1;comparador<=12;comparador++)
    {
        
            if(conta & comparador)
            {
                aux += codif_palabra[i];
            }

            i++;
        
    }

   if(aux%2!=0)
   {
        error++;
        paridad[sum]=1;
   
   }
    else
    {
    
        paridad[sum]=0;
    }
   sum++;
}

}


void Clasehamm::dec_setMensaje()
{
aux=0;
for(i=0;i<12;i++)
{
    if(i!=0 && i!=1 && i!=3 && i!=7)
    {

        data_palabra[aux]=codif_palabra[i];
        aux++;
    }

}

for(i=0;i<8;i++)
{
    printf("%d",data_palabra[i]);
}

            printf(" ");
}

void Clasehamm::mierror()
{
    codif_palabra[6]=1;

}

void Clasehamm::det_error()
{
    if(error>1)
    {
        aux=0;
        for(i=0;i<4;i++)
        {
             aux+=(paridad[i]*pow(2,i));
        }

    codif_palabra[aux-1]=!codif_palabra[aux-1];
    
   }
}
