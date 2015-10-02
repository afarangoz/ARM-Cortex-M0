
/*
#include "decoder.h"
#include "ALU.h"
#include "registros.h"
#include "desplazamiento.h"
#include "curses.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "PILA.h"
int main()
{

    uint32_t Reg[16]={2,0,3,4,0,0,0,0,0,0,0,0,0,5,0,0};
    //uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es V es 1 si hubo sobreflujo es la operacion

    unsigned int Registros[16]={1,0,1,1,0,0,0,0,0,0,0,0,0,0,0}; //orden decendente del refistro
    uint32_t PILA[5]={1,1,1,1,1};
    int i;
    for(i=4;i>=0;i--)
    {
        printf("%d \n",PILA[i]);
    }
    printf("\n");
    PUSH(Registros,&Reg[0],&PILA[0]);
    for(i=4;i>=0;i--)
    {
        printf("%d \n",PILA[i]);
    }
}

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
    Reg[1]=15;

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
    */


