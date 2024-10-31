/*
Complete o programa abaixo. Use as funções fprintf e fscanf para escrever e ler os dados dos alunos em um arquivo CSV chamado alunos.csv.

Todas as variáveis necessárias já foram criadas. Não crie outras variáveis!

Exemplos de como o arquivo deve ficar:

    10;Maria dos Santos;9.70
    20;José Silva;10.00
    30;Pedro Brasil;7.30

Dica: para ler strings com espaços em branco no scanf, utilize o especificador: %50[^\n]

De maneira similar, ao ler o csv com fscanf, utilize o especificador: %50[^;]
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    int ra;
    float nota;
} Aluno;

void ler_aluno(Aluno *alu) {
    printf(" Nome do Aluno: ");
    scanf(" %50[^\n]", &alu->nome);
    printf(" R.A. do Aluno: ");
    scanf(" %d", &alu->ra);
    printf(" Nota do Aluno: ");
    scanf("%f", &alu->nota);
}

int main() {
    FILE *arq;
    Aluno alu;
    char opcao;
    arq = fopen("alunos.txt", "a+");

    printf("Deseja inserir um novo aluno (S/N)? ");
    scanf(" %c", &opcao);
    while (opcao == 's' || opcao == 'S') {
        ler_aluno(&alu);
        fprintf(arq, "%d;%s;%.2f\n", alu.ra, alu.nome, alu.nota);
        printf("Deseja inserir um novo aluno (S/N)? ");
        scanf(" %c", &opcao);
    }

    fseek(arq, 0, SEEK_SET);
    
    while (!feof(arq)) {
        fscanf(arq, "%d;%50[^;];%f\n", &alu.ra, alu.nome, &alu.nota);
    }
    
    fclose(arq);

    printf("\nListagem dos alunos: \n");
    // utilize o arquivo aberto e percorra-o para listar os alunos gravados

    fclose(arq);
}