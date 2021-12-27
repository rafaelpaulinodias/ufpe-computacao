#include <stdio.h>
#include <math.h>

double Delta(double a, double b, double c) {
    return pow(b, 2) - 4*a*c;
}

void Baskara(double a, double b, double c, double *x1, double *x2) {
    double delta = Delta(a, b, c);
    *x1 = ((-1*b) + sqrt(delta)) / (2*a);
    *x2 = ((-1*b) - sqrt(delta)) / (2*a);
}

int Raizes(double a, double b, double c, double *x1, double *x2) {
    double delta = Delta(a, b, c);
    if (delta < 0) return 0;
    Baskara(a, b, c, x1, x2);
    if (delta == 0) return 1;
    return 2;
}

void PrintResults(double a, double b, double c, double *x1, double *x2) {
    int raizes = Raizes(a, b, c, x1, x2);
    if (raizes == 1) printf("%.2lf\n", *x1);
    if (raizes > 1) printf("%.2f %.2lf\n", *x1, *x2);
    printf("%d", raizes);
}

int main() {
    double a, b, c, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    PrintResults(a, b, c, &x1, &x2);
    return 0;
}
