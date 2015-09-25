#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "ALU.h"
#include <string.h>

void ADDS(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas) //tipo_opercion=1
{
    *Rd=Rn+Rm;

    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rd<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rd<(1<<31))))//condicion pasa reconoser el acarreo
        {*(banderas+2)=1;} //*(banderas+2) es la bandera de acarreo
    else
        {*(banderas+2)=0;}
    if(((Rn>=(1<<31))&&(Rm>=(1<<31))&&(*Rd<(1<<31)))||((Rn<(1<<31))&&(Rm<(1<<31))&&(*Rd>=(1<<31))))  //condicion para reconocer el sobreflujo
        {*(banderas+3)=1;}  //*(banderas+3) es la bandera u "sobreflujo" del arreglo                                         y bit mas significativo del resultado es diferente.
    else
        {*(banderas+3)=0;}
}

void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn)
{
    *Rd=Rn+Rm;
}

void SUBS(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas)  //tipo_opercion=2
{
    ADDS(Rd,Rm,-Rn,banderas);  // se expresa la resta como una suma
}

void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn)  //tipo_opercion=2
{
    *Rd=Rm-Rn;
}

void ANDS(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas)  //tipo_opercion=3
{
    *Rd=(Rm&Rn);
    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z

}

void ORRS(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas)   //tipo_opercion=4
{
    *Rd=(Rm|Rn);
    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z
}

void MOVS(uint32_t *Rm, uint32_t Rn,uint32_t *banderas)   //tipo_opercion=5
{
    *Rm=Rn;
    ACTNZ(Rm,banderas);
}

void MOV(uint32_t *Rm, uint32_t Rn)   //tipo_opercion=5
{
    *Rm=Rn;
}

void BICS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    *Rd=Rm&(~Rn);
    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z
}

void EORS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    *Rd=Rm^Rn;
    ACTNZ(Rd,banderas);  //se actualizan las banderas  N y Z
}                        // las otras banderas no se actualizan

void MVNS(uint32_t *Rd,uint32_t Rm,uint32_t *banderas)
{
    *Rd=~Rm;
    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z
}

void NOP()
{

}

void CMN(uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    uint32_t Rd;
    ADDS(&Rd,Rm,Rn,banderas);
    ADDS(&Rd,Rm,Rn,banderas);
}

void CMP(uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    uint32_t Rd;
    Rn=~Rn+1;
    ADDS(&Rd,Rm,Rn,banderas);
}

void TST(uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    uint32_t Rd;
    ANDS(&Rd,Rm,Rn,banderas);
}

void ACTNZ(uint32_t *Rd,uint32_t *banderas)
{
    if(*Rd&(1<<31))
        {*banderas=1;}    //*banderas es la bandera N del arreglo
    else
        {*banderas=0;}
    if(*Rd==0)
        {*(banderas+1)=1;}// avanzamos una posicion en memoria y le asignamos el valor
    else
        {*(banderas+1)=0;} //*(banderas+1) es la bandera C del arreglo
}
void ADCS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    *Rd=Rm+Rn+(*(banderas+2));
    //ADDS(Rd,Rm,Rn,banderas);              //tener encuenta que Rd es una direccion de memoria
    //ADDS(Rd,*Rd,*(banderas+2),banderas);  //se efecta la suma con carry y se actualizan banderas
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rd<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rd<(1<<31))))//condicion pasa reconoser el acarreo
        {*(banderas+2)=1;} //*(banderas+2) es la bandera de acarreo
    else
        {*(banderas+2)=0;}
    if(((Rn>=(1<<31))&&(Rm>=(1<<31))&&(*Rd<(1<<31)))||((Rn<(1<<31))&&(Rm<(1<<31))&&(*Rd>=(1<<31))))  //condicion para reconocer el sobreflujo
        {*(banderas+3)=1;}  //*(banderas+3) es la bandera u "sobreflujo" del arreglo                                         y bit mas significativo del resultado es diferente.
    else
        {*(banderas+3)=0;}
    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z
}

void SBCS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    *Rd=Rm-Rn;
    //SUBS(Rd,Rm,Rn,banderas);              //tener encuenta que Rd es una direccion de memoria
    SUBS(Rd,*Rd,*(banderas+2),banderas);  //actualiza banderas implicitamente
}
void RSBS(uint32_t *Rd,uint32_t Rm,uint32_t *banderas)   //complemento ados
{
    ADDS(Rd,~Rm,1,banderas);
    ACTNZ(Rd,banderas);

}
void MULS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas)
{
    *Rd=Rm*Rn;
    ACTNZ(Rd,banderas);  //se actualizan las banderas N y Z
}
