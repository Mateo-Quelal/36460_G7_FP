#include <stdio.h>

int main() {
    long long c;
    printf("Ingrese la cantidad de segundos: ");
    scanf("%lld", &c);
    long long dias = c / 86400;
    c = c % 86400;
    long long horas = c / 3600;
    c = c % 3600;
    long long min = c / 60;
    long long seg = c % 60;
    printf("Dias: %lld, Horas: %lld, Minutos: %lld, Segundos: %lld\n", dias, horas, min, seg);
    return 0;
}
