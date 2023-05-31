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



void iniciarNcurses(){
    initscr(); 
    cbreak(); 
    noecho();
    nonl();
}
void finalizarNcurses(){
    endwin();
}

int pedirPalabra(int maxLetras,char ** resultado){    
    int cantLetras = 0;
    char c = ' ';
    while (cantLetras < maxLetras){
        c = getch();
        if((c>='a') && (c<='z')){
            (*resultado)[cantLetras] = c;
            cantLetras++;
            printw("%c",c);
        }else if(c == '0'){
            (*resultado)[cantLetras] = 0;
            printw("\n");
            return 0;
        }
    }   
    (*resultado)[cantLetras] = 0;
    printw("\n");
    return 1;
}

int partida(ListaPalabras * lista,int intentos,int largoPalabras,char * palabraObjetivo){
    int victoria = 0;
    //printw("\n%s",palabraObjetivo);

    ListaPalabras * listaGuardado = crearListaPalabras();
    while(intentos > 0 && victoria != 1){
        printw("\ningrese intento: ");
        agregarPalabra(listaGuardado,"\ningrese intento: \n");
        char * input = (char*)malloc(sizeof(char) * (largoPalabras+1));
            
        if(pedirPalabra(largoPalabras,&input)== 0){
            free(input);
            break;
        }
            
        if(buscaPalabra(lista,input) != -1){
            intentos--;
            char * resultado = (char*)malloc(sizeof(char) * (largoPalabras+1));
            comparaPalabra(input,palabraObjetivo,&resultado);
            printw("\n%s",resultado);
            agregarPalabra(listaGuardado,resultado);
            if(strcmp(input,palabraObjetivo) == 0){
                victoria = 1;
            }
            free(resultado);
        }else{
            printw("\npalabra no existe intente otra");
            agregarPalabra(listaGuardado,"\npalabra no existe intente otra");
        }

        printw("\nintentos restantes: %d",intentos);
        char cadena[50];
        snprintf(cadena, sizeof(cadena), "\nintentos restantes: %d", intentos);
        agregarPalabra(listaGuardado,cadena);
        free(input);
    }


    if(victoria == 1){
        printw("\nhas ganado\n");
    }else if(intentos <= 0){
        printw("\nhas perdido, la palabra era: %s\n",palabraObjetivo);
    }else{
        printw("\npartida interrumpida\n");
    }

    printw("\ndeseas guardar la partida? [y/n]\n");
    char respuestaGuardado = getch();
    printw("%c",respuestaGuardado);
    if(respuestaGuardado == 'y'){
        guardarPartida("guardado.txt",listaGuardado);
    }


    liberarLista(listaGuardado);
    
    int otraVez = 1;
    printw("deseas jugar una nueva partida? [y/n]");
    char respuesta = getch();
    printw("\n%c",respuesta);
    if(respuesta == 'y'){
        otraVez = 1;
    }else{
        otraVez = 0;
    }
    return otraVez;
}

void guardarPartida(const char* nombreArchivo,ListaPalabras * lista) {
    // Abre el archivo en modo escritura
    FILE* archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printw("No se pudo abrir el archivo.\n");
        return;
    }

    // Escribe el texto en el archivo
    for(int i = 0;i<obtenerCount(lista);i++){
        char * cadena = (char*)malloc(sizeof(char) * (50+1));
        seleccionarPalabra(lista,i,&cadena);
        fprintf(archivo, "%s", cadena);

    }
    
    fclose(archivo);
    printw("\npartida guardada en el archivo: %s\n", nombreArchivo);
}