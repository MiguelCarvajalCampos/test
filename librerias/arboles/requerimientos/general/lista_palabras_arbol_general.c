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



ListaPalabras * crearListaPalabras(){
    ListaPalabras* lista = (ListaPalabras*)malloc(sizeof(ListaPalabras));
    lista->root = NULL;
    lista->count = 0;
    return lista;
}

void agregarPalabra(ListaPalabras * lista,char * palabra){
    agregaNodo(&(lista->root),palabra,0);
    lista->count++;
    //printf("%d",lista->count);
}

int buscaPalabra(ListaPalabras * lista,char * palabra){
    if(buscaNodoArbol(lista->root,palabra) == NULL){
        return -1;
    }
    return 1;
}

void marcarPalabraUsada(ListaPalabras * lista, int index) {
    if (lista == NULL || lista->root == NULL) {
        return;
    }
    marcarNodoArbolUsado(lista->root, index);
}

void liberarLista(ListaPalabras * lista) {
    if (lista == NULL) {
        return;
    }
    eliminaNodoArbol(lista->root);
    free(lista);
}

int elegirPalabraAleatoriaNoUsada(ListaPalabras * lista,char ** resultado){
    ListaPalabras * nuevaLista = crearListaPalabras();

    for(int i = 0;i<obtenerCount(lista);i++){
        int iter = 0;
        NodoArbol * elemento = recorrerArbolHasta(lista->root,i,&iter);
        if(elemento != NULL){
            //printf("%s",elemento->dato);

            if(elemento->num == 0){
                agregarPalabra(nuevaLista,elemento->dato);
            }
        }else{
            printf("(null)");
        }

    }
    
    int exito = 0;
    if(obtenerCount(nuevaLista) != 0){
        int randNum = rand()%obtenerCount(nuevaLista);
        seleccionarPalabra(nuevaLista,randNum,resultado);
        buscaNodoArbol(lista->root,*resultado)->num = 1;
        exito = 1;
    }
    liberarLista(nuevaLista);
    return exito;
}

int seleccionarPalabra(ListaPalabras *lista,int index,char ** resultado){
    int iter = 0;
    NodoArbol * elegido = recorrerArbolHasta(lista->root,index,&iter);
    strcpy(*resultado,elegido->dato);
    return 1;
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

int obtenerCount(ListaPalabras * lista){
    return lista->count;
}