#include <stdio.h>
#include <stdlib.h>

typedef struct _TNodo{
    int dato;
    struct _TNodo *izq, *der;
} TNodo;

TNodo * crearArbol(int dato){
    TNodo *nuevoArbol = malloc (sizeof(TNodo));
    if (nuevoArbol == NULL)
        return NULL;

    nuevoArbol->dato = dato;
    nuevoArbol->izq = NULL;
    nuevoArbol->der = NULL;

    return nuevoArbol;
}

int sumarArbol (TNodo *arbol){
    if (arbol == NULL)
        return 0;
    
    return arbol->dato + sumarArbol(arbol->izq) + sumarArbol(arbol->der);
}

int cantNodos (TNodo *arbol){
    if (arbol == NULL)
        return 0;
    
    return 1 + cantNodos(arbol->izq) + cantNodos(arbol->der);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura (TNodo *arbol){
    if (arbol == NULL)
        return 0;

    return 1 + max(altura(arbol->izq), altura(arbol->der));
}

void liberarArbol(TNodo *arbol) {
    if (arbol == NULL)
        return;
    
    liberarArbol(arbol->izq);
    liberarArbol(arbol->der);
    free(arbol);
}

int main(){

    TNodo *miArbol = crearArbol(1);

    miArbol->izq = crearArbol(2);
    miArbol->der = crearArbol(3);

    miArbol->izq->izq = crearArbol(4);
    miArbol->izq->der = crearArbol(5);
    miArbol->der->izq = crearArbol(6);
    miArbol->der->der = crearArbol(7);
    
    printf("\nLa suma del arbol es: %i", sumarArbol(miArbol));
    printf("\nLos nodos del arbol son: %i", cantNodos(miArbol));
    printf("\nLa altura del arbol es: %i", altura(miArbol));



    liberarArbol(miArbol);
}