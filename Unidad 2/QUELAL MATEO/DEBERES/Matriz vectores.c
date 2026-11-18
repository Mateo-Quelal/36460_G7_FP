#include <stdio.h>

// Prototipos de funciones
void limpiarBuffer();
int leerEnteroPositivo(const char *mensaje);
float leerFlotante(const char *mensaje);
void gestionarVector();
void gestionarMatriz();

int main() {
    int opcion;

    // Bucle principal para que el menu se repita hasta que el usuario elija salir
    do {
        printf("\nSOMOS EL GRUPO 7 DE FUNDAMENTOS DE LA PROGRAMACION\n");
        printf("MENU PRINCIPAL\n");
        printf("1. Crear y mostrar vector de enteros positivos\n");
        printf("2. Crear y mostrar matriz de numeros flotantes\n");
        printf("3. Salir del programa\n");
        printf("Seleccione una opcion (1-3): ");

        // Valida que la entrada sea un numero entero
        if (scanf("%d", &opcion) != 1) {
            printf("\nError: Entrada invalida. Por favor, ingrese un numero.\n");
            limpiarBuffer();
            opcion = 0;
            continue;
        }
        limpiarBuffer();

        // Estructura de seleccion segun la opcion elegida
        switch (opcion) {
            case 1:
                gestionarVector();
                break;
            case 2:
                gestionarMatriz();
                break;
            case 3:
                printf("\nSaliendo del programa. Gracias por usar nuestro sistema.\n");
                break;
            default:
                printf("\nError: Opcion no valida. Elija un numero entre 1 y 3.\n");
                break;
        }

    } while (opcion != 3);

    return 0;
}

// Limpia los caracteres residuales del teclado para evitar bucles infinitos
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Solicita y valida que el usuario ingrese un entero mayor a cero
int leerEnteroPositivo(const char *mensaje) {
    int valor;

    while (1) {
        printf("%s", mensaje);
        if (scanf("%d", &valor) == 1 && valor > 0) {
            limpiarBuffer();
            return valor;
        }
        printf("Error: Debe ingresar un numero entero mayor a cero.\n");
        limpiarBuffer();
    }
}

// Solicita y valida que el usuario ingrese un numero decimal valido
float leerFlotante(const char *mensaje) {
    float valor;

    while (1) {
        printf("%s", mensaje);
        if (scanf("%f", &valor) == 1) {
            limpiarBuffer();
            return valor;
        }
        printf("Error: Entrada invalida. Ingrese un numero decimal valido.\n");
        limpiarBuffer();
    }
}

// Crea, llena y muestra el vector de enteros positivos
void gestionarVector() {
    printf("\n--- Caso 1: Gestion de Vectores ---\n");
    int n = leerEnteroPositivo("Ingrese cuantos numeros tendra el vector: ");
    int numeros[n];

    printf("\nIngrese solo numeros positivos mayores a cero:\n");
    for (int i = 0; i < n; i++) {
        char etiqueta[40];
        sprintf(etiqueta, "Posicion [%d]: ", i);
        numeros[i] = leerEnteroPositivo(etiqueta);
    }

    printf("\nVector generado:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("]\n");
}

// Crea, llena y muestra la matriz de numeros flotantes
void gestionarMatriz() {
    printf("\n--- Caso 2: Gestion de Matrices ---\n");
    int filas = leerEnteroPositivo("Ingrese el numero de filas: ");
    int columnas = leerEnteroPositivo("Ingrese el numero de columnas: ");
    float matriz[filas][columnas];

    printf("\nIngrese los elementos flotantes para la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            char etiqueta[40];
            sprintf(etiqueta, "Elemento [%d][%d]: ", i, j);
            matriz[i][j] = leerFlotante(etiqueta);
        }
    }

    printf("\nMatriz resultante:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%8.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}
