#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif /* stdio_h */

#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif /* stdlib_h */

#ifndef string_h
#define string_h
#include <string.h>
#endif /* string_h */


typedef struct ListaPalabras{
    NodoArbol * root;
    int count;
}ListaPalabras;

//funciones por implementar

ListaPalabras * crearListaPalabras();
void agregarPalabra(ListaPalabras* lista, char* palabra);
int buscaPalabra(ListaPalabras * lista,char * palabra);
void liberarLista(ListaPalabras* lista);
void leerArchivoGuardarPalabras(char * nombreArchivo, int longitud,ListaPalabras * lista); //
//int palabraEstaUsada(ListaPalabras * lista,int index);
void marcarPalabraUsada(ListaPalabras * lista,int index);
int elegirPalabraAleatoriaNoUsada(ListaPalabras * lista,char ** resultado);
int obtenerCount(ListaPalabras * lista);
int seleccionarPalabra(ListaPalabras *lista,int index,char ** resultado);

#include "lista_palabras_arbol_general.c"