#include <stdio.h>

void contagemRegressiva(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) 
            j < i ? printf("%i-", i) : printf("%i", i);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%i", &n);
    contagemRegressiva(n);
    return 0;
}