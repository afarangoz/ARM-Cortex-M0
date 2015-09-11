#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include "ALU.h"
#include <math.h>
#include <curses.h>

int main()
{
    uint32_t Reg[13]={0,0,0,0,0,0,0,0,0,0,0};
    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es V es 1 si hubo sobreflujo es la operacion
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    getch();	// Espera entrada del usuario
	clear();

	Reg[0]=15;
    Reg[1]=-15;
    REV(&Reg[1],Reg[2]);
    REV16(&Reg[1],Reg[2]);
    ADD(&Reg[2], Reg[0],Reg[1],&banderas[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
	getch();
	clear();

	Reg[0]=15;
    Reg[1]=-15;
    SUB(&Reg[2], Reg[0],Reg[1],&banderas[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
	getch();
	clear();


	endwin();	// Finaliza el modo curses

    return 0;
}

