#include<stdio.h>
#include<string.h>

void swap (int *a, int *b);
int longitudCadena ( char * cadena);
void invertirArreglo (int *arr , int size);
int cuentaPares (int *arr , int size);

int main(){
	int x = 234;
	int y = 109;
	
	printf("swap antes: x=%d, y=%d\n",x,y);
	swap(&x,&y);
	printf("swap despues: x=%d, y=%d\n",x,y);
	
	char texto[] = "Esta es una practica de la carrera de IIS";
    printf("Longitud: %d\n", longitudCadena(texto));
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

void invertirArreglo (int *arr , int size){
	
}




