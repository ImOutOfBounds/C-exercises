#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1, *f2;
    f1 = fopen("minusculo.txt", "r");
    f2 = fopen("maiucsulo.txt", "w");
    if (f1==NULL || f2==NULL) {
        printf("Erro na leitura\n");
        system("pause");
        exit(1);
    }
}