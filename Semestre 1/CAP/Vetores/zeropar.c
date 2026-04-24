/* Passar um vetor para uma função e, dentro dessa função, pegar todos os valores pares e substituir por zero */

#include <stdio.h> 
#include <stdlib.h>
#define TAMANHO 10

void substitui_par(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            vetor[i] = 0;
        }
    }
}

void imprima_vetor(const int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[TAMANHO];


    // Coloca valores aleatórios no vetor
    srand(10);
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor antes = ");
    imprima_vetor(vetor, TAMANHO);

    substitui_par(vetor, TAMANHO);

    printf("Vetor depois = ");
    imprima_vetor(vetor, TAMANHO);

    return 0;
}
