#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
/**
new crea una dirrecion de memoria en el heap
en linkedlist de sources se ponen las pruebas osea las funciones.
en testing, erc estan las pruebas
en lind list la locomotora
en ew bagones
this sale azul por que es una palabra reservada en c++
no deberia hacer realloc sobre un puntero
get node y Add node trabajan con add y con get
Cuando dice pElement es una estructura
con indexOf le envias el indice la estructura devuelve la estructura le paso una estructura con un dato
leeer que devuelven las funciones de linkedlist
no reservas un empleado en las funciones cno malloc
hay que leer el archivo en binario una ves y luego
en la parte de crea un nuevo empleado poner un constructor parametrisado
Al setear algunos datos solo sirve en modificar

 Estructura de linked list:
size  tama�o (cant de elementos guardados en la linked list)
pNode  nodo es otra estructura
Estructura de NODE:
pElement  EL elemento que guardo en la lista
pNextNode  El puntero al siguiente nodo permite que la linked list sea una lista enlazada
para agregar un elemento a la linked list, creo un nuevo nodo, le asigno un elemento y guardo la direcc del siguiente nodo
Si quiero saber si ese nodo es el primero (unico) o el ultimo, tengo que guardar el nodo y preguntar por la direccion de memoria del nodo siguiente
para saber si apunta a NULL (es el ultimo) o no

    //ll_get buscar le paso el indice devuelve el dato
    //ll_set sobreescribir un dato, pero no se puede porque puede haber otra estructura apuntando al mismo dato
    //desengancho un nodo de la locomotora y enchando el dato a un nuevo nodo, el anterior nodo lo pongo a nulo y ahora ahi que enganchar elque se creo al siguiente nodo
    // retuirn del dato (ddd,0,ddd)0 es la posicion dd el dato
    //ll_pop desengancho la locomotora lo enchancho con el nodo que cree y  tengo que recordar cual es el anterior y el siguiente puedo reutilizar funcionar utilizo la funcion add
    ll_delete desengancho el nodo y lo enchancho al siguiente
    ll_clear desengancho el primer vagon, hacer un free desde el ultimo hasta el primero por que los anteriores sen quedan enganchados en el heap
    pero la lista sige estando en dirrecion de memoria
    ll_deletelinkedlist
    ll_remove me creo una funcion que reciba un nodo y lo destruya
    ll_indexOf con un get obtengo el dato de un nodo y comparo los datos, tengo que hasta llegar a nulo y cuando concido encuentro la variable dfe valor y lo devuelvo
    darme un indice de un elemento en general recivbo un dato y recorro cuando lo encuentro dejo de contar y devuelvo eese contrador por ejemplo para llegar a un dato devuelve la cantidad de datos recorridos
    //ll_pop puede llamar a remove
    ll_contains reico un puntero a void y pregundo si esta en la lista
    parecido a indexof, lo pudo usar si devuelvo el indice del elemento es por que esta,si esta va a devolver un valor sino un nulo
    ll_containsAll recibe dos listas,pregundo si el subconjunto esta contenido en la primer lista preguntamos
    por una direccion de memoria,
    ll_sublist devuelve de todas las listas un pedaso, si le paso del 0 al 2 me muestra el 0 1 me deveulde una nueva lista con un pedaso de la lista original trabaja desde un desde hasta,
    trabaja con un excluyente 0<2 el 2 lo excluye
    ll_clone crea un lista nueva,por ejemplo si tengo nueva=lista; si hago eso el clon pasa al 100%
    estaria copiando la misma dirrecion,entonces deberia crear una nueva lista, luego copiar los elementos
    desencapsulo un dato con get de cada uno y lo agrego a la nueva lista




*/

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* lista= NULL;
    lista=(LinkedList*)malloc(sizeof(LinkedList));
    if(lista!=NULL){
    lista->pFirstNode=NULL;
    lista->size=0;
    }
    return lista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* lista)
{
    int returnAux = -1;
   // int returnAux = -2; rompe por que esta mal el retorno
    if(lista!=NULL){
    returnAux=lista->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
obtengo un nodo de la lista
 *
 */
static Node* getNode(LinkedList* lista, int nodeIndex)
{
    //buscar un nodo en partitucal en un indiice que es get devuelva el nodo encapsulado
    Node* pNodo=NULL;
    int len;
    int i;
    len=ll_len(lista);
    if(lista!=NULL&&nodeIndex>=0&&nodeIndex<len)
    {
        if(nodeIndex==0)
        {
            pNodo=lista->pFirstNode;
        }
        else
        {
            pNodo=lista->pFirstNode;
            for(i=0; i<nodeIndex; i++)
            {
                pNodo=pNodo->pNextNode;

            }
        }
   }
   return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 agrego un nodo a la lista
 */

///static int addNode(LinkedList* this<- lista, int nodeIndex<-donde se agregara nuevo nodo,void* pElement<-puntero al elemento a ser contenido por el nuevo nodo)
static int addNode(LinkedList* lista, int nodeIndex,void* pElement)
{
    //ll_add, busca donde enganchar el elemento
    //ala llamo al addnote y buscar el ultimo elemento guardado osea el que esta en nulo e ir a engancharlo obtengo el indice y se lo paso a la funcion addnode busco el ultimo elemento y lo engancho previo tengo que crear un nodo en memoria
    int returnAux = -1;
    Node* pNode;
    Node* aNode;//anterior

    int len=ll_len(lista);
    if(lista!=NULL&&nodeIndex>=0&&nodeIndex<=len)
    {
        pNode=(Node*)malloc(sizeof(Node));
        pNode->pElement=pElement;
        if(pNode!=NULL)
        {
            if(nodeIndex==0)
            {
                pNode->pNextNode=lista->pFirstNode;
                lista->pFirstNode=pNode;
                lista->size++;
                returnAux=0;
            }
            else
            {
                aNode=getNode(lista,nodeIndex-1);
                if(aNode!=NULL)
                {
                    pNode->pNextNode=aNode->pNextNode;
                    aNode->pNextNode=pNode;
                    lista->size++;
                    returnAux=0;
                }
            }
        }

    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 agrego una estructura a la lista
 */
int ll_add(LinkedList* lista, void* pElement)
{
    int returnAux = -1;
    int len;
    len=ll_len(lista);
    if(lista!=NULL)
    {
        returnAux=addNode(lista,len,pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *obtengo una estrucuta elemento de la lista
 */
void* ll_get(LinkedList* lista, int index)
{
    void* returnAux = NULL;
    Node* aNode;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&index>=0&&index<len)
    {
        aNode=getNode(lista,index);
        if(aNode!=NULL)
        {
            returnAux=aNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 //ll_set sobreescribir un dato, pero no se puede porque puede haber otra estructura apuntando al mismo dato
 el set
crea un nuevo nodo, que apunta el nuevo dato (EL que se quiere ingresar) y engancho ese nodo en la lista al nodo anterior
y al siguiente
si es el ultimo elemento y quiero hacer un ser en la posicion dos, realizo un add -> si es igual al size, hago un add
sobreescribo una estructura elemento en la lista
 */

int ll_set(LinkedList* lista, int index,void* pElement)
{
    int returnAux = -1;
    Node* aNode;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&index>=0&&index<len)
    {
        aNode=getNode(lista,index);
        if(aNode!=NULL)
        {
            aNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 el remove
busco el indice en particular, recorro la lista y pongo a ese nodo realizo el free y engancho los demas nodos apropiadamente elimino un nodo de la lista y resto a size
 */
int ll_remove(LinkedList* lista,int index)
{
    int returnAux = -1;
    Node* aNode=NULL;
    Node* anterior=NULL;
    Node* siguiente=NULL;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&index>=0&&index<len)
    {

        aNode=getNode(lista,index);
        anterior=getNode(lista,index-1);
        siguiente=getNode(lista,index+1);
        if(anterior==NULL)
        {
            lista->pFirstNode=siguiente;
        }
        else
        {
            anterior->pNextNode=siguiente;
        }
        free(aNode);
        lista->size--;
        returnAux=0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 clear
desengancha el primer nodo del siguiente en nulo y setea el size en cero tengo que hacer un free de los demas nodos
elimino todos los nodos y pongo la lista en 0
 */

int ll_clear(LinkedList* lista)
{
    Node* aNode=NULL;
    int returnAux = -1;
    int i;
    int len;
    // int returnAux = -2; rompe por que esta mal el retorno
    if(lista!=NULL)
    {
        len=ll_len(lista);
        for(i=0; i<len; i++)
        {
            aNode=getNode(lista,i);
            free(aNode);
        }
        lista->pFirstNode=NULL;
        lista->size=0;
        returnAux=0;
    }
    return returnAux;
}

/*
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            returnAux=ll_remove(this, i);
        }
    }
    return returnAux;
}
*/

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 delete
 llama al clear y hace un free del primer nodo
elimino todos los nodos y luego la lista
 */
int ll_deleteLinkedList(LinkedList* lista)
{
    int returnAux = -1;
    if(lista!=NULL)
    {
        if(ll_clear(lista)!=-1)
        {
            free(lista);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 indexOF
 hago un get y voy comparando direcciones de memoria y cuando encuentro, hago un break y me quedo con ese indice
busco el indice de la estructura elemento en la lista
 */
int ll_indexOf(LinkedList* lista, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;
    Node* aNode=NULL;
    if(lista!=NULL)
    {
        len=ll_len(lista);
        for(i=0; i<len; i++)
        {
            aNode=getNode(lista,i);
            if(aNode!=NULL&&(aNode->pElement==pElement))
            {
                returnAux=i;
                break;
            }

        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* lista)
{
    int returnAux = -1;
    int len;

    if(lista!=NULL)
    {
        len=ll_len(lista);
        if(len==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 el push
tengo que obtener el nodo que voy a correr para no perder la referencia
pongo un nuevo elemento en la posicion indicada
 */

int ll_push(LinkedList* lista, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&index>=0&&index<=len)
    {
        returnAux=addNode(lista,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
elimina el nodo y devuelve su puntero de la estructura
 *
 */
void* ll_pop(LinkedList* lista,int index)
{
    void* returnAux = NULL;
    //Node* aNode=NULL;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&index>=0&&index<=len)
    {
        //aNode=getNode(lista,index);
        //if(aNode!=NULL){
        //returnAux=aNode->pElement;
        returnAux=ll_get(lista,index);
        ll_remove(lista,index);
        //}

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento

contains
llamo al index of -> si esta devuelve uno si no, no exite

*/
int ll_contains(LinkedList* lista, void* pElement)
{
    int returnAux = -1;

    if(lista!=NULL)
    {

        if(ll_indexOf(lista,pElement)!=-1)
        {
            returnAux=1;

        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
containsall
tengo que preguntar por direcciones de memoria no por los valores. si la lista a tiene un 4 apuntando a X y
la lista b tiene un 4 apuntando a Y, SON DIFERENTES. es decir, no cuenta
si las estructuras de list 2 estan contenidas en lista 1
*/
int ll_containsAll(LinkedList* lista,LinkedList* lista2)
{
    int returnAux = -1;
    int len;
    int i;
    Node* aNode=NULL;
    len=ll_len(lista2);
    if(lista!=NULL&&lista2!=NULL)
    {

        for(i=0; i<len; i++)
        {
            aNode=ll_get(lista2,i);
            if(ll_contains(lista,aNode)==0)
            {
                returnAux=0;
                break;
            }
            /*
            else
            {
                returnAux=1;
            }
            */
        }
        if(returnAux!=0)
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok

sublist
lista desde una parte hasta otra un pedaso

*/
LinkedList* ll_subList(LinkedList* lista,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* aNode=NULL;
    int i;
    int len;

    if(lista!=NULL)
    {
        len=ll_len(lista);
        if(from>=0 && from<to && to<=len&& from<len)
        {
            cloneArray=ll_newLinkedList();
            if(cloneArray!=NULL)
            {
                for(i=from; i<to; i++)
                {
                    aNode=getNode(lista,i);
                    if(aNode!=NULL)
                    {
                        ll_add(cloneArray,aNode->pElement);
                    }

                }
            }
        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
clone
 tengo que crear espacio para la nueva lista, y tengo que hacer un get para cada dato de la lista a clonar

*/
LinkedList* ll_clone(LinkedList* lista)
{
    LinkedList* cloneArray = NULL;
    int len;
    if(lista!=NULL)
    {
        len=ll_len(lista);
        cloneArray=ll_subList(lista,0,len);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok

ll_sort mandar a la funcion 2 puntero a void, desengacno uno lo pongo a un auxiliar desengancho el otro lo
pongo a un auxiliar y lo pongo
hacer diagramas
*/
int ll_sort(LinkedList* lista, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i,j,comp;
    void* auxElement;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&pFunc!=NULL&&(order==0 || order ==1))
    {
        returnAux=0;
        if(len>1)
        {
            for(i=0; i<len-1; i++)
            {

                for(j=i+1; j<len; j++)
                {
                    comp=pFunc(ll_get(lista,i),ll_get(lista,j));
                    if(comp==1&&order==1)
                    {
                        auxElement=ll_get(lista,i);
                        ll_set(lista,i,ll_get(lista,j));
                        ll_set(lista,j,auxElement);
                    }
                    else
                    {
                        if(comp==-1&&order==0)
                        {
                            auxElement=ll_get(lista,j);
                            ll_set(lista,j,ll_get(lista,i));
                            ll_set(lista,i,auxElement);
                        }
                    }
                }
            }
        }
    }
    return returnAux;
}

