#include <stdio.h>

int main() {
    double altura, suma = 0, maxVal = 0, minVal = 0, media = 0;
    int cont = 0;
    printf("Ingrese altura (negativo para terminar): ");
    scanf("%lf", &altura);
    while (altura >= 0) {
        if (cont == 0) {
            maxVal = altura;
            minVal = altura;
        } else {
            if (altura > maxVal) {
                maxVal = altura;
            }
            if (altura < minVal) {
                minVal = altura;
            }
        }
        suma += altura;
        cont++;
        printf("Ingrese altura (negativo para terminar): ");
        scanf("%lf", &altura);
    }
    if (cont > 0) {
        media = suma / cont;
        printf("Media: %.2f, Maximo: %.2f, Minimo: %.2f\n", media, maxVal, minVal);
    } else {
        printf("No hay alturas\n");
    }
    return 0;
}
