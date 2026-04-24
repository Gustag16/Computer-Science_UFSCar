#include <iostream>
#include <string>

using namespace std;

// definição do nó
struct Node {
    int id;
    string data;
    Node* next;
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

// função de inversão recursiva
Node* inverterLista_R(Node* L) {
    // CASO BASE
    // se a lista for vazia ou se chegamos no último nó, L será a nova cabeça
    if (L == nullptr || L->next == nullptr) {
        return L;
    }

    // PASSO RECURSIVO
    // invertemos o resto da lista (do próximo em diante)
    // 'new_head' vai receber o último elemento da lista original e vai "borbulhar" ela de volta até o topo da recursão.
    Node* new_head = inverterLista_R(L->next);

    // passo de retorno
    L->next->next = L;

    // o nó atual agora é o último dessa sub-lista, então deve apontar para NULL
    L->next = nullptr;

    // retornamos a nova cabeça
    return new_head;
}

void imprime_lista(Node* cabeca) {
    Node* temp = cabeca;
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

    // chamada da função de inversão com recursão
    L = inverterLista_R(L);

    imprime_lista(L);

    // limpar memória
    while (L != nullptr) {
        Node* lixo = L;
        L = L->next;
        delete lixo;
    }

    return 0;
}