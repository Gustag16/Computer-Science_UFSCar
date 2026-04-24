// Descrição: Operações com variáveis
// Requer: Nada
// Assegura: Apresentação dos resultados das operações

#include <stdio.h>
#include <stdbool.h>

int main(){
    double d1 = 5.0;
    double d2 = 2.0;

    printf("soma %g; subtração %g\n", d1 + d2, d1 - d2);
    printf("multiplicação %g; divisão %g\n", d1 * d2, d1 / d2);
    printf("d1+d2*d1 = %g\n", d1 + d2 * d1);    // Multiplicação primeiro
    printf("(d1+d2)*d1 = %g\n\n", (d1 + d2)*d1);  // Parêntesis primeiro

    // Atentar-se às operações entre inteiros e doubles
        // int com int = int
        // double com double = double
        // int com double = double com int = double
        // Isso inclui os casos nos quais as atribuições de uma variável double estão em valores inteiros
            // Exemplo: double div = 5/2 --> double recebe o valor 2.0 e não 2.5

    printf("d1>d2?: %d\n", d1 > d2);    // Exemplo de comparação que retorna valor True (1)
    printf("d1=d2?: %d\n\n", d1==d2);     // Exemplo de comparação que retorna valor False (0)

    // Obs: nunca comparar três valores ao mesmo tempo
        // A expressão 0 < -10 < 20 retorna valor True (1)
            // 0 < -10 < 20 == 0 < 20 == 1
        // Ao invés disso, compare da seguinte forma
            // 0 < -10 && -10 < 20 (Função 'and')

    // Função 'and': &&
    // Função 'or': ||

    printf("%d\n", d1 > d2);    // Maior que
    printf("%d\n", d1 < d2);    // Menor que
    printf("%d\n", d1 >= d2);   // Maior ou igual a
    printf("%d\n", d1 <= d2);   // Menor ou igual a
    printf("%d\n", d1 == d2);   // Igual a
    printf("%d\n", d1 != d2);   // Diferente de

    return 0;
}