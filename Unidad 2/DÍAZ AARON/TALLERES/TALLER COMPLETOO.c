#include <stdio.h>  // Libreria estandar para entrada y salida de datos (printf, scanf, getchar)
#include <stdlib.h> // Libreria estandar del sistema (permite usar system("cls"))

int main() {
    int op, mes, anio, dia, diasMaximos;

    int n, i;                // 'n' guarda la cantidad de terminos; 'i' es el contador de los bucles for
    char letraSup, letraInf; // Variables tipo caracter (char) para almacenar las letras de arriba y abajo


    int num1, num2;          // Almacenan los valores actuales de cada subsecuencia (empiezan en 1 y 5)

    do {
        system("cls"); // Limpia la pantalla de la consola en cada repeticion del menu

        // Despliegue de opciones del menu exacto
        printf("MENU\n");
        printf("1. Validar fecha\n");
        printf("2. Desplegar serie letras\n");
        printf("3. Desplegar serie numero\n");
        printf("4. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &op); // Lee la opcion elegida por el usuario y la guarda en 'op'

        system("cls"); // Limpia la pantalla antes de mostrar la opcion seleccionada

        // Evalua que opcion eligio el usuario
        switch(op) {
            case 1:
                // Validacion del anio (debe estar entre 1900 y 2015)
                do {
                    printf("INGRESE UN ANIO: ");
                    scanf("%d", &anio);
                    if(anio < 1900 || anio > 2015) {
                        printf("Error, tiene que insertar un ano de (1900 a 2015).\n");
                    }
                } while (anio < 1900 || anio > 2015);
                printf("Anio valido ingresado %d!\n", anio);

                // Validacion del mes (debe estar entre 1 y 12)
                do {
                    printf("INGRESE UN MES (1-12): ");
                    scanf("%d", &mes);
                    if (mes < 1 || mes > 12) {
                        printf("Error, el mes debe ser un valor entre 1 y 12.\n");
                    }
                } while (mes < 1 || mes > 12);

                // Muestra el nombre del mes segun el numero ingresado
                printf("Mes valido ingresado: ");
                switch(mes) {
                    case 1:  printf("Enero\n"); break;
                    case 2:  printf("Febrero\n"); break;
                    case 3:  printf("Marzo\n"); break;
                    case 4:  printf("Abril\n"); break;
                    case 5:  printf("Mayo\n"); break;
                    case 6:  printf("Junio\n"); break;
                    case 7:  printf("Julio\n"); break;
                    case 8:  printf("Agosto\n"); break;
                    case 9:  printf("Septiembre\n"); break;
                    case 10: printf("Octubre\n"); break;
                    case 11: printf("Noviembre\n"); break;
                    case 12: printf("Diciembre\n"); break;
                }

                // Determina la cantidad maxima de dias segun el mes elegido
                if (mes == 2) {
                    diasMaximos = 29;
                } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                    diasMaximos = 30;
                } else {
                    diasMaximos = 31;
                }

                // Validacion del dia dentro del rango permitido para ese mes
                do {
                    printf("INGRESE UN DIA (1-%d): ", diasMaximos);
                    scanf("%d", &dia);
                    if (dia < 1 || dia > diasMaximos) {
                        printf("Error, el dia debe ser un valor entre 1 y %d para este mes.\n", diasMaximos);
                    }
                } while (dia < 1 || dia > diasMaximos);

                // Impresion final de la fecha completa validada
                printf("\nFecha ingresada: %d de ", dia);
                switch(mes) {
                    case 1:  printf("Enero"); break;
                    case 2:  printf("Febrero"); break;
                    case 3:  printf("Marzo"); break;
                    case 4:  printf("Abril"); break;
                    case 5:  printf("Mayo"); break;
                    case 6:  printf("Junio"); break;
                    case 7:  printf("Julio"); break;
                    case 8:  printf("Agosto"); break;
                    case 9:  printf("Septiembre"); break;
                    case 10: printf("Octubre"); break;
                    case 11: printf("Noviembre"); break;
                    case 12: printf("Diciembre"); break;
                }
                printf(" de %d\n", anio);

                break; // Sale del case 1

            case 2:
                // 1. VALIDACION DE ENTRADA:
                // Pide 'n' y repite el bucle mientras el numero sea menor o igual a cero
                do {
                    printf("INGRESE LA CANTIDAD DE TERMINOS DE LA SERIE: ");
                    scanf("%d", &n);
                    if (n <= 0) {
                        printf("Error, la cantidad de terminos debe ser mayor que cero.\n");
                    }
                } while (n <= 0);

                printf("\n"); // Salto de linea estetico antes de imprimir la serie

                letraSup = 'a'; // Inicializa en la letra 'a'
                for (i = 0; i < n; i++) {
                    // Verifica que el caracter no pase de 'z'
                    if (letraSup <= 'z') {
                        printf("%c   ", letraSup); // Imprime la letra actual con espacios de separacion
                        letraSup += 2;             // Avanza 2 posiciones para saltar a la siguiente letra impar
                    }
                }
                printf("\n"); // Baja a la siguiente linea para dibujar los guiones
                for (i = 0; i < n; i++) {
                    // Solo dibuja un guion si existe una letra valida arriba ('a' + i*2 <= 'z')
                    if (('a' + (i * 2)) <= 'z') {
                        printf("-   "); // Imprime el guion alineado con las letras
                    }
                }
                printf("\n"); // Baja a la tercera linea para las letras inferiores

                letraInf = 'b'; // Inicializa en la letra 'b'
                for (i = 0; i < n; i++) {
                    // Verifica que el caracter no pase de 'z'
                    if (letraInf <= 'z') {
                        printf("%c   ", letraInf); // Imprime la letra par actual
                        letraInf += 2;             // Avanza 2 posiciones para saltar a la siguiente letra par
                    }
                }
                printf("\n"); // Salto de linea final al terminar la serie

                break; // Sale del case 2

            case 3:
                // Pide 'n' y repite solo si es negativo (n < 0). Se permite ingresar 0.
                do {
                    printf("INGRESE LA CANTIDAD DE TERMINOS DE LA SERIE: ");
                    scanf("%d", &n);
                    if (n < 0) {
                        printf("Error, la cantidad de terminos no puede ser negativa.\n");
                    }
                } while (n < 0);

                // Cada vez que se entra a la opcion 3, las subsecuencias arrancan en 1 y 5
                num1 = 1;
                num2 = 5;

                printf("\nSerie generada: ");

                // Se repite (n / 2) veces. Por ejemplo, si n = 6 hace 3 parejas; si n = 5 hace 2 parejas
                for (i = 0; i < n / 2; i++) {
                    printf("%d, %d", num1, num2); // Imprime la pareja actual
                    num1 += 2; // Aumenta en 2 la primera subsecuencia (1 -> 3 -> 5...)
                    num2 += 2; // Aumenta en 2 la segunda subsecuencia (5 -> 7 -> 9...)

                    // Si todavia faltan mas parejas o un termino impar por imprimir, pone coma
                    if (i < (n / 2) - 1 || n % 2 != 0) {
                        printf(", ");
                    }
                }

                // Si el residuo de dividir 'n' para 2 es distinto de 0, imprime un ultimo valor de num1
                if (n % 2 != 0) {
                    printf("%d", num1);
                }

                printf("\n"); // Salto de linea al finalizar la serie

                break; // Sale del case 3

            case 4:
                printf("Salir...\n");
                break;

            default:
                // Se ejecuta si el usuario ingresa un numero distinto de 1, 2, 3 o 4
                printf("Opcion no valida\n");
                break;
        }

        // Pausa antes de volver al menu (excepto si eligio 4 para salir)
        if (op != 4) {
            printf("\nPresione una tecla para continuar...");
            getchar(); // Limpia el salto de linea ('\n') que quedo pendiente en el buffer tras el scanf
            getchar(); // Espera a que el usuario presione Enter para continuar
        }

    } while(op != 4); // Condicion de repeticion del menu

    return 0; // Indica que el programa finalizo correctamente
}
