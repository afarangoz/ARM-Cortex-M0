#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include "ALU.h"
#include <math.h>

int main()
{
    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las pisiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es U es 1 si hubo sobreflujo es la operacion

    uint32_t Reg[13];


    Reg[1]=pow(2,31);
    Reg[2]=0;
    Reg[4]=Reg[2];
    ASR(&Reg[3],Reg[1],3);
    mostrar_registros(Reg);
    unsigned int i;
    for(i=0;i<=3;i++)
    {
        printf("banderas[%d]=%d \n",i+1,banderas[i]);
    }


    return 0;
}
