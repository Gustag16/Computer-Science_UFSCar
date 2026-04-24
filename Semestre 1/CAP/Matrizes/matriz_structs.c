/* Função que retorna a soma de todos os elementos de uma matriz */

#include <stdio.h>

#define MAX_LINHAS 25
#define MAX_COLUNAS 25

struct matriz {
    int linhas;
    int colunas;
    double dados[MAX_LINHAS][MAX_COLUNAS];
};

struct matriz cria_matriz(int linhas, int colunas) {
    struct matriz mat; // cria uma variável 'virtual' com a configuração declarada no struct matriz
    mat.linhas = linhas; // passa o parametro 'linhas' para a cópia da variável dentro da configuração do struct matriz
    mat.colunas = colunas;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            mat.dados[i][j] = i + j; // passa o valor para a variável 'dados' (que está dentro de 'mat')
        }
    }
    return mat; // retorna o struct todo
}

void escreve_matriz(struct matriz mat) {
    for (int i = 0; i < mat.linhas; i++) {
        for (int j = 0; j < mat.colunas; j++) {
            printf("%g ", mat.dados[i][j]);
        }
        printf("\n");
    }
}

double soma_matriz(struct matriz m1) {
    double soma = 0;
    for (int i = 0; i < m1.linhas; i++) {
        for (int j = 0; j < m1.colunas; j++) {
            soma += m1.dados[i][j];
        }
    }
    return soma;
}

int main (){
    // copio as linhas, colunas e a matriz para a variável m1 
    // (como um backup do struct da função que logo desaparecerá)
    struct matriz m1 = cria_matriz(5, 5);

    // o parâmetro 'm1' é copiado para um novo struct 'virtual'/temporário dentro da função
    escreve_matriz(m1);

    printf("Soma dos elementos da matriz = %g\n", soma_matriz(m1));

    return 0;
}