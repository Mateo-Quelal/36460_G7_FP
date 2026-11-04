#include <stdio.h>

int main() {
    int x, y;
    printf("Ingrese X e Y: ");
    scanf("%d %d", &x, &y);
    if (y == 0) {
        printf("No es divisible por 0\n");
    } else {
        if (x % y == 0) {
            printf("%d Si es divisible por %d\n", x, y);
        } else {
            printf("%d No es divisible por %d\n", x, y);
        }
    }
    return 0;
}
