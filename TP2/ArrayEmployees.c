#include "ArrayEmployees.h"

int initEmployees(Employee empleados[],int tam)
{
    int retorno=-1;
    int i;
    if(tam>=0)
    {
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
    int r;
    int i;
    Employee aux;
    i=buscarLibre(empleados,tam);
    aux.id=i;
    aux.name=getStringLetras(&aux.name,"Ingrese nombre","Error",3,51);
    aux.lastName=getStringLetras(&aux.lastName,"Ingrese apellido","Error",5,51)
    aux.salary=getFloatValid(&aux.salary,"Ingrese salario","Error",0,100000);
    aux.sector=getIntValid(&aux.sector"Ingrese sector 1-administracion\n,2-Limpiesa\n3-Seguridad\n","Error",1,3);
    r=addEmployees(lista[],tam,aux.id,aux.name,aux.lastName,aux.salary,aux.sector);
    if(r!=1){
    retorno=0;
    }
    else{
    retorno=-1;
    }
    return retorno;
}

int addEmployees(Employee lista[],int tam,int id,char name[],char apellido[],float salario,int sector){
int i;
int retorno;
if(id!=-1){
lista[id].id=id;




else{
retorno=-1;

}

return retorno;
}
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



/*
int findEmployeeById(Employee*,int,int);
int removeEmployee(Employee*,int,int);
int sortEmployees(Employee*,int,int);
int printEmployees(Employee*,int,int);

*/

















