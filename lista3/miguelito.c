#include <stdio.h>

int serieMiguelito(int n) {
    if (n == 1) return 3;
    return n % 2 == 0 ? serieMiguelito(n-1) + 4 : serieMiguelito(n-1) + 1;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i", serieMiguelito(n));
    return 0;
}