#include <stdio.h>
#include <stdlib.h>

typedef struct _TNodo{
    int dato;
    struct _TNodo izq, der;
} TNodo;

TNodo * crearArbol(){
    TNodo *nuevoArbol = malloc (sizeof(TNodo));
    if (nuevoArbol == NULL)
        return NULL;
    
    return nuevoArbol;
}

void llenarArbol (TNodo *arbol){
    if (arbol == NULL)
        return;

    printf("\nIngrese valor: ");
    scanf("%d", arbol->dato);
    llenarArbol(arbol->izq);
    llenarArbol(arbol->der);
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
int main(){
    TNodo *miArbol = crearArbol();

    (miArbol->dato) = 1;
    (miArbol->izq) = crearArbol();
  
}