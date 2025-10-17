#include <stdio.h>
#include <stdlib.h>

void main(){
    printf("=== Calculadora de Promedio Dinamica ===\n\n");
    int opcion = 0;

    float *calificaciones = NULL; 
    int total_calificaciones = 0;  

    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i",&opcion);

        switch(opcion){
        case 1:
              {
                int nuevas_calif;  
                char respuesta;    
                
                do {
                    
                    printf("\n¿Cuántas calificaciones desea ingresar? ");
                    scanf("%d", &nuevas_calif);
                    
                    
                    while(nuevas_calif <= 0) {
                        printf("Error: Debe ingresar un número mayor a 0: ");
                        scanf("%d", &nuevas_calif);
                    }
                    
                    
                    if(total_calificaciones == 0) {
                        
                        calificaciones = (float*)malloc(nuevas_calif * sizeof(float));
                    } else {
                        
                        calificaciones = (float*)realloc(calificaciones, (total_calificaciones + nuevas_calif) * sizeof(float));
                    }
                    
                    
                    if(calificaciones == NULL) {
                        printf("Error: No se pudo asignar memoria\n");
                        return;
                    }
                    
                    
                    for(int i = 0; i < nuevas_calif; i++) {
                        float calif;
                        printf("Ingrese la calificación %d: ", total_calificaciones + i + 1);
                        scanf("%f", &calif);
                        
                        
                        while(calif < 0 || calif > 10) {
                            printf("Error: La calificación debe estar entre 0 y 10: ");
                            scanf("%f", &calif);
                        }
                        
                        calificaciones[total_calificaciones + i] = calif;
                    }
                    
                    
                    total_calificaciones += nuevas_calif;
                    
                    
                    float suma = 0;
                    for(int i = 0; i < total_calificaciones; i++) {
                        suma += calificaciones[i];
                    }
                    float promedio = suma / total_calificaciones;
                    
                    
                    printf("\nPromedio: %.2f\n", promedio);
                    if(promedio >= 7.0) {
                        printf("Estado: APROBADO\n");
                    } else {
                        printf("Estado: REPROBADO\n");
                    }
                    
                    
                    printf("\n¿Desea agregar más calificaciones? (s/n) ");
                    scanf(" %c", &respuesta);  
                    
                    
                    while(respuesta != 's' && respuesta != 'n') {
                        printf("Error: Por favor ingrese 's' para sí o 'n' para no: ");
                        scanf(" %c", &respuesta);
                    }
                    
                } while(respuesta == 's');  
            }
            break;

        case 2:
            //se libera la memoria reservada
             if(calificaciones != NULL) {
                free(calificaciones);
            }

            //mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;
        default:
            //opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }

}

