#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int valor) {
        data = valor;
        next = nullptr;
    }
};

// classe Pilha implementada com lista encadeada
class Pilha {
    private:
        Node* top_node;
        int tamanho_pilha;
    public:
        Pilha() {
            top_node = nullptr;
            tamanho_pilha = 0;
        }
        
        void push(int value) {
            Node* new_node = new Node(value);
            new_node->next = top_node;
            top_node = new_node;
            tamanho_pilha++;
        }
        
        void pop() {
            if (!is_empty()) {
                Node* temp = top_node;
                top_node = top_node->next;
                delete temp;
                tamanho_pilha--;
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

        int size() {
        return tamanho_pilha;
        }
        
        // destrutor para liberar memória
        ~Pilha() {
            while (!is_empty()) {
                pop();
            }
        }
};

// implementação da fila
class Queue {
private:
    Node* front_node;
    Node* rear_node;
    int queue_size;
    
public:
    Queue() {
        front_node = nullptr;
        rear_node = nullptr;
        queue_size = 0;
    }
    
    void enqueue(int valor) {
        Node* new_node = new Node(valor);
        if (is_empty()) {
            front_node = new_node;
            rear_node = new_node;
        } else {
            rear_node->next = new_node;
            rear_node = new_node;
        }
        queue_size++;
    }
    
    void dequeue() {
        if (!is_empty()) {
            Node* temp = front_node;
            front_node = front_node->next;
            if (front_node == nullptr) {
                rear_node = nullptr;
            }
            delete temp;
            queue_size--;
        }
    }
    
    int front() {
        if (!is_empty()) {
            return front_node->data;
        }
        return -1;
    }
    
    bool is_empty() {
        return front_node == nullptr;
    }
    
    int size() {
        return queue_size;
    }
    
    ~Queue() {
        while (!is_empty()) {
            dequeue();
        }
    }
};

int main() {
    int ferramentas[] = {1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1}; // base -> topo
    int trabalhadores[] = {1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1}; // início -> fim
    
    int n = sizeof(ferramentas) / sizeof(ferramentas[0]);
    
    // criar pilha de ferramentas
    Pilha pilha_ferramentas;
    // empilhar do último para o primeiro para manter a ordem correta
    for (int i = n - 1; i >= 0; i--) {
        pilha_ferramentas.push(ferramentas[i]);
    }
    
    // criar fila de trabalhadores
    Queue fila_trabalhadores;
    for (int i = 0; i < n; i++) {
        fila_trabalhadores.enqueue(trabalhadores[i]);
    }
    
    // distribuição
    int tentativas_sem_sucesso = 0;
    
    while (!pilha_ferramentas.is_empty() && tentativas_sem_sucesso < fila_trabalhadores.size()) {
        int ferramenta_top = pilha_ferramentas.top();
        int trabalhador_front = fila_trabalhadores.front();
        
        if (ferramenta_top == trabalhador_front) {
            // trabalhador pega a ferramenta
            pilha_ferramentas.pop();
            fila_trabalhadores.dequeue();
            tentativas_sem_sucesso = 0; // reset do contador
        } else {
            // trabalhador vai para o final da fila
            fila_trabalhadores.dequeue();
            fila_trabalhadores.enqueue(trabalhador_front);
            tentativas_sem_sucesso++;
        }
    }
    
    // resultado: número de ferramentas que sobraram (equivalente aos trabalhadores sem ferramenta)
    int resultado = pilha_ferramentas.size();
    
    cout << "Número de trabalhadores que não conseguiram pegar ferramentas: " << resultado << endl;
    
    return 0;
}