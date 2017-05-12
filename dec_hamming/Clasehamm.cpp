#include "Clasehamm.h"

Clasehamm::Clasehamm()
{

}



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
    Serial.print(data_palabra[i]);
}

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
        aux= (data_palabra[0]*1)+(data_palabra[1]*2)+(data_palabra[2]*4)+(data_palabra[3]*8);
       /* for(i=0;i<4;i++)
        {
             aux+=(paridad[i]*pow(2,i));
        }*/

    codif_palabra[aux-1]=!codif_palabra[aux-1];
    
   }
}

void Clasehamm::dec_getMensaje(int palabra[])
{
for(i=0;i<12;i++)
{
        codif_palabra[i]=palabra[i];


}
}

void Clasehamm::convert()
{
        conver=0;
        sum=7;
        conver= (data_palabra[0]*128)+(data_palabra[1]*64)+(data_palabra[2]*32)
      +(data_palabra[3]*16)+(data_palabra[4]*8)+(data_palabra[5]*4)+(data_palabra[6]*2)+
       (data_palabra[7]*1);
       
      /*  for(i=0;i<8;i++)
        {
             //conver+=(data_palabra[i]*pow(2,sum));
             Serial.print(sum);
             sum=sum-1;
        }
    */        
        conv=conver;

          Serial.print(" ");
          Serial.print(conv);
} 

