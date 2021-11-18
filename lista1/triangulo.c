#include <stdio.h>

int main()
{
    float l1, l2, l3;
    scanf("%f\n%f\n%f", &l1, &l2, &l3);
    int lados_iguais = (l1 == l2) && (l1 == l3) && (l2 == l3);
    int lados_diferentes = (l1 != l2) && (l1 != l3) && (l2 != l3);
    if (lados_iguais) printf("equilatero\n");
    if (lados_diferentes) printf("escaleno\n");
    if (!lados_iguais && !lados_diferentes) printf("isosceles\n");
}