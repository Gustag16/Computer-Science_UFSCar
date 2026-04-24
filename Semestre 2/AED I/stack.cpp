#include <iostream>

using namespace std;

// Classe Node para representar cada elemento da pilha
class Node {
public:
    int data;
    Node* next;
    
    Node(int valor) {
        data = valor;
        next = nullptr;
    }
};

// Classe Pilha implementada com lista encadeada
class Pilha {
    private:
        Node* top_node;
    public:
        Pilha() {
            top_node = nullptr;
        }
        
        void push(int value) {
            Node* new_node = new Node(value);
            new_node->next = top_node;
            top_node = new_node;
        }
        
        void pop() {
            if (!is_empty()) {
                Node* temp = top_node;
                top_node = top_node->next;
                delete temp;
            }
        }
        
        int top() {
            if (!is_empty()) {
                return top_node->data;
            }
            return -1; // retorno padrão se a pilha estiver vazia
        }
        
        bool is_empty() {
            return top_node == nullptr;
        }
        
        // destrutor para liberar memória
        ~Pilha() {
            while (!is_empty()) {
                pop();
            }
        }
};

int main() {
    int prices_A[] = {5, 2, 9, 4, 6, 3, 1, 2, 4};
    int prices_B[] = {2, 6, 9, 7, 2, 5, 1, 4, 2, 5, 3};
    int budget = 20;
    
    int size_A = sizeof(prices_A) / sizeof(prices_A[0]);
    int size_B = sizeof(prices_B) / sizeof(prices_B[0]);

    Pilha pilha_A;
    Pilha pilha_B;

    // preenche as pilhas (o último elemento do array será o topo)
    for (int i = size_A - 1; i >= 0; i--) {
        pilha_A.push(prices_A[i]);
    }
    for (int i = size_B - 1; i >= 0; i--) {
        pilha_B.push(prices_B[i]);
    }

    int total_cost = 0;
    int item_counter = 0;

    while ((!pilha_A.is_empty() || !pilha_B.is_empty()) && total_cost <= budget) {
        int cost_A = pilha_A.is_empty() ? budget + 1 : pilha_A.top();
        int cost_B = pilha_B.is_empty() ? budget + 1 : pilha_B.top();
        int min_cost;

        if (cost_A <= cost_B) {
            min_cost = cost_A;
            pilha_A.pop();
        } else {
            min_cost = cost_B;
            pilha_B.pop();
        }

        // incrementa o preço total e o contador de itens se estiver dentro do orçamento
        if (total_cost + min_cost <= budget) {
            total_cost += min_cost;
            item_counter++;
        } else {
            break;
        }
    }

    cout << "Número máximo de itens que podem ser comprados: " << item_counter << endl;

    return 0;
}