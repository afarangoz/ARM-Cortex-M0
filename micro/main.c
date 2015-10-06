
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

int main(void)
{



    int i;
    uint32_t Reg[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   //Reg[13] ---> SP
                                                          //Reg[14] ---> LR
     Reg[13]=128 ;                                         //Reg[15] ---> PC
     uint8_t SRam[129];
     for(i=0;i<129;i++)
     {
        SRam[i]=255;
     }

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
	i=0; //LoadStore
	for(i=0;i<4;i++) //LS
     {
        SRam[i+12]=186+i;
     }
     SRam[15]=255;  //LS
     SRam[14]=189;
     i=0;
	while(1)
    { i++;//LoadStore
	instruction = getInstruction(instructions[Reg[15]]);
	decodeInstruction(instruction,Reg,banderas,&SRam[0]);
	if(i==7)                //LS
    {
        LDR(&Reg[0],12,0,&SRam[0],0);     //LS
        LDRB(&Reg[1],12,0,&SRam[0]);     //LS
        LDRH(&Reg[2],12,0,&SRam[0],0);     //LS
        LDRSB(&Reg[3],12,0,&SRam[0]);     //LS
        LDRSH(&Reg[4],12,0,&SRam[0]);     //LS
        STR(Reg[0],16,0,&SRam[0],0);     //LS
        STRB(Reg[0],20,0,&SRam[0]);     //LS
        STRH(Reg[0],24,0,&SRam[0],0);     //LS
    }
    mostrar_registros(Reg);
	mostrar_SRam(SRam);
    mostrar_banderas(banderas);
    mostrar_operacion(instructions[Reg[15]]);
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
}


