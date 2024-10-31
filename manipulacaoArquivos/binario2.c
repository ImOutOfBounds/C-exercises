%%writefile struct_em_arquivo.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    int ra;
    float nota;
} Aluno;


void ler_aluno(Aluno *alu) {
    // complete a leitura dos dados com scanf

}

int gravar_aluno(char *caminho, Aluno *alu) {
    // grave os dados do aluno em arquivo

}

void listar(char *caminho) {
    Aluno alu;
    // liste (imprima) os alunos contidos no arquivo

}


int main() {
    Aluno alu;
    char opcao;
    char caminho[] = "arq_alunos.dat";
    printf("Deseja inserir novos dados (S/N)? ");
    scanf(" %c", &opcao);
    while (opcao == 's' || opcao == 'S') {
        ler_aluno(&alu);
        gravar_aluno(caminho, &alu);
        printf("Deseja inserir novos dados (S/N)? ");
        scanf(" %c", &opcao);
    }
    listar(caminho);
    return 0;
}