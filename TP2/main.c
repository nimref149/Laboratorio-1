#include <stdio.h>
#include <stdlib.h>
#define T 1000
#include "ArrayEmployees.h"
#include "input.h"

int main()
{
    printf("Hello world!\n");
    int r;
    Employee empleados[T];
    eSector sectores[TS]={{1,"administrador"},{2,"limpiesa"},{3,"seguridad"}};
    r=initEmployees(empleados,T);
    if(r==0)
    {
        int i;
        for(i=0; i<T; i++)
        {
           // printf("Esta libre %d \n",empleados[i].isEmpty);
        }
    }
    return 0;
}





























