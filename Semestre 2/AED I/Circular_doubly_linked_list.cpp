#include <iostream>
#include <vector>

using namespace std;

// definição da estrutura do nó
struct Node {
    int id;
    Node* prev;
    Node* prox;
};

// função auxiliar para criar um novo nó
Node* criar_node(int valor) {
    Node* novo = new Node;
    novo->id = valor;
    novo->prev = nullptr;
    novo->prox = nullptr;
    return novo;
}

// função para inserir no final de uma lista circular (usada para montar o exemplo)
void add_tail(Node*& L, int valor) {
    Node* novo = criar_node(valor);
    
    if (L == nullptr) {
        L = novo;
        L->prox = L;
        L->prev = L;
    } 
    else {
        Node* tail = L->prev;
        
        tail->prox = novo;
        novo->prev = tail;
        novo->prox = L;
        L->prev = novo;
    }
}

void imprimirLista(Node* L) {
    if (L == nullptr) {
        return;
    }
    Node* current = L;
    cout << "[ ";
    do {
        cout << current->id;
        current = current->prox;
        if (current != L) {
            cout << " ] <-> [ ";
        }
    } while (current != L);
    cout << " ] <-> (volta para o [ " << current->id << " ])" << endl;
}

// função solicitada pelo exercício
Node* reorganizarLista(Node* L) {
    // se a lista estiver vazia ou tiver apenas 1 elemento, não há o que fazer
    if (L == nullptr || L->prox == L) {
        return L;
    }

    // ponteiros para gerenciar as duas sub-listas
    Node* impar_L = nullptr;
    Node* impar_tail = nullptr;
    Node* par_L = nullptr;
    Node* par_tail = nullptr;

    Node* current = L;
    bool primeira_passada = true;
    
    // percorrer a lista original
    Node* inicio = L; // precisamos salvar a referência do início para saber quando parar
    do {
        // salva o próximo nó antes de modificarmos o current
        Node* next_node = current->prox;

        // isola o nó current (limpa conexões antigas para evitar lixo)
        current->prox = nullptr;
        current->prev = nullptr;

        // verifica se é ímpar ou par
        if (current->id % 2 != 0) {
            // adiciona na lista de impares
            if (impar_L == nullptr) {
                impar_L = current;
                impar_tail = current;
            } 
            else {
                impar_tail->prox = current;
                current->prev = impar_tail;
                impar_tail = current;
            }
        } 
        else {
            // adiciona na lista de pares
            if (par_L == nullptr) {
                par_L = current;
                par_tail = current;
            } 
            else {
                par_tail->prox = current;
                current->prev = par_tail;
                par_tail = current;
            }
        }

        // avança para o próximo da lista original
        current = next_node;

    } while (current != inicio);

    // se só existem números pares
    if (impar_L == nullptr) {
        par_tail->prox = par_L;
        par_L->prev = par_tail;
        return par_L;
    }

    // se só existem números ímpares
    if (par_L == nullptr) {
        impar_tail->prox = impar_L;
        impar_L->prev = impar_tail;
        return impar_L;
    }

    // caso contrário (se ímpares e pares)
    // conecta o fim dos ímpares ao início dos pares
    impar_tail->prox = par_L;
    par_L->prev = impar_tail;
    // conecta o fim dos pares ao início dos ímpares
    par_tail->prox = impar_L;
    impar_L->prev = par_tail;
    // retorna a nova cabeça (início dos ímpares)
    return impar_L;
}

int main() {
    Node* lista = nullptr;

    // exemplo dado
    vector<int> valores = {4, 3, 2, 7, 8, 5, 6, 9};

    for (int v : valores) {
        add_tail(lista, v);
    }

    // chamada da função solicitada
    lista = reorganizarLista(lista);

    imprimirLista(lista);
  
    return 0;
}