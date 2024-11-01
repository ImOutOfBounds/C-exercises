#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE * f;
    f = fopen("../files/arquivo2.txt", "w");
    if(f == NULL) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    char texto[20] = "Bom dia flor do dia";
    int i;

    for (i=0; i < strlen(texto); i++)
        fputc(texto[i], f);
    
    fclose(f);
    system("pause");
    return 0;
}