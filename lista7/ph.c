/* 

Escala Franjinha de pH

Franjinha (turma da Mônica) é um cientista nato, mas isso não quer dizer que tudo são flores.
O pequeno inventor iniciou uma nova série de experimentos com soluções básicas, mas, isso não
era suficiente para prender sua atenção, de modo que ele resolveu criar uma nova escala de pH
para usar em suas experiências. Ele não é genial?

E é aí que você pode ajudá-lo, não é?

Construa um programa que recebe a concentração de cada base adicionada, calcule a concentração
de hidroxilas (OH) em solução e devolva o pH na escala Franjinha a cada adição de uma nova base.

Lembre-se que, quando estamos trabalhando com bases, a concentração de hidroxilas é o produto
de seu índice pela concentração da base em questão.

Sabendo que a fórmula para se calcular o pH na escala Franjinha é a seguinte:

pH = 9 - pOH
pOH = -log[OH-]
 

Ou seja, o pH é igual a 9 mais o log na base 10 da concentração de hidroxilas na solução,

Construa uma função de assinatura: 

void Calcula (double *concentracaoBase, double *concentracaoTotal, double *pOH, int indiceHidroxilas) 
para poder calcular a concentração de Hidroxilas e pOH da solução, manipulando os valores 
das variáveis, e não apenas sua cópia na função.

entradas: receberá um número decimal que indica a concentração molar da base na primeira
linha e na segunda linha uma sequência de Elemento, Índice, Hidroxila, Índice, para cada
base adicionada, simulando, por exemplo, a fórmula Be(OH)2, no modelo:

0.1
Be 1 OH 2.

o programa deve parar de receber quando a concentração dada for igual a 0.

saídas: deve imprimir para cada base o valor do pH na escala Franjinha após sua adição,
lembrando que não tiramos as bases anteriores antes de adicionar as seguintes, de modo que
a concentração de hidroxilas deve ser levada em conta a cada adição.

Autor(a) do problema: andre.tiba@ufpe.br

*/


#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct t_solucao
{
  double concentracao;
  char formula[10];
} Solucao;

Solucao solucoes[10];
int n_solucoes = 0;

void LerDados() {
  int i = 0;
  double concentracao;
  while (1) {
    scanf("%lf", &concentracao);
    getchar();
    if (concentracao == 0) {
        break;
    }
    solucoes[i].concentracao = concentracao;
    fgets(solucoes[i].formula, 10, stdin);
    n_solucoes++;
    i++;
  }
}

int CharToInt(char c) {
  return (c>48) && (c<58) ? c-48 : 0;
}

int getIndiceHidroxilas(char formula[10]) {
  int len = strlen(formula);
  if (formula[len-1] < 48) len -= 1;
  return CharToInt(formula[len-1]);
}

void Calcula (double *concentracaoBase, double *concentracaoTotal, double *pOH, int indiceHidroxilas) {
    *concentracaoTotal += *concentracaoBase * indiceHidroxilas;
    *pOH = -1 * log10(*concentracaoTotal);
}

double PohToPh(double pOH) {
  return 9 - pOH;
}

void PrintSolucoes(double *concentracaoBase, double *concentracaoTotal, double *pOH) {
  
  for (int i = 0 ; i < n_solucoes ; i++){
      int indiceHidroxilas = getIndiceHidroxilas(solucoes[i].formula);
      *concentracaoBase = solucoes[i].concentracao;
      Calcula(concentracaoBase, concentracaoTotal, pOH, indiceHidroxilas);
      printf("%.1f\n", PohToPh(*pOH));
  }
}

int main()
{
    double concentracaoTotal, concentracaoBase, pOH;
    LerDados();
    PrintSolucoes(&concentracaoBase, &concentracaoTotal, &pOH);
    return 0;
}
