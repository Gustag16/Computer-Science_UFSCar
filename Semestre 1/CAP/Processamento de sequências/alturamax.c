// Descrição: Determinação da altura máxima em uma equipe de 20 competidores
// Requer: uma sequência com 20 medidas de altura
// Assegura: a altura máxima

#include <stdio.h>

int main() {
    char entrada[160];

    printf("Altura: "); // primeira altura
    fgets(entrada, sizeof entrada, stdin);
    double altura, altura_max;
    sscanf(entrada, "%lf", &altura);

    altura_max = altura;

    for (int i = 2; i <= 20; i++) {    // da segunda à vigésima
        // obtenha a altura e substitua altura_max se necessário
        printf("Altura: ");
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%lf", &altura);
            if (altura > altura_max) {
                altura_max = altura;
            }
    }

    printf("A altura máxima é %.2f\n", altura_max);

    return 0;
}