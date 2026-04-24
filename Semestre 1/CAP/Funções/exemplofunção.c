/* 
Escreva uma função que aceite um valor real x e:
a) Retorne 2x
b) Zere o valor de x
*/

// Descrição: Algoritmo que retorna o dobro de um valor lido e o mesmo valor zerado
// Requer: Um valor real
// Assegura: Apresentação do dobro do valor lido e do valor zerado

#include <stdio.h>

double f(double);
int zera(double);

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    double x;
    sscanf(entrada, "%lf", &x);

    printf("x = %d e y = %g\n", zera(x), f(x));

    return 0;
}

double f(double x) {
    double f;
    f = 2 * x;
    return f;
}

int zera(double x) {
    x = 0;
    return x;
}