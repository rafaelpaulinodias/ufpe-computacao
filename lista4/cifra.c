#include <stdio.h>

void PrintMat(char m[100][100], int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
}

void CopyMat(char m1[100][100], char m2[100][100], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m1[i][j] = m2[i][j];
}

char Cifra(char c) {
    if ((c < 97) || (c >122)) return c;
    if (c > 120) return 97 + (c - 121);
    return c + 2;
}

void CifraMat(char m[100][100], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = Cifra(m[i][j]);
}

void TranspMat(char m[100][100], int n) {
    char mt[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mt[i][j] = m[j][i];
    CopyMat(m, mt, n);
}

void ReadMat(char m[100][100], int n) {
    for (int i=0; i < n; i++) {
        getchar();
        for (int j=0; j < n; j++) {
            scanf("%c", &m[i][j]);
        }
    }
}

int main() {
    int n;
    char m[100][100];
    scanf("%d", &n);
    ReadMat(m, n);
    TranspMat(m, n);
    CifraMat(m, n);
    PrintMat(m, n);
}
