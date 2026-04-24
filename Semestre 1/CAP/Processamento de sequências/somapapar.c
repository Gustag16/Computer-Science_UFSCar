/*
Descrição: cálculo da soma dos números naturais pares menores ou iguais a
Requer: o valor de n
Assegura: a soma dos números naturais menores que n
*/

#include <stdio.h>

int main() {
    char entrada[160];

    printf("Insira o valor de n: ");
    fgets(entrada, sizeof entrada, stdin);
    int n;
    sscanf(entrada, "%d", &n);

    int soma = 0;
    for (int i = 2; i <= n; i = i + 2) {
        soma = soma + i; 
    }

    printf("A soma é %d\n", soma);

    return 0;
}