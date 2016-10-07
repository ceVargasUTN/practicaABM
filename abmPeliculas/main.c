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

    int opcion = 0,  ultimo_idP = 0, ultimo_idD = 0;
    char auxTitulo[50], auxNacionalidad[50], auxDirector[50], auxID[3], auxNombre[50], auxPais[50], auxDia[2], auxMes[2],  auxAnio[4], auxIDD[3];
    int lugarLibre, lugarOcupado;
    int i, genInt, converAnio, converDia,converMes ;


    ePeliculas peliculas[cELEMENTOS];
    eDirectores directores[cELEMENTOS];
    eFecha fecha[cELEMENTOS];

    iniciarDatosArray(peliculas, cELEMENTOS, VACIO);//Inicio Datos en  0 "Vacio"
    iniciarDatosArrayD(directores, cELEMENTOS, VACIO);
    iniciarDatosArrayF(fecha, cELEMENTOS, VACIO);
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
                printf("%s", auxDirector);

                strcpy(peliculas[lugarLibre].titulo, auxTitulo);
                strcpy(peliculas[lugarLibre].nacionalidad, auxNacionalidad);
                if (buscarDirector(directores,cELEMENTOS, auxDirector)!= -1)//compara el auxDirector con el nombre del director en la estructura eDirectores
                {
                    strcpy(peliculas[lugarLibre].director, auxDirector);
                    peliculas[lugarLibre].flag_estado = OCUPADO;
                    peliculas[lugarLibre].id_peliculas = ultimo_idP +1;
                    ultimo_idP = ultimo_idP +1;
                    printf( "CARGADO CON EXITO!\n");
                    system("pause");
                    system("cls");
                }else{
                    printf("No tiene registro de ese director");
                }
                break;

            case 2:
                printf("MODIFICAR\n");
                if (!getNumerosString("Ingrese el ID que desea modificar...", auxID))
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

                strcpy(peliculas[lugarOcupado].titulo, auxTitulo);
                strcpy(peliculas[lugarOcupado].nacionalidad, auxNacionalidad);
                strcpy(peliculas[lugarOcupado].director, auxDirector);
                printf( "MODIFICACION EXITOSA!\n");
                system("pause");
                system("cls");
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
                printf( "BORRADO CON EXITO!\n");
                system("pause");
                system("cls");
                break;
            case 4:
                printf("AGREGAR DIRECTOR\n");
                lugarLibre = buscarPrimerOcurrenciaD(directores, cELEMENTOS, -1);
                if (lugarLibre == LLENO)
                {
                    printf("Lleno! ");
                    break;
                }
                if(!getStringValidado("Nombre: ", auxNombre))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Pais de origen: ", auxPais))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                lugarLibre = buscarPrimerOcurrenciaF(fecha, cELEMENTOS, -1);
                if (lugarLibre == LLENO)
                {
                    printf("Lleno! ");
                    break;
                }

                printf("A continuacion ingrese fecha de nacimiento:\n ");
                if (!getNumerosString("Dia: ", auxDia))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }

                if (!getNumerosString("Mes: ", auxMes))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }

                if (!getNumerosString("Año: ", auxAnio))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }
                converDia= atoi(auxDia);
                converMes= atoi(auxMes);
                converAnio= atoi(auxAnio);
                strcpy(directores[lugarLibre].nombre, auxNombre);
                strcpy(directores[lugarLibre].pais_origen, auxPais);

                directores[lugarLibre].flag_estado = OCUPADO;
                directores[lugarLibre].id_director = ultimo_idD +1;

                fecha[lugarLibre].anio = converAnio;
                fecha[lugarLibre].mes = converMes;
                fecha[lugarLibre].dia = converDia;

                ultimo_idD = ultimo_idD +1;
                printf( "CARGA EXITOSA!\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("ELIMINAR DIRECTOR\n");
                if (!getNumerosString("Ingrese el ID que desea eliminar...", auxIDD))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }
                genInt = atoi(auxIDD);
                lugarOcupado = buscarPrimerOcurrenciaD(directores, cELEMENTOS, genInt);//genInt en  este caso es el  id
                printf("%d", lugarOcupado);
                if(lugarOcupado == LLENO)
                {
                    printf("No se encuentra del  registro! \n");
                    break;

                }
                directores[lugarOcupado].flag_estado = BORRADO;
                printf( "BORRADO CON EXITO!\n");
                system("pause");
                system("cls");
                break;

            case 6:
                printf("INFORMAR\n");
                printf("directores con  mas peliculas")

            case 7:
                    //tengo  que notificar en  caso  de que no  haya ningun  registro

                    for(i=0;i < cELEMENTOS; i++)
                    {
                        if(peliculas[i].flag_estado == OCUPADO)
                        {
                            printf("\n%s - %s - %s - %d \n",peliculas[i].titulo,peliculas[i].nacionalidad,peliculas[i].director, peliculas[i].id_peliculas);
                        }
                    }
                    printf("LISTA DIRECTORES\n");
                    for(i=0;i < cELEMENTOS; i++)
                    {
                        if(directores[i].flag_estado == OCUPADO)
                        {
                            printf("\n%s - %s - %d - %d/%d/%d \n",directores[i].nombre,directores[i].pais_origen, directores[i].id_director, fecha[i].dia, fecha[i].mes, fecha[i].anio);
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
            }
    }
    return 0;
}
