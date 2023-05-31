//obtiene el nodo de una lista por indice... ej: nodo numero 0 es el primer nodo. 
struct Nodo * seleccionarPalabraConNodo(struct Nodo *lista,int index){
    struct Nodo *actual = lista;

    int count= 0;
    while (actual != NULL)
    {
        if(count == index){
            return actual;
            break;
        }
        actual = actual->sgte;
        count++;
    }
    return NULL;
}


//toma como argumento una palabra y devuelve el nodo en el que se encuentra (devuelve null pointer si no existe)
Nodo * buscaPalabraConNodo(Nodo * lista,char * palabra){
    Nodo *actual = lista;
    while (actual != NULL)
    {
        if(strcmp(palabra,actual->texto) == 0){
            return actual;
        }
        actual = actual->sgte;
    }
    return NULL;
}

Nodo * agregarNodo(Nodo** lista, char* texto, int num){
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->texto = (char*) malloc(strlen(texto) + 1);
    strcpy(nuevoNodo->texto, texto);
    nuevoNodo->num = num;
    nuevoNodo->sgte = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
        return nuevoNodo;
    }

    struct Nodo* nodoActual = *lista;
    struct Nodo* nodoAnterior = NULL;
    while(nodoActual != NULL){
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sgte;
    }
    nodoAnterior->sgte = nuevoNodo;
    return nuevoNodo;
}

void modificarValor(Nodo * lista,int index,int nuevoValor){
    seleccionarPalabraConNodo(lista,index)->num = nuevoValor;
}

int obtenerValor(Nodo * lista,int index){
    return seleccionarPalabraConNodo(lista,index)->num;
}
