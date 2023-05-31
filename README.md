[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/YWhW4XMs)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10990408)
# Taller 2
Estructuras de datos - 2023.1

Integrantes del Grupo:
-Erick Araya
-Martin Cortes
-Eduardo Cortes
-Miguel Carvajal

[Incluya a continuación información acerca del proceso de desarrollo, por ejemplo: distribución de tareas, estrategias de implementación, y principales problemas y cómo fueron solucionados.
Incluya también indicaciones de cómo usar su programa.]


## Tareas:

### Mejorar implementacion taller 1

Corregidas observaciones realizadas en la evaluacion del taller 1
- Mejorado el orden respecto a funciones en nodo.c y listapalabras.c
- La funcion elegirPalabraAleatoriaNoUsada en listapalabras.c ahora funciona correctamente

### Implementar lista_palabras.h usando ABB

En lista_palabras_abb.h se encuentran las funciones que deben ser implementadas comentadas, una vez se complete la implementacion de una funcion en lista_palabras_abb.c se debera descomentar (no se debe cambiar nada respecto al nombre o los argumentos de la funcion) 

#### Funciones ya implementadas:
- crearListaPalabras
- agregarPalabra
- buscaPalabra
- marcarPalabraUsada
- elegirPalabraAleatoriaNoUsada

### Implementar lista_palabras.h usando AVL

El código ha sido reestructurado con el propósito de permitir que la implementación utilizando árboles AVL haga uso de todas las funciones utilizadas por el árbol ABB, a excepción de la función de agregación de nodos. Dicha función aún está pendiente de implementación, ya que difiere en su lógica para los árboles AVL y ABB.

- Revisar librerias/arboles/requerimientos/avl/avl.c
- La funcion para agregar nodos en arbol ABB ahora se encuentra en librerias/arboles/requerimientos/abb/abb.c


## Notas

### Uso de gdb para encontrar errores tipo segmentation fault (core dumped)
En caso de que intentemos acceder a memoria de manera incorrecta (ej: tratar de acceder a nodo->sgte cuando nodo es NULL) el compilador solo mostrara el error: segmentation fault (core dumped) sin indicar en donde se produce el error, para encontrarlo mas facilmente seguir los siguientes pasos:

- Compilar usando la opcion "-g" de esta forma: "gcc juego.c -g -o juego -lncurses".
- Usar el comando "gdb" para abrir gdb.
- Usar el comando "file juego" para indicarle cual es el programa que queremos debugear.
- Usar el comando "run".

De esta forma gbd nos mostrara donde ocurrio el error, para salir de gbd escribir "q"
