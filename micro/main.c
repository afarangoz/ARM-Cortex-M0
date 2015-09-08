/*
#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include "ALU.h"
#include <math.h>
#include <curses.h>

int main()
{
    uint32_t Reg[13];
    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es U es 1 si hubo sobreflujo es la operacion



    Reg[1]=pow(2,31);
    Reg[2]=0;
    Reg[4]=Reg[2];

    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    getch();	 // Espera entrada del usuario
	clear();

	Reg[1]=pow(2,31);
    Reg[2]=30;
    Reg[4]=Reg[2];
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
	getch();
	clear();


	endwin();	// Finaliza el modo curses

    return 0;

}    */
