/*
Examine o paciente

Escreva um programa que solicite ao usuário:

Sua temperatura
Se está tendo secreção, tosse e dor no corpo (“S” ou “N”)
Após a solicitação dos dados:

Caso a temperatura seja maior ou igual a 37 graus e as demais respostas sejam iguais a “S”,
uma mensagem “Exames Especiais” deve ser exibida.
Caso a temperatura seja maior ou igual a 37 graus e as demais respostas sejam iguais a “N”,
uma mensagem “Exames Basicos” deve ser exibida.
Caso a temperatura seja menor do que 37 graus e não houver secreção, tosse e dor no corpo,
a mensagem será “Liberado”.
Caso a temperatura seja menor do que 37 graus, mas houver dor no corpo, tosse e secreção,
a mensagem deve ser igual a “Exames Básicos”.
Se, ao perguntar se o usuário está com secreção, tosse e dor no corpo, ele responder algo
diferente de "S" ou "N", exiba uma mensagem de erro.

entrada: 

A temperatura do paciente (entre 35 e 41 graus). 
Se está tendo secreção, tosse e dor no corpo ("S" ou "N")

saída:

"Exames Especiais", caso a temperatura seja maior ou igual a 37 graus e ele esteja com
secreção, tosse e dor.

"Exames Basicos", caso a temperatura seja maior ou igual a 37 graus e ele esteja sem
secreção, tosse e dor.

"Exames Basicos", caso a temperatura seja menor  que 37 graus e ele esteja com secreção,
tosse e dor.

"Liberado", caso a temperatura seja menor que 37 graus e ele não esteja com secreção,
tosse e dor.

Se, ao perguntar se o usuário está com secreção, tosse e dor no corpo, ele responder
algo diferente de "S" ou "N", exiba a mensagem "Erro".

Exemplo de entrada | Exemplo de saída
-------------------------------------
37                   Exames Especiais
S
-------------------------------------	                
36.02                Liberado
N	                

Autor(a): andre.tiba@ufpe.br
*/

#include <stdio.h>

int main()
{
    float temperatura;
    char tem_secrecao;
    scanf("%f", &temperatura);
    getchar();
    tem_secrecao = getchar();
    if (tem_secrecao == 'S' || tem_secrecao == 'N') {
        if ((temperatura >= 37.0) && tem_secrecao == 'S') printf("Exames Especiais");
        if ((temperatura >= 37.0) && tem_secrecao == 'N') printf("Exames Basicos");
        if ((temperatura < 37.0) && tem_secrecao == 'N') printf("Liberado");
        if ((temperatura < 37.0) && tem_secrecao == 'S') printf("Exames Basicos");
    } else {
        printf("Erro");
    }
}