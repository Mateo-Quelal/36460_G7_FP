#include <stdio.h>

int main() {
    int n;
    printf("Ingrese n: ");
    scanf("%d", &n);
    int suma = 0;
    int i = 1;
    while (i < n) {
        if (n % i == 0) {
            suma = suma + i;
        }
        i = i + 1;
    }
    if (suma == n) {
        printf("Es perfecto\n");
    } else {
        printf("No es perfecto\n");
    }
    return 06;
}
