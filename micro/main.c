#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include "ALU.h"
#include <math.h>
#include <curses.h>

int main()
{
    uint32_t banderas[4]={0,0,0,0}; //estas son las banderas del microprocesador las posiciones indican la bandera
                                        //[0] es N es 1 si el resultado es negatico
                                        //[1] es Z es 1 si el resultado es cero
                                        //[2] es C es 1 si hay acarreo en la operacion aritmetica
                                        //[3] es U es 1 si hubo sobreflujo es la operacion
    uint32_t Reg[13];

	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	start_color();	/* Permite manejar colores */

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);//texto MAGENTA fondo negro
	init_pair(2, COLOR_GREEN, COLOR_BLACK);//Texto verde fondo negro

	border( ACS_VLINE, ACS_VLINE,            //Esta funcion crea una margen en la interfaz,
			ACS_HLINE, ACS_HLINE,            // los parametros de entrada son los predeterminados
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

	attron(COLOR_PAIR(1));	 // Activa el color verde para el
                             //texto y negro para el fondo Pair 1

	move(2, 34);	         /* Mueve el cursor a la posición y=2, x=34*/
	printw("ARM-Cortex-M0");
	refresh();	             // Imprime en la pantalla


    Reg[1]=pow(2,31);
    Reg[2]=0;
    Reg[4]=Reg[2];
    mostrar_registros(Reg);
    unsigned int i;

    for(i=0;i<=3;i++)       //Este ciclo se utiliza para mostrar los valores de las banderas
    {
        attron(COLOR_PAIR(2));
    	move(i+5, 5);
        printw("bandera[%d]=%d \n",i+1,banderas[i]);
        refresh();
    }

	attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */

	getch();	/* Espera entrada del usuario */
	endwin();	/* Finaliza el modo curses */

    return 0;
}
