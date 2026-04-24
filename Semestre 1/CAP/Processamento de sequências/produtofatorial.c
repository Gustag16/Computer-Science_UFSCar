/*
Descrição: Cálculo por multiplicações sucessivas do valor do produto dos números de 1 até n
Requer: o valor de n
Assegura: apresentação do produto dos números de 1 até n
*/

#include <stdio.h>

int main() {
    char entrada[160];

    printf("Insira o valor de n: ");
    fgets(entrada, sizeof entrada, stdin);
    int n;
    sscanf(entrada, "%d", &n);

    long int produto = 1;
    for (int i = 1; i <= n; i++) {
        produto = produto*i; // ou produto *= i
    }

    printf("A produto é %ld\n", produto);

    return 0;
}