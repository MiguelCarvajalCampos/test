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


//crear una nueva lista vacía
ListaPalabras* crearListaPalabras(){
    ListaPalabras* lista = (ListaPalabras*) malloc(sizeof(ListaPalabras));
    lista->head = NULL;
    lista->count = 0;
    return lista;
}

//agrega palabra a una lista
void agregarPalabra(ListaPalabras* lista, char* palabra){
    Nodo * nodoAgregado = agregarNodo(&(lista->head),palabra,0);
    if(lista->count == 0){
        lista->head = nodoAgregado;
    }
    lista->count++; 
}

//obtiene la cantidad de elementos guardados en la lista
int obtenerCount(ListaPalabras * lista){
    return lista->count;
}

void marcarPalabraUsada(ListaPalabras * lista,int index){
    modificarValor(lista->head,index,1);
}

//libera la memoria de la lista
void liberarLista(ListaPalabras* lista){
    struct Nodo* nodoActual = lista->head;
    while(nodoActual != NULL){
        struct Nodo* nodoSiguiente = nodoActual->sgte;
        free(nodoActual->texto);
        free(nodoActual);
        nodoActual = nodoSiguiente;
    }
    free(lista);
}


//obtiene una palabra de una lista por indice... ej: palabra numero 0 es la primera palabra.
int seleccionarPalabra(ListaPalabras *lista,int index,char ** resultado){
    int count = lista->count;
    
    if(index < 0 || index >= count){
        printf("error: indice fuera de los limites de la lista");
        return -1;
    }
    struct Nodo *actual = lista->head;
    for(int i = 0;i<count ; i++){
        if(i == index){
            strcpy(*resultado,actual->texto);
            break;
        }
        actual = actual->sgte;
    }
    return 1;
}


//busca una palabra en una lista, si la encuentra devuelve su indice, si no existe devuelve -1
int buscaPalabra(ListaPalabras * lista,char * palabra){
    int count = lista->count;
    struct Nodo *actual = lista->head;
    for(int i = 0;i<count ; i++){
        if(strcmp(palabra,actual->texto) == 0){
            return i;
        }
        actual = actual->sgte;
    }
    return -1;
}

//revisa si la palabra en la lista ya se marco como usada
int palabraEstaUsada(ListaPalabras * lista,int index){
    return obtenerValor(lista->head,index);
}

//Lee archivo de texto y guarda las palabras con una longitud dada
void leerArchivoGuardarPalabras(char * nombreArchivo, int longitud,ListaPalabras * lista) {
    FILE* file = fopen(nombreArchivo, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char palabra[50];
    while (fscanf(file, "%s", palabra) != EOF) {
        if (strlen(palabra) == longitud) {
            agregarPalabra(lista, palabra);
        }
    }

    fclose(file);
}

int elegirPalabraAleatoriaNoUsada(ListaPalabras * lista,char ** resultado){
    ListaPalabras * nuevaLista = crearListaPalabras();

    for(int i = 0;i<obtenerCount(lista);i++){
        Nodo * elemento = seleccionarPalabraConNodo(lista->head,i);
        if(elemento->num == 0){
            agregarPalabra(nuevaLista,elemento->texto);
        }
    }
    
    int exito = 0;
    if(obtenerCount(nuevaLista) != 0){
        int randNum = rand()%obtenerCount(nuevaLista);
        seleccionarPalabra(nuevaLista,randNum,resultado);
        marcarPalabraUsada(lista,buscaPalabra(lista,*resultado));
        exito = 1;
    }
    liberarLista(nuevaLista);
    return exito;
}

