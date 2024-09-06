#include <stdio.h>
#include <stdlib.h>

// Estructura del árbol binario completo
typedef struct {
    int *datos;      // Arreglo para almacenar los datos de los nodos
    int capacidad;   // Capacidad total del arreglo
    int tamaño;      // Número actual de elementos en el árbol
} CBTree;

// Función para crear un árbol binario completo
CBTree* cbtree_crear(int niveles) {
    CBTree *arbol = (CBTree *)malloc(sizeof(CBTree));
    if (arbol == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    
    // Calcula la capacidad total del arreglo
    int numNodos = (1 << niveles) - 1;  // 2^niveles - 1
    arbol->datos = (int *)malloc(numNodos * sizeof(int));
    if (arbol->datos == NULL) {
        perror("Error al asignar memoria");
        free(arbol);
        exit(EXIT_FAILURE);
    }
    
    arbol->capacidad = numNodos;
    arbol->tamaño = 0;
    return arbol;
}

// Función para destruir un árbol
void cbtree_destruir(CBTree *arbol) {
    if (arbol != NULL) {
        free(arbol->datos);
        free(arbol);
    }
}

// Función para insertar un elemento en el árbol
void cbtree_insertar(CBTree *arbol, int dato) {
    if (arbol->tamaño >= arbol->capacidad) {
        printf("El árbol está lleno.\n");
        return;
    }
    
    arbol->datos[arbol->tamaño] = dato;
    arbol->tamaño++;
}

// Función para obtener el número de elementos en el árbol
int cbtree_nelementos(CBTree *arbol) {
    return arbol->tamaño;
}

// Función para recorrer el árbol en profundidad (preorden)
void cbtree_recorrer(CBTree *arbol, int index, void (*func)(int)) {
    if (index >= arbol->tamaño) {
        return;
    }
    
    func(arbol->datos[index]);
    cbtree_recorrer(arbol, 2 * index + 1, func);  // Recorrer subárbol izquierdo
    cbtree_recorrer(arbol, 2 * index + 2, func);  // Recorrer subárbol derecho
}

// Función para recorrer el árbol en amplitud (por niveles)
void cbtree_recorrer_bfs(CBTree *arbol, void (*func)(int)) {
    if (arbol == NULL || arbol->tamaño == 0) {
        return;
    }
    
    for (int i = 0; i < arbol->tamaño; i++) {
        func(arbol->datos[i]);
    }
}

// Función de ejemplo para imprimir un nodo
void imprimir(int dato) {
    printf("%d ", dato);
}

// Función de ejemplo para imprimir un salto de línea
void salto_linea(int dato) {
    printf("\n");
}

// Ejemplo de uso
int main() {
    int niveles = 3;  // Número máximo de niveles
    CBTree *arbol = cbtree_crear(niveles);

    // Insertar algunos elementos
    cbtree_insertar(arbol, 1);
    cbtree_insertar(arbol, 2);
    cbtree_insertar(arbol, 3);
    cbtree_insertar(arbol, 4);
    cbtree_insertar(arbol, 5);
    cbtree_insertar(arbol, 6);
    cbtree_insertar(arbol, 7);

    // Recorrer el árbol en profundidad (preorden)
    printf("Recorrido en profundidad (preorden): ");
    cbtree_recorrer(arbol, 0, imprimir);
    printf("\n");

    // Recorrer el árbol en amplitud (por niveles)
    printf("Recorrido en amplitud (por niveles): ");
    cbtree_recorrer_bfs(arbol, imprimir);
    printf("\n");

    // Imprimir el número de elementos
    printf("Número de elementos en el árbol: %d\n", cbtree_nelementos(arbol));

    // Destruir el árbol
    cbtree_destruir(arbol);

    return 0;
}
