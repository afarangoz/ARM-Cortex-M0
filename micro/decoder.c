#include "decoder.h"
#include "ALU.h"
#include "registros.h"
#include "desplazamiento.h"
#include "curses.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "branch.h"
#include "LoadStore.h"
#include "PILA.h"


//MOVS R0,#5
/*mnemonico = MOVS
op1_type = R
op1_value = 0
op2_type = #
op2_value = 5
*/
void decodeInstruction(instruction_t instruction,uint32_t *Reg,uint32_t *banderas, uint8_t *SR,uint16_t *operacion)
{
    uint32_t imm;
    /*....................Load-Store...................*/

 	if( strcmp(instruction.mnemonic,"LDR") == 0 ){

        if(instruction.op3_type=='#'){
            imm=(uint32_t)instruction.op3_value;
            if(instruction.op2_value==13)
            {
                *operacion=38912+(instruction.op1_value<<8)+instruction.op3_value;
            }
            else
            {
                *operacion=26624+(instruction.op1_value)+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            }
            LDR(&Reg[instruction.op1_value],Reg[instruction.op2_value],imm,SR,1);
        }
        if(instruction.op3_type=='R'){
            *operacion=22528+(instruction.op1_value)+(instruction.op2_value<<3)+(instruction.op3_value<<6);

            LDR(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR,0);
        }
        Reg[15]++;
 	}

 	if( strcmp(instruction.mnemonic,"LDRB") == 0 ){
        if(instruction.op3_type=='#'){
            *operacion=30720+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op1_value<<6);
            imm=(uint32_t)instruction.op3_value;
            LDRB(&Reg[instruction.op1_value],Reg[instruction.op2_value],imm,SR);
        }
        if(instruction.op3_type=='R'){
            *operacion=23552+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            LDRB(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR);
        }
        Reg[15]++;
 	}

 	if( strcmp(instruction.mnemonic,"LDRH") == 0 ){

        if(instruction.op3_type=='#'){
            *operacion=34816+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            imm=(uint32_t)instruction.op3_value;

            LDRH(&Reg[instruction.op1_value],Reg[instruction.op2_value],imm,SR,1);
        }
        if(instruction.op3_type=='R'){
            *operacion=34816+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            LDRH(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR,0);
        }
        Reg[15]++;
 	}

 	if( strcmp(instruction.mnemonic,"LDRSB") == 0 ){
        *operacion=22016+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
        LDRSB(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR);
        Reg[15]++;
 	}

 	if( strcmp(instruction.mnemonic,"LDRSH") == 0 ){
        *operacion=24064+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
        LDRSH(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR);
        Reg[15]++;
 	}

 	if( strcmp(instruction.mnemonic,"STR") == 0 ){
        if(instruction.op3_type=='#'){
            if(instruction.op2_value==13)
            {
                *operacion=36864+(instruction.op1_value<<8)+(instruction.op3_value);
            }
            else
            {
                *operacion=24576+(instruction.op1_value)+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            }
            imm=(uint32_t)instruction.op3_value;
            STR(Reg[instruction.op1_value],Reg[instruction.op2_value],imm,SR,1);
        }
        if(instruction.op3_type=='R'){
            *operacion=20480+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            STR(Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR,0);
        }
        Reg[15]++;
 	}
 	if( strcmp(instruction.mnemonic,"STRB") == 0 ){
            if(instruction.op3_type=='#')
            {
                STRB(Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,SR);
                *operacion=28672+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            }
            else
            {
                STRB(Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR);
                *operacion=21504+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            }
        Reg[15]++;
 	}
 	if( strcmp(instruction.mnemonic,"STRH") == 0 ){
        if(instruction.op3_type=='#'){
            *operacion=32768+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            imm=(uint32_t)instruction.op3_value;
            STR(Reg[instruction.op1_value],Reg[instruction.op2_value],imm,SR,1);
        }
        if(instruction.op3_type=='R'){
            *operacion=20992+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
            STR(Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],SR,0);
        }
        Reg[15]++;
 	}



    /*......................................*/
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ){

        if(instruction.op1_type=='R' && instruction.op2_type=='#'){
            *operacion=8192+(instruction.op1_value<<8)+instruction.op2_value;
            MOVS(&Reg[instruction.op1_value], instruction.op2_value,banderas);
        }
        if(instruction.op1_type=='R' && instruction.op2_type=='R'){
            *operacion=instruction.op1_value+(instruction.op2_value<<3);
            MOVS(&Reg[instruction.op1_value], Reg[instruction.op2_value],banderas);
        }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"MOV") == 0 ){

        if(instruction.op1_type=='R' && instruction.op2_type=='#'){
            *operacion=8192+(instruction.op1_value<<8)+instruction.op2_value;
            MOV(&Reg[instruction.op1_value], instruction.op2_value);
        }
        if(instruction.op1_type=='R' && instruction.op2_type=='R'){
            *operacion=17920+instruction.op1_value+(instruction.op1_value<<3);
            MOV(&Reg[instruction.op1_value], Reg[instruction.op2_value]);
        }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){

        if( instruction.op2_type=='R' && instruction.op3_type=='R' )
	    {
	        *operacion=6144+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
	        ADDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op2_type=='#' && instruction.op3_type=='R' )
	    {
	        ADDS(&Reg[instruction.op1_value], instruction.op2_value,Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op2_type=='#' && instruction.op3_type=='#' )
	    {
	        ADDS(&Reg[instruction.op1_value], instruction.op2_value,instruction.op3_value,banderas);
	    }
        if( instruction.op2_type=='R' && instruction.op3_type=='#' )
	    {
	        *operacion=7168+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
	        ADDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        if(instruction.op3_type=='N' )
	    {
	        ADDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"ADD") == 0 ){

        if(instruction.op3_type=='N' )
	    {
            ADD(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value]);
	    }
        if(instruction.op3_type=='#' )
	    {
            ADD(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value);
	    }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
        *operacion=16704+instruction.op1_value+(instruction.op2_value<<3);
        ADCS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"ANDS") == 0 ){
        *operacion=16384+instruction.op2_value+(instruction.op3_value<<3);
        ANDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"ASRS") == 0 ){
        if( instruction.op2_type=='R' && instruction.op3_type=='#' )
	    {
	        *operacion=4096+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
	        ASRS(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='R'&& instruction.op3_type=='R' )
	    {
	        *operacion=16640+instruction.op2_value+(instruction.op3_value<<3);
	        ASRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"BICS") == 0 ){
        *operacion=17280+instruction.op2_value+(instruction.op3_value<<3);
        BICS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"CMN") == 0 ){
        *operacion=17088+instruction.op1_value+(instruction.op2_value<<3);
        CMN(Reg[instruction.op1_value], Reg[instruction.op2_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"CMP") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R' )
	    {
	        *operacion=17024+instruction.op1_value+(instruction.op2_value<<3);
	        CMP(Reg[instruction.op1_value],Reg[instruction.op2_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='#' )
	    {
	        *operacion=10240+(instruction.op1_value<<8)+instruction.op2_value;
	        CMP(Reg[instruction.op1_value],instruction.op2_value,banderas);
	    }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"EORS") == 0 ){
        *operacion=16448+instruction.op1_value+(instruction.op2_value<<3);
        EORS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"LSRS") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R' && instruction.op3_type=='R' )
	    {
	        *operacion=16576+instruction.op2_value+(instruction.op3_value<<3);
	        LSRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op3_type=='#' && instruction.op2_type=='R' )
	    {
	        *operacion=2048+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
	        LSRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"LSLS") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R'&& instruction.op3_type=='R')
	    {
	        *operacion=16512+instruction.op2_value+(instruction.op3_value<<3);
	        LSLS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='R'&&instruction.op3_type=='#' )
	    {
	        *operacion=instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
	        LSLS(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        Reg[15]++;
	}


	if( strcmp(instruction.mnemonic,"MULS") == 0 ){

        *operacion=17216+instruction.op1_value+(instruction.op2_value<<3);
        MULS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"MVNS") == 0 ){

        *operacion=17344+instruction.op1_value+(instruction.op2_value<<3);
        MVNS(&Reg[instruction.op1_value],Reg[instruction.op2_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"NOP") == 0 ){

        *operacion=48896;
        NOP();
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"ORRS") == 0 ){

        *operacion=17152+instruction.op2_value+(instruction.op3_value<<3);
        ORRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"REV") == 0 ){

        *operacion=47616+instruction.op1_value+(instruction.op2_value<<3);
        REV(&Reg[instruction.op1_value],Reg[instruction.op2_value]);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"REV16") == 0 ){

        *operacion=47680+instruction.op1_value+(instruction.op2_value<<3);
        REV16(&Reg[instruction.op1_value],Reg[instruction.op2_value]);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"REVSH") == 0 ){

        *operacion=47808+(instruction.op1_value)+(instruction.op2_value<<3);
        REVSH(&Reg[instruction.op1_value],Reg[instruction.op2_value]);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"RORS") == 0 ){

        *operacion=16832+instruction.op2_value+(instruction.op3_value<<3);
        RORS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"RSBS") == 0 ){

        *operacion=16960+instruction.op1_value+(instruction.op2_value<<3);
        RSBS(&Reg[instruction.op1_value],instruction.op2_value,banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"SBCS") == 0 ){

        *operacion=16768+instruction.op2_value+(instruction.op3_value<<3);
        SBCS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"SUBS") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R' )
	    {
	        *operacion=6656+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
	        SUBS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op3_type=='#' )
	    {
	        *operacion=14336+instruction.op3_value+(instruction.op2_value);
	        SUBS(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"SUB") == 0 ){

        *operacion=6656+instruction.op1_value+(instruction.op2_value<<3)+(instruction.op3_value<<6);
        SUB(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value);
        Reg[15]++;
	}

	if( strcmp(instruction.mnemonic,"TST") == 0 ){

        *operacion=16896+instruction.op1_value+(instruction.op2_value<<3);
        TST(Reg[instruction.op1_value],Reg[instruction.op2_value],banderas);
        Reg[15]++;
	}


