#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

struct sort_data {
    vector<int> array;
    int n;
    long int trocas;
    long int comparacoes;
};

void insertion_sort(sort_data& insertion) {
    int aux;
    for (int i = 1; i < insertion.n; i++) {
        for (int j = i; j > 0; j--) {
            insertion.comparacoes++;
            if (insertion.array[j] < insertion.array[j-1]) {
                // swap
                aux = insertion.array[j];
                insertion.array[j] = insertion.array[j-1];
                insertion.array[j-1] = aux;
                insertion.trocas++;            
            }
        }
    }
}

int main() {
    const int TAMANHO = 20000;
    sort_data insertion;
    insertion.n = TAMANHO;
    insertion.trocas = 0;
    insertion.comparacoes = 0;
    
    // preencher o vetor com números de 1 a TAMANHO
    insertion.array.resize(TAMANHO);
    iota(insertion.array.begin(), insertion.array.end(), 1);
    
    // embaralhar o vetor para ter uma ordem aleatória
    random_device rd;
    mt19937 gen(rd());
    shuffle(insertion.array.begin(), insertion.array.end(), gen);
    
    // --- MEDIÇÃO DO TEMPO ---
    
    auto inicio = high_resolution_clock::now(); // captura o tempo inicial
    
    // chamada da função de ordenação
    insertion_sort(insertion);
    
    // captura o tempo final
    auto fim = high_resolution_clock::now();
    
    // calcula a diferença de tempo
    std::chrono::duration<double> duracao = fim - inicio;
    double tempo_execucao = duracao.count();   
    
    // --- FIM DA MEDIÇÃO ---
   
   
    
    cout << "Comparações: " << insertion.comparacoes << endl;
    cout << "Trocas: " << insertion.trocas << endl;
    cout << "Tempo gasto: " << tempo_execucao << " segundos" << endl;
    
    return 0;
}