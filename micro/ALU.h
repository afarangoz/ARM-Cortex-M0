/**
* \brief funcion que suma
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas);


/**
* \brief funcion que resta
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas);


/**
* \brief funcion que producto logico a nivel de bit
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void AND(uint32_t *Rd, uint32_t Rm,uint32_t Rn);


/**
* \brief funcion OR
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void ORR(uint32_t *Rd, uint32_t Rm,uint32_t Rn);


/**
* \brief funcion que mueve datos de un registro a otro
* \param Rn Registro de entrada
* \param *Rm lugar donde se almacenara el resultado.
* \return no hay retorno
*/
void MOV(uint32_t *Rm, uint32_t Rn);


/**
* \brief funcion para actualizar las banderas del microprocesador
* \param tipo_opercion a cada funcion se le asigna un entero en el .c de la libreria y esto indica que tipo de operacion aritmetico logica se efectua
* \param Rn Registro de entrada de la operacion aritmetico logica
* \param Rm Registro de entrada de la operacion aritmetico logica
* \param *banderas es el valor de la posicion cero en el arreglo banderas
* \return no hay retorno
*/
void actualizar(uint32_t tipo_operacion,uint32_t Rn,uint32_t Rm,uint32_t *banderas);



