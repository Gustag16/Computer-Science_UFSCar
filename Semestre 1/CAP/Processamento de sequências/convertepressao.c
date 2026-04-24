// Descrição: conversão de uma sequência de valores de pressão dadas em mmHg para atm, usando um valor
//      nulo como sentinela
// Requer: uma sequẽncia potencialmente vazia de valores de pressão (mmHg) não nulos seguidos por um valor
//     sentinela nulo
// Assegura: O valor de cada medida de pressão convertido para atm

/*
obtenha pressão_mmHg
enquanto pressão_mmHg != 0 faça
    calcule pressão_atm como 1/760 * pressão_mmHg
    apresente pressão_atm
    obtenha pressão_mmHg
fim enquanto
*/

#include <stdio.h>

int main() {
    char entrada[160];

    // obtenha o primeiro valor
    printf("Valor da pressão em mmHg: ");
    fgets(entrada, sizeof entrada, stdin);
    double pressão_mmhg;
    sscanf(entrada, "%lf", &pressão_mmhg);

    double pressão_atm;
    while (pressão_mmhg != 0) {
        pressão_atm = 1.0/760 * pressão_mmhg;
        printf("A pressão em atm é: %.2f\n", pressão_atm);

        // obtenha o próximo valor
        printf("Valor da pressão em mmHg: ");
        fgets(entrada, sizeof entrada, stdin);
        sscanf(entrada, "%lf", &pressão_mmhg);
    }
}