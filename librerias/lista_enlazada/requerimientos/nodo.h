
typedef struct Nodo{
    char* texto;
    int num;
    struct Nodo* sgte;
}Nodo;

//funciones implementadas en nodo.c

Nodo * buscaPalabraConNodo(Nodo * lista,char * palabra);
Nodo * seleccionarPalabraConNodo(Nodo *lista,int index);
Nodo * agregarNodo(Nodo** lista, char* texto, int num);
void modificarValor(Nodo * lista,int index,int nuevoValor);
int obtenerValor(Nodo * lista,int index);

#include "nodo.c"