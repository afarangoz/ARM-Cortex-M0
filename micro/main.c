#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"

int main()
{
    unsigned long int Reg[13];


    Reg[1]=2;
    Reg[2]=4;
    Reg[3]=MVN(Reg[1]);
    mostrar_registros(Reg);



    return 0;
}
