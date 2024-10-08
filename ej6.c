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


void liberarArbol(TNodo *arbol) {
    if (arbol == NULL)
        return;
    
    liberarArbol(arbol->izq);
    liberarArbol(arbol->der);
    free(arbol);
}

void mirror(TNodo *arbol){
    if(arbol->izq == NULL && arbol->der == NULL) return;

    TNodo *aux;

    aux = arbol->izq;
    arbol->izq = arbol->der;
    arbol->der = aux;

    mirror(arbol->izq);
    mirror(arbol->der);
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
    
    mirror(miArbol);
    imprimirArbolEsquematico(miArbol, 0);

    liberarArbol(miArbol);
}