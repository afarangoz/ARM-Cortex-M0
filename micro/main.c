#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"

int main()
{
    long int Reg[13];


    Reg[1]=25;
    Reg[2]=3;
    ADD(Reg[1],Reg[2]);
    mostrar_registros(Reg);

    printf("Resultado=%d", Reg);

    return 0;
}
