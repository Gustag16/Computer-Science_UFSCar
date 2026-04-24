/* Escreva uma função que aceite uma matriz e um valor escalar e retorne a multiplicação da matriz pelo escalar */
/* Escreva uma função que aceite duas matrizes e retorne a soma delas */

/*VAI CAIR NA PROVA*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_linhas 50
#define MAX_colunas 50

struct matriz {
    int linhas;
    int colunas;
    double dados[MAX_linhas][MAX_colunas];
};

// Função que cria uma matriz com valores aleatórios
struct matriz cria_matriz(int linhas, int colunas, int random) {
    srand(random);
    struct matriz mat;
    mat.linhas = linhas;
    mat.colunas = colunas;
    for (int i = 0; i < mat.linhas; i++) {
        for (int j = 0; j < mat.colunas; j++) {
            mat.dados[i][j] = (rand() % 1000) * 0.01;
        }
    }
    return mat;
}

// Função que multiplica os elementos de uma matriz por um escalar
struct matriz multiplica_escalar(double escalar, struct matriz m1) {
    for (int i = 0; i < m1.linhas; i++) {
        for (int j = 0; j < m1.colunas; j++) {
            m1.dados[i][j] *= escalar;
        }
    }
    return m1;
}

// Função que escreve a matriz formatada
void escreva_matriz(struct matriz mat) {
    for (int i = 0; i < mat.linhas; i++) {
        for (int j = 0; j < mat.colunas; j++) {
            printf("%5.2f ", mat.dados[i][j]);
        }
        printf("\n");
    }
}

struct matriz soma_matrizes(struct matriz m1, struct matriz m2) {
    struct matriz mat_somada;
    if (m1.linhas == m2.linhas && m1.colunas == m2.colunas) {
        mat_somada.linhas = m1.linhas;
        mat_somada.colunas = m1.colunas;
        for (int i = 0; i < mat_somada.linhas; i++) {
            for (int j = 0; j < mat_somada.colunas; j++) {
                mat_somada.dados[i][j] = m1.dados[i][j] + m2.dados[i][j];
            }
        }
    }
    else {
        mat_somada.linhas = 0;
        mat_somada.colunas = 0;
    }
    return mat_somada;
}

struct matriz subtrai_matrizes(struct matriz m1, struct matriz m2) {
    struct matriz mat_subtraida;
    // m1 - m2 == m1 + (-1)*m2
    mat_subtraida = soma_matrizes(m1, multiplica_escalar(-1, m2));
    return mat_subtraida;
}

int main() {
    struct matriz m1 = cria_matriz(3, 3, 10);
    printf("m1\n");
    escreva_matriz(m1);

    printf("\n");

    // struct matriz m2 = multiplica_escalar(-1, m1);
    // printf("m1 * -1\n");
    // escreva_matriz(m2);

    struct matriz m3 = cria_matriz(3, 3, 20);
    printf("m3\n");
    escreva_matriz(m3);

    printf("\n");

    // struct matriz matriz_somada = soma_matrizes(m1, m3);
    // printf("Matriz somada\n");
    // escreva_matriz(matriz_somada);

    // struct matriz matriz_subtraida = subtrai_matrizes(m1, m3);
    // printf("Matriz subtraída\n");
    // escreva_matriz(matriz_subtraida);

    /* Dados uma linha e uma coluna específica, multiplicar o primeiro elemento da linha com o primeiro elemento
    da coluna e somar com os próximos, até o fim */

    int linha = 1;
    int coluna = 2;

    double soma = 0;
    for (int i = 0; i < m1.colunas; i++) {
        soma += (m1.dados[linha][i] * m3.dados[i][coluna]);
    }

    printf("Soma do pseudo determinante: %g\n", soma);

    /* Implementar um multiplicador de matrizes!!! */

    return 0;
}