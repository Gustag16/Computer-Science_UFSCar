#include <iostream>

using namespace std;

// definição da estrutura da lista original (L)
struct NodeL {
    int valor;
    NodeL* prev;
    NodeL* prox;
};

// definição da estrutura da lista compactada (C)
struct NodeC {
    int key;
    int count;
    NodeC* prev;
    NodeC* prox;
};

// função solicitada
NodeC* compactarLista(NodeL* L_head) {
    // inicializa a cabeça da lista C como vazia
    NodeC* C_head = nullptr;

    // ponteiro para percorrer a lista L
    NodeL* L_current = L_head;

    while (L_current != nullptr) {
        int val = L_current->valor;

        // procurar onde inserir ou atualizar na lista C, que deve ser mantida ordenada.
        NodeC* C_current = C_head;
        NodeC* C_prev = nullptr;

        // percorre C enquanto não chegar ao fim e o valor da chave for menor que o valor atual
        while (C_current != nullptr && C_current->key < val) {
            C_prev = C_current;
            C_current = C_current->prox;
        }

        // se encontramos o nó com a mesma chave
        if (C_current != nullptr && C_current->key == val) {
            C_current->count++; // apenas incrementa a contagem
        }
        // se não, precisamos criar um novo nó, já que ele não existe em C ainda
        else {
            NodeC* new_node = new NodeC; // aloca novo nó dinamicamente
            new_node->key = val;
            new_node->count = 1;
            new_node->prox = nullptr;
            new_node->prev = nullptr;

            // se a inserção ocorre no início da lista C
            if (C_prev == nullptr) {
                new_node->prox = C_head;
                if (C_head != nullptr) {
                    C_head->prev = new_node;
                }
                C_head = new_node; // atualiza a cabeça da lista C
            }
            // se a inserção ocorre no meio ou no fim (entre C_prev e C_current)
            else {
                new_node->prox = C_current;
                new_node->prev = C_prev;
                C_prev->prox = new_node;
                
                if (C_current != nullptr) {
                    C_current->prev = new_node;
                }
            }
        }

        // avança para o próximo nó da lista original L
        L_current = L_current->prox;
    }

    return C_head;
}

// função auxiliar para criar nós (apenas para a lista L)
void add_head(NodeL* &head, int value) {
    NodeL* new_node = new NodeL;
    new_node->valor = value;
    new_node->prox = head;
    new_node->prev = nullptr;
    if (head != nullptr) {
        head->prev = new_node;
    }
    head = new_node;
}

// função para imprimir a lista C
void imprime_lista(NodeC* node) {
    while (node != nullptr) {
        cout << "(" << node->key << ", " << node->count << ")";
        if (node->prox != nullptr) {
            cout << " <-> ";
        }    
        node = node->prox;
    }
    cout << " <-> NIL" << endl;
}

int main() {
    NodeL* listaL = nullptr;

    // lista do exemplo
    int valores[] = {5, 3, 1, 4, 2, 3, 2, 2, 5, 5, 3, 1, 3, 2, 4, 1, 2, 4};
    int n = sizeof(valores)/sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        add_head(listaL, valores[i]);
    }

    // chamada da função solicitada
    NodeC* listaC = compactarLista(listaL);

    imprime_lista(listaC);

    return 0;
}