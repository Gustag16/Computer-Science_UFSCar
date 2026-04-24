// Descrição: algoritmo que cria um arquivo texto
// Requer: três textos
// Assegura: criação de um arquivo texto com as entradas escritas

#include <stdio.h>

int main() {
    // Criação do arquivo
    FILE *arquivo = fopen("tres-textos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo");
        return 1;
    }

    // Uso do arquivo
    char entrada[160];
    char texto[160];
    for(int i = 1; i <= 3; i++) {
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%s", texto);
        fprintf(arquivo, "%s\n", texto);
    }

    // Encerramento do acesso ao arquivo
    fclose(arquivo);

    return 0;
}