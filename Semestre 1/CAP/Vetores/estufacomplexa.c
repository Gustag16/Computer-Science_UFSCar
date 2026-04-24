// Descrição: Programa que registra as temperaturas dentro de uma estufa a cada hora ao longo de um dia,  calcula a 
//    média e apresenta as temperaturas mínimas e máximas e a hora nas quais se deu o mínimo e o máximo.
// Requer: 24 valores de temperaturas.
// Assegura: Apresentação da média das temperaturas, a máxima e a mínima e a hora que se deu cada uma.

#include <stdio.h>
#include <stdbool.h>
#define TAMANHO 24

int main() {
    char entrada[160];
    int temperaturas[TAMANHO];
    
    // Lê cada temperatura da entrada e joga em um vetor de int
    for (int i = 0; i < TAMANHO; i++) {
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%d", &temperaturas[i]);
    }

    // Apresentação do vetor temperatura
    printf("Registro das temperaturas: ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", temperaturas[i]);
    }
    printf("\n");

    // Descobrir as temperaturas mínimas e máximas e as horas em que elas se dão
    int min = temperaturas[0];
    int max = temperaturas[0];

    // Descobrir a soma das temperaturas para fazer a média
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += temperaturas[i];
        if (temperaturas[i] <= min) {
            min = temperaturas[i];
        }
        if (temperaturas[i] >= max) {
            max = temperaturas[i];
        }
    }

    // Calcular a média forçando soma como double
    double media = (double) soma / TAMANHO;

    // Escrever 1 no vetor se ele é igual ao mínimo ou ao máximo
    int vetor_horamin[TAMANHO] = {0};
    int vetor_horamax[TAMANHO] = {0};
    for (int i = 0; i < TAMANHO; i++) {
        if (temperaturas[i] == min) {
            vetor_horamin[i] = 1;
        }
        if (temperaturas[i] == max) {
            vetor_horamax[i] = 1;
        }
    }

    // Apresentação dos resultados
    printf("Temperatura mínima = %dºC às ", min);   
    for (int i = 0; i < TAMANHO; i++) {
        if (vetor_horamin[i] == 1) {
            printf("%dh ", i);   
        } 
    }
    printf("\n");

    printf("Temperatura máxima = %dºC às ", max);   
    for (int i = 0; i < TAMANHO; i++) {
        if (vetor_horamax[i] == 1) {
            printf("%dh ", i);   
        } 
    }
    printf("\n");

    printf("Média das temperaturas: %g°C\n", media);

    return 0;
}
