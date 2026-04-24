// Descrição: Calcula o valor da área de um círculo
// Requer: A medida do raio do círculo
// Assegura: Apresentação do valor da área

#include <stdio.h>
#include <math.h>

int main(){
    char entrada[180];
    double raio, area;

    printf("Insira a medida do raio do círculo, em metros: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf", &raio);
    
    area = 3.14 * pow(raio, 2);

    printf("A área do círculo é %g metros\n", area);

    return 0;
}