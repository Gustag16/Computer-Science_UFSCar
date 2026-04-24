#include <iostream>
#include <vector>

using namespace std;

struct sort_data {
    vector<int> array;
    int n;
    int trocas;
    int comparacoes;
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
    sort_data insertion;
    
    insertion.array = {7, 4, 5, 2};
    insertion.n = 4;
    insertion.trocas = 0;
    insertion.comparacoes = 0;
    
    // chamada da função de ordenação
    insertion_sort(insertion);
    
    // printar o vetor ordenado
    for (int i = 0; i < insertion.n; i++) {
        cout << insertion.array[i] << " ";
    }
    cout << "\n";
    
    cout << "Comparações: " << insertion.comparacoes << endl;
    cout << "Trocas: " << insertion.trocas << endl;
    
    return 0;
}