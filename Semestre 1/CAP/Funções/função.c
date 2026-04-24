#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Protótipo(s) (declaração da função)
double dobro(double);

double metade(double);

double raizquarta(double);

bool eh_vogal(char);

bool eh_impar(int);

int main() {
    double valor = 5.2;
    double resultado = dobro(valor);
    printf("2 * %g = %g\n", valor, resultado);
    printf("metade de %g = %g\n", valor, metade(valor));
    printf("raiz quarta de %g = %g\n", valor, raizquarta(valor));

    for (char c = 'A'; c <= 'Z'; c++) {
        if (eh_vogal(c)) {
            printf("%c é vogal\n", c);
        }
        else {
            printf("%c não é vogal\n", c);
        }
    }

    for (int i = 1; i <= 10; i++) {
        if (eh_impar(i)) {
            printf("%d é ímpar", i);
        }
        else {
            printf("%d não é ímpar", i);
        }
    }

    return 0;
}

// Implementação(ões)
double dobro(double x) {
    return 2 * x;
}

double metade(double x) {
    return x / 2;
}

double raizquarta(double x) {
    return sqrt(sqrt(x));
}

bool eh_vogal(char c) {
    if (c == 'A' || c == 'e' || c == 'I' || c == 'O' || c == 'U' ||
        c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    else {
        return false;
    }
}

bool eh_impar(int n) {
    if (n % 2 != 0) {
        return true;
    }
    else {
        return false;
    }
}