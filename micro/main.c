
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
#include "LoadStore.h"
#include "interrupciones.h"
#include "io.h"

extern port_t PORTA;
extern port_t PORTB;
extern uint8_t irq[16];	// Arreglo de interrupciones
						// Cada elemento es una interrupción por pin
int main(void)
{
    initIO();	// Inicializa los puertos de E/S
    int i;
    uint32_t Reg[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   //Reg[13] ---> SP
    uint16_t operacion=0;                                                      //Reg[14] ---> LR
    Reg[13]=256 ;                                        //Reg[15] ---> PC
    uint8_t SRam[257];
    for(i=0;i<=256;i++)
     {
        SRam[i]=255;
     }
     //SRam[0]=1; //Guardo en la Ram la posicion donde se encuentra el salto para ejecutar la interrupccion 1
    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es V es 1 si hubo sobreflujo es la operacion



	//------- No modificar ------//
		int num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("prueba.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; // Arreglo con las instrucciones
	//---------------------------//



    char tecla='z';
    char puerto;
	while(1)
    {
	instruction = getInstruction(instructions[Reg[15]]);
	decodeInstruction(instruction,Reg,banderas,&SRam[0],&operacion);
    if(tecla=='a')
    {
        puerto=getch();
        if(puerto=='0')
        {
            if((PORTA.Pins&1)==0)
            {
                changePinPortA(0,HIGH);
            }
            else
            {
                changePinPortA(0,LOW);
            }
        }
        if(puerto=='1')
        {
            if((PORTA.Pins&(1<<1))==0)
            {
                changePinPortA(1,HIGH);
            }
            else
            {
                changePinPortA(1,LOW);
            }
        }
        if(puerto=='2')
        {
            if((PORTA.Pins&(1<<2))==0)
            {
                changePinPortA(2,HIGH);
            }
            else
            {
                changePinPortA(2,LOW);
            }
        }
        if(puerto=='3')
        {
            if((PORTA.Pins&(1<<3))==0)
            {
                changePinPortA(3,HIGH);
            }
            else
            {
                changePinPortA(3,LOW);
            }
        }
        if(puerto=='4')
        {
            if((PORTA.Pins&(1<<4))==0)
            {
                changePinPortA(4,HIGH);
            }
            else
            {
                changePinPortA(4,LOW);
            }
        }
        if(puerto=='5')
        {
            if((PORTA.Pins&(1<<5))==0)
            {
                changePinPortA(5,HIGH);
            }
            else
            {
                changePinPortA(5,LOW);
            }
        }
        if(puerto=='6')
        {
            if((PORTA.Pins&(1<<6))==0)
            {
                changePinPortA(6,HIGH);
            }
            else
            {
                changePinPortA(6,LOW);
            }
        }
        if(puerto=='7')
        {
            if((PORTA.Pins&(1<<7))==0)
            {
                changePinPortA(7,HIGH);
            }
            else
            {
                changePinPortA(7,LOW);
            }
        }
    }
    if(tecla=='b')
    {
        puerto=getch();
        if(puerto=='0')
        {
            if((PORTB.Pins&1)==0)
            {
                changePinPortB(0,HIGH);
            }
            else
            {
                changePinPortB(0,LOW);
            }
        }
        if(puerto=='1')
        {
            if((PORTB.Pins&(1<<1))==0)
            {
                changePinPortB(1,HIGH);
            }
            else
            {
                changePinPortB(1,LOW);
            }
        }
        if(puerto=='2')
        {
            if((PORTB.Pins&(1<<2))==0)
            {
                changePinPortB(2,HIGH);
            }
            else
            {
                changePinPortB(2,LOW);
            }
        }
        if(puerto=='3')
        {
            if((PORTB.Pins&(1<<3))==0)
            {
                changePinPortB(3,HIGH);
            }
            else
            {
                changePinPortB(3,LOW);
            }
        }
        if(puerto=='4')
        {
            if((PORTB.Pins&(1<<4))==0)
            {
                changePinPortB(4,HIGH);
            }
            else
            {
                changePinPortB(4,LOW);
            }
        }
        if(puerto=='5')
        {
            if((PORTB.Pins&(1<<5))==0)
            {
                changePinPortB(5,HIGH);
            }
            else
            {
                changePinPortB(5,LOW);
            }
        }
        if(puerto=='6')
        {
            if((PORTB.Pins&(1<<6))==0)
            {
                changePinPortB(6,HIGH);
            }
            else
            {
                changePinPortB(6,LOW);
            }
        }
        if(puerto=='7')
        {
            if((PORTB.Pins&(1<<7))==0)
            {
                changePinPortB(7,HIGH);
            }
            else
            {
                changePinPortB(7,LOW);
            }
        }

    }
    //NVIC(&Reg[0],&banderas[0],&SRam[0],&irq[0]);


    showPorts();
    mostrar_registros(Reg);
	mostrar_SRam(SRam);
    mostrar_banderas(banderas);
    mostrar_operacion(instructions[Reg[15]]);
        //********Muestro la variable operacion********//
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(5));
    move(14, 50);
    printw("Operacion: %.X",operacion);
    refresh();
    attroff(COLOR_PAIR(5));
    //********************************************//
    for(i=0;i<=15;i++)
    {
        printf("-%d-",irq[i]);
    }
    printf("\n");

	tecla=getch();
    }
    endwin();


	//------- No modificar ------//
	// Libera la memoria reservada para las instrucciones
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//
	return 0;
}


