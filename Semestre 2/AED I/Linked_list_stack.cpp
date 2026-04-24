#include <iostream>
#include <string>
#include <vector>

using namespace std;

// definição do nó
struct Node {
    int id;
    string data;
    Node* next; // ponteiro que liga este nó ao próximo
};

struct pilha {
    Node* dado;
    pilha* abaixo; // aponta para o elemento abaixo da pilha
};

class Pilha {
    private:
        pilha* top;

    public:
        Pilha() {
            top = nullptr;
        }

        ~Pilha() {
            while (!is_empty())
                pop();
        }

        void push(Node* node) {
            pilha* novo = new pilha;
            novo->dado = node;
            novo->abaixo = top; // o novo aponta para o antigo topo
            top = novo; // o topo agora é o novo
        }

        void pop() {
            if (is_empty()) {
                return;
            }
            pilha* temp = top;
            top = top->abaixo; // o topo desce um nível
            delete temp;
        }

        Node* peek() {
            if (is_empty()) {
                return nullptr;
            }    
            return top->dado;
        }

        bool is_empty() {
            return (top == nullptr);
        }
};

// função auxiliar para criar nós
void add_tail(Node* &head, int id, string data) {
    // cria um novo nó
    Node* new_node = new Node;
    new_node->id = id;
    new_node->data = data;
    new_node->next = nullptr; // como será o último, aponta para null

    // se a lista estiver vazia, o novo nó vira a cabeça
    if (head == nullptr) {
        head = new_node;
    } 
    else {
        // se não, percorre até achar o último nó atual
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // o antigo último nó agora aponta para o novo nó recém-criado
        temp->next = new_node;
    }
}

// função de inversão usando pilha
Node* inverterLista_S(Node* L) {
    // se a lista estiver vazia, não há o que inverter
    if (L == nullptr) {
        return nullptr;
    }
    // criar uma stack para armazenar os ponteiros dos nós
    Pilha stack;
    
    // encher a pilha com todos os nós da lista, percorrendo ela inteira
    Node* temp = L;
    while (temp != nullptr) {
        stack.push(temp);
        temp = temp->next;
    }

    // definir a nova cabeça da lista (topo da pilha)
    Node* new_head = stack.peek();
    stack.pop(); // remover o nó do topo

    // reconstruir as ligações usando a ordem da pilha
    Node* current = new_head;

    while (!stack.is_empty()) {
        // o próximo do current será o que está no topo da pilha agora
        current->next = stack.peek();
        // removemos da pilha
        stack.pop();
        // avançamos o ponteiro 'current' para o nó que acabamos de pegar
        current = current->next;
    }

    // evitar que o último nó da nova lista ainda aponte para o segundo nó original
    current->next = nullptr;

    return new_head;
}

void imprime_lista(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "(" << temp->id << ", " << temp->data << ") -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* L = nullptr;

    // construindo a lista dado o exemplo do exercicio
    add_tail(L,12,"vida adulta");
    add_tail(L,11,"trabalho");
    add_tail(L,10,"faculdade");
    add_tail(L,9,"ensino medio");
    add_tail(L,8,"amizade");
    add_tail(L,7,"adolescencia");
    add_tail(L,6,"ensino fundamental");
    add_tail(L,5,"natal");
    add_tail(L,4,"praia");
    add_tail(L,3,"infancia");
    add_tail(L,2,"pai");
    add_tail(L,1,"mae");

    // chamada da função de inversão com pilha
    L = inverterLista_S(L);

    imprime_lista(L);

    // limpar memória
    while (L != nullptr) {
        Node* lixo = L;
        L = L->next;
        delete lixo;
    }

    return 0;
}