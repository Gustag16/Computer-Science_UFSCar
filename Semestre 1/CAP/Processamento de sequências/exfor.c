// Descrição: Exemplos com 'for' em C

#include <stdio.h>

int main() {
    // para i <- 1 até 10
    for (int i = 1; i <= 10; i++) {  // i++ -> i = i + 1
        printf("%d ", i);
    }
    printf("\n");

    // para i <- a até b
    int a = -5;
    int b = 5;
    for (int i = a; i <= b; i++) {  // i <= b (enquanto i for menor ou igual a b)    // i++ -> i = i + 1
        printf("%d ", i);
    }
    printf("\n");

    // para i <- a até b passo -1 (decrescente)
    a = 5;
    b = -5;
    for (int i = a; i >= b; i--) {   // i >= b (enquanto i for maior ou igual a b)   // i-- -> i = i - 1
        printf("%d ", i);
    }
    printf("\n");

    // para i <- 1 até 11 passo 2
    for (int i = 1; i <= 12; i += 2) {    // i += 2 -> i = i + 2
        printf("%d ", i);   // Não haverá printf de i como 12, nem como 13, pois o 12 limita
    }
    printf("\n");

    /* a variável i deve ser declarada sempre (int i), pois ela só existe dentro da estrutura
        do for na qual ela foi declarada */

    return 0;
}