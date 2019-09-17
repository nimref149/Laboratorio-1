void harcodearLegajos(int sillas[],int tam)
{
    int arrayAux[]= {41,25,32,6,5};
    int i;
    printf("Cargando datos\n");
    for(i=0; i<tam; i++)
    {
        sillas[i]=arrayAux[i];
    }
}
void hardcodearEdades(int edades[],int tam)
{
    int arrayAux[]= {4,5,2,6,5};
    int i;
    printf("Cargando datos\n");
    for(i=0; i<tam; i++)
    {
        edades[i]=arrayAux[i];
    }
}
int calcularMaximo(int vector[],int tam)
{
    int maximo;
    int flag=0;
    int i;
    for(i=0; i<tam; i++)
    {

        if(sillas[i]>maximo || flag==0)
        {
            maximo[i]=sillas[i];
            flag=0;
        }

    }
    return maximo;
}

int calcularMinimo(int vector[],int tam)
{
    int minimo;
    int flag=0;
    int i;
    for(i=0; i<tam; i++)
    {

        if(sillas[i]>minimo || flag==0)
        {
            minimo[i]=sillas[i];
            flag=0;
        }

    }
    return minimo;
}

void inicializarArray(int vector[],int tam,int valorInicial)
{

    int i;
    for(i=0; i<tam; i++)
    {
        vector[i]=valorInicial;
    }

}
int estaLibre(int vector[],int tam,int laSilla, int valorDeInicio)
{
    int respuesta=0;

    if(vector[laSilla]==valorDeInicio)
    {

        respuesta=1;

    }
    return respuesta;
}
}
int ocuparSilla(int arrayDeSillas[],int arrayDeEdades[],int tam,int silla,int edad,int legajo)
{
    int retorno=0;
    int estaLibreLaSilla;
    estaLibreLaSilla=estaLibre(arrayDeSillas,tam,silla,-1);
    if(estaLibreLaSilla==-1)
    {
        arrayDeSillas[silla]=legajo;
        arrayDeEdades[silla]=edad;
        retorno=1;

    }

    return retorno;

}
int cantidadOcupadas(int arrayDeSillas[],int tam,int valorInicial)
{
    int i;
    int ocupadas=0;
    for(i=0; i<tam,i++)
    {
        if(estaLibre(arrayDeSillas,tam,i,valorInicial)==1)
        {
            ocupadas++;
        }
    }
    return ocupadas;
}

int cantidadLibres(int arrayDeSillas[],int tam,int valorInicial)
{
    int i;
    int libres=0;
    for(i=0; i<tam,i++)
    {
        if(estaLibre(arrayDeSillas,tam,i,valorInicial)==0)
        {
            libres++;
        }
    }
    return libres;
}
























































































































































































































































































