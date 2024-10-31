#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    int ra;
    int n1, n2, n3;
} aluno;

typedef struct {
    int TABLE_SIZE;    
    int qtd;
    struct aluno ** itens;
} Hash;

Hash* criaHash(int TABLE_SIZE) {
    Hash * ha = (Hash*)malloc(sizeof(Hash));
    if (ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno *));
        if(ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (i=0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void main() {
    
}