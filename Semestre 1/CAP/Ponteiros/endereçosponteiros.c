// Descrição: exemplos de ponteiros

/* 
Ponteiros são variáveis que guardam endereços de memória.
Com o ponteiro, é possível:
I) Ver o que tem no endereço
II) Mudar o que tem no endereço
*/

#include <stdio.h>

int main() {
    int i = 10;
    int j = 20;
    int *endereco_i = &i;  // * guarda um endereço (guarda o endereço de i)

    printf("%p\n", &i);
    printf("%p\n", endereco_i); // Ambas as linhas retornam a mesma coisa (endereço de i)

    printf("%d\n", *endereco_i);  // *endereco_i (sabendo do endereço de i) le o valor de i
    i++;
    printf("%d\n", *endereco_i);

    *endereco_i = 100;  // Altera o valor da variável i a partir de seu endereço
    printf("i = %d\n", i);

    return 0;
}

/*
EXEMPLO: 

double d;       // guarda real
double *pd      // guarda end. de um real

pd = &d;        // guarda end. do real d

*pd = 5.2       // altera d indiretamente
*pd = *pd * 7   // multiplica o valor de *pd por 7 e armazena em *pd
*/