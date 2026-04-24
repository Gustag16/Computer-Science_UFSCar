// Descrição: Cálculo da média de duas notas e sinalização da aprovação/reprovação
// Requer: Duas notas
// Assegura: Apresentação da média e mensagem "aprovado" ou "reprovado"

#include <stdio.h>

int main() {
    // obtenha as duas notas
    char entrada[160];
    printf("Digite as duas notas: ");
    fgets(entrada, sizeof entrada, stdin);
    double nota1, nota2;
    sscanf(entrada, "%lf%lf", &nota1, &nota2);

    // calcule a média

    double media;
    media = (nota1 + nota2) / 2;
    
    // apresente a média
    printf("Média = %.1f\n", media);

    // apresente a mensagem de aprovação/reprovação
    if (media >= 5.95) {   // >= 6 por conta da precisão
        printf("Situação = aprovado\n");
    }
    else {
        printf("Situação = reprovado\n");
    }

    return 0;
}