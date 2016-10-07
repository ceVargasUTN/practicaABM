#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
void iniciarDatosArrayD(eDirectores arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        arrayPeli[i].flag_estado = valor;
    }
}

/*int buscarPrimerOcurrenciaD(eDirectores arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayPeli[i].flag_estado == VACIO || arrayPeli[i].flag_estado == BORRADO)&& valor == -1)//busco que el campo  este vacio  o borrado para posterioirmente ocuparlo
        {
            return i;
        }
        else
        {
            if(valor == arrayPeli[i].id_director && arrayPeli[i].flag_estado == OCUPADO)//busco  que exista el id que le paso  por parametro (valor)
            {
                return i;
            }
        }

    }
    return LLENO;
}*/
int buscarPrimerOcurrenciaD(eDirectores arrayPeli[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayPeli[i].flag_estado == VACIO || arrayPeli[i].flag_estado == BORRADO)&& valor == -1)//busco que el campo  este vacio  o borrado para posterioirmente ocuparlo
        {
            return i;
        }

            if(valor == arrayPeli[i].id_director && arrayPeli[i].flag_estado == OCUPADO)//busco  que exista el id que le paso  por parametro (valor)
            {
                return i;
            }

        else
        {
            if(arrayPeli[i].flag_estado == OCUPADO)//busco  que exista el id
            {
                return i;
            }
        }
    }
    return LLENO;
}

int buscarDirector(eDirectores dir[], int cantElemetos, char val[])
{
    int i;
    for (i = 0; i< cantElemetos; i++)
    {
        if (dir[i].flag_estado != BORRADO || dir[i].flag_estado == 1)
        {
            if (strcmp(val, dir[i].nombre)==0)
            {
                return val;
            }
        }
    }
    return -1;

}






