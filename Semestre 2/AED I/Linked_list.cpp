#include <iostream>
#include <string>

using namespace std;

// definição do nó
struct Node {
    int id;
    string data;
    Node* next; // ponteiro que liga este nó ao próximo
};

// função auxiliar para criar nós
void add_tail(Node* &head, int id, string data) {
    // cria um novo nó na memória do computador
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

Node* inverterLista(Node* L) {
    Node* prev = nullptr; // nó que ficou para trás
    Node* current = L; // nó que estamos tratando agora
    Node* prox = nullptr; // nó que virá depois (para não perdermos a referência)

    while (current != nullptr) {
        prox = current->next; // salva quem é o próximo vizinho
        current->next = prev; // inverte a seta
        prev = current; // 'current' vira o 'prev' para a próxima rodada
        current = prox; // avança para o vizinho salvo
    }
    return prev;
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

    // chamada da função de inversão
    L = inverterLista(L);

    imprime_lista(L);

    // limpar memória
    while (L != nullptr) {
        Node* lixo = L;
        L = L->next;
        delete lixo;
    }

    return 0;
}