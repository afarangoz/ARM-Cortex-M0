#include <stdint.h>
#include <stdio.h>
#include "PILA.h"

void PUSH(uint8_t registros[16], uint32_t *Reg, uint8_t *SR)
{
    uint32_t aux;
    unsigned long posicion;
    int i;
    int contador=0;
    for(i=0; i<16; i++)
    {
        if(registros[i]==1)
        {
            contador+=1;      //contador incrementa cada vez que encuentra un 1 en registros
        }
    }
    *(Reg+13)=*(Reg+13)-(4*contador);//Reg[13] indica la ultima direccion de memoria se
    posicion=*(Reg+13);

    for(i=0; i<16; i++)             //resta contador para que guarde los datos en las ultimas direcciones de memoria
    {
        if(registros[i]==1)
        {
            aux=*(Reg+i);
            *(SR+posicion)=(aux);
            *(SR+posicion+1)=(aux>>8);
            *(SR+posicion+2)=(aux>>16);
            *(SR+posicion+3)=(aux>>24);
             posicion=posicion+4;
        }
    }

}
void POP(uint8_t registros[16], uint32_t *Reg, uint8_t *SR)
{
    uint32_t aux=0;
    unsigned long posicion;
    int i;
    int contador=0;
    for(i=0; i<16; i++)
    {
        if(registros[i]==1)
        {
            contador+=1;      //contador incrementa cada vez que encuentra un 1 en registros
        }
    }
    posicion=*(Reg+13);
    *(Reg+13)=*(Reg+13)+(4*contador);//Reg[13] indica la ultima direccion de memoria se
    for(i=0; i<16; i++)             //resta contador para que guarde los datos en las ultimas direcciones de memoria
    {
        if(registros[i]==1)
        {
            *(Reg+i)=0;

             aux=*(SR+posicion);//se guarden los datos en PILA
            *(Reg+i)=*(Reg+i)|(aux<<0);
            aux=*(SR+posicion+1);//se guarden los datos en PILA
            *(Reg+i)=*(Reg+i)|(aux<<8);
            aux=*(SR+posicion+2);//se guarden los datos en PILA
            *(Reg+i)=*(Reg+i)|(aux<<16);
            aux=*(SR+posicion+3);//se guarden los datos en PILA
            *(Reg+i)=*(Reg+i)|(aux<<24);
            posicion=posicion+4;

        }
    }

}
