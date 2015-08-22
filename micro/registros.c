#include <stdio.h>
#include <stdlib.h>
#include "registros.h"

void mostrar_registros(unsigned long registro[13])
{
    unsigned int i;
    for(i=0;i<=12;i++)
    {
        printf("R[%d]=%d \n",i,registro[i]);
    }
}
