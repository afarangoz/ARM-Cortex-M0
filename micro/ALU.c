#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <math.h>
#include "ALU.h"

void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas) //tipo_opercion=1
{
    *Rd=Rn+Rm;
    actualizar(1,Rm,Rn,*Rd,banderas);//actualizamos las banderas

}
void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas)  //tipo_opercion=2
{
    *Rd=(Rm-Rn);
    actualizar(2,Rm,Rn,Rd,banderas);//actualizamos las banderas

}
void AND(uint32_t *Rd, uint32_t Rm,uint32_t Rn)  //tipo_opercion=3
{
    *Rd=(Rm&Rn);
}
void ORR(uint32_t *Rd, uint32_t Rm,uint32_t Rn)   //tipo_opercion=4
{
    *Rd=(Rm|Rn);
}
void MOV(uint32_t *Rm, uint32_t Rn)   //tipo_opercion=5
{
    *Rm=Rn;
}
void BIC(uint32_t *Rd,uint32_t Rm,uint32_t Rn)
{
    *Rd=Rm&(~Rn);
}
void EOR(uint32_t *Rd,uint32_t Rm,uint32_t Rn)
{
    *Rd=Rm^Rn;
}
void MVN(uint32_t *Rd,uint32_t Rm)
{
    *Rd=~Rm;
}
void NOP()
{

}
void actualizar(unsigned int tipo_operacion,uint32_t Rm,uint32_t Rn, unsigned int Rd, unsigned int *banderas)
{
    if(Rd==0)
        {
            *(banderas+1)=1;// avanzamos una posicion en memoria y le asignamos el valor
        }
        else
        {
            *(banderas+1)=0; //*(banderas+1) es la bandera C del arreglo
        }

    if(Rd>=pow(2,31))
        {
            *banderas=1;    //*banderas es la bandera N del arreglo
        }
        else
        {
            *banderas=0;

        }
    if((tipo_operacion==1)) //se identifica la operacion aritmeticologica
    {
        uint32_t R;
        R=Rn+Rm;


        if(((Rn>=pow(2,31))&&(Rm>=pow(2,31)))||((Rm>=pow(2,31))&&(Rn<pow(2,31))&&(R<pow(2,31)))||((Rn>=pow(2,31))&&(Rm<pow(2,31))&&(R<pow(2,31))))//condicion pasa reconoser el acarreo
        {
            *(banderas+2)=1; //*(banderas+2) es la bandera de acarreo
        }
        else
        {
            *(banderas+2)=0;
        }

        if(((Rn>=pow(2,31))&&(Rm>=pow(2,31))&&(R<pow(2,31)))||((Rn<pow(2,31))&&(Rm<pow(2,31))&&(R>=pow(2,31))))  //condicion para reconocer el sobreflujo
        {
            *(banderas+3)=1;  //*(banderas+3) es la bandera u del arreglo                                         y bit mas significativo del resultado es diferente.
        }
        else
        {
            *(banderas+3)=0;
        }

    }
    if((tipo_operacion==2)) //se identifica la operacion aritmeticologica
    {
        uint32_t R;
        R=Rm-Rn;

        // faltan mas banderas de la resta
    }
}

