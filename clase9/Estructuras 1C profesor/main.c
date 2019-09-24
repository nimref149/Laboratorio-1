#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Alumno.h"
#define A 5
//dar de baja
//hacer modificar
int main()
{
    eAlumno listaDeAlumnos[A];
    int i;
    int opcion;
    int respuesta;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

    hardCodearAlumnos(listaDeAlumnos,A);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.borrar\n5.Modificar\n6.BuscarLegajo\n7.Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarListadoAlumnos(listaDeAlumnos,A);

            break;
        case 2:
            mostrarListadoAlumnos(listaDeAlumnos, A);
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
            break;
        case 4:
            respuesta=bajaAlumno(listaDeAlumnos,A);
            switch(respuesta)
            {
            case 1:
                printf("El alumno fue eliminado con exito\n");
                break;
            case 0:
                printf("El alumno no ha sido eliminado\n");
                break;
            case -1:
                printf("El alumno no existe\n");
                break;
            }
            break;
        case 5:
            modificarAlumno(listaDeAlumnos,A);
            break;
        case 6:
            buscarLegajo(listaDeAlumnos,A);
        default:
            printf("No ingreso una opcion\n");
            fflush(stdin);
        }

        system("pause");
        system("cls");

    }
    while(opcion!=7);



    return 0;
}

