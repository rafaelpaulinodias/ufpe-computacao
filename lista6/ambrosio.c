#include <stdio.h>
#include <string.h>

typedef struct t_item
{
    char nome[25];
    double preco;
} Item;

typedef struct t_lista
{
    int n;
    Item itens[100];
    double total;
} Lista;

Lista lista;

void RemoverUltimo() {
    lista.n--;
    lista.total -= lista.itens[lista.n].preco;
}

void Trocar(int p1, int p2){
    Item aux = lista.itens[p1];
    lista.itens[p1] = lista.itens[p2];
    lista.itens[p2] = aux;
}

void OrdenarPorPrecoCrescente() {
    int min, p1, p2;
    int n = lista.n;
    for (p1=0; p1<n; p1++) {
        min = p1;
        for (p2=p1+1; p2<=n-1; p2++)
            if (lista.itens[p2].preco < lista.itens[min].preco) min = p2;
        Trocar(p1, min);
    }
}

void OrdenarPorNome() {
    int min, p1, p2;
    int n = lista.n;
    for (p1=0; p1<n; p1++) {
        min = p1;
        for (p2=p1+1; p2<=n-1; p2++)
            if (strcmp(lista.itens[p2].nome, lista.itens[min].nome) < 0) min = p2;
        Trocar(p1, min);
    }
}

void ColocarNaLista(char nome[25], double preco) {
    strncpy(lista.itens[lista.n].nome, nome, 25);
    lista.itens[lista.n].preco = preco;
    lista.total += preco;
    lista.n++;
    if (lista.n > 100) lista.n = 0;
}

void CriarLista(int n_itens){
    lista.n = 0;
    lista.total = 0;
    char nome[25];
    double preco;
    for (int i = 0; i < n_itens; i++) {
        scanf("%s %lf", nome, &preco);
        ColocarNaLista(nome, preco);
    }
}

void SelecionarItens(double valor_disponivel) {
    while (lista.total > valor_disponivel) RemoverUltimo();
}

void ImprimirLista(double valor_disponivel) {
    for (int i=0; i < lista.n; i++) {
        printf("%s %.2f\n", lista.itens[i].nome, lista.itens[i].preco);
    }
    printf("%.2f", valor_disponivel - lista.total);
}

int main() {
    int n = 0;
    double valor_disponivel;
    scanf("%lf", &valor_disponivel);
    scanf("%d", &n);
    CriarLista(n);
    OrdenarPorPrecoCrescente();
    SelecionarItens(valor_disponivel);
    OrdenarPorNome();
    ImprimirLista(valor_disponivel);
    return 0;
}
