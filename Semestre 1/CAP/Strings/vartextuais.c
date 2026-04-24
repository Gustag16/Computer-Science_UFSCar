// Descrição: exemplos básicos de utilização de variáveis textuais
// Requer: entradas gerais pra exemplificar as operações
// Assegura: apresentação de resultados das operações

#include <stdio.h>
#include <string.h>

int main() {
    // char c1 = 'A';
    // printf("c1 = %c, código %d (%ld byte)\n", c1, c1, sizeof c1);

    // char c2 = 'a';
    // printf("c2 = %c, código %d (%ld byte)\n", c2, c2, sizeof c2);

    // if (c1 == c2) {
    //     printf("c1 = c2");
    // }
    // else {
    //     printf("c1 != c2\n");
    // }

    // if (c1 > c2) {
    //     printf("c1 > c2\n");
    // }
    // else {
    //     printf("c1 <= c2\n");
    // }

    // printf("Depois de %c vem %c\n", c2, c2 + 1);
    // printf("No meio de %c e %c, tem %c\n", c1, c2, (c1+c2)/2);
    // printf("%d\n", c2 - c1);
    // printf("%c\n", c1 + 32);

    // for(char c = 'A'; c <= 'Z'; c++) {
    //     printf("%c --> %c\n", c, c + 32);
    // }

    // Cadeias de caracteres
    char texto[50] = "um texto qualquer";   // criação de variável com atribuição
    printf("texto: %s (%ld caracteres)\n", texto, strlen(texto));

    // Atribuição fora da declaração --> strncpy
    char texto2[10];
    char texto3[10];
    strncpy(texto2, "Gustavo", sizeof texto2 - 1);    // 'sizeof (variável) - 1' para tirar o \0
    strncpy(texto3, "Gabriel", sizeof texto3 - 1);
    printf("texto 2: %s\n", texto2);
    printf("texto 3: %s\n", texto3);

    if (strcmp(texto2, texto3) == 0) {     // 'strcmp(var1, var2)' para comparar as strings
        printf("Textos iguais\n");
    }
    else if (strcmp(texto2, texto3) < 0) {
        printf("Primeiro texto menor que o segundo (vem primeiro na ordem alfabética)\n");
    }
    else if (strcmp(texto2, texto3) > 0) {
        printf("Primeiro texto maior que o segundo (vem depois na ordem alfabética)\n");
    }

    strncat(texto, " e mais algo", sizeof texto - strlen(texto) - 1); // para tirar da var os bytes já usados e o \0
    printf("texto concatenado = %s\n", texto);

    // Leitura
    char outro_texto[40];
    fgets(outro_texto, sizeof outro_texto - 1, stdin);
    outro_texto[strlen(outro_texto) - 1] = '\0';    // para substituir o \n pelo \0 (outro_texto[posição])
    printf("Texto digitado: <<%s>>\n", outro_texto);

    return 0;
}