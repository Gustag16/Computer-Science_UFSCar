/* Função que retorna o dígito da dezena. Ex.: 127 --> 2 */

// Descrição: Algoritmo que retorna a dezena de um valor natural por meio de uma função
// Requer: Um valor natural
// Assegura: A dezena desse valor

#include <stdio.h>

/*
retorna a dezena de um valor natural
@param n: numero natural
@retorna dezena (natural)
*/
int dezena(int n) {
    return n / 10 % 10; // me livro da unidade e vejo o resto do que sobrou
}

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    int numero;
    sscanf(entrada, "%d", &numero);

    printf("A dezena de %d é %d\n", numero, dezena(numero));

    return 0;
}