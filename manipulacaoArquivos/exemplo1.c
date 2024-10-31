#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    char letra;

    arq = fopen("exemplo.txt", "w");
    fprintf(arq, "Esta é uma linha de texto escrita no modo 'w'.\n");
    fclose(arq);

    arq = fopen("exemplo.txt", "a");
    fprintf(arq, "Esta linha foi acrescentada no modo 'a'.\n");
    fclose(arq);

    arq = fopen("exemplo.txt", "r");
    printf("Conteúdo do arquivo:\n");
    int resp = fscanf(arq, "%c", &letra);
    while (resp != EOF) {
        printf("%c", letra);
        resp = fscanf(arq, "%c", &letra);
    }
    fclose(arq);

    return 0;
}