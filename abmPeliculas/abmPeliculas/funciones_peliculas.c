#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
void iniciarDatosArray(ePeliculas arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        arrayPeli[i].flag_estado = valor;
    }
}

int buscarPrimerOcurrencia(ePeliculas arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayPeli[i].flag_estado == VACIO || arrayPeli[i].flag_estado == BORRADO)&& valor == -1)//si  el  estado  es vacio, o borrado, y  ademas el  valor es -1
        {
            return i;
        }
        else
        {
            if(valor == arrayPeli[i].id_peliculas && arrayPeli[i].flag_estado == OCUPADO)//busco  que exista el id que le paso  por parametro (valor)
            {
                return i;
            }
        }
    }
    return LLENO;
}
