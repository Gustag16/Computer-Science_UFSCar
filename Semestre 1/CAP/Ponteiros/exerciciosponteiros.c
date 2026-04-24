/* 
Escreva uma função com referência:
1) Tornar par:
    - Se for par, mantém igual
    - Se for ímpar, soma 1
2) Tornar média:
    Alterar dois valores reais para que ambos tenham a média dos dois
3) Trocar dois valores inteiros
4) Ordenar:
    Mudar duas variáveis para que o valor da primeira seja menor ou igual ao da segunda
*/

#include <stdio.h>

void torna_par(int *);

void torna_media(double *, double *);

void troca_valores(int *, int *);

void ordene(int *, int *);

int main() {
    int numero = 5;
    printf("Antes: %d\n", numero);
    torna_par(&numero);
    printf("Tornando-se par: %d\n\n", numero);

    double v1 = 7.7;
    double v2 = 0.3;
    printf("Antes: v1 = %g e v2 = %g\n", v1, v2);
    torna_media(&v1, &v2);
    printf("v1 = %g e v2 = %g\n\n", v1, v2);

    int i = 7;
    int k = 3;
    printf("Valores de i e k antes: %d e %d\n", i, k);
    troca_valores(&i, &k);
    printf("Novo valor de i = %d\n", i);
    printf("Novo valor de k = %d\n\n", k);

    int x = 69;
    int y = 42;
    printf("x e y antes da ordenação: %d, %d\n", x, y);
    ordene(&x, &y);
    printf("x e y ordenado: %d, %d\n", x, y);

    return 0;
}

void torna_par(int *n) {
    if (*n % 2 != 0) {
        *n = *n + 1;
    }
}

void torna_media(double *n, double *m) {
    double media = (*n + *m) / 2;
    *n = media;
    *m = media;
}

void troca_valores(int *i, int *k) {
    int armazenamento = *i;
    *i = *k;
    *k = armazenamento;
}

void ordene(int *x, int *y) {
    if (*x > *y) {
        troca_valores(x, y);    // x e y já são os endereços, portanto não é necessária a notação &*x e &*y
    }
}