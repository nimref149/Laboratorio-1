
int buscarLibre(eAlumno listadoDeAlumnos[],int tam)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado==LIBRE)
        {
            indice=i;
            break;
        }

    }
    return indice;

}











void cargarListadoAlumnos(eAlumno listadoDeAlumno){
int indice;
    int i;
    indice=buscarLibre(listadoDeAlumno,tam);
    if(indice!=-1){
        //hya lugar
        listadoDeAlumno[indice]=cargarAlumno();

    }
    else{
        printf("No hay espacio");
    }
    for(i=0; i<tam; i++)
    {

    }

}



eAlumno cargarAlumno(void)
{
    eAlumno
    printf("Ingrese legajo\n");
    gets(miAlumno.legajo);
    fflush(stdin);
    printf("Ingrese nombre\n");
    fflush(stdin);
    scanf("%[^\n]",&miAlumno.nombre);
    printf("Ingrese promedio"\n);
    scanf("%d",&miAlumno.promedio);
    //miAlumno.estado=OCUPADO;
    return miAlumno;
}






void cargarAlumno(eAlumno alumno[],int tam){

int indice;
indice=buscarLibre(alumno,tam);
if(indice!=-1){
printf("Ingrese legajo");
scanf("%d",alumno[indice].legajo);
printf("Ingrese nombre");
gets(alumno[indice].nombre);
fflush(stdin);
printf("Ingrese nota");
scanf("%d",&alumno[indice].nota);
}else{
printf("No hay espacion");
}

}
//hacer baja logica
void bajaAlumno(eAlumno alumno[],int tam){












}

int bajaAlumno(eAlumno alumno[],int tam){
int auxLegajo;
printf("Ingrese legajo a dar de baja");
scanf("%d",&auxLegajo);

int i;
//si lo encuentra verificar que no este dado de baja
/*
for(i=0;i<tam;i++){
    if(eAlumno[i].legajo==auxLegajo){
    if(eAlumno[i].estado!=OCUPADO){
    //eAlumno[i].estado==LIBRE;
    return i;
    }
    }
}
*/
}























































