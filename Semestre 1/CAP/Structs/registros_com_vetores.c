/* Manipula registros com vetores internos */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXIMO 100

// definição do conjunto
struct conjunto {
    int elementos[MAXIMO];
    int quantidade;
};

bool conjunto_vazio(struct conjunto conjunto) {
    return conjunto.quantidade == 0;
}

void escreva_conjunto(char *nome, struct conjunto conjunto) {
    printf("%s = { ", nome);
    for (int i = 0; i < conjunto.quantidade; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}

bool pertence(struct conjunto conjunto, int elemento) {
    int i = 0;
    while (i < conjunto.quantidade && conjunto.elementos[i] != elemento) {
        i++;
    }
    return i < conjunto.quantidade;
}

void insira(struct conjunto *conjunto, int novo_elemento) {
    if (!pertence(*conjunto, novo_elemento)) {
        conjunto->elementos[conjunto->quantidade] = novo_elemento;
        conjunto->quantidade++;
    }
}

struct conjunto uniao(struct conjunto conj1, struct conjunto conj2) {
    struct conjunto resultado;
    resultado.quantidade = 0;

    for (int i = 0; i < conj1.quantidade; i++) {
        insira(&resultado, conj1.elementos[i]);
    }
    for (int i = 0; i < conj2.quantidade; i++) {
        insira(&resultado, conj2.elementos[i]);
    }
    return resultado;
}

struct conjunto intersecao(struct conjunto conj1, struct conjunto conj2) {
    struct conjunto resultado;
    resultado.quantidade = 0;

    for (int i = 0; i < conj1.quantidade; i++) {
        if (pertence(conj2, conj1.elementos[i])) {
            insira(&resultado, conj1.elementos[i]);
        }
    }

    return resultado;
}

int main() {
    // conjunto 1 vazio
    struct conjunto conjunto1;
    conjunto1.quantidade = 0;

    if (conjunto_vazio(conjunto1)) {
        printf("É vazio\n");
    }
    else {
        printf("Não é vazio\n");
    }
    escreva_conjunto("C1", conjunto1);

    insira(&conjunto1, 10);
    escreva_conjunto("C1", conjunto1);

    for (int i = 0; i < 100; i++) {
        insira(&conjunto1, rand() % 10);
    }
    escreva_conjunto("C1", conjunto1);

    struct conjunto conjunto2;
    conjunto2.quantidade = 0;
    for (int i = 0; i < 100; i++) {
        insira(&conjunto2, rand() % 10 + 5);
    }
    escreva_conjunto("C2", conjunto2);

    escreva_conjunto("C1 união C2", uniao(conjunto1, conjunto2));

    escreva_conjunto("C1 intersecção C2", intersecao(conjunto1, conjunto2));

    return 0;
}