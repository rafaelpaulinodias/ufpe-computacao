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