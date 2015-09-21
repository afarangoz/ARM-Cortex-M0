#include "decoder.h"
#include "ALU.h"
#include "registros.h"
#include "desplazamiento.h"
#include "curses.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    uint32_t Reg[15]={0,0,0,0,0,0,0,0,0,0,0,0,0};   //Reg[13] ---> PC
                                                    //Reg[14] ---> LR

    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es V es 1 si hubo sobreflujo es la operacion
	//------- No modificar ------//
		int i, num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//

	while(1)
    {

	instruction = getInstruction(instructions[Reg[13]]);
	decodeInstruction(instruction,Reg,banderas);
    mostrar_registros(Reg);
    mostrar_banderas(banderas);
    mostrar_operacion(instructions[Reg[13]]);
	getch();
    Reg[13]++;


    }
    endwin();


	//------- No modificar ------//
	/* Libera la memoria reservada para las instrucciones */
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//

	return 0;
}
