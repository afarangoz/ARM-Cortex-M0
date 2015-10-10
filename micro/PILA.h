#ifndef _PILA_H_
#define	_PILA_H_

/**
* \brief funcion para escribir datos en la pila
* \param registros[16]
* \param *Reg dato del registro cero
* \param *PILA valor en la primer direccion de memoria en la pila
* \return no hay retorno
*/
void PUSH(uint8_t registros[16], uint32_t *Reg, uint8_t *SR);
/**
* \brief funcion para escribir datos en la pila
* \param registros[16]
* \param *Reg dato del registro cero
* \param *PILA valor en la primer direccion de memoria en la pila
* \return no hay retorno
*/
void POP(uint8_t registros[16], uint32_t *Reg, uint8_t *SR);

#endif
