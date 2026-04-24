// Descrição: Programa que soma todos os valores de um arquivo texto
// Requer: Um valor real por linha
// Assegura: Apresentação da soma dos valores

#include <stdio.h>
#include <string.h>

int main() {
    // Selecionar o arquivo
    printf("Qual o nome do arquivo? ");
    char nome_arquivo[160];
    fgets(nome_arquivo, sizeof nome_arquivo, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';  // Para substituir o \n por um \0

    // Abrir o arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r");

    // Encerrar o programa em caso de erro
    if (nome_arquivo == NULL) {
        perror(nome_arquivo);
        return 1;
    }

    // Leitura das linhas
    char linha [160];

    double soma = 0;
    double numero;
    while (fgets(linha, sizeof linha, arquivo) != NULL) {
        sscanf(linha, "%lf", &numero);  // Converte a entrada (linha) em double (numero)
        soma += numero;
    }

    fclose(arquivo);

    printf("A soma é %g\n", soma);

    return 0;
}