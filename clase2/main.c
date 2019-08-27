#include <stdio.h>
#include <stdlib.h>
int sumarNumeros(int numero1,int numero2);

int main(){
int numero1=7;
int numero2=9;
int total;
printf("ingrese numero 1 \n",numero1);
scanf("%d",&numero1);
printf("ingrese numero 2 \n",numero2);
scanf("%d",&numero2);
total=sumarNumeros(numero1,numero2);
printf(" resultado %d ",total);
}

int sumarNumeros(int numero1,int numero2){
int resultado;
resultado=numero1+numero2;
return resultado;

}






/*
int main()
{
    char opcion;
    do
    {
        printf("1. ALTA Cliente\n");
        printf("2. BAJA Cliente\n");
        printf("3. MODIFICAR Cliente\n");
        printf("4. MOSTRAR Clientes\n");
        printf("5. SALIR\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
        switch(opcion)
        {
            case '1':
                printf("Estoy dando de alta!!!\n");
                break;
            case '2':
                printf("Estoy dando de baja!!!\n");
                break;
            case '3':
                printf("Estoy modificando!!!\n");
                break;
            case '4':
                printf("Estoy mostrando!!!\n");
                break;
            default:
                printf("Opcion incorrecta!!!\n");

        }
    system("pause");
    system("cls");
    }
    while(opcion!='5');

    return 0;
}
*/
