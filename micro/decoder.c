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


//MOVS R0,#5
/*mnemonico = MOVS
op1_type = R
op1_value = 0
op2_type = #
op2_value = 5
*/
void decodeInstruction(instruction_t instruction,uint32_t *Reg,uint32_t *banderas)
{
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ){

        if(instruction.op1_type=='R' && instruction.op2_type=='#'){
            MOVS(&Reg[instruction.op1_value], instruction.op2_value,banderas);
        }
        if(instruction.op1_type=='R' && instruction.op2_type=='R'){
            MOVS(&Reg[instruction.op1_value], Reg[instruction.op2_value],banderas);
        }
	}

	if( strcmp(instruction.mnemonic,"MOV") == 0 ){

        if(instruction.op1_type=='R' && instruction.op2_type=='#'){
            MOV(&Reg[instruction.op1_value], instruction.op2_value);
        }
        if(instruction.op1_type=='R' && instruction.op2_type=='R'){
            MOV(&Reg[instruction.op1_value], Reg[instruction.op2_value]);
        }
	}

	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){

        if( instruction.op2_type=='R' && instruction.op3_type=='R' )
	    {
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
	        ADDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        if(instruction.op3_type=='N' )
	    {
	        ADDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
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

	}

	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
        ADCS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"ANDS") == 0 ){
        ANDS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"ASRS") == 0 ){
        if( instruction.op2_type=='R' && instruction.op3_type=='#' )
	    {
	        ASRS(&Reg[instruction.op1_value], Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='R'&& instruction.op3_type=='R' )
	    {
	        ASRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
	}

	if( strcmp(instruction.mnemonic,"BICS") == 0 ){
        BICS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"CMN") == 0 ){
        CMN(Reg[instruction.op1_value], Reg[instruction.op2_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"CMP") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R' )
	    {
	        CMP(Reg[instruction.op1_value],Reg[instruction.op2_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='#' )
	    {
	        CMP(Reg[instruction.op1_value],instruction.op2_value,banderas);
	    }
	}

	if( strcmp(instruction.mnemonic,"EORS") == 0 ){
        EORS(&Reg[instruction.op1_value], Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"LSRS") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R' && instruction.op3_type=='R' )
	    {
	        LSRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op3_type=='#' && instruction.op2_type=='R' )
	    {
	        LSRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
	}

	if( strcmp(instruction.mnemonic,"LSLS") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R'&& instruction.op3_type=='R')
	    {
	        LSLS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='R'&&instruction.op3_type=='#' )
	    {
	        LSLS(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
	}


	if( strcmp(instruction.mnemonic,"MULS") == 0 ){

        MULS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"MVNS") == 0 ){

        MVNS(&Reg[instruction.op1_value],Reg[instruction.op2_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"NOP") == 0 ){

        NOP();
	}

	if( strcmp(instruction.mnemonic,"ORRS") == 0 ){

        ORRS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"REV") == 0 ){

        REV(&Reg[instruction.op1_value],Reg[instruction.op2_value]);
	}

	if( strcmp(instruction.mnemonic,"REV16") == 0 ){

        REV16(&Reg[instruction.op1_value],Reg[instruction.op2_value]);
	}

	if( strcmp(instruction.mnemonic,"REVSH") == 0 ){

        REVSH(&Reg[instruction.op1_value],Reg[instruction.op2_value]);
	}

	if( strcmp(instruction.mnemonic,"RORS") == 0 ){

        RORS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}



	if( strcmp(instruction.mnemonic,"RSBS") == 0 ){

        RSBS(&Reg[instruction.op1_value],instruction.op2_value,banderas);
	}



	if( strcmp(instruction.mnemonic,"SBCS") == 0 ){

        SBCS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	}

	if( strcmp(instruction.mnemonic,"SUBS") == 0 ){

        if( instruction.op1_type=='R' && instruction.op2_type=='R' )
	    {
	        SUBS(&Reg[instruction.op1_value],Reg[instruction.op2_value],Reg[instruction.op3_value],banderas);
	    }
        if( instruction.op1_type=='R' && instruction.op2_type=='#' )
	    {
	        SUBS(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value,banderas);
	    }
	}

	if( strcmp(instruction.mnemonic,"SUB") == 0 ){
	        SUB(&Reg[instruction.op1_value],Reg[instruction.op2_value],instruction.op3_value);
	}

	if( strcmp(instruction.mnemonic,"TST") == 0 ){

        TST(Reg[instruction.op1_value],Reg[instruction.op2_value],banderas);
	}


/*...............BRANCH.................*/

	if( strcmp(instruction.mnemonic,"B") == 0){
        B(&Reg[13],instruction.op1_value);
	}

	if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
        BEQ(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BNE") == 0 ){
        BNE(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BCS") == 0 ){
        BCS(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BCC") == 0 ){
        BCC(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BMI") == 0 ){
        BMI(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BPL") == 0 ){
        BPL(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BVS") == 0 ){
        BVS(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BVC") == 0 ){
        BVC(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BHI") == 0 ){
        BHI(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BLS") == 0 ){
        BLS(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BGE") == 0 ){
        BGE(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BLT") == 0 ){
        BLT(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BGT") == 0 ){
        BGT(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BLE") == 0 ){
        BLE(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BAL") == 0 ){
        BAL(&Reg[13],instruction.op1_value,banderas);
	}

	if( strcmp(instruction.mnemonic,"BL") == 0 ){
        BL(&Reg[14],&Reg[13],Reg[instruction.op1_value]);
	}

	if( strcmp(instruction.mnemonic,"BLX") == 0 ){
        BLX(&Reg[14],&Reg[13],Reg[instruction.op1_value]);
	}












}



instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
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
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}

		split = strtok(NULL, " ,.");
		num++;
	}

	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
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