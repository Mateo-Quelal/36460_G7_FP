#include <stdio.h>
#include <stdlib.h>

int main() {
    int op, mes, anio, dia, diasMaximos;

    do {
        system("cls");

        printf("\nMenu Taller en clases\n");
        printf("1. Validar Fecha\n");
        printf("2. Desplegar serie de fechas\n");
        printf("3. Desplegar Serie Numero\n");
        printf("4. Salir\n");
        printf("Seleccione un valor de (1-4): ");
        scanf("%d", &op);

        system("cls");

        switch(op) {
            case 1:
                do{
                    printf("INGRESE UN ANIO: ");
                    scanf("%d", &anio);
                    if(anio<1900 || anio>2015){
                            printf("Error, tiene que insertar un ano de (1900 a 2015).\n");
                    }
                } while (anio<1900 || anio>2015);
                printf ("Anio valido ingresado %d!\n", anio);

                do {
                    printf("INGRESE UN MES (1-12): ");
                    scanf("%d", &mes);
                    if (mes < 1 || mes > 12) {
                        printf("Error, el mes debe ser un valor entre 1 y 12.\n");
                    }
                } while (mes < 1 || mes > 12);

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

                if (mes == 2) {
                    diasMaximos = 29;
                } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                    diasMaximos = 30;
                } else {
                    diasMaximos = 31;
                }

                do {
                    printf("INGRESE UN DIA (1-%d): ", diasMaximos);
                    scanf("%d", &dia);
                    if (dia < 1 || dia > diasMaximos) {
                        printf("Error, el dia debe ser un valor entre 1 y %d para este mes.\n", diasMaximos);
                    }
                } while (dia < 1 || dia > diasMaximos);

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

                break;

            case 2:
                printf("Opcion 2 aun no implementada.\n");
                break;

            case 3:
                printf("Opcion 3 aun no implementada.\n");
                break;

            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
                break;
        }

        if (op != 4) {
            printf("\nPresione una tecla para continuar...");
            getchar();
            getchar();
        }

    } while(op != 4);

    return 0;
}
