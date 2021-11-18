#include <stdio.h>

int divisivel(int a, int b) {
    return a % b == 0;
}

int main()
{
    int a, b;
    scanf("%i %i", &a, &b);
    divisivel(a, b) ? printf("divisivel") : printf("nao divisivel");
    return 0;
}