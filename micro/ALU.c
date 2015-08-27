#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"

void ADD(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn,unsigned int *banderas) //tipo_opercion=1
{
    actualizar(1,Rm,Rn,banderas);//actualizamos las banderas
    *Rd=Rn+Rm;
}
void SUB(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn)  //tipo_opercion=2
{
    *Rd=(Rm-Rn);
}
void BIC(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn)  //tipo_opercion=3
{
    *Rd=(Rm&Rn);
}
void OR(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn)   //tipo_opercion=4
{
    *Rd=(Rm|Rn);
}
void MOV(unsigned long int *Rm, unsigned long int Rn)   //tipo_opercion=5
{
    *Rm=Rn;
}
void actualizar(unsigned int tipo_operacion,unsigned long int Rn,unsigned long int Rm,unsigned int *banderas)
{
    if((tipo_operacion==1)) //se identifica la operacion aritmeticologica
    {
        if((Rn+Rm)<0)
        {
            *banderas=1;    //*banderas es la bandera N del arreglo
        }
        else
        {
            *banderas=0;

        }
        if((Rn+Rm)==0)
        {
            *(banderas+1)=1;// avanzamos una posicion en memoria y le asignamos el valor
        }
        else
        {
            *(banderas+1)=0; //*(banderas+1) es la bandera C del arreglo
        }



        if((((Rn<<31)==1)&&((Rm<<31)==1)&&((Rn+Rm)<<31==0))||(((Rn<<31)==0)&&((Rm<<31)==0)&&((Rn+Rm)<<31==1)))  //se esta comparando si los bits mas significativos son iguales
        {
            *(banderas+3)=1;  //*(banderas+3) es la bandera u del arreglo                                         y bit mas significativo del resultado es diferente.
        }
        else
        {
            *(banderas+3)=0;
        }

    }
}

