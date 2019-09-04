#include <stdio.h>
#include <stdlib.h>



/** \brief Calcula el factorial
 *
 * \param int El numero sobre el que se calcula
 * \return int El factorial
 *
 */
unsigned int factorial(int);
//int funcion(int numero);
int main()
{
    int numero;

    unsigned int resultado=1;
    printf("Ingrese el numero ");
    scanf("%d",&numero);
    resultado=factorial(numero);
    printf("El factorial es: %d ",resultado);

    int i;
  /*
    for(i=numero;i>=1;i--){
    resultado = resultado*i;

    }
    printf("%d",resultado);

    */
    return 0;

}
unsigned int factorial(int numero)
{

    unsigned int resultado;
    if(numero==0)
    {
        resultado=1;
    }
    else
    {
        resultado=numero*factorial(numero-1);

    }
    return resultado;
}






