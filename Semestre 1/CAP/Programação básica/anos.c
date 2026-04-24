// Descrição: Estimativa do ano de nascimento de uma pessoa
// Requer: A idade da pessoa
// Assegura: Apresentação da estimativa do ano de nascimento

#include <stdio.h>

int main(){
    char entrada[180];
    int idade, ano_nascimento;

    printf("Insira a sua idade: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%d", &idade);

    ano_nascimento = 2025 - idade;

    printf("Você nasceu em %d ou %d\n", ano_nascimento, ano_nascimento - 1);

    return 0;
}