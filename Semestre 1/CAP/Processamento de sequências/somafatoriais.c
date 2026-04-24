/*
Descrição: cálculo da soma sucessivas de fatoriais de 1! até n!
Requer: valor de n
Assegura: a soma de 1! até n!
*/

#include <stdio.h>

int main() {
    char entrada[160];

    printf("Insira o valor de n: ");
    fgets(entrada, sizeof entrada, stdin);
    int n;
    sscanf(entrada, "%d", &n);
    
    long int soma = 0;
    long int produto = 1;
    for (int i = 1; i <= n; i++) {
        produto *= i; // ou produto = produto*i
        soma += produto;
    }

    printf("A soma é %ld\n", soma);

    return 0;
}