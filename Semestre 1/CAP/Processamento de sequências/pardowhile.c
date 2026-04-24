// Descrição: contador do número de pares em uma sequência de inteiros positivos terminando com sentinela = 0
// Requer: uma sequência de inteiros maiores que zero e um zero (sentinela)
// Assegura: apresentação da contagem de pares

/*
contador <- 0
repita
    obtenha valor
    se valor != 0 e valor for par então
        contador <- contador + 1
    fim se
até valor = 0
apresente contador
*/

#include <stdio.h>

int main() {
    char entrada[160];

    // contagem de pares para a sequência
    int contador_pares = 0;
    int valor;
    do {
        // obtenha o valor
        printf("Valor: ");
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%d", &valor);

        // testa se é zero e se é par
        if (valor != 0 && valor % 2 == 0) {   
            contador_pares++;   // contador_pares = contador_pares + 1
        }
    }
    while (valor != 0);   // (leia valores enquanto valor for diferente de zero)

    // resultado
    printf("Existem %d pares na sequência\n", contador_pares);

    return 0;
}