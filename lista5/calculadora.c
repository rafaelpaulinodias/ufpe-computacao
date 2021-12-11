/*
Calculadora Rustica

Faça um programa que receba dois números(float) e, depois, uma
palavra. A palavra indicará a operação matemática a ser realizada
(soma, multiplicacao, divisao ou subtracao) sobre os dois números
inseridos anteriormente. Seu programa deve mostrar o resultado da
operação.

Exemplo de entrada	Exemplo de saída

3.1
99.5
multiplicacao	    resultado = 308.45

80.8
20.4
divisao	            resultado = 3.96

*/

#include <stdio.h>
#include <string.h>

float calc(float a, float b, char op[13]) {
    if (strcmp(op, "soma") == 0) return a + b;
    if (strcmp(op, "subtracao") == 0) return a - b;
    if (strcmp(op, "multiplicacao") == 0) return a * b;
    if (strcmp(op, "divisao") == 0) return a / b;
    return 0.0;
}


int main()
{
    float a, b;
    char operation[13];
    
    scanf("%f %f %s", &a, &b, operation);
    printf("resultado = %.2f", calc(a, b, operation));
    
    return 0;
}
