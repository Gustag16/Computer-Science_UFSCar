// Descrição: Conversão de um conceito (A, B, C, D ou E) para nota numérica por switch
// Requer: Um conceito
// Assegura: Apresentação da nota equivalente

#include <stdio.h>

int main(){
    char entrada[160];

    printf("Insira o conceito: ");
    fgets(entrada, sizeof entrada, stdin);
    char conceito = entrada[0];
    sscanf(entrada, "%c", &conceito);

    double nota;
    switch (conceito) {
    case 'A':
        nota = 10;
        break;
    case 'B':
        nota = 8;
        break;
    case 'C':
        nota = 6;
        break;
    case 'D':
        nota = 3;
        break;
    default:
        nota = 0;
    }

    printf("Nota equivalente a %c é %g\n", conceito, nota);

    return 0;
}