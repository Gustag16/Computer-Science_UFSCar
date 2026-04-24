// Descrição: Exemplos de código de recursividade
// Requer: Dois numeros naturais
// Assegura: Apresentação do mdc desses numeros, fatoriais, e a sequência de fibonacci

#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

long int fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fatorial(n-1);
    }
}

int mdc(int n1, int n2) {
    if (n2 == 0) {
        return n1;
    }
    else {
        return mdc(n2, n1 % n2);
    }
}

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    int num1, num2;
    sscanf(entrada, "%d%d", &num1, &num2);

    printf("O mdc é %d\n\n", mdc(num1, num2));

    for (int i; i < 10; i++) {
        printf("%d! = %ld\n", i, fatorial(i));
    }

    for (int i = 1; i < 10; i++) {
        printf("fib(%d) = %d\n", i, fibonacci(i));
    }

    return 0;
}