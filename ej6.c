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
    int *aux;

    aux = arbol->izq;
    arbol->izq = arbol->der;
    arbol->der = aux;

    //FALTA RECURSIVA
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