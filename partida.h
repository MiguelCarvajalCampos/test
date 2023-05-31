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

// #ifndef lista_palabras_abb_h
// #define lista_palabras_abb_h
// #include "lista_palabras_abb.h"
// #endif /* Lista_palabras_abb_h */

#include <ncurses.h>

void iniciarNcurses();
void finalizarNcurses();

int pedirPalabra(int maxLetras,char ** resultado);
int partida(ListaPalabras * lista,int intentos,int largoPalabras,char * palabraObjetivo);
void guardarPartida(const char* nombreArchivo,ListaPalabras * lista);

#include "partida.c"