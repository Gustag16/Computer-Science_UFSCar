// Descrição: algoritmo que cria um arquivo texto
// Requer: três números inteiros
// Assegura: criação de um arquivo texto com as entradas escritas

#include <stdio.h>

int main() {
    // Criação do arquivo
    FILE *arquivo = fopen("tres-numeros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro na criação do arquivo\n");
        return 1;
    }

    // Uso do arquivo
    char entrada[160];
    int numero;
    for(int i = 1; i <= 3; i++) {
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%d", &numero);
        fprintf(arquivo, "%d\n", numero);
    }

    // Encerramento do acesso ao arquivo
    fclose(arquivo);

    return 0;
}