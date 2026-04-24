// Descrição: Conversão de graus Celsius para Fahrenheit
// Requer: A temperatura em Celsius
// Assegura: Apresentação da temperatura equivalente em Faherenheit

#include <stdio.h>

int main(){
    // Obtenha a temperatura em Celsius
    printf("Digite um valor em Celsius: ");
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    double celsius;
    sscanf(entrada, "%lf", &celsius);

    // Calcule a temperatura equivalente em Fahrenheit
    double fahrenheit = 9.0 / 5.0 * celsius + 32;

    // Apresente a temperatura em Fahrenheit
    printf("%g Celsius = %g Fahreinheit\n", celsius, fahrenheit);

    return 0;
}

