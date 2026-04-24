/* Manipulação de arquivos */

#include <stdio.h>

int main() {
    FILE *arquivo = fopen("dados-binarios", "w");

    if (arquivo == NULL) {
        perror("Arquivo dados-binarios");
        return 1;
    }

    int i = 10;
    // de onde vou pegar os dados, quantos dados (bytes), quantas vezses escrever, onde escrever
    fwrite(&i, sizeof i, 1, arquivo);
    i = -1;
    fwrite(&i, sizeof i, 1, arquivo);

    double d = 1342.527;
    fwrite(&d, sizeof d, 1, arquivo);

    fclose(arquivo);

    arquivo = fopen("dados-binarios", "r");

    if (arquivo == NULL) {
        perror("Arquivo leitura dados-binarios");
        return 1;
    }

    int j;
    fread(&j, sizeof j, 1, arquivo);
    printf("primeiro i lido = %d\n", j);
    fread(&j, sizeof j, 1, arquivo);
    printf("segundo i lido = %d\n", j); 
    fread(&d, sizeof d, 1, arquivo);
    printf("double lido = %.3lf\n", d);

    fclose(arquivo);

    return 0;
}