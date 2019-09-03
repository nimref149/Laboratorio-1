#include <stdio.h>
#include <stdlib.h>//incluye archivos
#define T 5//define un valor que luego va a ser buscado y reemplasado en el codigo,solo es para esta biblioteca
#include "Vectores.h"
//no programar todo dentro del main
void cargarVector(int [],int);//com regla para el tamaño
void mostrarMaximo(int [],int );
int calcularMaximo(int[],int);

int main()
{
    int const T=10;// es un valor que no cambia en ningun momento del programa variable de solo lectura,opcupa espacio ne memoria el define no
        //int vectorDeNumeros
    int vectorNumeros[10]={10,-5,10,-6,-1,-4,10,5,4,-6};
    int i;
    int contadorDePositivos=0;
    int sumaDePositivos
    int maximo;
    int minimo;
    int flag=0;
    int opcion;
    ordenarVector(vectorDeNumeros,T);

    do{
        printf("1. cargar numeros\n);
        printf("2. mostrar mostrar todo\n");
        printf("3.mostrar mostrar negativos\n");//se hace con printf
        printf("4.mostrar promedio positivos\n");//se hace con 2 printf
        printf("5.mostrar maximo\n");
        printf("6.mostrar minimo\n");
        printf("7.salir");
        printf("Elija opcion");
        scanf("%d",&opcion);


      switch(opcion){
        case 1:
           cargarVector(vectorNumeros,T);//se pasan sin corchetes los vectores,la direccion de memoria del primer elemento el nombre del vector,los vectores son punteros y se pasan por referencia
           /*//copiar del repositorio todo ahora y luego hacer el tp de dota help luego enviar el repositorio nuevo
            printf("\t CARGA DE DATOS\n");
            for(i=0,i<10; i++)
            {
                printf("Ingrese numero: ");
                scanf("%d",&vectorNumeros[i]);
            }
            */
        case 2:


          for(i=0;i<10;i++){
            printf("El numero ingresado: %d",vectorNumeros[i]);  }
        case 3:
            for(i=0;i<10;i++){
                    if(){
            printf("El numero ingresado: %d",vectorNumeros[i]);
                    }
            }

        case 4:
        //para que la primera iteracion se cumpla
        flag=0;
        case 5:
            mostrarMaximo(vectorNumeros,T);
        flag=0;//para que la primera iteracion se cumpla
        case 6:
            flag=0;
            for
            for
        default:
            printf("Ingreso una opcion invalida");

        }
        system("pause");
        system("cls");
    } while(opcion!=7);
    return 0;
}
void cargarVector(int vector[],int tam) //estoy reciebiendo el vector en un vector
{
    int i;
    printf("\t CARGA DE DATOS\n");
    for(i=0,i<tam; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d",&vector[i]);
    }
}
void mostrarMaximo(int vector[],int tam)
{

    int maximo;
    //int flag=0; desaparece
    int i;
    maximo=calcularMaximo(vectorr,tam);

    for(i=0; i<tam; i++)
    {
        if(flag==0 || vector[i]>maximo)
        {
            maximo=vector[i];
        }

        flag=1


    }
    printf("EL MAXIMO: %d\n",maximo)
    for(i=0; i<tam; i++){
        if(vector[i]==maximo){
            printf("%d-",i);
        }

    }
}

int calcularMaximo(int vector[],int tam){
int i:
int flag=0;
int maximo;

  for(i=0; i<tam; i++)
    {
        if(flag==0 || vector[i]>maximo)
        {
            maximo=vector[i];
        }

        flag=1;

    }

}

void ordenarVector(int vector[],int tam){//mecanica para mover elementos en el vector
    int j;
    int i;
    int aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(vector[i]>vector[j])//condicion con criterio de evaluacion
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}


