#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "desplazamiento.h"

void LSL(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm<<num);      //Rm se desplaza hacia la izquierda una cantidad de num en bits
}
void LSR(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm>>num);      //Rm se desplaza hacia la derecha una cantidad de num en bits
}
void ROR(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm>>num);          //se eliminan los bits menos significativos hasta num
    Rm=(Rm<<(32-num));      //los bits menos significativos hasta num pasan a ser los mas significtivos
    *Rd=*Rd|Rm;             //se suman los resultados anteriores
}
void ASR(uint32_t *Rd,uint32_t Rm,uint32_t num)
{
    *Rd=(Rm&(1<<31));       //se identifica el signo multiplicando el registro por un 1 corrido 31 posiciones hacia la izquierda
    Rm=Rm>>num;             //se ejecuta el desplazamiento normal
    *Rd=*Rd+Rm;             //se suman los resultados anterirores para recuperar el signo
}
