// Descrição: Definição do conceito a partir de uma nota de 0 a 10
// Requer: Uma nota de 0 a 10
// Assegura: Apresentação do conceito equivalente

#include <stdio.h>

int main() {
    printf("Insira a nota de 0 a 10: ");
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    double nota;
    sscanf(entrada, "%lf", &nota);

    char conceito;
    if (nota <= 10 && nota >= 9) {
        conceito = 'A';
    }
    else if (nota > 8.5) {
        conceito = 'B';
    }
    else if (nota > 4.5) {
        conceito = 'C';
    }
    else if (nota > 1) {
        conceito = 'D';
    }
    else if (nota >= 0) {
        conceito = 'E';
    }
    else {
        conceito = '?';
    }

    printf("Com a nota %g, seu conceito é %c\n", nota, conceito);

    return 0;
}