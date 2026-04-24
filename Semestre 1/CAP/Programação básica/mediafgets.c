// Descrição: Cálculo da média simples de duas notas
// Requer: Duas notas
// Assegura: Apresentação do valor da média simples

#include <stdio.h>

int main(){
    char entrada[180];
    double nota_1, nota_2, media;
    printf("Insira a nota 1: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf", &nota_1);

    printf("Insira a nota 2: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf", &nota_2);

    media = (nota_1 + nota_2) / 2;

    printf("Sua média é %g\n", media);

    return 0;
}
