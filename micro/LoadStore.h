/**
* \brief funcion para cargar un dato de la RAM al registro Rt
* \param *Rt resultado
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram puede ser un dato o un inmediato
* \param imm es 1 si Rm es un inmediato cero en caso de ser un registro
* \param *SRAM posicion cero de la memoria RAM
* \return no hay retorno
*/
void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm);


/**
* \brief funcion para cargar 8 bits de la RAM al registro Rt
* \param *Rt resultado
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram puede ser un dato o un inmediato
* \param *SRAM posicion cero de la memoria RAM
* \return no hay retorno
*/
void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);


/**
* \brief funcion para cargar 16 bits de la RAM al registro Rt
* \param *Rt resultado
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram puede ser un dato o un inmediato
* \param *SRAM posicion cero de la memoria RAM
* \param imm es 1 si Rm es un inmediato cero en caso de ser un registro
* \return no hay retorno
*/
void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm);


/**
* \brief funcion para cargar 8 bits de la RAM al registro Rt con extension de signo
* \param *Rt resultado
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram
* \param *SRAM posicion cero de la memoria RAM
* \return no hay retorno
*/
void LDRSB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);


/**
* \brief funcion para cargar 16 bits de la RAM al registro Rt con extension de signo
* \param *Rt resultado
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram
* \param *SRAM posicion cero de la memoria RAM
* \return no hay retorno
*/
void LDRSH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);


/**
* \brief funcion que toma un registro y lo escribe en cierta direccion de memoria
* \param Rt dato a escribir
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram
* \param *SRAM posicion cero de la memoria RAM
* \param imm indica si Rm es inmediato si es 1 cero de lo contrario
* \return no hay retorno
*/
void STR(uint32_t Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm);


/**
* \brief funcion almacena los primeros 8 bits de un registro en cierta direccion de la RAM
* \param Rt dato a escribir
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram
* \param *SRAM posicion cero de la memoria RAM
* \return no hay retorno
*/
void STRB(uint32_t Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);


/**
* \brief funcion almacena los primeros 16 bits de un registro en cierta direccion de la RAM
* \param Rt dato a escribir
* \param Rn posicion de memoria en ram
* \param Rm posicion de memoria en ram
* \param *SRAM posicion cero de la memoria RAM
* \param imm indica si Rm es inmediato si es 1 cero de lo contrario
* \return no hay retorno
*/
void STRH(uint32_t Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM,uint32_t imm);
