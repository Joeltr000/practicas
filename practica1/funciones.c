#include<stdio.h>
#include<string.h>

// Dlecraracion de funciones ocupadas 
void swap (int *a, int *b);  // Para cambiar dos numeros
int longitudCadena ( char * cadena);  // Para saber cuantas letras tiene un texto
void invertirArreglo (int *arr, int size);  // Para voltear un arreglo
void imprimirArreglo (int *arr, int size);  // Para mostrar un arreglo
int cuentaPares (int *arr, int size);  // Para contar numeros pares

int main(){
    // Variables para probar el swap
    int x = 234;
    int y = 109;
    
    // Arreglo para las pruebas de longitudCadena y invertirArreglo
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10; 
    
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]); // Calculamos cuantos elementos tiene el arreglo
    int numPares = cuentaPares(arreglo, tamano); // Contamos los pares desde el principio

    // Probamos la función swap
    printf("swap antes: x=%d, y=%d\n",x,y);
    swap(&x,&y);  // Esto cambiamos los valores de X a Y y Y a X 
    printf("swap despues: x=%d, y=%d\n",x,y);
    
    // Probamos la longitud de cadena
    char texto[] = "Esta es una practica de la carrera de IIS";
    printf("El mensaje es: Esta es una practica de la carrera de IIS\n");
    printf("Longitud: %d\n", longitudCadena(texto));  // Deberia dar 41 
    
    // Probamos invertir arreglo
    printf("Antes\n");
    imprimirArreglo(arreglo, size);  // Muestra el arreglo original
    
    invertirArreglo(arreglo, size);  // Lo volteamos
    
    printf("Despues\n");
    imprimirArreglo(arreglo, size);  // Muestra el arreglo invertido
    
    // Muestra cuanto numeros son pares 
    printf("El numero de elementos pares en la matriz es: %d\n", numPares); 
    
    return 0;  
}


     
void swap(int *a, int *b){       //funcion cambira numeros
    int cb = *a;  // Guardamos el valor de a
    *a = *b;      // Ponemos b en a
    *b = cb;      // Ponemos el valor guardado en b
}

int longitudCadena(char * cadena){  //funcion de contar cuantos caracteres estan en la frace
    int i;  // Variable para contar
    // Recorremos hasta encontrar el final
    for (i = 0; cadena[i] != '\0'; i++) {
    }
    return i;  // Devolvemos el contador
}



void invertirArreglo(int *arr, int size) {      //funcion voltea la matriz al reves ejemplo: hola, aloh
    int *inicio = arr;           // Puntero al principio
    int *fin = arr + size - 1;   // Puntero al final
    int temp;                    // Variable temporal
    
    // Mientras no se crucen
    while (inicio < fin) {
        // Intercambiamos los valores
        temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        
        // Movemos los punteros
        inicio++;
        fin--;
    }
}

void imprimirArreglo(int *arr, int size) { // Este solo es para imprimir la matriz y luego sea ocupada en las otras funciones 
    printf("El arreglo: ");
    // Recorremos todo el arreglo
    for (int o = 0; o < size; o++) {
        printf("%d ", arr[o]);  // Imprimimos cada número
    }
    printf("\n"); 
}

int cuentaPares (int *arr, int size){    // funcion para contar cuantos numeros pares hay en la matriz escrita
    int contador = 0;  // Empezamos en cero
    
    // este for es para recorrer pero apuntadores 
    for (int *puntero_actual = arr; puntero_actual < arr + size; puntero_actual++) {
        // Si es divisible entre 2 es par
        if (*puntero_actual % 2 == 0) {
            contador++;
        }
    }
    return contador;  // Devolvemos el total
}

