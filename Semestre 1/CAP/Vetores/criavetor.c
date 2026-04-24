/* Crie um vetor com 100 posições (máx). Preencha o vetor com 5 valores iguais a 10. */
/* Escreva um procedimento para acrescentar um novo valor ao vetor */
/* Escreva uma função que retorne o índice da primeira ocorrência de um dado valor no vetor ou -1 se não achar */

// Descrição: Programa que cria um vetor com 100 posições e apresenta 5 valores iguais a 10
// Requer:
// Assegura: apresentação do valor '10' 5 vezes

#include <stdio.h>

#define MAXIMO 100

void escreva_vetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void acrescente_valor(int vet[], int valor, int *tamanho) {
    if (*tamanho == MAXIMO) {
        printf("Limite excedido...\n");
    }
    else {
        (*tamanho)++;
        vet[*tamanho - 1] = valor;
    }
}

int busca_primeiro_indice(int vetor[], int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int main() {
    int vetor[MAXIMO];
    int quantidade = 0;

    for (int i = 0; i < 5; i++) {
        vetor[i] = 10;
        quantidade++;
    }
    escreva_vetor(vetor, quantidade);

    acrescente_valor(vetor, 42, &quantidade);
    escreva_vetor(vetor, quantidade);

    int novo_vetor[] = {12, 4, 56, 64, 3, 22, 4, 42, 54, 42, 26};
    int nova_quantidade = 11;

    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    int valor;
    sscanf(entrada, "%d", &valor);

    if (busca_primeiro_indice(novo_vetor, valor, nova_quantidade) == -1) {
        printf("Erro, %d não existe no vetor\n", valor);
    }
    else {
        printf("Índice do vetor no qual %d aparece: %d\n", valor,
            busca_primeiro_indice(novo_vetor, valor, nova_quantidade));
    }

    return 0;
}