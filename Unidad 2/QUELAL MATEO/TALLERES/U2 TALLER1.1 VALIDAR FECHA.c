
#include <stdio.h>
#include <stdlib.h>

int main() {
    int dia, mes, anio, op;
    int valida;

    char *meses[] = {"Enero", "Febrero", "Marzo", "Abril",
                     "Mayo", "Junio", "Julio", "Agosto",
                     "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    do {
        printf("\nMENU\n");
        printf("1. Validar fecha\n");
        printf("2. Desplegar serie de letras\n");
        printf("3. Desplegar serie de numero\n");
        printf("4. Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                printf("\nVALIDAR FECHA\n");

                do {
                    printf("Ingrese el anio (1900 - 2015): ");
                    scanf("%d", &anio);
                } while(anio < 1900 || anio > 2015);

                do {
                    printf("Ingrese el mes (1 - 12): ");
                    scanf("%d", &mes);
                } while(mes < 1 || mes > 12);

                if(mes == 2) {
                    valida = 29;
                }
                else if(mes == 4 || mes == 6 ||
                        mes == 9 || mes == 11) {
                    valida = 30;
                }
                else {
                    valida = 31;
                }

                do {
                    printf("Ingrese el dia (1 - %d): ", valida);
                    scanf("%d", &dia);
                } while(dia < 1 || dia > valida);

                printf("\nFecha ingresada: %d de %s de %d\n",
                       dia, meses[mes - 1], anio);

                break;


            case 4:

                exit(0);



            default:
                printf("\nOpcion no valida\n");
                break;
        }

        if(op != 4) {
            printf("\nPresione ENTER para regresar al menu...");
            getchar();
            getchar();
            system("cls");
        }

    } while(op != 4);

    return 0;
}
