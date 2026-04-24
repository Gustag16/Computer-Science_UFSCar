/*  */

#include <stdio.h>

#define TAMANHO 10

int main() {
    int vetor[TAMANHO];

    // Atribuir nas posições do vetor os números de 1 a 10 crescente
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = i + 1;
    }
    for (int i = 0; i < TAMANHO; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("\n");
    
    // Atribuir nas posições do vetor os números de 10 a 1 decrescente
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = TAMANHO - i;
    }
    for (int i = 0; i < TAMANHO; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("\n");

    // Somar as posições ímpares do vetor
    int soma = 0;
    for (int i = 1; i < TAMANHO; i += 2) {
        soma += vetor[i];
    }
    printf("Soma das posições ímpares do vetor: %d\n", soma);

    printf("\n");

    // Trocar posições
    int i = 2;
    int j = 7;
    int temporario = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temporario;

    printf("Vetor: ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\n\n");

    // Saber a posição do menor valor e o valor em si
    int menor = vetor[0];
    int posicao;
    for (int i = 0; i < TAMANHO; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            posicao = i + 1;
        }
    }
    printf("Menor valor do vetor: %d\n", menor);
    printf("Posição do vetor: %d (vetor[%d])\n", posicao, posicao - 1);

    return 0;
}