#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"
float ADD(unsigned long int R1, unsigned long int R2)
{
    return (R1+R2);
}
float SUC(unsigned long int R1, unsigned long int R2)
{
    return(R1-R2);
}
float BIC(unsigned long int R1, unsigned long int R2)
{
    return(R1&R2);
}
float EOR(unsigned long int R1, unsigned long int R2)
{
    return(R1|R2);
}
float MVN(unsigned long int R1)
{
    return(~R1);
}
