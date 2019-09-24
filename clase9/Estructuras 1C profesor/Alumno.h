#include <stdio.h>
#include <ctype.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int estado;
} eAlumno;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno);
int buscarLibre(eAlumno*, int);
void cargarListadoAlumnos(eAlumno[], int);
void mostrarListadoAlumnos(eAlumno[], int);

void hardCodearAlumnos(eAlumno[], int);
void sortStudentsByNameAndAverage(eAlumno[], int);
int bajaAlumno(eAlumno[],int tam);
void modificarAlumno(eAlumno listaDeAlumnos[],int tam);
int getInt(char mensaje[]);
char getChar(char mensaje[]);
int esSoloLetras(char str[]);
int pedirEntero(char[],int,int);
int getIn(int* valor,char mensaje[],int min,int max);
void getString(char mensaje[],char input[]);
int esNumerico(char str[]);
int getStringNumeros(char mensaje[],char input[]);
void buscarLegajo(eAlumno alumno[],int);

