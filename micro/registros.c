#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

void mostrar_registros(long registro[13])
{
    int i;
    for(i=0;i<=12;i++)
    {
        printf("R[%d]=%d \n",i,registro[i]);
    }
}
