#include "Alumno.h"
#include  <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int buscarLibre(eAlumno listadoDeAlumnos[], int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(listadoDeAlumnos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int legajo[]= {101,102,105};
    float promedio[]= {6.66, 4,7.66};
    char nombre[][25]= {"Juan","Maria josefina","Maria"};
    for(i=0; i<3; i++)
    {
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].nombre, nombre[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
    }
}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    printf("Legajo\t\t  Nombre\t Promedio\n");
    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarUnAlumno(listadoDeAlumnos[i]);
        }

    }
}

void cargarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    //int i;
    int indice;

    indice = buscarLibre(listadoDeAlumnos, tam);
    printf("Indice: %d\n", indice);
    if(indice!=-1)
    {
        //hay lugar
        listadoDeAlumnos[indice] = cargarAlumno();
    }
    else
    {
        printf("No hay espacio disponible");
    }
}

eAlumno cargarAlumno(void)
{
    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);

    miAlumno.estado = OCUPADO;

    return miAlumno;
}
void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%4d \t %15s \t %8.2f\n",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio);
}

void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)//ordena por alumno y promedio
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }
            else
            {
                if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)==0)
                {
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio)
                    {
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }
    }
}

int bajaAlumno(eAlumno listadoDeAlumnos[],int tam)
{
    int retorno=-1;
    int auxLeg;
    char respuesta='n';
    //si lo encuentra verificar que no este dado de baja
    //talves poner un do while para voler a preguntar
    printf("Ingrese legajo  a borrar \n");
    scanf("%d",&auxLeg);
    int i;
    //si lo encuentra verificar que no este dado de baja
    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].legajo==auxLeg&&listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarUnAlumno(listadoDeAlumnos[i]);
            respuesta=getChar("Si realmente desea borrar el alumno escriba s\n");
            /*while(!(isalpha(respuesta))){
            printf("Error, Ingrese una opcion valida\n");
            }
            */
            if(respuesta=='s')
            {
                listadoDeAlumnos[i].estado=LIBRE;
                retorno=1;
            }
            else
            {
                retorno=0;
            }
            break;
        }

    }
    return retorno;
}

/*
void bajaAlumno(eAlumno listadoDeAlumnos[],int tam)
{
    int auxLeg;
    int flag=0;
    //si lo encuentra verificar que no este dado de baja
    //talves poner un do while para voler a preguntar
    printf("Ingrese legajo  a borrar");
    scanf("%d",&auxLeg);
    int i;
    //si lo encuentra verificar que no este dado de baja
    for(i=0; i<tam; i++)
    {listadoDeAlumnos[i].estado=LIBRE;
            flag=1;
            break;
        if(listadoDeAlumnos[i].legajo==auxLeg&&listadoDeAlumnos[i].estado==OCUPADO)
        {
            listadoDeAlumnos[i].estado=LIBRE;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No se ha encontrado el legajo");
    }
}
*/
void modificarAlumno(eAlumno listaDeAlumnos[],int tam)
{
    char auxNum[256];
    eAlumno auxiliar;
    int auxLeg;
    auxLeg=getInt("Ingrese legajo de alumno a modificar:\n");
    int respuesta;
    int i;
    char confirmacion;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(listaDeAlumnos[i].legajo==auxLeg&&listaDeAlumnos[i].estado==OCUPADO)
        {
            printf("Se modificara el siguiente alumno\n");
            mostrarUnAlumno(listaDeAlumnos[i]);
            printf("Que desea modificar?\n");
            printf("1-Nombre\n");
            printf("2-Promedio\n");
            scanf("%d",&respuesta);
            switch(respuesta)
            {
            case 1:
                getString("ingrese nuevo nombre alumno\n",auxiliar.nombre);
                confirmacion=getChar("Realmente desea modificar el alumno, ponga s\n");
                if(confirmacion=='s')
                {
                    strcpy(listaDeAlumnos[i].nombre,auxiliar.nombre);
                    printf("El alumno se ha modificado\n");
                }
                else
                {
                    printf("El alumno no se ha modificado\n");
                }
                flag=1;
                break;
            case 2:
                printf("Ingrese promedio");
                //scanf("%f",&auxiliar.promedio);

                while(!(getStringNumeros("Ingrese numero",auxNum)))
                {
                printf("Error reingrese numero");

                }
                auxiliar.promedio=atoi(auxNum);
                confirmacion=getChar("Realmente desea modificar el alumno, ponga s\n");
                if(confirmacion=='s')
                {
                    listaDeAlumnos[i].promedio=auxiliar.promedio;
                    printf("El alumno se ha modificado\n");
                }
                else
                {
                    printf("El alumno no se ha modificado\n");
                }
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("El alumno no existe");
    }
}
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
int pedirEntero(char mensaje[], int menorValor, int mayorValor)
{
int entero;

printf("Ingrese %s: ",mensaje);
scanf("%d",&entero);
while(entero>mayorValor||entero<menorValor)
    {
        printf("Error. Reingrese %s: ",mensaje);
        scanf("%d",&entero);
    }
return entero;
}


void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringNumeros(char mensaje[],char input[])//usa getstring,usaesNumerico
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
void buscarLegajo(eAlumno alumno[],int tam)
{
    int flag=0;
    int auxLeg;
    printf("Ingrese legajo");
    scanf("%d",&auxLeg);
    int i;

    for(i=0; i<tam; i++)
    {

        if(alumno[i].legajo==auxLeg&&alumno[i].estado==OCUPADO)
        {
            mostrarUnAlumno(alumno[i]);
            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("No se ha encontrado el alumno");
    }

}
