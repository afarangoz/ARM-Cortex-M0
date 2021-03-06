#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "desplazamiento.h"
#include "ALU.h"


void LSLS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas)
{
    *(banderas+2)=((Rm<<(num-1))&(1<<31))>>31;
    *Rd=(Rm<<num);      //Rm se desplaza hacia la izquierda una cantidad de num en bits
    ACTNZ(Rd,banderas);

}

void LSRS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas)
{
    *(banderas+2)=(Rm>>(num-1))&1;
    *Rd=(Rm>>num);      //Rm se desplaza hacia la derecha una cantidad de num en bits
    ACTNZ(Rd,banderas);
}

void RORS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas)
{
    *(banderas+2)=(Rm&(1<<(num-1)))>>(num-1);
    *Rd=(Rm>>num);          //se eliminan los bits menos significativos hasta num
    Rm=(Rm<<(32-num));      //los bits menos significativos hasta num pasan a ser los mas significtivos
    *Rd=*Rd|Rm;             //se suman los resultados anteriores
    ACTNZ(Rd,banderas);
}

void ASRS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas)
{
    *(banderas+2)=(Rm&(1<<(num-1)))>>(num-1);
    *Rd=(Rm&(1<<31));       //se identifica el signo multiplicando el registro por un 1 corrido 31 posiciones hacia la izquierda
    Rm=Rm>>num;             //se ejecuta el desplazamiento normal
    *Rd=*Rd+Rm;             //se suman los resultados anterirores para recuperar el signo
    ACTNZ(Rd,banderas);
}

void REV(uint32_t *Rd,uint32_t Rm)
{
    uint32_t AUX;
    *Rd=Rm<<24;
    AUX=Rm>>24;
    *Rd=*Rd|AUX;
    AUX=Rm<<8;
    AUX=AUX>>24;
    AUX=AUX<<8;
    *Rd=*Rd|AUX;
    AUX=Rm<<16;
    AUX=AUX>>24;
    AUX=AUX<<16;
    *Rd=*Rd|AUX;
}

void REV16(uint32_t *Rd,uint32_t Rm)
{
    uint32_t AUX;
    *Rd=Rm<<16;
    AUX=Rm>>16;
    *Rd=*Rd|AUX;
}

void REVSH(uint32_t *Rd,uint32_t Rm)
{
    uint32_t AUX;

    *Rd=(Rm<<24);
    *Rd=*Rd>>16;
    AUX=Rm<<16;
    AUX=AUX>>24;
    *Rd=*Rd|AUX;
    AUX=*Rd&(1<<15);
    if((AUX<<15))   //rellena los 16 bits mas significativos
    {
        AUX=0;
        AUX=~AUX;
        AUX=AUX<<16;
        *Rd=*Rd|AUX;

    }
}

