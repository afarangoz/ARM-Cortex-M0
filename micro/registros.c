#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include <curses.h>

unsigned int i;

void mostrar_registros(uint32_t* registro)
{

	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	start_color();	/* Permite manejar colores */

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);//texto MAGENTA fondo negro
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);

	attron(COLOR_PAIR(1));	 // Activa el color verde para el
                             //texto y negro para el fondo Pair 1

	move(2, 34);	         /* Mueve el cursor a la posici�n y=2, x=34*/
	printw("ARM-Cortex-M0");
	refresh();	             // Imprime en la pantalla
	attroff(COLOR_PAIR(1));


    for(i=0;i<=12;i++)
    {
        attron(COLOR_PAIR(3));
    	move(i+5, 20);
        printw("R[%d]=%d \n",i,registro[i]);
        refresh();
        attroff(COLOR_PAIR(3));
    }

        attron(COLOR_PAIR(5));
    	move(5, 50);
        printw("PC=%d \n",registro[13]);
        move(6, 50);
        printw("LR=%d \n",registro[14]);
        refresh();
        attroff(COLOR_PAIR(5));
}

void mostrar_banderas( uint32_t banderas[4])
{

        init_pair(2, COLOR_GREEN, COLOR_BLACK);//Texto verde fondo negro
        attron(COLOR_PAIR(2));
    	move(9, 50);
        printw("bandera[N]=%d \n",banderas[0]);
    	move(10, 50);
        printw("bandera[Z]=%d \n",banderas[1]);
        move(11, 50);
        printw("bandera[C]=%d \n",banderas[2]);
        move(12, 50);
        printw("bandera[V]=%d \n",banderas[3]);

        refresh();
        attroff(COLOR_PAIR(2));
}

void mostrar_operacion( char* op)
{


        init_pair(4, COLOR_BLUE, COLOR_BLACK);//Texto verde fondo negro
        attron(COLOR_PAIR(4));
    	move(15, 46);
        printw("    %s ",op);

        refresh();
        attroff(COLOR_PAIR(4));
        border( ACS_VLINE, ACS_VLINE,            //Esta funcion crea una margen en la interfaz,
                ACS_HLINE, ACS_HLINE,            // los parametros de entrada son los predeterminados
                ACS_ULCORNER, ACS_URCORNER,
                ACS_LLCORNER, ACS_LRCORNER	);
}




