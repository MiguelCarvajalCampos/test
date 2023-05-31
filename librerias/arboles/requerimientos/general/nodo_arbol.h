typedef struct NodoArbol{
	char * dato;
    int num;
    int altura;
	struct NodoArbol * der;
	struct NodoArbol * izq;
}NodoArbol;

void agregaNodoArbol(NodoArbol ** nodoArbol,char * palabra,int num);
NodoArbol * buscaNodoArbol(NodoArbol * nodoArbol,char * palabra);
void eliminaNodoArbol(NodoArbol *nodoArbol);
void marcarNodoArbolUsado(NodoArbol *nodoArbol, int index);
NodoArbol* recorrerArbolHasta(NodoArbol* nodo, int iteraciones,int * iteracionesActuales);
int cantidadNodosNoUsados(NodoArbol* nodo);
#include "nodo_arbol.c"