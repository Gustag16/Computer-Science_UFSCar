/* Escreva um programa que leia 2 inteiros e apresente o resto da divisão do 1º pelo 2º */

// Descrição: Programa que calcula o resto da divisão de dois inteiros
// Requer: Dois numeros inteiros
// Assegura: Apresentação do resto da divisão dos dois inteiros

#include <stdio.h>

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    int num1, num2;
    sscanf(entrada, "%d%d", &num1, &num2);

    printf("O resto da divisão de %d por %d é %d\n", num1, num2, num1 % num2);

    return 0;
}