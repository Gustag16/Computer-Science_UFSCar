#include <iostream>
#include <string>

using namespace std;

struct Registro {
    int id; // chave única
    string nome;
    int idade;

    Registro* left;
    Registro* right;

    // construtor para facilitar a criação de nós
    Registro(int _id, string _nome, int _idade) : id(_id), nome(_nome), idade(_idade), left(nullptr), right(nullptr) {}
};

class ArvoreBinariaBusca {
private:
    Registro* raiz;

    // funções private para proteção

    // função auxiliar para calcular o máximo entre dois inteiros
    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    // inserção usando recursão
    Registro* inserir_registro(Registro* node, int id, string nome, int idade) {
        if (node == nullptr) {
            return new Registro(id, nome, idade);
        }

        if (id < node->id) {
            node->left = inserir_registro(node->left, id, nome, idade);
        } 
        else if (id > node->id) {
            node->right = inserir_registro(node->right, id, nome, idade);
        }
        // se id for igual, não insere duplicatas (regra padrão de BST)
        return node;
    }

    // busca usando recursão
    Registro* buscar_registro(Registro* node, int id) {
        if (node == nullptr || node->id == id) {
            return node;
        }
        if (id < node->id) {
            return buscar_registro(node->left, id);
        }
        return buscar_registro(node->right, id);
    }

    // encontrar o menor valor (auxiliar para remoção)
    Registro* find_min(Registro* node) {
        Registro* atual = node;
        while (atual && atual->left != nullptr) {
            atual = atual->left;
        }
        return atual;
    }

    // remoção usando recursão
    Registro* remover_registro(Registro* node, int id) {
        if (node == nullptr) {
            return node;
        }
        // navegação até o nó
        if (id < node->id) {
            node->left = remover_registro(node->left, id);
        } 
        else if (id > node->id) {
            node->right = remover_registro(node->right, id);
        } 
        else {
            // nó encontrado - tratamento dos 3 casos:
            // caso 1: sem filhos
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // caso 2: um filho
            else if (node->left == nullptr) { // se filho a direita
                Registro* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == nullptr) { // se filho a esquerda
                Registro* temp = node->left;
                delete node;
                return temp;
            }
            // caso 3: dois filhos
            else {
                // encontrar o sucessor (menor nó da subárvore direita)
                Registro* temp = find_min(node->right);
                
                // copiar os dados do sucessor para este nó
                node->id = temp->id;
                node->nome = temp->nome;
                node->idade = temp->idade;

                // remover o sucessor antigo
                node->right = remover_registro(node->right, temp->id);
            }
        }
        return node;
    }

    // percurso em ordem (crescente)
    void listar_em_ordem(Registro* node) {
        if (node != nullptr) {
            listar_em_ordem(node->left);
            cout << "ID: " << node->id << " | Nome: " << node->nome << endl;
            listar_em_ordem(node->right);
        }
    }

    // percurso reverso (decrescente)
    void listar_decrescente(Registro* node) {
        if (node != nullptr) {
            listar_decrescente(node->right); // direita primeiro para decrescente
            cout << "ID: " << node->id << " | Nome: " << node->nome << endl;
            listar_decrescente(node->left);
        }
    }

    // visualização hierárquica da árvore
    // prefixo: string que carrega o desenho das linhas verticais das gerações anteriores
    // eh_ultimo: indica se o nó é o filho da direita (fecha o galho) ou esquerda (continua)
    void visualizar_arvore(Registro* node, string prefixo, bool eh_ultimo) {
        if (node == nullptr) return;

        cout << prefixo;

        // desenha a conexão: |-- para ramos intermediários, \-- para o último ramo
        if (eh_ultimo) {
            cout << "\\-- "; 
            prefixo += "    "; // o último filho não propaga a barra vertical
        } 
        else {
            cout << "|-- "; 
            prefixo += "|   "; // Filhos intermediários propagam a barra vertical
        }

        cout << node->id << endl;

        // lógica para os filhos:
        // se tiver ambos, o da esquerda NÃO é o último (precisa de |), o da direita É o último.
        // se tiver apenas um, ele é tratado como último para fechar o desenho.
        
        if (node->left != nullptr && node->right != nullptr) {
            visualizar_arvore(node->right, prefixo, false);
            visualizar_arvore(node->left, prefixo, true);
        } 
        else if (node->right != nullptr) {
            visualizar_arvore(node->right, prefixo, true);
        }
        else if (node->left != nullptr) {
            visualizar_arvore(node->left, prefixo, true);
        } 
    }

    // funções estatísticas

    // retornar altura usando recursão
    int altura_r(Registro* node) {
        if (node == nullptr) {
            return -1; // altura de árvore vazia é -1
        }    
        return 1 + maximo(altura_r(node->left), altura_r(node->right));
    }

    // retornar o número de nós usando recursão
    int contar_nodes_r(Registro* node) {
        if (node == nullptr) {
            return 0; // nenhum nó
        }
        // caso contário, passo recursivo para encontrar o número  
        return 1 + contar_nodes_r(node->left) + contar_nodes_r(node->right);
    }

