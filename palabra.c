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


int comparaPalabra(char*palabra1,char*palabra2,char ** resultado){
    int largo1 = strlen(palabra1);
    int largo2 = strlen(palabra2);
    int largo =  largo1;

    if(largo1 != largo2){
        printf("error : las palabras no son de tamaño igual");
        return -1;
    }

    for(int i= 0;i<largo;i++){
        int found = 0;

        if(palabra1[i] == palabra2[i]){
            (*resultado)[i] = *"*";
            found = 1;
        }

        if(found == 0){
            for(int j = 0;j<largo;j++){
                if(palabra1[i] == palabra2[j] && i!=j){
                    (*resultado)[i] = *"+";
                    found = 1;
                    break;
                }
            }
        }

        if(found == 0){
            (*resultado)[i] = *"-";
        }
    }
    (*resultado)[largo] = '\0';

    return 1;
}
