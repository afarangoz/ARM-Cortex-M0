/**
* \brief funcion que aumenta o disminuye b posiciones el pc
* \param *R direccion del PC
* \param b valor que se va a cambiar el PC
* \return no hay retorno
*/
void B(uint32_t *R,uint32_t b);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera Z esta en uno
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BEQ(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera Z esta en cero
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BNE(uint32_t *R,uint32_t b,uint32_t *banderas);


/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera C esta en uno
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BCS(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posisiones el pc si la bandera C esta en cero
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BCC(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera N esta en uno
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BMI(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera N esta en cero
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BPL(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera V esta en uno
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BVS(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera V esta en cero
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BVC(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera C esta en uno y la Z en cero
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BHI(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera C esta en cero o la Z en uno
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BLS(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera N y V son iguales
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BGE(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera N y V son diferentes
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BLT(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera Z es cero y N igual a V
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BGT(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que aumenta o disminuye b posiciones el pc si la bandera Z es cero 0 N diferente de V
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BLE(uint32_t *R,uint32_t b,uint32_t *banderas);


/**
* \brief funcion que aumenta o disminuye b posiciones el pc
* \param *R direccion del PC
* \param b valor que va a cambiar el PC
* \param *banderas Direccion de las banderas utilizada para evaluar la condicion
* \return no hay retorno
*/
void BAL(uint32_t *R,uint32_t b,uint32_t *banderas);

/**
* \brief funcion que llama una subrutina que esta en una direccion relativa al pc
* \param salto	el numero de direcciones que avanzara desde su posicion actual
* \param *PC tomara la direccion de la subrutina   						*PC=Reg[13]
* \param *LR tomara el valor de la siguiente direccion apartir de la posicion actual            *LR=Reg[14]
* \return no hay retorno
*/
void BL(uint32_t *RL,uint32_t *PC,uint32_t salto);

/**
* \brief funcion que llama una subrutina que esta en la posicion direccion y RL avanza a la siguiente direccion
* \param direccion es un registro cuyo valor es la direccion de la subrutina
* \param *PC tomara la direccion de la subrutina						*PC=Reg[13]
* \param *LR tomara el valor de la siguiente direccion apartir de la posicion actual		*LR=Reg[14]
* \return no hay retorno
*/
void BLX(uint32_t *RL,uint32_t *PC,uint32_t direccion);


/**
* \brief funcion que salta a una direccion espesifica por un registro
* \param direccion es un registro cuyo valor es la direccion
* \param *PC tomara la direccion de la subrutina				*PC=Reg[13]
* \return no hay retorno
*/
void BX(uint32_t *PC,uint32_t direccion);

