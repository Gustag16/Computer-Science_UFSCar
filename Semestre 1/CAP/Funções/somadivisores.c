/* Escreva uma função que retorne a soma dos divisores de um número natural */

// Descrição: Algoritmo que soma os divisores de um número natural
// Requer: Um número natural
// Assegura: Apresentação da soma dos divisores do número natural

#include <stdio.h>

int soma_divisores(int);

int main() {
    char entrada[160];

    fgets(entrada, sizeof entrada, stdin);
    int numero;
    sscanf(entrada, "%d", &numero);

    printf("Soma dos divisores de %d = %d\n", numero, soma_divisores(numero));

    return 0;
}

int soma_divisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}