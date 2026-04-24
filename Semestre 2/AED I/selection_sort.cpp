#include <iostream>
#include <vector>

using namespace std;

struct sort_data {
    vector<int> array;
    int n;
    int trocas;
    int comparacoes;
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
    sort_data selection;
    
    selection.array = {29, 10, 14, 37, 14};
    selection.n = 5;
    selection.trocas = 0;
    selection.comparacoes = 0;
    
    // chamada da função de ordenação
    selection_sort(selection);
    
    // printar o vetor ordenado
    for (int i = 0; i < selection.n; i++) {
        cout << selection.array[i] << " ";
    }
    cout << "\n";
    
    cout << "Comparações: " << selection.comparacoes << endl;
    cout << "Trocas: " << selection.trocas << endl;
    
    return 0;
}