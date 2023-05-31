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

// #ifndef lista_palabras_h
// #define lista_palabras_h
// #include "lista_palabras.h"
// #endif /* Lista_palabras_h */




#ifndef lista_palabras_abb_h
#define lista_palabras_abb_h
#include "librerias/arboles/lista_palabras_abb.h"
#endif /* Lista_palabras_abb_h */

#include "palabra.h"
#include "partida.h"


void main(){
    iniciarNcurses();
    printw("bienvenido al juego de adivinar una palabra\n");

    int largoPalabras = 5;    
    int intentos = 5;   

    printw("tienes %d intentos para adivinar una palabra de %d letras\n",intentos,largoPalabras);
    
    ListaPalabras * lista = crearListaPalabras();


    leerArchivoGuardarPalabras("palabras.txt",largoPalabras,lista);

    //testeo
    //char * testeo = (char *)malloc(sizeof(char)*40);
    //seleccionarPalabra(lista,5,&testeo);
    //printw("%s",lista->root->der->izq->der->dato);
    //printw("%s",testeo);

    int repetir = 1;
    while(repetir != 0){
        char * palabraObjetivo = (char*)malloc(sizeof(char) * (largoPalabras+1));
        if(elegirPalabraAleatoriaNoUsada(lista,&palabraObjetivo) != 1){
            printw("\nse acabaron las palabras de %d letras. fin del juego.",largoPalabras);
            free(palabraObjetivo);
            liberarLista(lista);
            finalizarNcurses();
            return;
        }
        repetir = partida(lista,intentos,largoPalabras,palabraObjetivo);
        free(palabraObjetivo);
    }

    liberarLista(lista);
    finalizarNcurses();
}