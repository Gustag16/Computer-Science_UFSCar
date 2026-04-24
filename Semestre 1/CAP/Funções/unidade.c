/* Função para retornar o último dígito (unidades) de um valor natural */

// Descrição: Algoritmo que retorna o último dígito de um valor natural por meio de uma função
// Requer: Um valor natural
// Assegura: O último dígito desse valor

#include <stdio.h>

/*
retorna o último dígito de um valor natural
@param n: numero natural
@retorna unidade (natural)
*/
int unidade(int n) {
    return n % 10;
}

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    int numero;
    sscanf(entrada, "%d", &numero);

    printf("A unidade de %d é %d\n", numero, unidade(numero));

    return 0;
}