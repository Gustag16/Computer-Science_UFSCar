// Descrição: Determinação se um valor da primeira posição de um vetor se repete
// Requer:
// Assegura: Apresentação SIM (se repete) ou NÃO (se não repete)

#include <stdio.h> 
#include <stdlib.h>
#define TAMANHO 10

int main() {
    int vetor[TAMANHO];


    // Coloca valores aleatórios no vetor
    srand(10);
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10;
    }
    printf("Vetor = ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Verifica se o primeiro valor se repete
    int primeiro = vetor[0];
    int contador = 0;
    for(int i = 1; i < TAMANHO; i++) {
        if (vetor[i] == primeiro) {
            contador++;
        }
    }

    if (contador > 0) {
        printf("SIM, se repete %d vezes\n", contador);
    }
    else {
        printf("NÃO se repete\n");
    }

    return 0;
}

