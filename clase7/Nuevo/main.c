#include <stdio.h>
#include <stdlib.h>
#define T 3
#define LEN 20
#include <string.h>
/*

Hacer un menu
agregar un alumno
mostrar los alumnos sentados
los alumnos mas viejos
agregar el nombre de cada alumno
buscar
una funcion que ordene todos los alumnnos que estan sentados por nombre y los muestra
mostrar el nombre, la silla, y la edad
mostrar el nombre del maximo alumno
ademas leer la clase de estructuras


*/
int main()
{
    int legajo[T];
    char nombre[T][LEN];
    int i;
    int j;
    int auxInt;
    char auxString[LEN];

    for(i=0; i<T; i++)
    {

        printf("Ingrese legajo: ");
        scanf("%d",&legajo[i]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);

    }
    for(i=0; i<T; i++)
    {
        printf("%d\t%s\n",legajo[i],nombre[i]);
    }

    for(i=0; i<T-1; i++)
    {
        for(j=i+1; j<T; j++)
        {
            if(legajo[i]>legajo[j])
            {
                //tecnica de swapeo,swap
                auxInt=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=auxInt;

                strcpy(auxString,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxString);

            }

        }
    }

    for(i=0; i<T; i++)
    {
        printf("%d\t%s\n",legajo[i],nombre[i]);
    }


    /*
    int vida[1000];
    int attack[5];
    if(vida<300){
    attack=600;

    }
    */
    return 0;
}










