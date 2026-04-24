// Descrição: contador do número de pares em uma sequência de inteiros positivos terminando com sentinela = 0
// Requer: uma sequência de inteiros maiores que zero e um zero (sentinela)
// Assegura: apresentação da contagem de pares

/*
obtenha valor
contador <- 0
enquanto valor != 0 faça
    se valor for par então
        contador <- contador + 1
    fim se
    obtenha valor   // próx valor
fim enquanto
apresente contador
*/

#include <stdio.h>

int main() {
    char entrada[160];

    // obtenha valor
    printf("Valor: ");
    fgets(entrada, sizeof entrada, stdin);
    int valor;
    sscanf(entrada, "%d", &valor);

    // contagem de pares para a sequência
    int contador_pares = 0;
    while (valor != 0) {
        if (valor % 2 == 0) {   // se valor for par
            contador_pares++;   // contador_pares = contador_pares + 1
        }
        // obtenha o próximo valor
        printf("Valor: ");
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%d", &valor);
    }

    printf("Existem %d pares na sequência\n", contador_pares);

    return 0;
}