#define LIBRE 0
#define OCUPADO 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
int idSector;
char descripcion[20];
float salarioTotal;

}eSector;
typedef struct
{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;


}Employee;

int initEmployees(Employee[],int);
int buscarLibre(Employee[],int);
/*
int cargarEmpleado(Employee*,int);
int addEmployees(Employee*,int,int,char[],char[],float,int);
int findEmployeeById(Employee*,int,int);
int removeEmployee(Employee*,int,int);
int sortEmployees(Employee*,int,int);
int printEmployees(Employee*,int,int);

*/















