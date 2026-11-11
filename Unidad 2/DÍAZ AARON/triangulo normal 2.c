#include <stdio.h>

int main()
{
    int a=0, b=0, c=0;

    do
    {
        printf("filas del triangulo: ");
        scanf("%d", &c);
    }
    while (c <= 0);

    for (a = 1; a <= c; a++)
    {
        for (b = 1; b <= a; b++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
