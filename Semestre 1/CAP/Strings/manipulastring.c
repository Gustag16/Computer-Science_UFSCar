/* Escreva uma função que retorna TRUE se, e somente se, um caractere for vogal */
/* Função que retorna TRUE ou FALSE conforme um char seja uma maiúscula */
/* Função que retorna o número de vogais em uma string */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool eh_vogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool eh_minuscula(char c) {
    return (c >= 'a' && c <= 'z');
}

int main() {
    char entrada[3];
    fgets(entrada, sizeof entrada, stdin);
    char letra;
    sscanf(entrada, "%c", &letra);

    printf("%c é uma vogal? %s\n", letra, eh_vogal(letra) ? "Sim" : "Não");
    printf("%c é minúsculo? %s\n", letra, eh_minuscula(letra) ? "Sim" : "Não");

    char string[160];
    fgets(string, sizeof string, stdin);
    
    int posicao = 0;
    int conta_vogais = 0;
    while (string[posicao] != '\0') {
        if (eh_vogal(string[posicao])) {
            conta_vogais++;
        }
        posicao++;
    }

    printf("Quantidade de vogais: %d\n", conta_vogais);

    return 0;
}