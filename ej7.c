#include <stdio.h>
#include <stdlib.h>

typedef struct _TNodo{
    int dato;
    struct _TNodo *izq, *der;
} TNodo;

TNodo * crearArbol(int nivel){
    if (nivel <= 0) {
        return NULL;
    }

    TNodo *nuevoArbol = malloc (sizeof(TNodo));
    if (nuevoArbol == NULL)
        return NULL;

    nuevoArbol->izq = NULL;
    nuevoArbol->der = NULL;
    
    nuevoArbol->izq = crearArbol(nivel - 1);
    nuevoArbol->der = crearArbol(nivel - 1);

    return nuevoArbol;
}


void liberarArbol(TNodo *arbol) {
    if (arbol == NULL)
        return;
    
    liberarArbol(arbol->izq);
    liberarArbol(arbol->der);
    free(arbol);
}

void imprimirArbolEsquematico(TNodo *raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }
    
    // Primero imprimimos el hijo derecho
    imprimirArbolEsquematico(raiz->der, nivel + 1);
    
    // Imprimimos el nodo actual con un espaciado proporcional al nivel
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%d\n", raiz->dato);
    
    // Finalmente, imprimimos el hijo izquierdo
    imprimirArbolEsquematico(raiz->izq, nivel + 1);
}

int main(){

    TNodo *miArbol = crearArbol(1);

    miArbol->izq = crearArbol(2);
    miArbol->der = crearArbol(3);

    miArbol->izq->izq = crearArbol(4);
    miArbol->izq->der = crearArbol(5);
    miArbol->der->izq = crearArbol(6);
    miArbol->der->der = crearArbol(7);
    

    liberarArbol(miArbol);
}