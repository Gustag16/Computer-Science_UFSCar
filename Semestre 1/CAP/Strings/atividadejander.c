// Descrição: contagem de vezes em que o primeiro nome apareceu na sequência seguido pelo sentinela 'FIM'
// Requer: uma série de nomes e o sentinela
// Assegura: apresentação da quantidade de vezes em que o primeiro nome apareceu na sequência

#include <stdio.h>
#include <string.h>

int main() {
    char entrada[160];
   
    fgets(entrada, sizeof entrada, stdin);
    char primeiro_nome[20];
    sscanf(entrada, "%s", primeiro_nome);   // Leitura do primeiro nome

    int qtd_nomes = 1;
    char nome_atual[20];
    while (strcmp(nome_atual, "FIM") != 0) {
        fgets(entrada, sizeof entrada, stdin);  // Leitura do próximo nome
        sscanf(entrada, "%s", nome_atual);
        if (strcmp(nome_atual, primeiro_nome) == 0) {
            qtd_nomes++;
        }
    }

    printf("%d\n", qtd_nomes);
    
    return 0;
}