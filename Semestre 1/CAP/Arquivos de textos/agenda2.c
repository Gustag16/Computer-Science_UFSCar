/* arquivo: agenda.c
 * 
 * Jander, 2025 - CAP
 */
#include <stdio.h>

struct info {
    char nome[40];
    char telefone[20];
    double salario;
};

void cadastre() {
    FILE *arquivo = fopen("agenda.dat", "a");
    if (arquivo == NULL) {
        perror("Acesso a agenda");
        return 1;
    }

    // leitura
    struct info pessoa;
    printf("Nome: ");
    fgets(pessoa.nome, sizeof pessoa.nome, stdin);
    printf("Telefone: ");
    fgets(pessoa.telefone, sizeof pessoa.telefone, stdin);
    printf("Salario: ");
    char entrada[160];
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf", &pessoa.salario);

    fwrite(&pessoa, sizeof pessoa, 1, arquivo);

    fclose(arquivo);
}

void liste() {
    FILE *arquivo = fopen("agenda.dat", "r");
    if (arquivo == NULL) {
        perror("Acesso a agenda");
        return 1;
    }

    struct info pessoa;
    while (fread(&pessoa, sizeof pessoa, 1, arquivo) > 0)
        printf("%s%s%.2f\n", pessoa.nome, pessoa.telefone, pessoa.salario);

    fclose(arquivo);
}

void consulte_por_numero() {
    FILE *arquivo = fopen("agenda.dat", "r");
    if (arquivo == NULL) {
        perror("Acesso a agenda");
        return 1;
    }

    printf("Qual é o número? ");
    char entrada[160];
    int numero_registro;
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%d", &numero_registro);

    fseek(arquivo, numero_registro * sizeof (struct info), SEEK_SET);

    struct info pessoa;
    fread(&pessoa, sizeof pessoa, 1, arquivo);
    printf("%s%s%.2f\n", pessoa.nome, pessoa.telefone, pessoa.salario);

    fclose(arquivo);
}

int main(void) {
    char opcao[40];
    do {
        printf("\nO que você quer fazer?\n"
               "1 - Cadastrar uma pessoa\n"
               "2 - Listar a agenda\n"
               "3 - Consulta por número\n"
               "9 - Sair\n"
               "\nOpção: "
        );
        fgets(opcao, sizeof opcao, stdin);
        switch (opcao[0]) {
            case '1':
                cadastre();
                break;
            case '3':
                consulte_por_numero();
                break;
            case '2':
                liste();
                break;
        }
    } while (opcao[0] != '9');

    return 0;
}