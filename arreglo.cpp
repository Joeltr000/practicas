#include <stdio.h>



void invertirArreglo(int *arr, int size);
void imprimirArreglo(int *arr, int size); 

int main() {
    // Ejemplo 1: Arreglo pequeño
    int arreglo[] = {1, 2, 3, 4, 5};
    int size = 5;
    printf("Antes de invertir:\n");
    imprimirArreglo(arreglo, size);
    
    invertirArreglo(arreglo, size);
    
    printf("Despues de invertir:\n");
    imprimirArreglo(arreglo, size);
    
   
    return 0;
}


// Función para invertir el arreglo usando punteros
void invertirArreglo(int *arr, int size) {
    int *inicio = arr;           // Puntero al primer elemento
    int *fin = arr + size - 1;   // Puntero al último elemento
    int temp;
    
    // Intercambiamos elementos hasta que los punteros se crucen
    while (inicio < fin) {
        // Intercambiar los valores
        temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        
        // Mover los punteros
        inicio++;
        fin--;
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int *arr, int size) {
    printf("Arreglo: ");
    for (int o = 0; o < size; o++) {
        printf("%d ", arr[o]);
    }
    printf("\n");
}


