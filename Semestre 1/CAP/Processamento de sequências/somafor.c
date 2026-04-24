// Descrição: Algoritmo para obter a soma de uma quantidade de valores
// Requer: A quantidade de valores e os valores
// Assegura: Apresentação da soma dos valores

#include <stdio.h>

int main() {
    char entrada[160];
    printf("Digite a quantidade de valores a serem somados: ");
    fgets(entrada, sizeof entrada, stdin);
    int quantidade;
    sscanf(entrada, "%d", &quantidade);

    // leitura e soma dos valores
    double soma = 0;
    for (int i = 1; i <= quantidade; i++) {
        fgets(entrada, sizeof entrada, stdin);
        double valor;
        sscanf(entrada, "%lf", &valor);

        soma += valor;  // soma += valor -> soma = soma + valor
    }

    printf("A soma é %g\n", soma);
    if (quantidade > 0) {
        printf("A média é %g\n", soma/quantidade);
    }

    return 0;
}