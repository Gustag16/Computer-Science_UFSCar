/* Escreva uma função que retorne V ou F (0, 1 ou true, false) caso um valor natural seja divisível por 3 e 5 
ao mesmo tempo */

// Descrição: Verificação se um número natural é divisível por 3 e 5 ao mesmo tempo
// Requer: Um valor natural
// Assegura: Apresentação de verdadeiro se sim ou falso se não

#include <stdio.h>
#include <stdbool.h>

/*
Verificação se o número é divisível por 3 e 5 ao mesmo tempo
@param n: número natural
@return booleano
*/
bool div_3_5(int n) {
    return n % 3 == 0 && n % 5 == 0;
}

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    int numero;
    sscanf(entrada, "%d", &numero);

    printf("%x\n", div_3_5(numero));
    printf("%s\n", div_3_5(numero) ? "Verdadeiro" : "Falso");

    return 0;
}