/*...............BRANCH.................*/



	if( strcmp(instruction.mnemonic,"B") == 0){
        *operacion=53248+instruction.op1_value;
        B(&Reg[15],instruction.op1_value);
	}

	if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
        BEQ(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BNE") == 0 ){
        BNE(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BCS") == 0 ){
        BCS(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BCC") == 0 ){
        BCC(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BMI") == 0 ){
        BMI(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BPL") == 0 ){
        BPL(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BVS") == 0 ){
        BVS(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BVC") == 0 ){
        BVC(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BHI") == 0 ){
        BHI(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BLS") == 0 ){
        BLS(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BGE") == 0 ){
        BGE(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BLT") == 0 ){
        BLT(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BGT") == 0 ){
        BGT(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BLE") == 0 ){
        BLE(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BAL") == 0 ){
        BAL(&Reg[15],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BL") == 0 ){
        BL(&Reg[14],&Reg[15],instruction.op1_value);
        }

	if( strcmp(instruction.mnemonic,"BLX") == 0 ){
        *operacion=18304+(instruction.op1_value<<3);
        BLX(&Reg[14],&Reg[15],Reg[instruction.op1_value]);
	}

	if( strcmp(instruction.mnemonic,"BX") == 0 ){
        *operacion=18176+(instruction.op1_value<<3);
        BX(&Reg[15],&Reg[14]);
	}

	if( strcmp(instruction.mnemonic,"PUSH") == 0 ){
        PUSH(instruction.registers_list,Reg,SR);
        Reg[15]++;
	}
	if( strcmp(instruction.mnemonic,"POP") == 0 ){
        POP(instruction.registers_list,Reg,SR);
        Reg[15]++;
	}
}


instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:

                if(split[0] == '[')
				split++;
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}


int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}
