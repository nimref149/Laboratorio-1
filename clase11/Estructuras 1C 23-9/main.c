#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 5
/**
hacer:
1-Mostrar todos los alumnos con la descripcion de su localidad
2-Mostrar todas las localidades
3-Mostrar por cada localidad, todos los alumnos que viven en ella.
4-Mostrar los alumnos que viven en avellaneda
5-Mostrar la localidad con menos habitantes.
*/

int main()
{
    eAlumno listaDeAlumnos[A];
    eLocalidad listaLocalidades[3]={{1,"Avellaneda",1870},{2,"Wilde",1872},{3,"Lomas de Zamora",1700}};
    int i;
/*
    for(i=0;i<3;i++)
    {
        printf("%d - %s - %d\n", listaLocalidades[i].idLocalidad,listaLocalidades[i].localidad,listaLocalidades[i].codigoPostal);
    }
*/

    int respuesta;
    int opcion;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

    hardCodearAlumnos(listaDeAlumnos,A);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n7.Salir");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarListadoAlumnos(listaDeAlumnos,A);

            break;
        case 2:
            //mostrarListadoAlumnos(listaDeAlumnos, A);
           mostrarAlumnosConLocalidad(listaDeAlumnos,A,listaLocalidades,3);
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos,A);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno eliminado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }

            break;
        case 5:

            respuesta = modificarAlumno(listaDeAlumnos,A,102);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno modificado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }
            break;
        }
    }
    while(opcion!=7);
    return 0;
}


