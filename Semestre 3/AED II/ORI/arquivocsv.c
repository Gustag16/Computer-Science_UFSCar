#include <stdio.h>
#include <stdlib.h>

struct Pessoas {
    int id;
    char usuario[20];
    char email[30];
    char nome[20];
    char sobrenome[20];  
};

int main() {
    FILE *arq = fopen("usuarios_exemplo.txt", "r");

    if (arq == NULL) {
        perror("impossivel abrir arquivo usuarios_exemplo.csv");
        return 1;
    }

    char linha[100];
    struct Pessoas registros[30];
    int i = 0;
    fgets(linha, sizeof(linha), arq); // ignora a primeira linha
    while (fgets(linha, sizeof(linha), arq)) {
        if (sscanf(linha, "%d,%19[^,],%29[^,],%19[^,],%19[^\n]", 
            &registros[i].id, registros[i].usuario, registros[i].email, registros[i].nome, registros[i].sobrenome) == 5) { 
        }
        i++;
    }

    int id;
    printf("Insira o indice da pessoa que voce quer buscar: ");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &id);

    printf("id: %d\n", registros[id].id);
    printf("usuario: %s\n", registros[id].usuario);
    printf("email: %s\n", registros[id].email);
    printf("nome: %s\n", registros[id].nome);
    printf("sobrenome: %s\n", registros[id].sobrenome);

    fclose(arq);

    return 0;
}