// Descrição: criação de um arquivo texto
// Requer:
// Assegura: Escrita de linhas em um arquivo

#include <stdio.h>

int main() {
    // Criação do arquivo
    FILE *arquivo = fopen("saida-exemplo.txt", "w");  // w = crie/substitua um arquivo com o nome "saida-exemplo.txt"
    
    if (arquivo == NULL) {
        printf("Erro na criação do arquivo\n");
        return 1;   // Condição de erro (pode ser qualquer valor diferente de 0) --> encerra o programa
    }

    // Uso do arquivo
    for(int i = 0; i < 10; i++) {
        fprintf(arquivo, "%d + %d = %d\n", i, 10, i + 20);
    }

    // Encerramento do acesso ao arquivo
    fclose(arquivo);

    return 0;
}