#include <stdint.h>
#include <stdio.h>
#include "PILA.h"

void PUSH(unsigned int registros[16], uint32_t *Reg, uint32_t *PILA)
{
    unsigned long posicion;
    int i;
    int contador=0;
    for(i=0; i<15; i++)
    {
        if(registros[i]==1)
        {
            contador+=1;      //contador incrementa cada vez que encuentra un 1 en registros
        }
    }
    posicion=*(Reg+13)-contador;    //Reg[13] indica la ultima direccion de memoria se
    for(i=0; i<15; i++)             //resta contador para que guarde los datos en las ultimas direcciones de memoria
    {
        if(registros[i]==1)
        {
            *(PILA+posicion)=*(Reg+i);  //se guarden los datos en PILA
            posicion+=1;
        }
    }
    *(Reg+13)-=contador;
}
