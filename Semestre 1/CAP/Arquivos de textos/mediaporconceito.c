/*
Considere um arquivo contendo conceitos, 1 por linha, de A até E. 
Calcule a média numérica de todos os conceitos
*/

// Descrição: Conversão de um conceito (A, B, C, D ou E) para nota numérica por switch usando um arquivo e
//      cálculo da média numérica da turma
// Requer: O arquivo com os conceitos
// Assegura: Apresentação da média numérica da turma

#include <stdio.h>
#include <string.h>

int main(){
    // Selecionar o arquivo:
    printf("Qual o nome do arquivo? ");
    char nome_arquivo[160];
    fgets(nome_arquivo, sizeof nome_arquivo, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';  // Para substituir o \n por \0

    // Abrir o arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r");

    // Encerrar o programa em caso de erro
    if (nome_arquivo == NULL) {
        perror(nome_arquivo);
        return 1;
    }
    
    // Leitura dos conceitos (um por linha);
    char linha[5];
    double nota; 
    double soma = 0;
    int contador = 0;
    while (fgets(linha, sizeof linha, arquivo) != NULL) { // Enquanto ele não ler uma linha NULL
        char conceito;
        sscanf(linha, "%c", &conceito); 

        switch (conceito) {
        case 'A':
            nota = 10;
            break;
        case 'B':
            nota = 8;
            break;
        case 'C':
            nota = 6;
            break;
        case 'D':
            nota = 3;
            break;
        default:
            nota = 0;
        }
        contador++;
        soma += nota;
    }
    
    fclose(arquivo);

    double media = soma / contador;
    printf("A média da turma foi: %.2f %d\n", media, contador);

    return 0;
}