#include <stdio.h>
#include <string.h>

typedef struct t_aluno
    {
        char nome[20];
        double nota;
    } Aluno;
    
typedef struct t_turma
    {
        Aluno alunos[50];
        int qnt_alunos;
    } Turma; 

Turma turmas[2]; 

void Matricular(char nome[20], double nota, int n_turma) {
    int i_aluno = turmas[n_turma].qnt_alunos;
    strncpy(turmas[n_turma].alunos[i_aluno].nome, nome, 20);
    turmas[n_turma].alunos[i_aluno].nota = nota;
    turmas[n_turma].qnt_alunos += 1;
    if (turmas[n_turma].qnt_alunos > 50) turmas[n_turma].qnt_alunos = 0;
}

double Media(Turma turma) {
    double somatorio = 0;
    for (int i = 0 ; i < turma.qnt_alunos; i++) somatorio += turma.alunos[i].nota;
    return somatorio/turma.qnt_alunos; 
}

Aluno MaiorNota(Turma turma) {
    Aluno ganhador = turma.alunos[0];
    for (int i = 0 ; i < turma.qnt_alunos; i++)
        if (turma.alunos[i].nota > ganhador.nota)
            ganhador = turma.alunos[i];
    return ganhador;
}

void CriarTurmas(Turma turmas[2]) {
    int n_turma = 0, i = 1;
    char nome[20];
    double nota;

    while (n_turma <= 1) {
        scanf("%s", nome);
        if (strcmp("*", nome) == 0) n_turma++;
        else {
            scanf("%lf", &nota);
            Matricular(nome, nota, n_turma);
        }
        i++;
    }
        
}

void ImprimeResultado(Turma turmas[2]) {
    double media_turmaA = Media(turmas[0]);
    double media_turmaB = Media(turmas[1]);
    Aluno ganhadorA = MaiorNota(turmas[0]);
    Aluno ganhadorB = MaiorNota(turmas[1]);
    Aluno ganhador = ganhadorA.nota > ganhadorB.nota ? ganhadorA : ganhadorB;
    
    if ((media_turmaA >= 8) && (media_turmaB >= 8)) printf("Viagem para todos!\n");
    if ((media_turmaA >= 8) && (media_turmaB < 8)) printf("Viagem para turma A\n");
    if ((media_turmaA < 8) && (media_turmaB >= 8)) printf("Viagem para turma B\n");
    if ((media_turmaA < 8) && (media_turmaB < 8)) printf("Nenhuma das turmas viaja...\n");
    if (ganhador.nota > 8) 
        printf (
            "%s ganhou viagem e ingresso no parque!\nNota: %.2f",
            ganhador.nome, ganhador.nota
        );
    else printf("Ninguem ganhou viagem e ingresso no parque...");
}

int main() {
    CriarTurmas(turmas);
    ImprimeResultado(turmas);
    return 0;
}
