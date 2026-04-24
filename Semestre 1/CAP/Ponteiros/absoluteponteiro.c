/* Escreva uma função para pegar uma variável e alterar seu valor para o valor absoluto */

#include <stdio.h>

void absoluto(double *);

int main(void) {

    double d = -7.95;
    absoluto(&d);
    printf("d = %g\n", d);

    return 0;
}

void absoluto(double *v) {
    if (*v < 0)
        *v = -*v;      // A função não retorna nada (void)
}
