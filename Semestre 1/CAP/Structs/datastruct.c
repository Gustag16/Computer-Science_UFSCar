/* Faça um novo programa para declarar e usar uma data em um struct. A data deve juntar dia, mês e ano */

#include <stdio.h>

int main() {
    struct data {
        int dia; 
        int mes; 
        int ano;
    };

    struct data d1, d2;
    
    // Data 1:
    d1.dia = 10;
    d1.mes = 6;
    d1.ano = 2022;

    // Data 2:
    d2.dia = 11;
    d2.mes = 7;
    d2.ano = 2006;

    // Natal desse ano:
    struct data natal = {25, 12, 2025};

    printf("Data 1 %d/%d/%d \nData 2 %d/%d/%d\n", d1.dia, d1.mes, d1.ano, d2.dia, d2.mes, d2.ano);
    printf("O Natal desse ano vai ser dia %d/%d/%d :O\n", natal.dia, natal.mes, natal.ano);

    return 0;
}