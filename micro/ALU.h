/**
* \brief funcion que suma
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que resta
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que producto logico a nivel de bit
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void AND(uint32_t *Rd, uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion OR
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void ORR(uint32_t *Rd, uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion que mueve datos de un registro a otro
* \param Rn Registro de entrada
* \param *Rm lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void MOV(uint32_t *Rm, uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion para ejecutar una AND entre un registro y el negado del otro
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void BIC(uint32_t *Rd,uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion para ejecutar una exclusive OR de Rm y Rn
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void EOR(uint32_t *Rd,uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion para ejecutar la operacion logica NOT a Rm
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \return no hay retorno
*/
void MVN(uint32_t *Rd,uint32_t Rm, uint32_t *banderas,char *op);


/**
* \brief funcion para no hacer nada
* \param no tiene parametros de entrada
* \return no hay retorno
*/
void NOP(uint32_t *banderas,char *op);


/**
* \brief funcion sumar pero no guarda el valor pero no actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void CMN(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion restar pero no guarda el valor solo actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void CMP(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion realiza la operacion AND pero no guarda el valor solo actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void TST(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion para actualizar las banderas del microprocesador
* \param tipo_opercion a cada funcion se le asigna un entero en el .c de la libreria y esto indica que tipo de operacion aritmetico logica se efectua
* \param Rn Registro de entrada de la operacion aritmetico logica
* \param Rm Registro de entrada de la operacion aritmetico logica
* \param *Rd es la direccion donde se guarda el resultado de la operacion que se hizo
* \param *banderas es el valor de la posicion cero en el arreglo banderas
* \return no hay retorno
*/
void actualizar(uint32_t tipo_operacion,uint32_t Rm,uint32_t Rn,uint32_t Rd,uint32_t *banderas);





