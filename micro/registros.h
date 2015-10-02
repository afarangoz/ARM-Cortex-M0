
/**
* \brief Funcion que toma los valores de los registros y los imprime en pantalla
* \param registro[13] Arreglo que contiene cada 1 de los registros
* \return No tiene retorno
*/

void mostrar_registros(uint32_t* registro);



/**
* \brief Funcion que toma los valores de las banderas y los imprime en pantalla
* \param banderas[4] Arreglo que contiene cada 1 de las banderas
* \return No tiene retorno
*/

void mostrar_banderas( uint32_t banderas[4]);



/**
* \brief Funcion que muestra la operacion que se realizo
* \param op[5] variable tipo caracter donde se gusrda el nombre de la operacion realizada
* \return No tiene retorno
*/

void mostrar_operacion( char *op);

/**
* \brief Funcion que muestra los valores almacenados en la SRam
* \param SRam[65] Memoria disponible
* \return No tiene retorno
*/
void mostrar_SRam(uint8_t *SRam);
