#include <iostream>

using namespace std;

class FilaPrioridades {

    private:

        int* elementos;
        int tamanho;
        int capacidade;

        void garantir_capacidade() {
            if (tamanho == capacidade) {
                // se o array está cheio, crie um novo com o dobro da capacidade
                int nova_capacidade = (capacidade == 0) ? 10 : capacidade * 2;
                int* novo_array = new int[nova_capacidade];

                // copiar elementos antigos para o novo array
                for (int i = 0; i < tamanho; ++i) {
                    novo_array[i] = elementos[i];
                }

                // deletar o array antigo e atualizar os ponteiros/valores
                delete[] elementos;
                elementos = novo_array;
                capacidade = nova_capacidade;
            }
        }

    public:

        FilaPrioridades() {
            capacidade = 10; // capacidade inicial
            tamanho = 0;
            elementos = new int[capacidade];
        }

        ~FilaPrioridades() {
            delete[] elementos;
        }

        bool is_empty() const {
            return tamanho == 0;
        }

        int size() const {
            return tamanho;
        }

        void enqueue(int valor) {
            garantir_capacidade(); // garante que há espaço
            elementos[tamanho] = valor;
            tamanho++;
        }

        int dequeue() {
            if (is_empty()) {
                cout << "Erro: Fila de prioridades está vazia." << endl;
                return 0; 
            }

            // 1. Encontrar o índice do menor elemento
            int min_val = elementos[0];
            int min_index = 0;
            for (int i = 1; i < tamanho; ++i) {
                if (elementos[i] < min_val) {
                    min_val = elementos[i];
                    min_index = i;
                }
            }

            // 2. Remover o elemento "deslocando" todos os elementos subsequentes uma posição para a esquerda
            for (int i = min_index; i < tamanho - 1; ++i) {
                elementos[i] = elementos[i + 1];
            }

            // 3. Decrementar o tamanho e retornar o valor
            tamanho--;
            return min_val;
        }
};

int main() {
    int L[] = {20, 13, 15, 10, 19, 11, 8, 14, 17, 2, 9, 3, 18, 1, 16, 4, 12, 7, 5, 6};
    int n = 20;

    FilaPrioridades pq;

    // 1. Inserir todos os comprimentos na fila de prioridades
    for (int i = 0; i < n; ++i) {
        pq.enqueue(L[i]);
    }

    long long custo_total = 0;

    // 2. Iterar até que apenas uma corda permaneça
    while (pq.size() > 1) {
        // remover as duas menores cordas
        int corda_1 = pq.dequeue();
        int corda_2 = pq.dequeue();

        // calcular o custo e adicionar ao total
        int custo_atual = corda_1 + corda_2;
        custo_total += custo_atual;

        // inserir a corda combinada de volta
        pq.enqueue(custo_atual);
    }

    cout << "O custo total obtido é: " << custo_total << endl;

    return 0;
}
