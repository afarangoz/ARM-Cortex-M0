/**
* \brief funcion que suma
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void ADD(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que resta
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void SUB(uint32_t *Rd, uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que producto logico a nivel de bit
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void AND(uint32_t *Rd, uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion OR
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void ORR(uint32_t *Rd, uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion que mueve datos de un registro a otro
* \param Rn Registro de entrada
* \param *Rm lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void MOV(uint32_t *Rm, uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion para ejecutar una AND entre un registro y el negado del otro
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void BIC(uint32_t *Rd,uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion para ejecutar una exclusive OR de Rm y Rn
* \param Rn Registro de entrada
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void EOR(uint32_t *Rd,uint32_t Rm,uint32_t Rn, uint32_t *banderas,char *op);


/**
* \brief funcion para ejecutar la operacion logica NOT a Rm
* \param Rm Registro de entrada
* \param *Rd lugar donde se almacenara el resultado.
* \param *op se identifica la operacion
* \return no hay retorno
*/
void MVN(uint32_t *Rd,uint32_t Rm, uint32_t *banderas,char *op);


/**
* \brief funcion para no hacer nada
* \param no tiene parametros de entrada
* \param *op se identifica la operacion
* \return no hay retorno
*/
void NOP(uint32_t *banderas,char *op);


/**
* \brief funcion sumar pero no guarda el valor pero no actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void CMN(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion restar pero no guarda el valor solo actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void CMP(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion realiza la operacion AND pero no guarda el valor solo actualiza banderas
* \param Rn Registro de entrada
* \param Rm registro de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void TST(uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que actualiza las banderas N y Z
* \param *Rd resultado
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void ACTNZ(uint32_t *Rd,uint32_t *banderas,char *op);


/**
* \brief funcion que efectua la suma normal y suma el carry
* \param *Rd registro donde se guarda el resultado
* \param Rm registro a sumar
* \param Rn registro a sumar
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void ADC(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que efectua la resta normal y resta el carry el carry
* \param *Rd registro donde se guarda el resultado
* \param Rm registro a de entrada
* \param Rn registro a restar con el de entrada
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void SBC(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);


/**
* \brief funcion que efectua el complemento a dos de un registro
* \param *Rd registro donde se guarda el resultado
* \param Rm registro al que se le aplicara el complemento
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void RSB(uint32_t *Rd,uint32_t Rm,uint32_t *banderas,char *op);

/**
* \brief funcion que efectue el producto de dos registros sin signo
* \param *Rd registro donde se guarda el resultado
* \param Rm registro a multiplicar
* \param Rn registro a multiplicar
* \param *banderas direccion de memoria de la bandera cero "N"
* \param *op se identifica la operacion
* \return no hay retorno
*/
void MUL(uint32_t *Rd,uint32_t Rm,uint32_t Rn,uint32_t *banderas,char *op);




