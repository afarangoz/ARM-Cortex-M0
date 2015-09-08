#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include <curses.h>

unsigned int i;

void mostrar_registros(uint32_t registro[13])
{

	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	start_color();	/* Permite manejar colores */

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);//texto MAGENTA fondo negro
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

	border( ACS_VLINE, ACS_VLINE,            //Esta funcion crea una margen en la interfaz,
			ACS_HLINE, ACS_HLINE,            // los parametros de entrada son los predeterminados
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

	attron(COLOR_PAIR(1));	 // Activa el color verde para el
                             //texto y negro para el fondo Pair 1

	move(2, 34);	         /* Mueve el cursor a la posición y=2, x=34*/
	printw("ARM-Cortex-M0");
	refresh();	             // Imprime en la pantalla
	attroff(COLOR_PAIR(1));


    for(i=0;i<=12;i++)
    {
        attron(COLOR_PAIR(3));
    	move(i+10, 5);
        printw("R[%d]=%d \n",i,registro[i]);
        refresh();
        attroff(COLOR_PAIR(3));
    }
}

void mostrar_banderas( uint32_t banderas[4])
{

        init_pair(2, COLOR_GREEN, COLOR_BLACK);//Texto verde fondo negro
        attron(COLOR_PAIR(2));
    	move(5, 5);
        printw("bandera[N]=%d \n",banderas[0]);
    	move(6, 5);
        printw("bandera[Z]=%d \n",banderas[1]);
        move(7, 5);
        printw("bandera[C]=%d \n",banderas[2]);
        move(8, 5);
        printw("bandera[V]=%d \n",banderas[3]);

        refresh();
        attroff(COLOR_PAIR(2));
}



