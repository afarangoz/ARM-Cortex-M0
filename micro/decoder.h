#ifndef _DECODER_H_
#define	_DECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


typedef struct
{
	char** array;
}ins_t;


typedef struct
{
	char mnemonic[10];
	char op1_type;
	char op2_type;
	char op3_type;
	uint32_t op1_value;
	uint32_t op2_value;
	uint32_t op3_value;
	uint8_t  registers_list[16];
}instruction_t;


/** \fn void decodeInstruction(instruction_t instruction)
    \brief Decodifica la instrucción y la ejecuta.
    \param instruction instrucción a decodificar y ejecutar.
*/
void decodeInstruction(instruction_t instruction,uint32_t *Reg,uint32_t *banderas, uint8_t *pila,uint16_t *operacion);

/** \fn instruction_t getInstruction(char* instStr)
    \brief Obtiene la instrucción separada por partes.
    \param instrStr cadena que contiene la instrucción.
    \param *operacion almacenara la direccion asignada en memoria para una instruccion especifica
	\return instruction_t la instrucción separada por partes.
*/
instruction_t getInstruction(char* instStr);

/** \fn int readFile(char** instructions)
    \brief Lee instrucciones de un archivo.
    \param filename Nombre del archivo.
    \param instructions estructura con arreglo con las instrucciones leidas.
	\return Entero indicando la cantidad de líneas.
*/
int readFile(char* filename, ins_t* instructions);

/** \fn int countLines(FILuint32_tE fp)
    \brief Cuenta la cantidad de líneas de un archivo.
    \param fp Puntero al archivo.
	\return Entero con la cantidad de líneas del archivo.
*/
int countLines(FILE* fp);

#endif /*_DECODER_H_*/
