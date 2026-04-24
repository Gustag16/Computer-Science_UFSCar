// Descrição: Verifica se uma equação é de segundo grau de acordo com a, b e c
// Requer: Os valores de a, b e c
// Assegura: Apresentação da mensagem "Sim" ou "Não"

#include <stdio.h>
#include <stdbool.h>

int main(){
    char entrada[160];
    double a, b, c;
    
    printf("Insira a, b e c: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf%lf%lf", &a, &b, &c);

    bool segundo_grau = a != 0;
    printf("A equação é do segundo grau?: %s\n", segundo_grau ? "Sim" : "Não");

    return 0;
}
