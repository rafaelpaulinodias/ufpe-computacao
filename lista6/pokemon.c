#include <stdio.h>
#include <string.h>

typedef struct t_pokemon
{
    char nome[25];
    int id;
    int ataque;
    int vida;
} Pokemon;

typedef struct t_treinador
{
    char nome[5];
    Pokemon pokemons[6];
} Treinador;

typedef struct t_resultado
{
    char pokemon_red[25];
    char pokemon_blue[25];
    char vencedor[5];
} Resultado;


Treinador red, blue;

void ApresentarTreinadores() {
    strncpy(red.nome, "Red", 5);
    strncpy(blue.nome, "Blue", 5);
    for (int i = 0; i < 6; i++) {
        scanf("%s", red.pokemons[i].nome);
        scanf("%d", &red.pokemons[i].id);
        scanf("%d", &red.pokemons[i].ataque);
        scanf("%d", &red.pokemons[i].vida);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%s", blue.pokemons[i].nome);
        scanf("%d", &blue.pokemons[i].id);
        scanf("%d", &blue.pokemons[i].ataque);
        scanf("%d", &blue.pokemons[i].vida);
    }
}

Pokemon EuEscolhoVoce(Treinador treinador) {
    int mais_forte = 0;
    for (int i = 1; i < 6; i++) {
        if (treinador.pokemons[mais_forte].ataque == treinador.pokemons[i].ataque) {
            if (treinador.pokemons[i].id < treinador.pokemons[mais_forte].id)
                mais_forte = i;
        }
        else if (treinador.pokemons[mais_forte].ataque < treinador.pokemons[i].ataque) {
            mais_forte = i;
        }      
    }
    return treinador.pokemons[mais_forte];
}

Resultado Lutem(Pokemon pokemon_red, Pokemon pokemon_blue) {
    Resultado resultado;
    strncpy(resultado.pokemon_red, pokemon_red.nome, 25);
    strncpy(resultado.pokemon_blue, pokemon_blue.nome, 25);

    int fim_da_luta = 0;
    while (!fim_da_luta) {
        pokemon_red.vida -= pokemon_blue.ataque;
        pokemon_blue.vida -= pokemon_red.ataque;
        if ((pokemon_blue.vida) <= 0 || (pokemon_red.vida <= 0)) fim_da_luta = 1;
    }

    if ((pokemon_red.vida > 0) && (pokemon_blue.vida <= 0)) strncpy(resultado.vencedor, "Red", 5);
    if ((pokemon_red.vida <= 0) && (pokemon_blue.vida > 0)) strncpy(resultado.vencedor, "Blue", 5);
    if ((pokemon_red.vida <= 0) && (pokemon_blue.vida <= 0)) strncpy(resultado.vencedor, "Emp", 5);

    return resultado;
}

void AnuciarVencedor(Resultado resultado) {
    if (strcmp(resultado.vencedor, "Emp"))
    printf(
        "Pokemon do Red: %s\nPokemon do Blue: %s\nVencedor: %s",
        resultado.pokemon_red,
        resultado.pokemon_blue,
        resultado.vencedor
    );
    else
    printf(
        "Pokemon do Red: %s\nPokemon do Blue: %s\nEmpate",
        resultado.pokemon_red,
        resultado.pokemon_blue,
        resultado.vencedor
    );
}

int main() {
    ApresentarTreinadores();
    Pokemon pokemon_red = EuEscolhoVoce(red);
    Pokemon pokemon_blue = EuEscolhoVoce(blue);
    Resultado resultado = Lutem(pokemon_red, pokemon_blue);
    AnuciarVencedor(resultado);
    return 0;
}
