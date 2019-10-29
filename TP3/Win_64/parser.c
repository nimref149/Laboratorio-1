#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int len;
    len=ll_len(pArrayListEmployee);
    int i=0;
    Employee* empleado;

    int var1;
    char var2[150];
    int var3;
    float var4;

    ll_add(pArrayListEmployee,i);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        pArrayListEmployee
        empleado[i].id=atoi(var1);
        strcpy(empleado[i].nombre,var2);
        empleado[i]=


    }while(!feof(pFile)&&i<len)


    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