    // retornar o número de folhas usando recursão
    int contar_folhas_r(Registro* node) {
        if (node == nullptr) {
            return 0; // nenhuma folha
        }    
        if (node->left == nullptr && node->right == nullptr) {
            return 1; // uma folha
        }
        // caso contrário, passo recursivo para encontrar o número
        return contar_folhas_r(node->left) + contar_folhas_r(node->right);
    }

    // verifica se a árvore está balanceada usando recursão
    bool esta_balanceado_r(Registro* node) {
        if (node == nullptr) {
            return true;
        }

        int altura_left = altura_r(node->left);
        int altura_right = altura_r(node->right);
        
        // está balanceada se a diferença de altura entre esquerda e direita é menor ou igual a 1
        if (abs(altura_left - altura_right) <= 1 
            && esta_balanceado_r(node->left) 
            && esta_balanceado_r(node->right)) {
                return true;
        }
        return false;
    }

public:
    // métodos públicos para acesso aos dados da classe

    ArvoreBinariaBusca() : raiz(nullptr) {}

    void InserirRegistro(int id, string nome, int idade) {
        raiz = inserir_registro(raiz, id, nome, idade);
    }

    void RemoverRegistro(int id) {
        raiz = remover_registro(raiz, id);
    }

    Registro* BuscarRegistro(int id) {
        return buscar_registro(raiz, id);
    }

    void ListarEmOrdem() {
        cout << "\nListagem em ordem crescente" << endl;
        listar_em_ordem(raiz);
    }

    void ListarDecrescente() {
        cout << "\nlistagem decrescente" << endl;
        listar_decrescente(raiz);
    }

    void VisualizarArvore() {
        cout << "\n- Visualizacao da arvore -" << endl;

        if (raiz == nullptr) {
            cout << "(arvore vazia)" << endl;
            return;
        }
        
        // imprime a raiz isolada primeiro para iniciar a estrutura
        cout << raiz->id << endl;
        
        // inicia a recursão para os filhos da raiz
        if (raiz->left != nullptr && raiz->right != nullptr) {
            visualizar_arvore(raiz->right, "", false);
            visualizar_arvore(raiz->left, "", true);
        } 
        else if (raiz->right != nullptr) {
            visualizar_arvore(raiz->right, "", true);
        }
        else if (raiz->left != nullptr) {
            visualizar_arvore(raiz->left, "", true);
        } 
    }

    void RelatorioEstatistico() {
        cout << "\n- Relatorio estatistico -" << endl;
        cout << "Altura da arvore: " << altura_r(raiz) << endl;
        cout << "Numero total de registros: " << contar_nodes_r(raiz) << endl;
        cout << "Numero de folhas: " << contar_folhas_r(raiz) << endl;
        cout << "Esta balanceada? " << (esta_balanceado_r(raiz) ? "Sim" : "Nao") << endl;
    }
};

int main() {
    ArvoreBinariaBusca arvore;

    // 1 e 2. inserção dos registros conforme o roteiro de testes
    cout << "Inserindo registros..." << endl;
    arvore.InserirRegistro(16, "Alex", 18);
    arvore.InserirRegistro(8, "Ana", 15);
    arvore.InserirRegistro(24, "Bruno", 21);
    arvore.InserirRegistro(4, "Maria", 17);
    arvore.InserirRegistro(12, "Lucas", 28);
    arvore.InserirRegistro(20, "Isabela", 18);
    arvore.InserirRegistro(28, "Rafael", 14);
    arvore.InserirRegistro(2, "Laura", 25);
    arvore.InserirRegistro(6, "Pedro", 18);
    arvore.InserirRegistro(10, "Sofia", 17);
    arvore.InserirRegistro(14, "Gabriel", 19);
    arvore.InserirRegistro(18, "Helena", 20);
    arvore.InserirRegistro(22, "Arthur", 18);
    arvore.InserirRegistro(26, "Beatriz", 16);
    arvore.InserirRegistro(30, "Mateus", 19);
    arvore.InserirRegistro(5, "Alice", 17);
    arvore.InserirRegistro(17, "Davi", 18);
    arvore.InserirRegistro(19, "Livia", 21);

    // 3. listar em ordem e ordem reversa
    arvore.ListarEmOrdem();
    arvore.ListarDecrescente();

    // 4. visualizar a árvore inicial
    arvore.VisualizarArvore();

    // 5. relatório estatístico inicial
    arvore.RelatorioEstatistico();

    // 6. remover nós com ID 8, 24, 4 e 30
    cout << "\n(Removendo registros 8, 24, 4, 30)" << endl;
    arvore.RemoverRegistro(8);
    arvore.RemoverRegistro(24);
    arvore.RemoverRegistro(4);
    arvore.RemoverRegistro(30);

    // 7. relatório estatístico após remoções
    arvore.RelatorioEstatistico();

    // 8. visualizar a árvore final
    arvore.VisualizarArvore();

    return 0;
}