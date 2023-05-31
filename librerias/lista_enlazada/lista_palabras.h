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

#include <time.h>
#include "requerimientos/nodo.h"


typedef struct ListaPalabras{
    struct Nodo * head;
    int count;
}ListaPalabras;

//funciones implementadas en lista_palabras.c

int buscaPalabra(ListaPalabras * lista,char * palabra);
ListaPalabras* crearListaPalabras();
void agregarPalabra(ListaPalabras* lista, char* palabra);
void liberarLista(ListaPalabras* lista);
void leerArchivoGuardarPalabras(char * nombreArchivo, int longitud,ListaPalabras * lista);
int palabraEstaUsada(ListaPalabras * lista,int index);
void marcarPalabraUsada(ListaPalabras * lista,int index);
int elegirPalabraAleatoriaNoUsada(ListaPalabras * lista,char ** resultado);

#include "lista_palabras.c"
