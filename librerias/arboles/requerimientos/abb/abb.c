void agregaNodo(NodoArbol ** nodoArbol,char * palabra,int num){
	if(*nodoArbol == NULL){
		NodoArbol * nuevoNodoArbol = (NodoArbol*)malloc(sizeof(NodoArbol));
        nuevoNodoArbol->izq =NULL;
        nuevoNodoArbol->der =NULL;

		nuevoNodoArbol->dato = (char*)malloc(sizeof(char) * (strlen(palabra)+1));
		strcpy(nuevoNodoArbol->dato,palabra);
        nuevoNodoArbol->num = num;
        *nodoArbol = nuevoNodoArbol;
		return; 
	}

    int diferencia = strcmp(palabra,(*nodoArbol)->dato);

	if(diferencia < 0){
		agregaNodo(&((*nodoArbol)->izq),palabra,num);

	}else{
		agregaNodo(&((*nodoArbol)->der),palabra,num);
	}
}