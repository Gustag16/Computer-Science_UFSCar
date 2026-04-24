#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

// função auxiliar para criar nós (apenas para as listas do exercício)
Node* add_tail(int val) {
    Node* temp = new Node;
    temp->value = val;
    temp->next = nullptr;
    return temp;
}

// função que vai mesclar as duas listas
Node* intercalarListas(Node* L1, Node* L2) {

    Node sentinela;
    sentinela.next = nullptr;
    
    // 'tail' sempre apontará para o último nó adicionado na nova lista ordenada
    Node* tail = &sentinela;
    
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->value < L2->value) {
            // se L1 é menor, anexamos L1 ao final da nova lista
            tail->next = L1;
            tail = L1; // atualizamos o tail
            L1 = L1->next; // avançamos L1
        } 
        else if (L2->value < L1->value) {
            // se L2 é menor, anexamos L2
            tail->next = L2;
            tail = L2;
            L2 = L2->next;
        } 
        else { 
            // caso duplicatas            
            tail->next = L1; // anexa L1
            tail = L1;
            L1 = L1->next; // avança L1
            
            // tratamento do nó duplicado em L2:
            Node* duplicado = L2;
            L2 = L2->next; // avança L2 para não perder a referência
            delete duplicado; // remove o nó extra da memória
        }
    }
    
    // após o loop, uma das listas pode ainda ter elementos.
    // como estão ordenados, basta "colar" o restante no final.
    if (L1 != nullptr) {
        tail->next = L1;
    } 
    else if (L2 != nullptr) {
        tail->next = L2;
    }
    
    // retorna o início da lista (o próximo do nó sentinela)
    return sentinela.next;
}

void imprime_lista(Node* head) {
    while (head != nullptr) {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "nil" << endl;
}

int main() {
    // construindo L1
    Node* L1 = add_tail(1);
    L1->next = add_tail(3);
    L1->next->next = add_tail(5);
    L1->next->next->next = add_tail(7);
    L1->next->next->next->next = add_tail(9);
    L1->next->next->next->next->next = add_tail(10);
    L1->next->next->next->next->next->next = add_tail(11);

    // construindo L2
    Node* L2 = add_tail(2);
    L2->next = add_tail(3);
    L2->next->next = add_tail(4);
    L2->next->next->next = add_tail(6);
    L2->next->next->next->next = add_tail(8);
    L2->next->next->next->next->next = add_tail(10);
    L2->next->next->next->next->next->next = add_tail(12);

    // chamada da função
    Node* L = intercalarListas(L1, L2);

    imprime_lista(L);

    return 0;
}