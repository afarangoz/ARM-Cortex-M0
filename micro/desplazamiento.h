
/**
* \brief funcion para hacer un desplazamiento aritmetico a la derecha
* \param *Rd variable donde se almacena el desplazamiento
* \param Rm registro que se desplazara
* \param num numero de bits que se desplazara
* \param *banderas direccion de memoria de la las banderas
* \return no hay retorno
*/
void ASRS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas);

/**
* \brief funcion para desplazar el dato Rm cierta cantidad de veces hacia la izquierda
* \param *Rd registro donde se guardara el dato desplazado
* \param Rm registro que se desplazara
* \param num numero de bits que se desplazara el dato Rm
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void LSLS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas);

/**
* \brief funcion para desplazar el dato Rm cierta cantidad de veces hacia la derecha
* \param *Rd registro donde se guardara el dato desplazado
* \param Rm registro que se desplazara
* \param num numero de bits que se desplazara el dato Rm
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void LSRS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas);

/**
* \brief funcion para desplazar paquetes de 8 bits
* \param *Rd variable donde se almacena el desplazamiento
* \param Rm registro que se desplazara
* \return no hay retorno
*/
void REV(uint32_t *Rd,uint32_t Rm);

/**
* \brief funcion para desplazar paquetes de 16 bits
* \param *Rd variable donde se almacena el desplazamiento
* \param Rm registro que se desplazara
* \return no hay retorno
*/
void REV16(uint32_t *Rd,uint32_t Rm);

/**
* \brief funcion para intercambiar los dos byts menos significativos.
* \param *Rd variable donde se almacena el desplazamiento
* \param Rm registro que se desplazara
* \return no hay retorno
*/
void REVSH(uint32_t *Rd,uint32_t Rm);

/**
* \brief funcion para rotar hacia la derecha un dato
* \param *Rd variable donde se almacena la rotacion
* \param Rm registro que se rotara
* \param num numero de bits que se rotara el dato Rm
* \param *banderas direccion de memoria de las banderas
* \return no hay retorno
*/
void RORS(uint32_t *Rd,uint32_t Rm,uint32_t num,uint32_t *banderas);
