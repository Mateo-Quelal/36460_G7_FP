#include <stdio.h>

int main() {
    int n, i = 0;
    printf("Ingrese N: ");
    scanf("%d", &n);
    while (i * i <= n) {
        i = i + 1;
    }
    int r = i - 1;
    printf("La raiz cuadrada entera es: %d\n", r);
    return 0;
}
