
#include <stdint.h>
#include <stdio.h>
#include "interrupciones.h"

void NVIC(uint32_t *Reg,uint32_t *banderas, uint8_t *SR, uint8_t *Rin)
{
    static uint8_t itc =0 ;
    int i,n=0,b=0;

    for(i=0;i<16;i++)
    {
        if(*(Rin+i)==1){
        n++;
        b=i;
        break;}
    }

    if(n!=0)
    {


           if(itc==1)
        {

            if(*(Reg+15)==-1)
            {
    //...................RESTAURO LOS REGISTROS Y LAS BANDERAS................//

        uint32_t aux;
        unsigned long posicion;
        int i;
        int registros[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1};
        posicion=*(Reg+13);
        *(Reg+13)=*(Reg+13)+(4*11);

        for(i=0; i<16; i++)
        {
            if(registros[i]==1)
            {
                *(Reg+i)=0;
                 aux=*(SR+posicion);
                *(Reg+i)=*(Reg+i)|(aux<<0);
                aux=*(SR+posicion+1);
                *(Reg+i)=*(Reg+i)|(aux<<8);
                aux=*(SR+posicion+2);
                *(Reg+i)=*(Reg+i)|(aux<<16);
                aux=*(SR+posicion+3);
                *(Reg+i)=*(Reg+i)|(aux<<24);
                posicion=posicion+4;

            }
        }

            for(i=0;i<4;i++)
            {
                *(banderas+i)=0;
                 aux=*(SR+posicion);
                 *(banderas+i)= *(banderas+i)|(aux<<0);
                aux=*(SR+posicion+1);
                 *(banderas+i)= *(banderas+i)|(aux<<8);
                aux=*(SR+posicion+2);
                 *(banderas+i)= *(banderas+i)|(aux<<16);
                aux=*(SR+posicion+3);
                 *(banderas+i)= *(banderas+i)|(aux<<24);
                posicion=posicion+4;

            }
    //........................................................................//

                itc=0;
                *(Rin+b)=0;
            }
        }
        else
            {
    //...................SALVO LOS REGISTROS Y LAS BANDERAS................//

            uint32_t aux;
            unsigned long posicion;
            int i;
            int registros[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1};
            *(Reg+13)=*(Reg+13)-(4*11);
            posicion=*(Reg+13);
            for(i=0; i<16; i++)
            {
                if(registros[i]==1)
                {
                    aux=*(Reg+i);
                    *(SR+posicion)=(aux);
                    *(SR+posicion+1)=(aux>>8);
                    *(SR+posicion+2)=(aux>>16);
                    *(SR+posicion+3)=(aux>>24);
                     posicion=posicion+4;

                }
            }
            for(i=0;i<4;i++)
            {
                aux=*(banderas+i);
                *(SR+posicion)=(aux);
                *(SR+posicion+1)=(aux>>8);
                *(SR+posicion+2)=(aux>>16);
                *(SR+posicion+3)=(aux>>24);
                 posicion=posicion+4;
            }

        //....................................................................//

            for(i=0;i<16;i++)
            {
                if(*(Rin+i)==1)
                    {
                        *(Reg+15)=i+1;
                        itc=1;
                        b=i;
                        break;
                    }
            }
            *(Reg+14)=-1;
            }
        }
    }



