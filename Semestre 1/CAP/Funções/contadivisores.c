/* Escreva uma função para retornar a quantidade de divisores de um numero natural

Ex.:
    n   |   nº div
 -------+-----------
    5   |     2
    3   |     2
    6   |     4
    7   |     2
    28  |     6

*/

// Descrição: Algoritmo que calcula a quantidade de divisores de um número natural
// Requer: Um número natural
// Assegura: Quantidade de divisores do número natural dado

#include <stdio.h>

int divisores(int);

int main() {
    char entrada[160];
    
    fgets(entrada, sizeof entrada, stdin);
    int numero;
    sscanf(entrada, "%d", &numero);

    printf("%d tem %d divisor(es)\n", numero, divisores(numero));
    return 0;
}

int divisores(int n) {
    int contador = 0;
   for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            contador++;
        }
   }
   return contador;
}