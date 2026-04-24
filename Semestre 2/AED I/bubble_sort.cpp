#include <iostream>
#include <vector>

using namespace std;

struct sort_data {
    vector<int> array;
    int n;
    int trocas;
    int comparacoes;
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
    sort_data bubble;
    
    bubble.array = {4, 3, 2, 1};
    
    bubble.n = 20000;
    bubble.trocas = 0;
    bubble.comparacoes = 0;
    
    // chamada da função de ordenação
    bubble_sort(bubble);
    
    // printar o vetor ordenado
    for (int i = 0; i < bubble.n; i++) {
        cout << bubble.array[i] << " ";
    }
    cout << "\n";
    
    cout << "Comparações: " << bubble.comparacoes << endl;
    cout << "Trocas: " << bubble.trocas << endl;
    
    return 0;
}