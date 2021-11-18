#include <stdio.h>

double euler(int n) {
    return n == 0 ? 1 : euler(n - 1) + 1.0 / fat(n);
}

long fat(int n) {
    return n == 0 ? 1 : n * fat(n - 1);
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%.15f", euler(n - 1));
    return 0;
}
