#include <stdio.h>

int mod(int n) {
    return n < 0 ? n * -1 : n;
}

void Swap(int v[], int p1, int p2){
    int aux = v[p1];
    v[p1] = v[p2];
    v[p2] = aux;
}

void PrintVet(int v[], int n) {
    int p1 = 0;
    printf("[");
    while (p1 < n - 1) {
        printf("%d ", v[p1]);
        p1++;
    }
    printf("%d]\n", v[n-1]);
}

void ReadVet(int v[], int *n) {
    int i = 0;
    int num = 0;
    while (1) {
        scanf("%d", &num);
        if (num >= 0) {
            v[i] = num;
        } else {
            *n = i;
            break;
        }
        i++;
    }
}

void CopyVet(int v1[], int v2[], int n) {
    for (int i = 0 ; i < n; i++) 
        v2[i] = v1[i];  
}

void SortVet(int v[], int n) {
    int aux, min, p1, p2;
    for (p1=0; p1<n; p1++) {
        min = p1;
        for (p2=p1+1; p2<=n-1; p2++)
            if (v[p2] < v[min]) min = p2;
        Swap(v, p1, min);
    }
}

isEqualDifMod(int n1, int n2, int x) {
    return mod(n1 - n2) == x;
}

void PrintCountDifMod(int v1[], int v2[], int n, int x) {
    int count = 0;
    for (int i=0; i<n ; i++) 
        count += isEqualDifMod(v1[i], v2[i], x) ? 1 : 0;
    printf("%d\n", count);
}

void PrintNumbersDifMod(int v1[], int v2[], int n, int x) {
    for (int i=0; i<n ; i++) {
        if (isEqualDifMod(v1[i], v2[i], x)) {
            printf("%d %d %d\n", v1[i], v2[i], i + 1);
        }
    }
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int numbers[n], ord_numbers[n];
    ReadVet(numbers, &n);
    CopyVet(numbers, ord_numbers, n);
    SortVet(ord_numbers, n);
    //PrintVet(ord_numbers, n);
    PrintCountDifMod(numbers, ord_numbers, n, x);
    PrintNumbersDifMod(numbers, ord_numbers, n, x);
    return 0;
}
