/* ENUNCIADO:
Classe de compras, que tem um vetor alocado dinamicamente que representam os itens comprados
Cada compra deve ter um id único e constante
Deve ser possível obter: tamanho, id, e um item dado sua posição, alem de uma funcao para printar a compra

Ao criar uma compra, enviando o n° de itens é possivel detalhar item a item
Também deve ser possivel criar uma compra sem passar um tamanho, nesse caso o tamanho padrao = 1

Deve ser possível alterar um item de um pedido, de uma posição especifica
*/

#include <iostream>

using namespace std;

class compras {
    public:
        compras(int _tamanho); // construtor
        ~compras(); // destrutor

        // métodos set
        bool set_tamanho(int _tamanho);
        bool set_item(int posicao, string _item);

        // métodos get
        int get_tamanho() const;
        string get_item(int posicao) const;
        int get_id() const;

        void print(int posicao) const;

    private:
        const int id;
        string *ptr_itens;
        int tamanho;
        static int compra;
};

int compras::compra = 0;

// construtor
compras::compras(int _tamanho):id(++compra) {
    set_tamanho(_tamanho);
    ptr_itens = new string[_tamanho];
}

// destrutor
compras::~compras() {
    delete [] ptr_itens;
}

// métodos set
bool compras::set_tamanho(int _tamanho) {
    if (_tamanho >= 0) {
        tamanho = _tamanho;
        return true;
    }
    else
        return false;
}

bool compras::set_item(int posicao, string _item) {
    if (posicao >= 0) {
        ptr_itens[posicao] = _item;
        return true;
    }
    else
        return false;
}

// métodos get
int compras::get_tamanho() const {
    return tamanho;
}

string compras::get_item(int posicao) const {
    return ptr_itens[posicao];
}

int compras::get_id() const {
    return id;
}

void compras::print(int posicao) const {
    cout << "Item da posição " << posicao << ": " << ptr_itens[posicao] << endl;
}

int main() {
    compras compra1(4);

    compra1.set_item(0, "Arroz");
    compra1.set_item(1, "Feijão");
    compra1.set_item(2, "Damasco");
    compra1.set_item(3, "Vinho");

    compra1.print(0);
    compra1.print(1);
    compra1.print(2);
    compra1.print(3);

    return 0;
}