#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Função recursiva que encontra todos os caminhos possíveis no labirinto
    Parâmetros:
    - labirinto: matriz do labirinto (passada por referência)
    - i, j: coordenadas atuais na matriz (i = linha; j = coluna)
    - caminho: string que grava os movimentos feitos até o momento
    - caminhos: vetor no qual todos os caminhos válidos encontrados são armazenados
*/
void encontrar_caminhos(vector<vector<int>>& labirinto, int i, int j, string caminho, vector<string>& caminhos_totais) {
    int n = labirinto.size();  // tamanho do labirinto
    
    // Condição de parada: cooredenadas atuais na matriz são ambas n-1
    if (i == n-1 && j == n-1) {
        caminhos_totais.push_back(caminho);  // Armazena o caminho encontrado em um vetor de strings
        return;
    }

    // Verificação de se o movimento dentro da matriz está dentro dos limites e se a célula de destino é segura (1)
    // Para cada verificação, marcamos a célula atual como amaldiçoada (0) temporariamente
    // No backtracking, restauramos a célula para segura novamente

    // Movimento para a direita (-)
    if (j + 1 < n && labirinto[i][j+1] == 1) {
        labirinto[i][j+1] = 0;  // Marca a célula como amaldiçoada (0) temporariamente
        // Chama recursivamente para a nova posição, adicionando "- " ao caminho
        encontrar_caminhos(labirinto, i, j+1, caminho + "- ", caminhos_totais);
        labirinto[i][j+1] = 1;  // Backtracking: restaura a célula para segura (1)
    }

    // Movimento para baixo (|)
    if (i + 1 < n && labirinto[i+1][j] == 1) {
        labirinto[i+1][j] = 0;
        // Chama recursivamente para a nova posição, adicionando "| " ao caminho
        encontrar_caminhos(labirinto, i+1, j, caminho + "| ", caminhos_totais);
        labirinto[i+1][j] = 1;
    }

    // Movimento para diagonal inferior direita (\)
    if (i + 1 < n && j + 1 < n && labirinto[i+1][j+1] == 1) {
        labirinto[i+1][j+1] = 0;
        // Chama recursivamente para a nova posição, adicionando "\ " ao caminho
        encontrar_caminhos(labirinto, i+1, j+1, caminho + "\\ ", caminhos_totais);
        labirinto[i+1][j+1] = 1;
    }
}

int main() {
    // Inicializa o labirinto com os valores fornecidos no problema
    vector<vector<int>> labirinto = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1},
    };
    
    vector<string> caminhos_totais;  // Vetor para armazenar todos os caminhos válidos encontrados

    // Verifica se a célula inicial (0,0) é segura (1)
    if (labirinto[0][0] == 1) {
        labirinto[0][0] = 0;  // Marca temporariamente a célula inicial como amaldiçoada
        // Inicia a busca recursiva a partir da posição (0,0)
        encontrar_caminhos(labirinto, 0, 0, "", caminhos_totais);
        labirinto[0][0] = 1;  // Restaura a célula inicial para segura (1)
    }

    // Para imprimir todos os caminhos encontrados
    for (int i = 0; i < caminhos_totais.size(); i++) {
        cout << "Caminho " << i+1 << ": " << caminhos_totais[i] << endl;
    }

    return 0;
}