/* Altere o procedimento de inserção para que um novo item seja inserido apenas se ele ainda não existir
    (i.e., o vetor não aceita repetições). Se o valor já existir, nada muda no vetor. */


#include <stdio.h>

#define MAXIMO 100
#define INEXISTENTE -1

void escreva_vetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int busca_valor(int vetor[], int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return INEXISTENTE;
}

// Acrescenta novos valores ao vetor se estes já não existem
void acrescente_valor(int vet[], int valor, int *tamanho) {
    if (*tamanho == MAXIMO) {
        printf("Limite excedido...\n");
    }
    else if (busca_valor(vet, valor, *tamanho) == INEXISTENTE ){
        (*tamanho)++;
        vet[*tamanho - 1] = valor;
    }
}

int main() {
    int vetor[MAXIMO];
    int quantidade = 0;

    for (int i = 0; i < 5; i++) {
        vetor[i] = 10;
        quantidade++;
    }
    escreva_vetor(vetor, quantidade);

    int valores[] = {18, 13, 21, 45, 10, 10, 21};
    for (int i = 0; i < sizeof valores / sizeof valores[0]; i++) {
        acrescente_valor(vetor, valores[i], &quantidade);
    }

    escreva_vetor(vetor, quantidade);

    return 0;
}