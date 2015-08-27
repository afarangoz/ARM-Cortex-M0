/**
* \brief funcion que suma
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void ADD(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn,unsigned int *banderas);


/**
* \brief funcion que resta
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void SUB(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn);


/**
* \brief funcion que producto logico a nivel de bit
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void BIC(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn);


/**
* \brief funcion OR
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void OR(unsigned long int *Rd, unsigned long int Rm,unsigned long int Rn);


/**
* \brief funcion que mueve datos de un registro a otro
* \param Rn Registro de entrada
* \param *Rm lugar donde se almacenara el resultado.
* \return no hay retorno
*/
void MOV(unsigned long int *Rm, unsigned long int Rn);


/**
* \brief funcion para actualizar las banderas del microprocesador
* \param tipo_opercion a cada funcion se le asigna un entero en el .c de la libreria y esto indica que tipo de operacion aritmetico logica se efectua
* \param Rn Registro de entrada de la operacion aritmetico logica
* \param Rm Registro de entrada de la operacion aritmetico logica
* \param bandera es el valor de la posicion cero en el arreglo banderas
* \return no hay retorno
*/
void actualizar(unsigned int tipo_operacion,unsigned long int Rn,unsigned long int Rm,unsigned int *banderas);



