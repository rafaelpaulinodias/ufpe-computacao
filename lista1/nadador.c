/*
Categorias de nadadores

Escreva um programa que, dada a idade de um nadador, classifique-o em uma das seguintes categorias:

Infantil A: [5; 7]
Infantil B: [8; 10]
Juvenil A: [11;13]
Juvenil B: [14;17]
Adulto: [18;40]
Master: A partir de 41 e sem limite superior
Caso a idade informada esteja fora dos limites, emita uma mensagem de erro: "Idade invalida."

entrada: A idade do nadador (int)

saída:  A categoria em que ele deve nadar de acordo com a tabela: do enunciado

 ------------------------------------------
| Exemplo de entrada  |   Exemplo de saída |
 ------------------------------------------
| 6	                  |     Infantil A     |
 ------------------------------------------
| 11	              |     Juvenil A      |
 ------------------------------------------

Autor(a): andre.tiba@ufpe.br
*/

#include <stdio.h>

int main()
{
    int idade;
    scanf("%i", &idade);
    if (idade > 5)
    {
        if (idade >= 5 && idade <= 7) printf("Infantil A");
        if (idade >= 8 && idade <= 10) printf("Infantil B");
        if (idade >= 11 && idade <= 13) printf("Juvenil A");
        if (idade >= 14 && idade <= 17) printf("Juvenil B");
        if (idade >= 18 && idade <= 40) printf("Adulto");
        if (idade >= 41) printf("Master");
    } 
    else printf("Idade invalida.");
}