/*
 Viciada em 'a'

 Joyce é uma pessoa muito organizada e perfeccionista e ama
 assistir o roda a roda Jequiti. De tanto assistir, ela percebeu
 que, em quase todas as rodadas, a probabilidade de sair a letra
 ‘a’ era muito grande, então, contava quantos ‘a’ apareciam, e
 notou, também, que era bastante raro ter alguma palavra em que o
 ‘a’ fosse acompanhado por um ‘i’, e ficava ainda mais animada
 quando isso acontecia.

 Seu irmão Júnior, por ser estudante de computação, teve a
 brilhante ideia de criar um programa para contabilizar a
 quantidade de letras ‘a’ e ‘a’ acompanhado de ‘i’, independente
 da ordem (‘ia’ ou ‘ai’), para cada palavra ou frase. Cada 'a'
 soma 1 ao total, mas se este 'a' está acompanhado de um 'i' soma
 2, pois traz para Joyce o dobro de felicidade.

Exemplo de entrada	Exemplo de saída

complacencia	    3
aparencia	        4
*/

#include <stdio.h>

int CountA(char word[20]) {
    int count=0, i=0;
    while (word[i] != '\0') {
        count += word[i] == 'a' ? 1 : 0;
        i++;
    }
    return count;
}

int isAI(char word[20], int i) {
    return (word[i] == 'i') && (word[i+1] == 'a');
}

int isIA(char word[20], int i) {
    return (word[i] == 'i') && (i>0) && (word[i-1] == 'a');
}

int CountIA(char word[20]) {
    int count=0, i=0;
    
    while (word[i] != '\0') {
        count += isIA(word, i) || isAI(word, i) ? 1 : 0; 
        i++;
    }
    return count;
}

int main()
{
    char word[20];
    scanf("%s", word);
    printf("%d", CountA(word) + CountIA(word));
    return 0;
}
