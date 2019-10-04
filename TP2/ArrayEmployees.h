#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int initEmployees(Employee[],int);
int buscarLibre(Employee[],int);
int buscarIdMayor(Employee lista[],int tam);
int autoId(Employee empleados[],int tam);

int cargarEmpleado(Employee[],int);
int addEmployees(Employee[],int,int*,char[],char[],float*,int*);
int findEmployeeById(Employee[],int,int);

int removeEmployee(Employee[],int,int);
int sortEmployees(Employee[],int,int);
int printEmployees(Employee[],int);

void mostrarUnEmpleado(Employee lista);
int ordernarDescendentePorNombreYsector(Employee lista[],int tam);
int ordernarAscendentePorNombreYsector(Employee lista[],int tam);
int eliminarEmpleadoPorId(Employee lista[],int tam);

int modificarAlumno(Employee[],int);
void menuListarOrdenar(Employee[],int);
int cuantosSuperanPromedio(Employee[],int);
float salarioPromedio(Employee[],int);
float salarioTotal(Employee[],int);








