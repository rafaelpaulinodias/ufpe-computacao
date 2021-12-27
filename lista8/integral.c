/*
integrais de Riemann

Seja uma função da forma F(x) = A*x^2 + B*x + C + D*exp(E*x), deseja-se calcular
a integral abaixo da curva no intervalo [a,b].

Uma maneira simples de realizar tal procedimento é uma soma de retângulos de
lados H e F(x_i), onde x_0 = a, x_n = b e:

 x_i = x_0 + i*H, para i = 0, ..., n-1 chama-se de integral à esquerda
 x_i = x_0 + i*H, para i = 1, ..., n  chama-se de integral à direita
 x_i = x_0 + i*H + H/2, para i = 0, ...,n-1  chama-se de integral ao centro

H é o tamanho do passo e n é o número de retângulos. Em geral para um limite de
integração [a,b] e uma quantididade de retângulos n, tem-se que H = (b-a)/n.

Crie um programa em C que calcule: (i) a área das três formas; (ii) os erros
relativos percentuais à esquerda e à direita com respeito a área central (onde
admite-se ser o valor mais próximo da área exata).

ENTRADAS:

o número M de funções a serem calculadas
para a primeira função: os coeficientes A, B, C, D, E, o número de intervalos
"n" e o intervalo de integração [a,b] para a m-ésima função: os coeficientes
A, B, C, D, E, o número de intervalos "n" e o intervalo de integração [a,b]

SAÍDAS:

Para cada função será impresso uma linha contendo: a integral à esquerda, a integral
à direita, a integral central, o MAIOR erro relativo percentual com respeito a integral
central. O  erro relativo percentual com respeito a Y, entre duas variáveis X e Y,
é calculado na forma erro = 100|X - Y|/|Y|. Deve-se seguir o formato 
printf(
"%f  %f  %f  %f%%  %s\n",area a esquerda, area a direita, area central, maior erro, "erro a YYYY"
);
onde "YYYY" representa "esquerda" ou "direita", a depender do resultado.

Observações:

Poderá ser usado qualquer conhecimento adquirido na disciplina.
Todas as variáveis reais devem ser declaradas como double
Qualquer indício de plágio acarretará na anulação da questão.
Faça sua questão do seu jeito, sem qualquer tipo de consulta.

*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_FUNC 20

typedef struct t_funcao
{
    double A, B, C, D, E, a, b;
    int n;
} Funcao;

typedef struct t_resultado
{
    double area_esquerda, area_direita, area_central, erro;
    int lado_erro; 
} Resultado;


Funcao f[MAX_FUNC];
Resultado resultados[MAX_FUNC];

double modulo(double x) {
    return x < 0 ? -1*x : x;
}

void LerFuncoes(int M) {
    for (int i = 0 ; i < M ; i++) 
        scanf(
            "%lf %lf %lf %lf %lf %d %lf %lf",
            &f[i].A,
            &f[i].B,
            &f[i].C,
            &f[i].D,
            &f[i].E,
            &f[i].n,
            &f[i].a,
            &f[i].b
        );
}

void ImprimirResultados(int M) {
    for (int i = 0 ; i < M ; i++) {
        printf(
            "%lf  %lf  %lf  %lf%%  ",
            resultados[i].area_esquerda,
            resultados[i].area_direita,
            resultados[i].area_central,
            resultados[i].erro
        );
        if (resultados[i].lado_erro) printf("erro a esquerda\n");
        else printf("erro a direita\n");
    }
}

double Fx(double A, double B, double C, double D, double E, double x) {
    return (A*pow(x,2)) + (B*x) + C + (D*exp(E*x));
}

double Erro(double x, double y) {
    return 100*(modulo(x-y)/modulo(y));
}

void CalcularResultados(int M) {
    double H, Fxi, x, erro_esq, erro_dir;
    for (int eq = 0 ; eq < M ; eq++) {
        H = (f[eq].b - f[eq].a)/f[eq].n;
        resultados[eq].area_esquerda = 0.0;
        resultados[eq].area_direita = 0.0;
        resultados[eq].area_central = 0.0;
        resultados[eq].erro = 0.0;
        for (int i = 0 ; i < f[eq].n ; i++) {
            Fxi = Fx(f[eq].A, f[eq].B, f[eq].C, f[eq].D, f[eq].E, f[eq].a + H*i);
            resultados[eq].area_esquerda += H*Fxi;
        }
        for (int i = 1 ; i < f[eq].n + 1; i++) {
            Fxi = Fx(f[eq].A, f[eq].B, f[eq].C, f[eq].D, f[eq].E, f[eq].a + H*i);
            resultados[eq].area_direita += H*Fxi;
        }
        for (int i = 0 ; i < f[eq].n  ; i++) {
            Fxi = Fx(f[eq].A, f[eq].B, f[eq].C, f[eq].D, f[eq].E, f[eq].a + H*i + (H/2));
            resultados[eq].area_central += (H*Fxi);
        }
        erro_esq = Erro(resultados[eq].area_esquerda, resultados[eq].area_central);
        erro_dir = Erro(resultados[eq].area_direita, resultados[eq].area_central);
        resultados[eq].erro = erro_esq > erro_dir ? erro_esq : erro_dir;
        resultados[eq].lado_erro = erro_esq > erro_dir;
    }
}

int main(){
    int M;
    scanf("%d", &M);
    LerFuncoes(M);
    CalcularResultados(M);
    ImprimirResultados(M);
    return 0;
}
