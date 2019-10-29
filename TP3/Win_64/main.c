#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir

*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    //lo que hise fue crear 3 empleados en memoria
    Employee* e1=employee_newParametros("5","maria","10","5000");
    Employee* e2=employee_newParametros("2","carlos","15","6500");
    Employee* e3=employee_newParametros("6","jose","12","6500.10");
    Employee* e4=employee_newParametros("7","Juan","20","100");
    Employee* aux;
    printf("hla");
    //si esta bien devuelve 0 o -1 si hay algo mal, poner un if
    int x;
    int len;

    //x=ll_add(listaEmpleados,e1);
    printf("%d",x);
    controller_loadFromText("data.txt",listaEmpleados);
    /*
    ll_add(listaEmpleados,e1);
    x=ll_len(listaEmpleados);
    //devuelve 1 si hay algo
    printf("%d",x);
    */

    ll_add(listaEmpleados,e1);
    ll_add(listaEmpleados,e2);
    ll_add(listaEmpleados,e3);
    //ll_add(listaEmpleados,e4);
    ll_push(listaEmpleados,1,e4);

    //ll_sort(listaEmpleados,compararPorLegajo,1);//el 1  de mayor a m y 0 de menor a may
    ll_sort(listaEmpleados,compararPorSueldo,0);
    //ll_sort(listaEmpleados,compararPorNombre,0);

    len=ll_len(listaEmpleados);
    for(x=0; x<len; x++)
    {
        aux=(Employee*)ll_get(listaEmpleados,x);
        mostrarEmpleado(aux);
    }






controller_loadFromText(char* path , LinkedList* pArrayListEmployee)

















     /*
    //ll_set(listaEmpleados,1,e4);


    ll_add(listaEmpleados,e4);




    //todo deberia estar en funciones
    x=ll_len(listaEmpleados);//no se pone en el for por que estaria llamadno la funcion varias veses
    for(x=0; x<len; x++)
    {
        aux=(Employee*)ll_get(listaEmpleados,x);//devuelve puntero a void lo que hago es castearlo osea (empleado*),con esto me aseguro que es un empleado
        mostrarEmpleado(aux);
    }


    aux=ll_pop(listaEmpleados,1);
    mostrarEmpleado(aux);
    //ll_remove(listaEmpleados,1);

    printf("\n");

    printf("hola");
    //x=ll_len(listaEmpleados);
    len=ll_len(listaEmpleados);
    for(x=0; x<len; x++)
    {
        aux=(Employee*)ll_get(listaEmpleados,x);//devuelve puntero a void lo que hago es castearlo osea (empleado*),con esto me aseguro que es un empleado
        mostrarEmpleado(aux);
    }
    //me trae 0 y 1

    LinkedList* listaAux=ll_subList(listaEmpleados,0,2);

    len=ll_len(listaAux);
    for(x=0; x<len; x++)
    {
        aux=(Employee*) ll_get(listaAux,x);//devuelve puntero a void lo que hago es castearlo osea (empleado*),con esto me aseguro que es un empleado
        mostrarEmpleado(aux);
    }

    /*
    ll_deleteLinkedList(listaEmpleados);
    len=ll_isEmpty(listaEmpleados);
    printf("%d",len);
    ll_clear(listaEmpleados);
    */









    return 0;
}
