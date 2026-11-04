#include <stdio.h>
#include <math.h>

int main() {
    double x, absX, resultado;
    printf("Ingrese un numero X: ");
    scanf("%lf", &x);
    if (x < 0) {
        absX = x * -1;
    } else {
        absX = x;
    }
    resultado = pow(absX, 3);
    printf("El valor absoluto al cubo es: %.2f\n", resultado);
    return 0;
}
