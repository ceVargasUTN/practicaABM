#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
int main()
{

    int opcion = 0,  ultimo_id = 0;
    char auxTitulo[50], auxNacionalidad[50], auxDirector[50], auxID[3];
    int lugarLibre, lugarOcupado;
    int i, genInt;


    ePeliculas peliculas[cELEMENTOS];
    eDirectores directores[cELEMENTOS];

    iniciarDatosArray(peliculas, cELEMENTOS, VACIO);//Inicio Datos en  0 "Vacio"
    while (opcion != 6)
    {
        opcion = getOpcion(opcion);
            switch (opcion)
            {
            case 1:
                lugarLibre = buscarPrimerOcurrencia(peliculas, cELEMENTOS, -1);
                if (lugarLibre == LLENO)
                {
                    printf("Lleno! ");
                    break;
                }
                if(!getStringValidado("Titulo: ", auxTitulo))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Nacionalidad: ", auxNacionalidad))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Director: ", auxDirector))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                strcpy(peliculas[lugarLibre].titulo, auxTitulo);
                strcpy(peliculas[lugarLibre].nacionalidad, auxNacionalidad);
                strcpy(peliculas[lugarLibre].director, auxDirector);
                peliculas[lugarLibre].flag_estado = OCUPADO;
                peliculas[lugarLibre].id_peliculas = ultimo_id +1;
                ultimo_id = ultimo_id +1;
                printf( "cargado\n");
                break;

            case 2:
            printf("\nLISTA\n");
                for(i=0;i < cELEMENTOS; i++)
                {
                    if(peliculas[i].flag_estado == OCUPADO)
                    {
                        printf("\n%s - %s - %s - %d \n",peliculas[i].titulo,peliculas[i].nacionalidad,peliculas[i].director, peliculas[i].id_peliculas);
                    }
                }
                break;
            case 3:
                printf("BORRAR\n");
                if (!getNumerosString("Ingrese el ID que desea eliminar...", auxID))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }
                genInt = atoi(auxID);
                lugarOcupado = buscarPrimerOcurrencia(peliculas, cELEMENTOS, genInt);//genInt en  este caso es el  id
                printf("%d", lugarOcupado);
                if(lugarOcupado == LLENO)
                {
                    printf("No se encuentra del  registro! \n");
                    break;

                }
                peliculas[lugarOcupado].flag_estado = BORRADO;
                break;
            case 4:
                printf("MODIFICAR\n");
                if (!getNumerosString("Ingrese el ID que desea modificar...", auxID))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }
                lugarOcupado = buscarPrimerOcurrencia(peliculas, cELEMENTOS, genInt);//genInt en  este caso es el  id
                printf("%d", lugarOcupado);
                if(lugarOcupado == LLENO)
                {
                    printf("No se encuentra del  registro! \n");
                    break;
                }
                if(!getStringValidado("Titulo: ", auxTitulo))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Nacionalidad: ", auxNacionalidad))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Director: ", auxDirector))
                {
                    printf("Solo debe contener letras...");
                    break;
                }

                strcpy(peliculas[lugarOcupado].titulo, auxDirector);
                strcpy(peliculas[lugarOcupado].nacionalidad, auxDirector);
                strcpy(peliculas[lugarOcupado].director, auxDirector);
                break;



            }

    }
    return 0;
}
