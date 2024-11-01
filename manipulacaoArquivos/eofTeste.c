#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    f = fopen("../files/arquivo.txt", "r");

    if (f == NULL) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    char c = fgetc(f);
    while(!feof(f)) {
        printf("%c", c);
        c = fgetc(f); // fgetc() le um caractere do arquivo e pula para o proximo
    }

    printf("\nFIM\n");
    fclose(f);

    system("pause");
    return 0;
}