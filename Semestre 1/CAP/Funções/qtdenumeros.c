/* Escreva uma função para retornar o número de dígitos de um número natural. Ex.: 125 --> 3 ; 23526 --> 5 */

// Descrição: Algoritmo que usa uma função que retorna o número de dígitos de um número natural.
// Requer: Um número natural
// Assegura: Número de dígitos de um número natural

#include <stdio.h>
#include <string.h>

int qtde_numeros(char n) {
    strlen(n);
    return strlen(n) - 1;
}

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    
    printf("%d possui %d dígitos", numero, qtde_numeros(entrada));

    return 0;
}