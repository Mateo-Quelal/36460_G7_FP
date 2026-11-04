#include <stdio.h>

int main() {
    double x;
    printf("Ingrese un numero: ");
    scanf("%lf", &x);
    if (x >= 0 && x <= 10) {
        printf("%.2f Pertenece al intervalo [0,10]\n", x);
    } else {
        printf("%.2f No pertenece al intervalo\n", x);
    }
    return 0;
}
