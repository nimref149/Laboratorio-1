#include "ArrayEmployees.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

int initEmployees(Employee empleados[],int tam)
{
    int retorno=-1;
    int i;
    if(empleados!=NULL && tam>0){

        for(i=0;i<tam;i++)
        {
        empleados[i].isEmpty=LIBRE;
        }
        retorno=0;

    }
    return retorno;
}


int cargarEmpleado(Employee empleados[],int tam)
{
    int retorno;
    int index;
    index=buscarLibre(empleados,tam);
    if(index!=-1)
    {
        retorno=addEmployees(empleados,tam,&empleados[index].id,empleados[index].name,empleados[index].lastName,&empleados[index].salary,&empleados[index].sector);
        empleados[index].isEmpty=OCUPADO;
    }
    else
    {
        retorno=1;
    }
    return retorno;
}

int addEmployees(Employee empleados[],int tam,int *id,char name[],char apellido[],float *salario,int *sector)
{
    //funcion para id automatico;

    int retorno;
    if(tam>0 && empleados!=NULL && ((buscarLibre(empleados,tam))!=-1))
    {
        *id=autoId(empleados,tam);
        while((getStringLetras(name,"Ingrese nombre: ","Error",3,51))==-1 || confirm()!=1);
        while((getStringLetras(apellido,"Ingrese apellido: ","Error",5,51))==-1);
        while((getFloatValid(salario,"Ingrese salario: ","Error",0,100000))==-1);
        while((getIntValid(sector,"Ingrese sector: [1][2][3]\n","Error",1,3))==-1);
        retorno=0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;

}


int buscarLibre(Employee empleados[],int tam)
{
    int retorno=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int autoId(Employee lista[],int tam)
{
    int retorno;
    int idMayor;
    idMayor=buscarIdMayor(lista,tam);
    if(idMayor!=-1)
    {
        retorno=idMayor+1;
    }
    else
    {
        retorno=1;
    }

    return retorno;
}

int buscarIdMayor(Employee lista[],int tam)
{
    int retorno=-1;
    int i;
    int flag=0;
    int mayor;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            if(lista[i].id>mayor || flag==0)
            {
                mayor=lista[i].id;
                flag=1;
            }
        }
    }
    if(flag!=0)
    {
        retorno=mayor;
    }
    return retorno;
}

int findEmployeeById(Employee empleados[],int tam,int id)
{
    int retorno=-1;
    int i;
    if(empleados!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(empleados[i].id==id && empleados[i].isEmpty==OCUPADO)
            {
                retorno=i;

                break;
            }

        }
    }
    return retorno;
}


int removeEmployee(Employee empleados[],int tam,int id)
{
    int retorno=-1;
    int respuesta;
    int i;
    if(empleados!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(empleados[i].id==id&&empleados[i].isEmpty==OCUPADO)
            {
                respuesta=confirm();
                if(respuesta==1)
                {
                    empleados[i].isEmpty=LIBRE;
                    retorno=0;
                }
                else
                {
                    retorno=1;
                }
                break;
            }
        }
    }
    return retorno;
}
//ordena el array de empleados por apellido y sector de manesa ascendente o descendente
//se envia 1 para maensa ascendente 0 para descendente
int sortEmployees(Employee list[], int tam, int order)
{
    int retorno=-1;
    if(list!=NULL && tam>0)
    {

        if(order==1)
        {
            retorno=ordernarAscendentePorNombreYsector(list,tam);

        }
        else if(order==0)
        {
            retorno=ordernarDescendentePorNombreYsector(list,tam);

        }
        else
        {
            printf("Ha ingresado mal el orden, 1 o 0\n");
            retorno=-1;
        }

    }
    return retorno;
}

int ordernarAscendentePorNombreYsector(Employee lista[],int tam)
{
    int i;
    int j;
    int retorno=-1;
    Employee auxEmpleado;
    for(i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty!=LIBRE)
        {

            for(j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty!=LIBRE)
                {

                    if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                        retorno=0;
                    }

                    else
                    {
                        if(strcmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                            if(lista[i].sector>lista[j].sector)
                            {
                                auxEmpleado = lista[i];
                                lista[i] = lista[j];
                                lista[j] = auxEmpleado;
                                retorno=0;
                            }
                        }
                    }

                }
            }

        }

    }
    return retorno;

}

int ordernarDescendentePorNombreYsector(Employee lista[],int tam)
{
    int retorno=-1;
    int i;
    int j;
    Employee auxEmpleado;
    for(i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            for(j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty==OCUPADO)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName)<0)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                        retorno=0;
                    }

                    else
                    {
                        if(strcmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                            if(lista[i].sector<lista[j].sector)
                            {
                                auxEmpleado = lista[i];
                                lista[i] = lista[j];
                                lista[j] = auxEmpleado;
                                retorno=0;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}


int printEmployees(Employee list[],int tam)
{
    int retorno=-1;
    int i;
    int hayAlguno;
    hayAlguno=autoId(list,tam);
    if(hayAlguno!=1)
    {
        printf("   id   |     nombre    |   apellido    | salario |   sector\n");

        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {

                mostrarUnEmpleado(list[i]);

            }
        }
        retorno=0;
    }


    return retorno;
}

void mostrarUnEmpleado(Employee lista)
{

printf(" %d  |  %-10s   |  %-10s   |   %.02f  |   %d  \n",lista.id,lista.name,lista.lastName,lista.salary,lista.sector);

}

int eliminarEmpleadoPorId(Employee lista[],int tam)
{
    int retorno;
    int id;
    while((getIntValid(&id,"Ingrese id de usuario a eliminar: ","Error, solo numeros entre 0 y 1000",1,1000)==-1));
    retorno=removeEmployee(lista,tam,id);
    return retorno;
}

int modificarAlumno(Employee lista[],int tam)
{
    int retorno=-1;
    int index;
    int opcion;
    int i;
    while((getIntValid(&index,"Ingrese id","Error",1,100000))==-1);
    index=findEmployeeById(lista,tam,index);
    if(index!=-1)
    {
        for(i=0; i<tam; i++)
        {
            if(lista[i].id==index &&lista[i].isEmpty==OCUPADO)
            {
                while((getIntValid(&opcion,"Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n","Error",1,3))==-1);
                switch(opcion)
                {
                case 1:
                    while((getStringLetras(lista[i].name,"Ingrese nuevo nombre: ","Error",1,51))==-1||confirm()!=1);
                    retorno=0;
                    break;
                case 2:
                    while((getStringLetras(lista[i].lastName,"Ingrese nuevo apellido: ","Error",1,51))==-1);
                    retorno=0;
                    break;
                case 3:
                    while((getFloatValid(&lista[i].salary,"Ingrese nuevo salario: ","Error",1,10000))==-1);
                    retorno=0;
                    break;
                case 4:
                    while((getIntValid(&lista[i].sector,"Ingrese nuevo Sector: ","Error",1,3))==-1);
                    retorno=0;
                    break;

                }

            }
        }
    }

    return retorno;
}

int menuListarOrdenar(Employee list[],int tam)
{
    int retorno;
    int res;
    while((getIntValid(&res,"1-Listado empleado ordenados alfabeticamente por apellido y sector\n2-Total y promedio de los salarios y cuantos superan el promedio","Error",1,2))==-1);
    switch(res)
    {
    case 1:
        retorno=sortEmployees(list,tam,1);
        break;
    case 2:
        retorno=sortEmployees(list,tam,0);
        break;
    }

    return retorno;
}











