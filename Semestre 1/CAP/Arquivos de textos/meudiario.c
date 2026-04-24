// Descrição: criação de um diário
// Requer: entradas de texto
// Assegura: criação de um arquivo de texto que contenha as entradas de texto salvas

#include <stdio.h>
#include <string.h>

int main() {
    // Criação do arquivo
    FILE *arquivo = fopen("diario.txt", "a");

    if (arquivo == NULL) {
        perror("Erro ao criar arquivo");
        return 1;
    }

    // Uso do diário
    char texto[160];

    // Obtenha a primeira linha
    printf("> ");
    fgets(texto, sizeof texto, stdin);       

    while (strcmp(texto, "\n") != 0) {      // Enquanto eu não 'der enter' com a linha vazia
        // Escreva linha no arquivo
        fprintf(arquivo, "%s", texto);    
        // Obtenha a próxima linha
        printf("> ");
        fgets(texto, sizeof texto, stdin);  
    }

    // Encerramento do acesso ao arquivo
    fclose(arquivo);

    return 0;
}