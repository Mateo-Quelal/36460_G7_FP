#include <stdio.h>

int main() {
    int op, n, i, j;
    long long a, b, siguiente;

    // Bucle principal para que el menú se repita hasta que el usuario elija salir
    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Dibujar cuadrado hueco\n");
        printf("2. Generar secuencia de Fibonacci\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion (1-3): ");
        scanf("%d", &op);

        // Estructura de selección según la opción elegida
        switch(op) {
            case 1: // Opción para dibujar la figura (cuadrado hueco)

                // Valida que el número ingresado sea positivo
                do {
                    printf("Ingrese el tamano del lado del cuadrado (n): ");
                    scanf("%d", &n);
                    if(n <= 0) {
                        printf("Error: Ingrese un numero entero positivo valido.\n");
                    }
                } while(n <= 0);

                printf("\n--- Resultado Cuadrado Hueco (%d x %d) ---\n", n, n);

                // Bucle para controlar las filas de la figura
                for(i = 0; i < n; i++) {
                    // Bucle para controlar las columnas de cada fila
                    for(j = 0; j < n; j++) {

                        // Si está en los bordes (primera/última fila o columna), imprime '*'
                        if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                            printf("* ");
                        } else {
                            // Si está en el centro, imprime espacios vacíos
                            printf("  ");
                        }
                    }
                    // Salto de línea al terminar cada fila de la matriz
                    printf("\n");
                }
                break;

            case 2: // Opción para generar la secuencia de Fibonacci

                // Valida que la cantidad de términos sea positiva
                do {
                    printf("Ingrese cuantos terminos desea ver: ");
                    scanf("%d", &n);
                    if(n <= 0) {
                        printf("Error: Por favor, ingrese un numero entero positivo.\n");
                    }
                } while(n <= 0);

                printf("\n--- Serie de Fibonacci (%d terminos) ---\n", n);

                a = 0;
                b = 1;

                // Bucle para generar y mostrar cada término de la secuencia
                for(i = 1; i <= n; i++) {
                    printf("%lld ", a);
                    siguiente = a + b;
                    a = b;
                    b = siguiente;
                }
                printf("\n");
                break;

            case 3: // Opción para salir
                printf("Saliendo del programa. Hasta luego!\n");
                break;

            default: // Se ejecuta si el usuario ingresa un número que no está en el menú
                printf("Opcion no valida. Elija una opcion entre 1 y 3.\n");
                break;
        }

        // Si la opción no es salir, hace una pausa antes de volver a mostrar el menú
        if(op != 3) {
            printf("\nPresione Enter para continuar...");
            while(getchar() != '\n'); // Limpia el búfer del teclado
            getchar();
        }

    } while(op != 3); // Condición para mantener el programa activo

    return 0;
}
