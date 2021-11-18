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