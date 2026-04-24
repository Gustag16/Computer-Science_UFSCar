/*
Descrição: Algoritmo que calcula a média de idade de um professor a partir dos palpites dados pelos alunos, sendo 0
    o valor que encerra a leitura de idades
Requer: Os palpites da idade
Assegura: Apresentação da média de todos os palpites

soma := 0
quantidade :=0
Obtenha idade
enquanto idade != 0 faça
    soma += idade
    quantidade++
    obtenha idade
fim enquanto
media := soma / quantidade
escreva media
*/

#include <stdio.h>

int main() {
    char entrada[160];

    // obtenha a primeira idade
    printf("Idade: ");
    fgets(entrada, sizeof entrada, stdin);
    int idade;
    sscanf(entrada, "%d", &idade);

    double soma = 0;
    int quantidade = 0;
    while (idade != 0) {
        soma += idade;
        quantidade++;
        // obtenha a próxima idade
        printf("Idade: ");
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%d", &idade);
    }

    double media;
    media = soma / quantidade;

    printf("A média de idade é %.3f\n", media);
    
    return 0;
}