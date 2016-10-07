#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
void iniciarDatosArrayF(eFecha arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        arrayPeli[i].flag_estado = valor;
    }
}



int buscarPrimerOcurrenciaF(eFecha arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayPeli[i].flag_estado == VACIO || arrayPeli[i].flag_estado == BORRADO)&& valor == -1)//si no existe la fecha o  esta borrada me devuleve la posicion
        {
            return i;
        }
    }
    return LLENO;//sino -1
}
