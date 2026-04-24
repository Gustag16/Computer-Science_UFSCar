// Descrição: Exemplos de leituras diversas em C
// Requer: Muitas coisas digitadas pelo usuário
// Assegura: Apresentação dos valores das variáveis lidas

#include <stdio.h>
#include <string.h>

int main(){
    char entrada[160];

    // int
    printf("Valor inteiro: ");
    fgets(entrada, sizeof entrada, stdin);
    int valor_inteiro;
    sscanf(entrada, "%d", &valor_inteiro);
    printf("O valor digitado foi %d\n", valor_inteiro);

    // double
    printf("Digite um valor real: ");
    fgets(entrada, sizeof entrada, stdin);
    double valor_real;
    sscanf(entrada, "%lf", &valor_real);
    printf("O valor digitado foi %g\n",valor_real);

    // int + double
    printf("Digite um valor inteiro e um real: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%d%lf", &valor_inteiro, &valor_real);
    printf("Os valores digitados foram %d e %g\n", valor_inteiro, valor_real);

    // texto
    char texto[1000];    // tamanho aleatório
    printf("Digite um texto: ");
    fgets(texto, sizeof texto, stdin);
    texto[strlen(texto) - 1] = '\0';     // remove o \n do final do texto
    printf("O texto digitado foi: \"%s\"\n", texto);

    // caractere (1 caractere só)
    char caractere;
    caractere = 'x';
    printf("Meu caractere é %c\n", caractere);
    fgets(entrada, sizeof entrada, stdin);
    caractere = entrada[0];     // pega o primeiro
    printf("Meu caractere agora é %c\n", caractere);

    return 0;
}