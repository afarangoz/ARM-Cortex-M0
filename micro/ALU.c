#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "ALU.h"
#include <string.h>

void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op) //tipo_opercion=1
{
    *Rd=Rn+Rm;
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rd<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rd<(1<<31))))//condicion pasa reconoser el acarreo
        {*(banderas+2)=1;} //*(banderas+2) es la bandera de acarreo
    else
        {*(banderas+2)=0;}
    if(((Rn>=(1<<31))&&(Rm>=(1<<31))&&(*Rd<(1<<31)))||((Rn<(1<<31))&&(Rm<(1<<31))&&(*Rd>=(1<<31))))  //condicion para reconocer el sobreflujo
        {*(banderas+3)=1;}  //*(banderas+3) es la bandera u "sobreflujo" del arreglo                                         y bit mas significativo del resultado es diferente.
    else
        {*(banderas+3)=0;}
    strcpy(op, "ADD");
}
void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)  //tipo_opercion=2
{
    ADD(Rd,Rm,-Rn,banderas,op);  // se expresa la resta como una suma
    strcpy(op, "SUB");
}

void AND(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)  //tipo_opercion=3
{
    *Rd=(Rm&Rn);
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
    //AND no actualiza acarreo
    //falta actualizar sobreflujo
    strcpy(op, "AND");
}

void ORR(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)   //tipo_opercion=4
{
    *Rd=(Rm|Rn);
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
    strcpy(op, "ORR");
}

void MOV(uint32_t *Rm, uint32_t Rn,uint32_t *banderas,char *op)   //tipo_opercion=5
{
    *Rm=Rn;
    ACTNZ(Rm,banderas,op);  //se actualizan las banderas N y Z
    //no se actualizan las demas vanderas
    strcpy(op, "MOV");
}

void BIC(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    *Rd=Rm&(~Rn);
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
    strcpy(op, "BIC");
}

void EOR(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    *Rd=Rm^Rn;
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
    strcpy(op, "EOR");
}

void MVN(uint32_t *Rd,uint32_t Rm,uint32_t *banderas,char *op)
{
    *Rd=~Rm;
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
    strcpy(op, "MVN");
}

void NOP(uint32_t *banderas,char *op)
{
    strcpy(op, "NOP");
}

void CMN(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    uint32_t Rd;
    ADD(&Rd,Rm,Rn,banderas,op);
}

void CMP(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    uint32_t Rd;
    ADD(&Rd,Rm,Rn,banderas,op);
}

void TST(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    uint32_t Rd;
    AND(&Rd,Rm,Rn,banderas,op);
}
void ACTNZ(uint32_t *Rd,uint32_t *banderas,char *op)
{
    if(*Rd&(1<<31))
        {*banderas=1;}    //*banderas es la bandera N del arreglo
    else
        {*banderas=0;}
    if(*Rd==0)
        {*(banderas+1)=1;}// avanzamos una posicion en memoria y le asignamos el valor
    else
        {*(banderas+1)=0;} //*(banderas+1) es la bandera C del arreglo
    strcpy(op, "ACTNZ");
}
void ADC(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    ADD(Rd,Rm,Rn,banderas,op);              //tener encuenta que Rd es una direccion de memoria
    ADD(Rd,*Rd,*(banderas+2),banderas,op);  //se efecta la suma con carry y se actualizan banderas
    strcpy(op, "ADC");
}
void SBC(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    SUB(Rd,Rm,Rn,banderas,op);              //tener encuenta que Rd es una direccion de memoria
    SUB(Rd,*Rd,*(banderas+2),banderas,op);
    strcpy(op, "SBC");
}
void RSB(uint32_t *Rd,uint32_t Rm,uint32_t *banderas,char *op)
{
    *Rd=(~Rm)+1;    //complemento a dos de un dato
}
void MUL(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op)
{
    *Rd=Rm*Rn;
    ACTNZ(Rd,banderas,op);  //se actualizan las banderas N y Z
}
