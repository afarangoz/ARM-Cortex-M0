#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "registros.h"
#include <curses.h>

void mostrar_registros(uint32_t registro[13])
{
    unsigned int i;
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    for(i=0;i<=12;i++)
    {
        attron(COLOR_PAIR(3));
    	move(i+10, 5);
        printw("R[%d]=%d \n",i,registro[i]);
        refresh();
    }
}
