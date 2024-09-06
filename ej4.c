#include <stdio.h>
#include <stdlib.h>

typedef struct _TNodo{
    int dato;
    struct _TNodo *izq, *der;
} TNodo;

typedef enum {
    BTREE_RECORRIDO_IN,
    BTREE_RECORRIDO_PRE,
    BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

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

void mostrar(TNodo *arbol, BTreeOrdenDeRecorrido orden) {
    if (arbol == NULL) return;

   if (orden == BTREE_RECORRIDO_IN){
        mostrar(arbol->izq, orden);
        printf(" %d ", arbol->dato);
        mostrar(arbol->der, orden);
   }

   if (orden == BTREE_RECORRIDO_PRE){
        printf(" %d ", arbol->dato);
        mostrar(arbol->izq, orden);
        mostrar(arbol->der, orden);
   }
   
   if (orden == BTREE_RECORRIDO_POST){
        mostrar(arbol->izq, orden);
        mostrar(arbol->der, orden);
        printf(" %d ", arbol->dato);
   }
}

int main(){

    TNodo *miArbol = crearArbol(1);

    miArbol->izq = crearArbol(2);
    miArbol->der = crearArbol(3);

    miArbol->izq->izq = crearArbol(4);
    miArbol->izq->der = crearArbol(5);
    miArbol->der->izq = crearArbol(6);
    miArbol->der->der = crearArbol(7);

    mostrar(miArbol, BTREE_RECORRIDO_IN);
    printf("\n");
    mostrar(miArbol, BTREE_RECORRIDO_PRE);
    printf("\n");
    mostrar(miArbol, BTREE_RECORRIDO_POST);

    //FALTA IMPLEMENTACION PILA//
    
    liberarArbol(miArbol);
}