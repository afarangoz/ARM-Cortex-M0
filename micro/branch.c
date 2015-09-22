#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "branch.h"

        //[0] es N es 1 si el resultado es negatico
        //[1] es Z es 1 si el resultado es cero
        //[2] es C es 1 si hay acarreo en la operacion aritmetica
        //[3] es V es 1 si hubo sobreflujo es la operacion

void B(uint32_t *R,uint32_t b)
{
    *R=*R+b;
}

void BEQ(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[1]==1)
    {
        *R=*R+b;
    }
}

void BNE(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[1]==0)
    {
        *R=*R+b;
    }
}

void BCS(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[2]==1)
    {
        *R=*R+b;
    }
}

void BCC(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[2]==0)
    {
        *R=*R+b;
    }
}

void BMI(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[0]==1)
    {
        *R=*R+b;
    }
}

void BPL(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[0]==0)
    {
        *R=*R+b;
    }
}

void BVS(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[3]==1)
    {
        *R=*R+b;
    }
}

void BVC(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[3]==0)
    {
        *R=*R+b;
    }
}

void BHI(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if((banderas[2]==1)&&(banderas[1]==0))
    {
        *R=*R+b;
    }
}

void BLS(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if((banderas[2]==0)||(banderas[1]==1))
    {
        *R=*R+b;
    }
}

void BGE(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[0]==banderas[3])
    {
        *R=*R+b;
    }
}

void BLT(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if(banderas[0]!=banderas[3])
    {
        *R=*R+b;
    }
}

void BGT(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if((banderas[0]==banderas[3])&&(banderas[1]==0))
    {
        *R=*R+b;
    }
}

void BLE(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    if((banderas[0]!=banderas[3])||(banderas[1]==0))
    {
        *R=*R+b;
    }
}

void BAL(uint32_t *R,uint32_t b,uint32_t *banderas)
{
    *R=*R+b;
}


void BL(uint32_t *LR,uint32_t *PC,uint32_t salto)
{
	*LR=*PC+1;
    *PC+=salto;
}

void BLX(uint32_t *LR,uint32_t *PC,uint32_t direccion)
{
	*LR=*PC+1;
    *PC=direccion;
}


void BX(uint32_t *PC,uint32_t *direccion)
{
        *PC=*direccion;
}

