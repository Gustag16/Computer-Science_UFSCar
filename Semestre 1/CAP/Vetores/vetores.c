/*  */

#include <stdio.h>

#define TAMANHO 10

int main() {
    int vetor[TAMANHO];

    // 5 na posição 1
    vetor[0] = 5;
    printf("%d\n", vetor[0]);

    // 1 na última posição
    vetor[TAMANHO - 1] = 1;
    printf("v[%d] = %d\n", TAMANHO - 1, vetor[TAMANHO - 1]);

    // maior entre o primeiro e o último na posição 2
    if (vetor[0] > vetor[TAMANHO - 1]) {
        vetor[2] = vetor[0];
    }
    else {
        vetor[2] = vetor[TAMANHO - 1];
    }

    // vetor[2] = vetor[0] > vetor[TAMANHO - 1] ? vetor[0] : vetor[TAMANHO - 1];

    printf("%d\n", vetor[2]);

    for (int i = 0; i < TAMANHO; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}