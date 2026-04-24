/*
Descrição: Comparação entre os tipos de dados
Requer: Nada
Assegura: Apresentação dos tipos de dados
*/

#include <stdio.h>

int main(){
    int valor_int = 10;
    double valor_real = 1.1;

    printf("Valor inteiro: %d\n", 3*8); // Output é o resultado da operação
    printf("Valor para comparacao: 3*8\n"); // Output é o texto 3*8
    printf("Valor inteiro por variavel: %d\n\n", valor_int);    // Output é a variável declarada no início

    printf("Valor real: %g\n", 17.75/3.98); // Double
    printf("Valor real: %f\n", 17.75/3.98); // Float
    printf("Valor real por variavel: %g\n\n", valor_real);  // Output é a variável declarada no início

    printf("Valor textual: %s\n\n", "Hoje");

    printf("Exemplo de diferentes tipos de valores em uma unica linha: %d %d %g %s", 10, 20, 3.14, "Ola\n\n");

    printf("Tamanho do int: %ld\n", sizeof(int));   // Para saber quantos bytes cabem em um int
    printf("Tamanho do double: %ld\n", sizeof(double)); // Para saber quantos bytes cabem em um double
    return 0;
}