/*
Edite o programa abaixo para gravar os 3 valores em arquivo. Em seguida, leia o arquivo e imprima os valores lidos:

Dica: chame o arquivo de exemplo_01.dat*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_conteudo() {
    int a;
    double b;
    char c[11];
    FILE * arq = fopen("exemplo_01.dat", "rb");
    fread(&a, sizeof(int), 1, arq);
    fread(&b, sizeof(double), 1, arq);
    fread(c, sizeof(char), 11, arq);
    printf("%d, %lf\n", a, b);
    fclose(arq);
}

int main() {
    int x = 10;
    double y = 3.14;
    char z[11] = "lelis";
    FILE * arq = fopen("exemplo_01.dat", "wb");
    fwrite(&x, sizeof(int), 1, arq);
    fwrite(&y, sizeof(double), 1, arq);
    fwrite(z, sizeof(char), 11, arq);
    fclose(arq);

    ler_conteudo();
}