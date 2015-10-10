

/**
* \brief funcion que me controla la interrupcion que se va a ejecutar
* \param *Reg direccion en memoria de los registros
* \param *banderas direccion en memoria de las banderas
* \param *SR direccion en memoria de la SRAM
* \param *Rin direccion en memoria del arreglo donde se encuentra la interrupccion que se va a ejecutar
* \return no hay retorno
*/
void NVIC( uint32_t *Reg,uint32_t *banderas, uint8_t *SR, uint32_t *Rin);
