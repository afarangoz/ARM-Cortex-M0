
#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include "ALU.h"
#include <math.h>
#include <curses.h>
#include <string.h>

int main()
{
    char op[5];
    uint32_t Reg[13]={0,0,0,0,0,0,0,0,0,0,0};
    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es V es 1 si hubo sobreflujo es la operacion

    REV(&Reg[1],Reg[2]);
    REV16(&Reg[1],Reg[2]);

    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    getch();	// Espera entrada del usuario
	clear();

    ADD(&Reg[2], Reg[0],Reg[1],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	Reg[0]=15;
    Reg[1]=-15;

    SUB(&Reg[2], Reg[0],Reg[1],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

    AND(&Reg[2], Reg[0],Reg[1],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

    ORR(&Reg[2], Reg[0],Reg[1],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	MOV(&Reg[1], Reg[0],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	BIC(&Reg[2], Reg[0],Reg[1],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	EOR(&Reg[2], Reg[0],Reg[1],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	MVN(&Reg[1], Reg[0],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	NOP(&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	CMN(Reg[1], Reg[0],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	CMP(Reg[1], Reg[0],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();

	TST(Reg[1], Reg[0],&banderas[0],&op[0]);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(op);
	getch();
	clear();


	endwin();	// Finaliza el modo curses

    return 0;
}

