#include<stdio.h>
#include<string.h>

void swap (int *a, int *b);
int longitudCadena ( char * cadena);
void invertirArreglo (int *arr, int size);
void imprimirArreglo (int *arr, int size);
int cuentaPares (int *arr, int size);

int main(){
	int x = 234;
	int y = 109;
	int arreglo[] = {1, 2, 3, 4, 5};
    int size = 5;
    
	printf("swap antes: x=%d, y=%d\n",x,y);
	swap(&x,&y);
	printf("swap despues: x=%d, y=%d\n",x,y);
	
	char texto[] = "Esta es una practica de la carrera de IIS";
	printf("Esta es una practica de la carrera de IIS\n");
    printf("Longitud: %d\n", longitudCadena(texto));
    
    printf("Antes:\n");
    imprimirArreglo(arreglo, size);
    
    invertirArreglo(arreglo, size);
    
    printf("Despues:\n");
    imprimirArreglo(arreglo, size);
    
    return 0;
}

void swap(int *a, int *b){
	int cb = *a;
	*a = *b;
	*b = cb;
}

int longitudCadena(char * cadena){
	int i;
     for (i = 0; cadena[i] != '\0'; i++) {
     }
	return i;
}

void invertirArreglo(int *arr, int size) {
    int *inicio = arr;           
    int *fin = arr + size - 1;   
    int temp;
    
  
    while (inicio < fin) {
        
        temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        
       
        inicio++;
        fin--;
    }
}


void imprimirArreglo(int *arr, int size) {
    printf("Arreglo: ");
    for (int o = 0; o < size; o++) {
        printf("%d ", arr[o]);
    }
    printf("\n");
}

int cuentaPares (int *arr, int size){
	
	
}




