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

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
} 

int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; // constranteb entre 0 e 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val); 
}

void main() {

}