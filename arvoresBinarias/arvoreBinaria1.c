#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no * esq;
    struct no * dir;
} NO;

typedef struct {
    NO * raiz;
} ArvB;

void inserirEsq(NO * no, int val);
void inserirDir(NO *no, int val);

void inserirEsq(NO * no, int val) {
    if (no->esq == NULL) {
        NO *novo = (NO*)malloc(sizeof(NO));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    } else {
        if (val < no->esq->val)
            inserirEsq(no->esq, val);
        else if (val > no->esq->val)
            inserirDir(no->esq, val);
    }
}

void inserirDir(NO * no, int val) {
    if (no->dir == NULL) {
        NO *novo = (NO*)malloc(sizeof(NO));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    } else {
        if (val > no->dir->val)
            inserirDir(no->dir, val);
        else if (val < no->dir->val)
            inserirEsq(no->dir, val);
    }
}

void inserir(ArvB * arv, int val) {
    if(arv->raiz == NULL) {
        NO *novo = (NO*)malloc(sizeof(NO));
        novo->val = val;
        novo->esq = NULL;
        novo->dir = NULL;
        arv->raiz = novo;
    } else {
        if (val < arv->raiz->val)
            inserirEsq(arv->raiz, val);
        else if (val > arv->raiz->val)
            inserirDir(arv->raiz, val);
    }
}

void printArv(NO * raiz) {
    if(raiz != NULL) {
        printArv(raiz->esq);
        printf("%d ", raiz->val);
        printArv(raiz->dir);
    }
}

int main() {
    int op;
    int val;
    ArvB arv;
    arv.raiz = NULL;

    do {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n");
        scanf("%d", &op);

        switch(op) {
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &val);
                inserir(&arv, val);
                break;
            case 2:
                printf("\nArvore binaria:\n");
                printArv(arv.raiz);
                break;
            default: 
                printf("\nOpcao invalida...\n");
        }
    } while (op != 0);
    
}