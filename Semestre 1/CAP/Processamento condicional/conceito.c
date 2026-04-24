// Descrição: Conversão de um conceito (A, B, C, D ou E) para nota numérica
// Requer: Um conceito
// Assegura: Apresentação da nota equivalente

#include <stdio.h>

int main() {
    char entrada[160];

    printf("Insira o conceito: ");
    fgets(entrada, sizeof entrada, stdin);
    char conceito = entrada[0];
    sscanf(entrada, "%c", &conceito);
    double nota;

    if (conceito == 'A') {
        nota = 10.0;
    }
    else if (conceito == 'B') {
        nota = 8.0;
    }
    else if (conceito == 'C') {
        nota = 6.0;
    }
    else if (conceito == 'D') {
        nota = 3.0;
    }
    else if (conceito == 'E') {
        nota = 0.0;
    }

    printf("Nota equivalente a %c é %g\n", conceito, nota);

    return 0;
}