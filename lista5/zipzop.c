/* 
Criptografia do zipzop

Julia gosta de trocar mensagens com sua amiga Camila,
mas elas não querem que seus amigos vejam suas conversas. 
Para isso, elas criaram um código de criptografia, que se 
baseia em utilizar o tamanho da string para multiplicar o
número do caractere na tabela ASCII (Imagem) por seu tamanho, 
MAS SOMENTE LETRAS SÃO PERMITIDAS. Para isso se utiliza o
valor do caractere multiplicado por o tamanho da string,
quando a tabela encontrar o último caractere minúsculo
(z num 122) ele pula para primeira maiúscula(A num 65), e
ao chegar ao último das maiúsculas (Z num 90) ele deve pular
para a primeira minúscula (a 97). Ou seja, o caractere deve
ser incrementado num ciclo correspondente às letras da tabela
(maiúsculas e minúsculas) pelo tamanho da string. Entrada tem
entre 1 e 100 caracteres.

Exemplo de entrada	            Exemplo de saída

Eu quero um bolinho	            Km Omuhc mq pcXSJzc
Eu amo computacao eletronica	Hz Ljn PnjPzXLPLn THTXTnLbPL

*/

#include <stdio.h>

int isAlpha(char c) {
    if (c < 65) return 0;
    if (c > 122) return 0;
    if (c > 90 && c < 97) return 0;
    return 1;
}

char OrdToAscii(int n) { 
    if (n > 51) OrdToAscii(n - 52);
    else return n < 26 ? n + 65 : n + 71; 
}

char Crip(char c, int len) {
    
    return !isAlpha(c) ? c : OrdToAscii(c*len - 1);
}

void Zipzop(char word[100]) {
    int i=0;
    int len = strlen(word) - 1;
    
    while (word[i] != '\0') {
        printf("%c", Crip(word[i], len));
        i++;
    }
}

int main() {
    char word[100];
    fgets(word, 100, stdin);
    Zipzop(word);
    return 0;
}
