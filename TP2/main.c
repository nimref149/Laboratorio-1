#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"
#define TE 1000
#define TS 3

int main()
{

    int respuesta;
    Employee empleados[TE];
    respuesta=initEmployees(empleados,TE);
    int flag=0;
    if(respuesta!=-1)
    {

        do
        {
            printf("ABM\n");
            printf("1.Altas\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\n");
            while((getIntValid(&respuesta,"Ingrese una opcion: ","Error, ingreso una opcion invalida\n",1,5))==-1);
            switch(respuesta)
            {
            case 1:
                flag=1;
                respuesta=cargarEmpleado(empleados,TE);
                switch(respuesta)
                {
                case 0:
                    printf("Usuario cargado con exito!!\n");
                    break;
                case -1:
                    printf("No se ha podido cargar el usuario\n");
                    break;
                case 1:
                    printf("No hay mas lugar!\n");
                    break;
                }
                break;
            case 2:


                respuesta=modificarAlumno(empleados,TE);
                switch(respuesta)
                {
                case 0:
                    printf("Empleado modificado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
                }
                break;

            case 3:
                if(flag==0)
                {
                    printf("Primero debe cargar usuarios!!");
                }
                else
                {
                    respuesta=eliminarEmpleadoPorId(empleados,TE);
                    switch(respuesta)
                    {
                    case 1:
                        printf("Accion cancelada por el usuario\n");
                        break;
                    case 0:
                        printf("Empleado eliminado\n");
                        break;
                    case -1:
                        printf("Id no encontrado\n");
                        break;
                    }
                }
                break;
            case 4:
                if(flag==0)
                {
                    printf("Primero debe cargar usuarios!!");
                }
                else
                {
                    respuesta=menuListarOrdenar(lista,tam);
                    switch(respuesta)
                    {
                    case 1:
                        respuesta=printEmployees(empleados,TE);
                        if(respuesta==-1)
                        {
                            printf("No hay empleados para mostrar○\n");
                        }
                    case -1:
                        printf("No hay para ordenar\n");
                    }
                }
                break;
            case 5:
                printf("Saliendo del programa");
                break;

            }
            system("pause");
            system("cls");
        }
        while(respuesta!=5);
    }
    return 0;
}





























