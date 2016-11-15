/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
/*struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;*/

typedef struct{
    char titulo[50];
    char genero[50];
    char linkImagen[500];
    char descripcion[500];
    int duracion;
    int puntaje;
    int flag_estado;
    int id_movie;
}eMovie;


int comparar_peliculas(eMovie* peliA, eMovie* peliB);
/*void imprimir_peliculas(Employee* this);
void employee_printAll(ArrayList* this);
eMovie* new_movie(int id, char title[],char genre[]);
void employee_delete(Employee* this);
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this);
Employee* employee_altaEmpleado();
Employee* buscarPorId (ArrayList*this);
void Employee_subList(ArrayList *this);*/


#endif // _EMPLOYEE_H



