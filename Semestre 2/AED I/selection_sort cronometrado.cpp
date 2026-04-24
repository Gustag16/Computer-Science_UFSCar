#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

struct sort_data {
    vector<int> array;
    int n;
    long int trocas;
    long int comparacoes;
};

void selection_sort(sort_data& selection) {
    int aux;
    int menor;
    for (int i = 0; i < selection.n - 1; i++) {
        menor = i;
        for (int j = i+1; j < selection.n; j++) {
            selection.comparacoes++;
            if (selection.array[j] < selection.array[menor]) {
                menor = j;
            }
        }
            
        // swap
        if (menor != i) {
            aux = selection.array[i];
            selection.array[i] = selection.array[menor];
            selection.array[menor] = aux;
            selection.trocas++;
        }
        
    }
}

int main() {
    sort_data selection = {
        vector<int>(20000),  
        20000,
        0,
        0
    };
    
    // randomizar as alturas dos copos
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // lances entre 1 e 1000000
    uniform_int_distribution<int> dist(1, 1000000);
    
    for (int i = 0; i < selection.n; i++) {
        selection.array[i] = dist(gen);
    }
    
    // --- MEDIÇÃO DO TEMPO ---
    
    auto inicio = high_resolution_clock::now(); // captura o tempo inicial
    
    // chamada da função de ordenação
    selection_sort(selection);
    
    // captura o tempo final
    auto fim = high_resolution_clock::now();
    
    // calcula a diferença de tempo
    std::chrono::duration<double> duracao = fim - inicio;
    double tempo_execucao = duracao.count();   
    
    // --- FIM DA MEDIÇÃO ---
    
    cout << "Comparações: " << selection.comparacoes << endl;
    cout << "Trocas: " << selection.trocas << endl;
    cout << "Tempo gasto: " << tempo_execucao << " segundos" << endl;
    
    return 0;
}