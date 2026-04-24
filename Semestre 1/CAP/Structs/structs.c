/* Escreva um programa para declarar um racional usando struct */

#include <stdio.h>

int main() {
    struct racional {
        int numerador;
        int denominador;
    };    

    struct racional q1, q2;

    // q1 = 1/2
    q1.numerador = 1;
    q1.denominador = 2;

    // q2 = 7/3
    q2.numerador = 7;
    q2.denominador = 3;

    printf("q1 = %d/%d e q2 = %d/%d\n", q1.numerador, q1.denominador, q2.numerador, q2.denominador);

    return 0;
}