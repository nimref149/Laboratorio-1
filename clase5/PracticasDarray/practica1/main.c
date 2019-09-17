#include <stdio.h>
#include <stdlib.h>
#define T 10
#include <string.h>
#include "vectores.h"

/*
Ejercicio:Crear un abm con numeros con 10, cargar, mostrar todo,mostrar negativos,mostrar 5 numeros, mostrar promedio de positivos,mostrar maximo, mostrar minimo,salir,
usar vectores flags y contadores
7 opciones
*/



int main()
{
    int vectorNumeros[T];




    int opcion;



    do
    {
        printf("Abm numeros\n");
        printf("1-Cargar numero: \n");
        printf("2-Mostrar todo: \n");
        printf("3-Mostrar negativos: \n");
        printf("4-Mostrar promedio de positivos: \n");
        printf("5-Mostrar maximo: \n" );
        printf("6-Mostrar minimo: \n");
        printf("7-Salir: \n");
        opcion=getInt("Ingrese una opcion\n");

        switch(opcion)
        {
        case 1:
            cargarVector(vectorNumeros,T);
            break;
        case 2:
            mostrarTodo(vectorNumeros,T);

            break;

        case 3:

            mostrarNegativos(vectorNumeros,T);

            break;


        case 4:
            mostrarPromedioPos(vectorNumeros,T);

            break;


        case 5:

            mostrarMaximo(vectorNumeros,T);

            break;
        case 6:

            mostrarMinimo(vectorNumeros,T);

            break;

        case 7:
            printf("Esta saliendo del programa○2n");
            break;
        default:
            printf("Ingreso una opcion invalida\n");

        }
        system("pause");
        system("cls");


    }
    while(opcion!=7);




    return 0;
}










