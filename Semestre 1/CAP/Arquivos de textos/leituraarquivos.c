// Descrição: algoritmo que lê um arquivo texto
// Requer: o nome do arquivo
// Assegura: apresentação do conteúdo de um arquivo texto

#include <stdio.h>
#include <string.h>

int main() {

    printf("Qual o nome do arquivo? ");
    char nome_arquivo[160];
    fgets(nome_arquivo, sizeof nome_arquivo, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0'; // Substitui o último caracter (\n), pois o fgets lê o \n
    // OU: nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    FILE *arquivo = fopen(nome_arquivo, "r");   // r = leitura do arquivo

    if (arquivo == NULL) {
        perror(nome_arquivo);
        return 1;
    }

    // Acesso ao texto do arquivo
    char linha[200];
    int numero_linhas = 0;
    while (fgets(linha, sizeof linha, arquivo) != NULL) {   // Enquanto o programa não ler 'NULL'
        printf("%s", linha);
        numero_linhas++;
    }

    // Encerramento do acesso ao arquivo
    fclose(arquivo);

    printf("\n\nO arquivo possui %d linhas\n", numero_linhas);

    return 0;
}