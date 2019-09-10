#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Notas:
Nose puede palabra="hola" por que se guarda en la primer lugar del vector.
por que el fgets deja un espacio?, el f gets esta preparado para leer un archivo , al final deja un \n
por que va a leer otra linea.
valores ascii entre 128 y -127

*/

int main()
{


    char apellido[15]="scarafilo";
    char nombre[15];
    int i;
    int largo;
    int comp;
    int len;
    int auxString[1000];
    //para comprobar si esta bien escrito el tamaño del vector
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxString);
    while(strlen(auxString)>14){
        printf("Reingrese nombre: ");
        fflush(stdin);
        gets(auxString);
    }
    strcpy(nombre,auxString);












    /*
    char nombre[15];//no se puede modificar
    char apellido[15];//nose puede modificar
    char apellidoNombre[30];//el usario va a guardar el apellido con la primer letra en mayuscula y nombre tambien, hay que concatenar todo primero y Scarafilo,German. una funcion
    printf("Ingrese nombre de 14 letras\n");
    fflush(stdin);
    scanf("%s",nombre);
    /*
    while((strlen(nombre))>14){
    printf("\nTe dije menos de 14 letras lcdtm!!\n");
    scanf("%s",nombre);
    }
    */
    nombre[0]=toupper(nombre[0]);
    printf("El nombre es %s",nombre);
    fflush(stdin);
    printf("\nIngrese apellido de 14 acaracteres\n");
    scanf("%s",apellido);
    apellido[0]=toupper(apellido[0]);
    /*
    while((strlen(apellido))>14){
    printf("Te dije menos de 14 letras lcdtm!!");
    scanf("%s",apellido);
    }
    */
    strcat(apellido,nombre);
    strcat(apellidoNombre,apellido);
    printf("El nombre y apellido es %s",apellidoNombre);

    */

//_________________________



    /*
    printf("Ingrese palabra!\n");
    fflush(stdin);
    scanf("%[^\n]",otraPalabra);
    //fgets(palabra,10,stdin);

    strcat(palabra,otraPalabra);
    printf("%s",palabra);

    */

    //____________________
    /*
    char letra='p';
    tolower(letra);//int es el peso de la letra en asking que se convierte,no trabaja con referencia por que letra es un char y los char se pasan por valor,devueve la letra modificada
    strlwr(palabra);//por que noes un puntero a char no se le puede pasar char,sino que recibe una cadena
    //strupr(palabra);//trabaja por referencia si recibe un puntero.

    printf("%s\n",palabra);

    //comp=stricmp(palabra,otraPalabra);//la i se asocia con ignore, va comparando letra por letra, mientras sean todas iguales va comparando letra por letra
    //comp=strcmp(palabra,otraPalabra);
    //printf("\ncompara: %d",comp);

    */
    //____________________

    /*
    strcpy(palabra,"hola a todos que les vaya bien");//"hola" es una constante,primer parametro el destino,segundo el origen
    strcpy(palabra,otraPalabra);
    */

    //____________________
    /*
    printf("Ingrese palabra!\n");
    fflush(stdin);
    //scanf("%[^\n]",palabra);
    fgets(palabra,10,stdin);
    printf("%s\n",palabra);
    largo=strlen(palabra);
    palabra[largo-1]='\0';
    printf("El largo es %d\n",largo);
    */

    //____________________

    /*
    scanf("%[^\n]",palabra);
    printf("%s",palabra);

    for(i=0;i<5;i++){
    scanf("%s",palabra);

    printf("%s",palabra);
    }
    fflush(stdin);
    fgets(palabra,10,stdin);

    */
    return 0;
}
