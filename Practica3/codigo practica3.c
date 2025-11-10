#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Punteros dobles globales para el inventario s
char **nombresProductos = NULL;  // Guarda los nombres de los productos
int *cantidades = NULL;          // Guarda las cantidades de cada producto  
double *precios = NULL;          // Guarda los precios de cada producto
int totalP = 0;                  // Contador de productos en el inventario

// Declaramos las funciones que vamos a usar
int agregarProducto();
void mostrarProductos();
double calcularValorTotalInventario();
void liberarInventario();
void cargarDatosIniciales();

int main() {
    int opcion;

    printf("=== SISTEMA DE INVENTARIO ===\n");

    // Llenar inventario con datos de ejemplo 

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular valor total del inventario\n");
        printf("4. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Llamamos a la función para agregar producto
                if(agregarProducto()) {
                    printf("Producto agregado exitosamente!\n");
                } else {
                    printf("Error al agregar producto.\n");
                }
                break;
            case 2:
                // Llamamos a la función para mostrar inventario
                mostrarProductos();
                break;
            case 3:
                // Calculamos y mostramos el valor total
                printf("Valor total del inventario: $%.2f\n", 
                       calcularValorTotalInventario());
                break;
            case 4:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 4);

    // Liberar memoria antes de salir
    liberarInventario();
    return 0;
}

// Función para cargar los productos iniciales de la tabla
void cargarDatosIniciales() {
    printf("Cargando productos iniciales...\n");
    
    // Estos son los datos de la tabla que nos dieron
    char *nombres[] = {"Laptop HP", "Mouse Inalambrico", "Teclado Mecanico", 
                      "Camisa Casual", "Jeans", "Zapatos Deportivos", 
                      "Arroz", "Frijol", "Aceite"};
    int cants[] = {5, 15, 8, 20, 12, 10, 50, 40, 30};
    double preciosIni[] = {1200.00, 25.50, 75.00, 35.00, 45.00, 60.00, 2.50, 3.00, 4.50};
    int numProductos = 9;  // Son 9 productos en la tabla
    
    // Por cada producto, lo agregamos al inventario
    for(int i = 0; i < numProductos; i++) {
        nombresProductos = realloc(nombresProductos, (totalP + 1) * sizeof(char*));
        cantidades = realloc(cantidades, (totalP + 1) * sizeof(int));
        precios = realloc(precios, (totalP + 1) * sizeof(double));
        
        // Reservamos memoria para el nombre y lo copiamos
        *(nombresProductos + totalP) = malloc((strlen(*(nombres + i)) + 1) * sizeof(char));
        strcpy(*(nombresProductos + totalP), *(nombres + i));
        
        // Guardamos cantidad y precio
        *(cantidades + totalP) = *(cants + i);
        *(precios + totalP) = *(preciosIni + i);
        
        totalP++;  // Aumentamos el contador de productos
    }
    printf("Se cargaron %d productos iniciales.\n", totalP);
}

int agregarProducto() {
    char nombre[100];
    int cantidad;
    double precio;
    
    printf("\n=== Agregar Producto ===\n");
    
    // Pedimos los datos al usuario
    printf("Nombre: ");
    getchar();  // Limpiamos el buffer del teclado
    fgets(nombre, 100, stdin);
    nombre[strcspn(nombre, "\n")] = 0;  
    
    printf("Cantidad: ");
    scanf("%d", &cantidad);
    
    printf("Precio: ");
    scanf("%lf", &precio);
    
    // Hacemos backup de los punteros originales por si falla realloc
    char **backupNombres = nombresProductos;
    int *backupCantidades = cantidades;
    double *backupPrecios = precios;
    int backupTotal = totalP;  // Backup del contador actual
    
    // 1. Agrandamos el arreglo de nombres
    char **tempNombres = realloc(nombresProductos, (totalP + 1) * sizeof(char*));
    if(tempNombres == NULL) {
        printf("Error: No se pudo agrandar la memoria para nombres\n");
        return 0;
    }
    nombresProductos = tempNombres;
    
    // 2. Agrandamos el arreglo de cantidades
    int *tempCantidades = realloc(cantidades, (totalP + 1) * sizeof(int));
    if(tempCantidades == NULL) {
        printf("Error: No se pudo agrandar la memoria para cantidades\n");
        nombresProductos = backupNombres;
        return 0;
    }
    cantidades = tempCantidades;
    
    // 3. Agrandamos el arreglo de precios
    double *tempPrecios = realloc(precios, (totalP + 1) * sizeof(double));
    if(tempPrecios == NULL) {
        printf("Error: No se pudo agrandar la memoria para precios\n");
        nombresProductos = backupNombres;
        cantidades = backupCantidades;
        return 0;
    }
    precios = tempPrecios;
    
    // 4. Reservamos memoria para el nuevo nombre y lo copiamos
    *(nombresProductos + totalP) = malloc((strlen(nombre) + 1) * sizeof(char));
    if(*(nombresProductos + totalP) == NULL) {
        printf("Error: No se pudo reservar memoria para el nombre\n");
        nombresProductos = backupNombres;
        cantidades = backupCantidades;
        precios = backupPrecios;
        return 0;
    }
    strcpy(*(nombresProductos + totalP), nombre);
    
    // 5. Guardamos la cantidad y precio en la última posición
    *(cantidades + totalP) = cantidad;
    *(precios + totalP) = precio;
    
    // 6. Aumentamos el contador de productos
    totalP++;
    
    return 1;  // Todo salió bien
}

void mostrarProductos() {
    printf("\n=== Productos %d ===\n", totalP);
    
    if(totalP == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    
    // Mostramos encabezados
    printf("Pos | Nombre                | Cantidad | Precio    | Valor Total\n");
    printf("----|-----------------------|----------|-----------|------------\n");
    
    // Recorremos todos los productos
    for(int i = 0; i < totalP; i++) {
        double valorTotal = *(cantidades + i) * *(precios + i);
        printf("%3d | %-21s | %8d | $%8.2f | $%10.2f\n", 
               i, *(nombresProductos + i), *(cantidades + i), *(precios + i), valorTotal);
    }
}

double calcularValorTotalInventario() {
    double total = 0;
    
    // Recorremos todos los productos
    for(int i = 0; i < totalP; i++) {
        // Para cada producto: cantidad * precio
        total += *(cantidades + i) * *(precios + i);
    }
    
    return total;
}

void liberarInventario() {
    printf("Liberando memoria...\n");
    
    // Primero liberamos cada nombre individual
    for(int i = 0; i < totalP; i++) {
        free(*(nombresProductos + i));  // Liberamos cada string
    }
    
    // Luego liberamos los arreglos principales
    free(nombresProductos);
    free(cantidades);
    free(precios);
    
    // Ponemos los punteros en NULL para evitar usarlos por error
    nombresProductos = NULL;
    cantidades = NULL;
    precios = NULL;
    totalP = 0;
    
    printf("Memoria liberada correctamente.\n");
}
