// Descrição: Cálculo da média
// Requer: Dois números reais
// Assegura: Apresentação da média

#include <stdio.h>

int main(){
    double valor1, valor2;  // Um tipo de declaração de variável
    valor1 = 2.5;
    valor2 = 6.4;

    double media = (valor1 + valor2) / 2;   // Outro tipo de declaração de variável (atribuição direta)

    printf("Media = %g\n", media);
    return 0;
}
