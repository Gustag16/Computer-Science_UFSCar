/* 
Descrição: Cálculo por somas sucessivas o valor da soma dos números de 1 até n
Requer: o valor de n
Assegura: somatória dos valores de 1 até n
*/

#include <stdio.h>

int main() {
    char entrada[160];

    printf("Insira o valor de n: ");
    fgets(entrada, sizeof entrada, stdin);
    int n;
    sscanf(entrada, "%d", &n);

    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma = soma + i; 
    }

    printf("A soma é %d\n", soma);

    return 0;
}