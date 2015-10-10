#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "LoadStore.h"
#include <string.h>

 //--funciones para cargar registros con datos de la RAM en algun registro--//
void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm)
{
    if(imm==1)
    {
        Rm=Rm*4;
    }
    uint32_t AUX=0,i;
    *Rt=0;
    for(i=1;i<=4;i++)
    {
        AUX=*(SRAM+Rn+Rm+i-1);          //se resta un 1 ya que i inicia en 1
        *Rt=*Rt|((AUX)<<((i-1)*8));      //desplazamiento necesario en cada iteracion
    }
}
void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    *Rt=0;
    *Rt=*(SRAM+Rn+Rm);
}
void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm)
{
    printf("%X,%d,%d\n",*SRAM,Rn,Rm);
    uint32_t AUX,i;
    if(imm==1)
    {
        Rm=Rm*2;
    }
    printf("%X,%d,%d\n",*SRAM,Rn,Rm);
    *Rt=0;
    for(i=0;i<2;i++)
    {
        AUX=*(SRAM+Rn+Rm+i);          //se resta un 1 ya que i inicia en 1
        *Rt=*Rt|((AUX)<<(i*8));      //desplazamiento necesario en cada iteracion
    }
    printf("%X,%d,%d",*SRAM,Rn,Rm);

}
void LDRSB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t SGN,i;  //variable auxiliar para almacenar el signo con 8 bits
    LDRB(Rt,Rn,Rm,SRAM);
    SGN=(*Rt)&(1<<7);
    SGN=SGN>>7;
    if(SGN==1)
    {
        for(i=8;i<32;i++)
        {
            *Rt=(*Rt)|(1<<i);
        }
    }
}
void LDRSH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t AUX,i;
    LDRH(Rt,Rn,Rm,SRAM,0);
    AUX=((*Rt)&(1<<15))>>15;
    if(AUX==1)
    {
        for(i=16;i<32;i++)
        {
            *Rt=(*Rt)|(1<<i);
        }
    }
}
    //--funciones para cargar datos los registros en la RAM--//

void STR(uint32_t Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm)
{
    uint32_t i;
    if(imm==1)
    {
        Rm=Rm<<2;
    }
    for(i=0;i<4;i++)
    {
       *(SRAM+Rn+Rm+i)=Rt>>(i*8); //corrimiento cada 8 bits para la escritura en RAM
    }
}
void STRB(uint32_t Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t i;
    for(i=1;i<=3;i++)
    {
        *(SRAM+Rn+Rm+i)=0;         //extension de cero
    }
    *(SRAM+Rn+Rm)=Rt; //escritura de 8 bits en RAM
}
void STRH(uint32_t Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm)
{
    uint32_t i;
    if(imm==1)
    {
        Rm=Rm*2;   //se identifico que el dato recbido es un inmediato
    }
    for(i=0;i<2;i++) //este programa supone que las direcciones se suman de modo que se mueva cada 4 direcciones
    {
        *(SRAM+Rn+Rm+i)=(Rt>>(8*i)); //escritura de 16 bits en RAM

    }

}
