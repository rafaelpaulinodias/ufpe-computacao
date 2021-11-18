#include <stdio.h>

#define pi 3.1416

double volumeEsfera(double r) {
    return (4*pi*(r*r*r)) / 3;
}

int main()
{
    double r1, r2, r3;
    scanf("%lf\n%lf\n%lf", &r1, &r2, &r3);
    printf("%.2lf\n%.2lf\n%.2lf", volumeEsfera(r1), volumeEsfera(r2), volumeEsfera(r3));
    return 0;
}