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
#include "LoadStore.h"
#include "interrupciones.h"

int main(void)
{
    int i,h=0;
    uint32_t Reg[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   //Reg[13] ---> SP
                                                          //Reg[14] ---> LR
     Reg[13]=256 ;                                        //Reg[15] ---> PC
     uint8_t SRam[257];
     for(i=0;i<=256;i++)
     {
        SRam[i]=255;
     }
     for(i=0;i<=32;i++)
     {
        SRam[i]=180+i;
     }
     SRam[0]=1; //Guardo en la Ram la posicion donde se encuentra el salto para ejecutar la interrupccion 1
    uint32_t  Rin[16]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//Arreglo que me indica cual interrupccion esta activa

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
	while(1)
    {
	instruction = getInstruction(instructions[Reg[15]]);//aqui esta el error
	decodeInstruction(instruction,Reg,banderas,&SRam[0]);
	if(h>=3){
    NVIC(&Reg[0],&banderas[0],&SRam[0],&Rin[0]);
    }
    mostrar_registros(Reg);
	mostrar_SRam(SRam);
    mostrar_banderas(banderas);
    mostrar_operacion(instructions[Reg[15]]);
    h++;
	getch();
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
}*/


