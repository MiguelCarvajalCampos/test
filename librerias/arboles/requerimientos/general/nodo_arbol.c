NodoArbol * buscaNodoArbol(NodoArbol * nodoArbol,char * palabra){
    if(nodoArbol == NULL){
        return NULL;
    }
    
    //printf("%s",nodoArbol->dato);

    int diferencia = strcmp(palabra,nodoArbol->dato);
    if(diferencia == 0){
        return nodoArbol;
    }

    if(diferencia <0){
        return buscaNodoArbol(nodoArbol->izq,palabra);    
    }else{
        return buscaNodoArbol(nodoArbol->der,palabra);
    }
    return NULL;
}

void eliminaNodoArbol(NodoArbol *nodoArbol) {
    if (nodoArbol == NULL) {
        return;
    }

    eliminaNodoArbol(nodoArbol->izq);
    eliminaNodoArbol(nodoArbol->der);

    free(nodoArbol->dato);
    free(nodoArbol);
}

void marcarNodoArbolUsado(NodoArbol *nodoArbol, int index) {
    int iter = 0;
    recorrerArbolHasta(nodoArbol,index,&iter)->num = 1;
}


NodoArbol* recorrerArbolHasta(NodoArbol* root, int iteraciones, int * iteracionesActuales) {    
    if (root == NULL || *iteracionesActuales >= iteraciones) {
        return root;
    }

    (*iteracionesActuales)++;
    NodoArbol* result = recorrerArbolHasta(root->izq, iteraciones, iteracionesActuales);
    if (result == NULL) {
        result = recorrerArbolHasta(root->der, iteraciones, iteracionesActuales);
    }

    return result;
}
