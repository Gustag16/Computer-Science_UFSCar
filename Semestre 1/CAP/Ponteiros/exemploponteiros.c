/* 
Escreva APENAS uma função que aceite um valor real x e:
a) Retorne 2x
b) Zere o valor de x
*/

// Descrição: Algoritmo que retorna o dobro de um valor lido e o mesmo valor zerado por UMA FUNÇÃO
// Requer: Um valor real
// Assegura: Apresentação do dobro do valor lido e do valor zerado

#include <stdio.h>

double f(double *);

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    double x;
    sscanf(entrada, "%lf", &x);

    printf("x = %g e y = %g\n", x, f(&x));  // (&x) joga o endereço de x para a ler e *a lê o que está no endereço

    return 0;
}

double f(double *a) {   // *a aponta para o valor de x, e não para o endereço
    double f;
    f = 2 * *a; // dobra o valor de x

    *a = 0; // aponta para o valor de x e muda pra zero

    return f;
}

/*
int i = 10;
int *pi = &i;
int *pi2;
pi2 = pi;
*pi = 7
*/