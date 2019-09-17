#include <stdio.h>
#include <stdlib.h>
#include <funciones.h>
#define CANTIDAD 5
/*

Hacer un menu
ABM DE SILLAS OPUPADAS CON LEGAJOS Y EDADES
crear funciones para XharcodearLegajo,xharcodearEdades,calcularMinimo,calcularMaximo,inicializarArray,estaLibre,ocuparSilla,cantidadOcupadas,cantidadLibres,
indicePrimerLibre  ordenarSillas mostrarTodosLosDatos
----------------------------------------------------------
agregar un alumno
mostrar los alumnos sentados
los alumnos mas viejos
agregar el nombre de cada alumno
buscar
una funcion que ordene todos los alumnnos que estan sentados por nombre y los muestra
mostrar el nombre, la silla, y la edad
mostrar el nombre del maximo alumno
ademas leer la clase de estructuras
*/
int main()
{

    int sillas[CANTIDAD];
    int edades[CANTIDAD];
    int minimo;
    int maximo;
    hardcodearLegajos(sillas,CANTIDAD);
    harcodearEdades(edades,CANTIDAD);

    minimo=calcularMinimo(sillas,CANTIDAD);
    maximo=calcularMaximo(sillas,CANTIDAD);












    return 0;
}
