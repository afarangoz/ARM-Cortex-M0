#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "desplazamiento.h"

void LSL(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm<<num);
}
void LSR(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm>>num);
}
void ROR(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm>>num);
    Rm=(Rm<<(32-num));
    *Rd=*Rd+Rm;
}
void ASR(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm&(1<<31));
    Rm=Rm>>num;
    *Rd=*Rd+Rm;
}
