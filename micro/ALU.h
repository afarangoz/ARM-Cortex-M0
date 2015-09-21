/**
* \brief funcion que efectua la suma normal y suma el carry
* \param *Rd registro donde se guarda el resultado
* \param Rm registro a sumar
* \param Rn registro a sumar
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void ADCS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion que suma
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas  direccion de memoria de las banderas
* \return no hay retorno
*/
void ADDS(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion que suma pero no actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn);

/**
* \brief funcion que producto logico a nivel de bit
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/

void ANDS(uint32_t *Rd, uint32_t Rm,uint32_t Rn, uint32_t *banderas);

/**
* \brief funcion para ejecutar una AND entre un registro y el negado del otro
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void BICS(uint32_t *Rd,uint32_t Rm,uint32_t Rn, uint32_t *banderas);

/**
* \brief funcion sumar pero no guarda el resultado
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void CMN(uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion restar pero no guarda el valor solo actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion en memoria de las banderas
* \return no hay retorno
*/
void CMP(uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion para ejecutar una exclusive OR bit a bit con los dos registros de entrada
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void EORS(uint32_t *Rd,uint32_t Rm,uint32_t Rn, uint32_t *banderas);

/**
* \brief funcion que mueve datos de un registro a otro pero no actualiza banderas
* \param Rn Registro que se va a mover
* \param *Rm lugar donde se almacenaria el resultado.
* \return no hay retorno
*/
void MOV(uint32_t *Rm, uint32_t Rn);

/**
* \brief funcion que mueve datos de un registro a otro
* \param Rn Registro que se mueve
* \param *Rm lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void MOVS(uint32_t *Rm, uint32_t Rn, uint32_t *banderas);

/**
* \brief funcion que efectue el producto de dos registros sin signo
* \param *Rd registro donde se guarda el resultado
* \param Rm registro a multiplicar
* \param Rn registro a multiplicar
* \param *banderas direccion de memoria de las bandera
* \return no hay retorno
*/
void MULS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion para ejecutar la operacion logica NOT a Rm
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de las bandera
* \return no hay retorno
*/
void MVNS(uint32_t *Rd,uint32_t Rm, uint32_t *banderas);

/**
* \brief funcion para no hacer nada
* \param no tiene parametros de entrada
* \return no hay retorno
*/
void NOP();

/**
* \brief funcion OR
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \return no hay retorno
*/
void ORRS(uint32_t *Rd, uint32_t Rm,uint32_t Rn, uint32_t *banderas);

/**
* \brief funcion que efectua el complemento a dos de un registro
* \param *Rd registro donde se guarda el resultado
* \param Rm registro al que se le aplicara el complemento
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void RSBS(uint32_t *Rd,uint32_t Rm,uint32_t *banderas);

/**
* \brief funcion que efectua la resta normal y resta el carry
* \param *Rd registro donde se guarda el resultado
* \param Rm registro a de entrada
* \param Rn registro a restar con el de entrada
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void SBCS(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion que resta y actualiza las banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memora de las banderas
* \return no hay retorno
*/
void SUBS(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas);

/**
* \brief funcion que resta
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \return no hay retorno
*/
void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn);

/**
* \brief funcion realiza la operacion AND pero no guarda el valor solo actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void TST(uint32_t Rm,uint32_t Rn,uint32_t *banderas);


/**
* \brief funcion que actualiza las banderas N y Z
* \param *Rd resultado
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void ACTNZ(uint32_t *Rd,uint32_t *banderas);












