/* Função que retorna uma matriz de "aleatórios", dado o número de linhas e colunas */
/* VAI CAIR NA PROVA!!! */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINHAS 50
#define MAX_COLUNAS 50

struct matriz {
    int linhas;
    int colunas;
    double dados[MAX_LINHAS][MAX_COLUNAS];
};

struct matriz cria_matriz(int linhas, int colunas) {
    srand(42);
    struct matriz mat;
    mat.linhas = linhas;
    mat.colunas = colunas;
    for (int i = 0; i < mat.linhas; i++) {
        for (int j = 0; j < mat.colunas; j++) {
            mat.dados[i][j] = (rand() % 1000) * 0.1;
        }
    }
    return mat;
}

void escreva_matriz(struct matriz mat) {
    for (int i = 0; i < mat.linhas; i++) {
        for (int j = 0; j < mat.colunas; j++) {
            printf("%g ", mat.dados[i][j]);
        }
        printf("\n");
    }
}

double soma_matriz(struct matriz mat) {
    double soma = 0;
    for (int i = 0; i < mat.linhas; i++) {
        for (int j = 0; j < mat.colunas; j++) {
            soma += mat.dados[i][j];
        }
    }
    return soma;
}

int main () {
    struct matriz m1 = cria_matriz(5, 5);
    escreva_matriz(m1);

    printf("A soma dos elementos da matriz é = %g\n", soma_matriz(m1));
    printf("A média dos elementos da matriz é = %g\n", soma_matriz(m1)/(m1.linhas*m1.colunas));

    return 0;
}