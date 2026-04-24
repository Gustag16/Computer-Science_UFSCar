/* Criar um vetor com valores aleatórios */

// Descrição: Criação de um vetor com valores aleatórios
// Requer:
// Assegura: Apresentação de um vetor com valores aleatórios

#include <stdio.h> 
#include <stdlib.h>
#define TAMANHO 10

int main() {
    int vetor[TAMANHO];


    // Coloca valores aleatórios no vetor
    srand(10);
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 100;
    }
    printf("Vetor 'aleatório' = ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");


    return 0;
}

