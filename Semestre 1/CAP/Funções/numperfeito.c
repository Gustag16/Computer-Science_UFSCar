/* 
Um núemro perfeito é o número natural igual à soma de seus divisores, exceto ele mesmo.
Exemplo: 28 é perfeito, pois
28 = 1 + 2 + 4 + 7 + 14
Escreva uma função que volta V ou F se for ou não perfeito
*/

// Descrição: Verificação se um número é perfeito
// Requer: Um número natural
// Assegura: Apresentação de V ou F se o número é ou não perfeito

#include <stdio.h>
#include <stdbool.h>

bool perfeito(int);

int main() {
    char entrada[160];

    fgets(entrada, sizeof entrada, stdin);
    int numero;
    sscanf(entrada, "%d", &numero);
    
    printf("%d = %s\n", numero, perfeito(numero) ? "V" : "F");

    return 0;
}

bool perfeito(int n) {
    int soma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }

    if (soma == n) {
        return true;
    }
    else {
        return false;
    }
}