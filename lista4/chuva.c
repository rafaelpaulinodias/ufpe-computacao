#include <stdio.h>

void ReadMat(int m[100][100], int n) {
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
            scanf("%d", &m[i][j]);
}

void SumMat(int m1[][100], int m2[][100], int n) {
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
            m1[i][j] += + m2[i][j]; 
}

void PrintMat(int m[][100], int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    int m1[100][100], m2[100][100];
    scanf("%d", &n);
    ReadMat(m1, n);
    ReadMat(m2, n);
    SumMat(m1, m2, n);
    PrintMat(m1, n);
    return 0;
}