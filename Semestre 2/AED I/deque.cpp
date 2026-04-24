#include <iostream>

using namespace std;

class Node {
public:
    int data;
    int index;
    Node* prev;
    Node* next;
    
    Node(int valor, int idx) {
        data = valor;
        index = idx;
        prev = nullptr;
        next = nullptr;
    }
};

// implementação da dupla fila
class Deque {
private:
    Node* front_node;
    Node* rear_node;
    int deque_size;
    
public:
    Deque() {
        front_node = nullptr;
        rear_node = nullptr;
        deque_size = 0;
    }
    
    void push_front(int valor, int index) {
        Node* new_node = new Node(valor, index);
        if (is_empty()) {
            front_node = new_node;
            rear_node = new_node;
        } else {
            new_node->next = front_node;
            front_node->prev = new_node;
            front_node = new_node;
        }
        deque_size++;
    }
    
    void push_back(int valor, int index) {
        Node* new_node = new Node(valor, index);
        if (is_empty()) {
            front_node = new_node;
            rear_node = new_node;
        } else {
            new_node->prev = rear_node;
            rear_node->next = new_node;
            rear_node = new_node;
        }
        deque_size++;
    }
    
    void pop_front() {
        if (!is_empty()) {
            Node* temp = front_node;
            front_node = front_node->next;
            if (front_node != nullptr) {
                front_node->prev = nullptr;
            } else {
                rear_node = nullptr;
            }
            delete temp;
            deque_size--;
        }
    }
    
    void pop_back() {
        if (!is_empty()) {
            Node* temp = rear_node;
            rear_node = rear_node->prev;
            if (rear_node != nullptr) {
                rear_node->next = nullptr;
            } else {
                front_node = nullptr;
            }
            delete temp;
            deque_size--;
        }
    }
    
    int front_value() {
        if (!is_empty()) {
            return front_node->data;
        }
        return -1;
    }
    
    int front_index() {
        if (!is_empty()) {
            return front_node->index;
        }
        return -1;
    }
    
    int back_valor() {
        if (!is_empty()) {
            return rear_node->data;
        }
        return -1;
    }
    
    int back_index() {
        if (!is_empty()) {
            return rear_node->index;
        }
        return -1;
    }
    
    bool is_empty() {
        return front_node == nullptr;
    }
    
    int size() {
        return deque_size;
    }
    
    ~Deque() {
        while (!is_empty()) {
            pop_front();
        }
    }
};

int main() {
    int prices[] = {120, 100, 80, 90, 80, 95, 105, 100, 90, 80, 70, 90, 100, 115, 125, 110, 95, 90, 80, 100};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];
    
    Deque dq;
    
    // primeiro elemento sempre tem span = 1
    span[0] = 1;
    dq.push_front(prices[0], 0);
    
    for (int i = 1; i < n; i++) {
        // remove elementos do deque enquanto o preço atual for maior ou igual ao preço no topo
        while (!dq.is_empty() && prices[i] >= dq.front_value()) {
            dq.pop_front();
        }
        
        // se o deque estiver vazio, significa que todos os preços anteriores são menores ou iguais
        if (dq.is_empty()) {
            span[i] = i + 1;
        } 
        // caso contrário, o span é a diferença entre o índice atual e o índice do último preço maior
        else {
            span[i] = i - dq.front_index();
        }
        
        // adiciona o preço atual à deque
        dq.push_front(prices[i], i);
    }
    
    cout << "Preços das ações: ";
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;
    
    cout << "Intervalos (span): ";
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << endl;
    
    return 0;
}