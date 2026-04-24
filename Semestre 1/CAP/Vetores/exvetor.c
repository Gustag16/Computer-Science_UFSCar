// Descrição: Declaração de vetores com valores zero
// Requer:
// Assegura: Vetores com valores zero, sem lixo

#include <stdio.h> 
#include <stdlib.h>
// #define TAMANHO 10

int main() {
    double v[5] = {1.1, 2.2, 3.3};  // Apenas 3 elementos dos 5 declarados
    for (int i = 0; i < 5; i++) {
        printf("Em %d tem %g\n", i, v[i]);  // Nesse caso, os últimos dois valores são zeros e não lixo
    }

    printf("\n");

    double vzero[5] = {0};  // Apenas o primeiro elemento dos 5 declarado
    for (int i = 0; i < 5; i++) {
        printf("Em %d tem %g\n", i, vzero[i]);  // Nesse caso, todos os valores são zeros e não lixo
    }
    
    // Criação de um vetor de tamanho não declarado
    const double v_undeclared[] = {0.50, 0.25, 0.10, 0.05, 0.01};  // const para manter constante (exemplo)
    int n = sizeof v_undeclared / sizeof v_undeclared[0];

    return 0;
}