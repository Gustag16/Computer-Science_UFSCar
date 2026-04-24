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

void bubble_sort(sort_data& bubble) {
    int aux;
    for (int i = 0; i < bubble.n - 1; i++) {
        for (int j = 0; j < bubble.n - i - 1; j++) {
            bubble.comparacoes++;
            if (bubble.array[j] > bubble.array[j+1]) {
                // swap
                aux = bubble.array[j];
                bubble.array[j] = bubble.array[j+1];
                bubble.array[j+1] = aux;
                bubble.trocas++;
            }
        }
    }
}

int main() {
    sort_data bubble = {
        vector<int>(20000),  
        20000,
        0,
        0
    };
    
    // randomizar as alturas dos copos
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // copos entre 1 e 20 cm
    uniform_int_distribution<int> dist(1, 20);
    
    for (int i = 0; i < bubble.n; i++) {
        bubble.array[i] = dist(gen);
    }
    
    // --- MEDIÇÃO DO TEMPO ---
    
    auto inicio = high_resolution_clock::now(); // captura o tempo inicial
    
    // chamada da função de ordenação
    bubble_sort(bubble);
    
    // captura o tempo final
    auto fim = high_resolution_clock::now();
    
    // calcula a diferença de tempo
    std::chrono::duration<double> duracao = fim - inicio;
    double tempo_execucao = duracao.count();   
    
    // --- FIM DA MEDIÇÃO ---
    
    cout << "Comparações: " << bubble.comparacoes << endl;
    cout << "Trocas: " << bubble.trocas << endl;
    cout << "Tempo gasto: " << tempo_execucao << " segundos" << endl;
    
    return 0;
}