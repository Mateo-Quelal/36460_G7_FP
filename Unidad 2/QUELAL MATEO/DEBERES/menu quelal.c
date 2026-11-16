#include <stdio.h>
#include <math.h>

int main() {
    int op, n, i, j;
    float res;

    // Bucle principal para que el menú se repita hasta que el usuario elija salir
    do {
        printf("\nMENU\n");
        printf("1. Figura\n");
        printf("2. Serie\n");
        printf("3. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &op);

        // Estructura de selección según la opción elegida
        switch(op) {
            case 1: // Opción para dibujar la figura (cuadrado hueco)

                // Valida que el número ingresado sea positivo
                do {
                    printf("Ingrese numero de filas: ");
                    scanf("%d", &n);
                } while(n <= 0);

                // Bucle para controlar las filas de la figura
                for(i = 0; i < n; i++) {
                    // Bucle para controlar las columnas de cada fila
                    for(j = 0; j < n; j++) {

                        // Si está en los bordes (primera/última fila o columna), imprime '1'
                        if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                            printf("1 ");
                        } else {
                            // Si está en el centro, imprime espacios vacíos
                            printf("  ");
                        }
                    }
                    // Salto de línea al terminar cada fila de la matriz
                    printf("\n");
                }
                break;

            case 2: // Opción para calcular la serie matemática

                // Valida que la cantidad de términos sea positiva
                do {
                    printf("Ingrese numero de terminos: ");
                    scanf("%d", &n);
                } while(n <= 0);

                res = 0;
                // Bucle para generar y sumar cada término de la serie
                for(i = 1; i <= n; i++) {

                    // Si es el último término, lo imprime sin el signo '+' al final
                    if(i == n) {
                        printf("%d^%d ", i, i);
                    } else {
                        // Si no es el último, imprime el término seguido de un '+'
                        printf("%d^%d + ", i, i);
                    }

                    // Suma el valor de la potencia i^i al acumulador
                    res = res + pow(i, i);
                }
                // Muestra el resultado final de la serie
                printf("\nEl resultado es %.2f\n", res);
                break;

            case 3: // Opción para salir
                printf("Saliendo...\n");
                break;

            default: // Se ejecuta si el usuario ingresa un número que no está en el menú
                printf("Opcion no valida\n");
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
