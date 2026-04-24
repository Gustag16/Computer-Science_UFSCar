/* Escreva uma função para retornar a média de três valores reais quaisquer */

// Descrição: Cálculo da média de 3 valores reais usando função
// Requer: Três valores reais
// Assegura: Apresentação da média dos três valores reais

#include <stdio.h>

/*
Média de 3 valores
@param n1, n2, n3: valores
@return média de n1, n2, n3
*/
double media(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    double nota1, nota2, nota3;
    sscanf(entrada, "%lf%lf%lf", &nota1, &nota2, &nota3);

    double media_final = media(nota1, nota2, nota3);

    printf("A média é %g\n", media_final);

    return 0;
}
