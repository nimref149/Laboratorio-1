#include <stdio.h>
#include <stdlib.h>
int main()
{
    int opcion;


    do
    {
        printf("1-Cargar\n2.Mostrar\n3.Ordenar\n7.Salir");
        printf("Elija una opcion\n");
        scanf("%d",&opcion);

        switch(opcion){
    case 1:
        cargarListadoAlumnos();
        break;
    case 2:

        break;

    case 4:
        break;
    case 5:
        break;

   ´}
    system("cls");
    system("pause");
    }
    while(opcion);



    return 0;
}
