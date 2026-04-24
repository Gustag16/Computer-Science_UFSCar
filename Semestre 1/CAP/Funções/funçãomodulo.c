/* Escreva uma função que, dado um valor real, retorne seu valor absoluto, sem usar fabs() */

// Descrição: Código que retorna o valor absoluto do input
// Requer: Um valor real
// Assegura: O valor absoluto do input

#include <stdio.h>

double modulo(double);

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    double numero;
    sscanf(entrada, "%lf", &numero);

    printf("Módulo de %g = %g\n", numero, modulo(numero));
    return 0;
}

double modulo(double n) {
    if (n >= 0) {
        return n;
    }
    else {
        return -n;
    }
}