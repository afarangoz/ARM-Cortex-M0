#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"

int main()
{
    unsigned int banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las pisiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es U es 1 si hubo sobreflujo es la operacion

    unsigned long int Reg[13];


    Reg[1]=-2;
    Reg[2]=2;
    ADD(&Reg[3],Reg[1],Reg[2],&banderas[0]);
    mostrar_registros(Reg);



    return 0;
}
