#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    int ra;
    float nota;
} Aluno;

void ler_aluno(Aluno *alu) {
    printf("Nome: ");
    scanf(" %[^\n]", alu->nome); // Lê até a nova linha
    printf("RA: ");
    scanf("%d", &alu->ra);
    printf("Nota: ");
    scanf("%f", &alu->nota);
}

int gravar_aluno(char *caminho, Aluno *alu) {
    FILE *f = fopen(caminho, "ab"); // Abre o arquivo para anexar
    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }
    fwrite(alu, sizeof(Aluno), 1, f); // Grava um aluno
    fclose(f);
    return 0;
}

void listar(char *caminho) {
    Aluno alu;
    FILE *f = fopen(caminho, "rb"); // Abre o arquivo para leitura
    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    printf("\nLista de Alunos:\n");
    while (fread(&alu, sizeof(Aluno), 1, f) == 1) {
        printf("Nome: %s, RA: %d, Nota: %.2f\n", alu.nome, alu.ra, alu.nota);
    }
    
    fclose(f);
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
