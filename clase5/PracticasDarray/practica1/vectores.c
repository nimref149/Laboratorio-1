
#include <stdio.h>
#include "vectores.h"

int getInt(char frase[]){


int numero;
printf("%s\n",frase);

scanf("%d",&numero);

return numero;

}

void cargarVector(int vector[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese numero: \n");
        scanf("%d",&vector[i]);
    }

}

void mostrarTodo(int vectorNumeros[],int tam){
int i;
for(i=0; i<tam; i++)
{
    printf("Numero %d\n",vectorNumeros[i]);
}

}


void mostrarNegativos(int vectorNumeros[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {

        if(vectorNumeros[i]<0)
        {
            printf("Numero %d\n",vectorNumeros[i]);

        }
    }

}
void mostrarPromedioPos(int vectorNumeros[],int tam)
{
    int contadorPos=0;
    int acumuladorPos=0;
    float promedioPositivos;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorNumeros[i]>0)
        {
            acumuladorPos=acumuladorPos+vectorNumeros[i];
            contadorPos++;
        }
    }
    promedioPositivos=(float)acumuladorPos/contadorPos;
    printf("Suma: %d -- Cantidad %d\n\n",acumuladorPos,contadorPos);
    printf("El promedio de positivos: %.2f\n\n",promedioPositivos);

}
void mostrarMaximo(int vectorNumeros[],int tam)
{

    int maximo;
    int flag=0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorNumeros[i]>maximo || flag==0)
        {

            maximo=vectorNumeros[i];

            flag=1;
        }

    }
    printf("El maximo es %d\n",maximo);

}

void mostrarMinimo(int vectorNumeros[],int tam)
{
    int minimo;
    int i;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(vectorNumeros[i]<minimo || flag==0)
        {

            minimo=vectorNumeros[i];

            flag=1;
        }

    }
    printf("El minimo es %d\n",minimo);

}

































































































