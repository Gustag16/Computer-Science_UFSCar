#include <iostream>

using namespace std;

class Pedido {
    public:
        Pedido(string _nome, int _num_itens); // construtor (aloc dinam)
        ~Pedido(); // destrutor (delete da aloc dinam)

        // Métodos set
        void set_nome(string _nome);
        void set_item(int posicao, string item); // void OU boolean
        // Métodos get
        int get_id() const;
        string get_nome() const;
        int get_num_itens() const;
        string get_item(int posicao) const; // string OU boolean + string por ref.
        static int get_contador_pedidos();
        static int get_total_itens();

    private:
        const int id;
        string nome;
        int num_itens;
        string *ptr_itens;
        static int contador_pedidos;
        static int total_itens;
        static int proximo_id; // não depende da decrementação do destrutor
};

// variáveis estáticas não são definidas com "static" fora da classe
int Pedido::contador_pedidos = 0;
int Pedido::total_itens = 0;
int Pedido::proximo_id = 1; // não depende da decrementação do destrutor

// construtor
Pedido::Pedido(string _nome, int _num_itens):id(proximo_id++) {
    contador_pedidos++;
    total_itens += _num_itens;
    
    ptr_itens = new string[_num_itens];

    for(int i = 0; i < _num_itens; i++) {
        ptr_itens[i] = "---";
    }

    set_nome(_nome);
    num_itens = _num_itens;
}

// destrutor
Pedido::~Pedido() {
    contador_pedidos--;
    total_itens -= num_itens;

    delete[] ptr_itens;
}

// metodos set

void Pedido::set_nome(string _nome) {
    nome = _nome;
}

void Pedido::set_item(int posicao, string item) {
    ptr_itens[posicao] = item;
}

// metodos get

int Pedido::get_id() const {
    return id;
}

string Pedido::get_nome() const {
    return nome;
}

int Pedido::get_num_itens() const {
    return num_itens;
}

string Pedido::get_item(int posicao) const {
    return ptr_itens[posicao];
}

int Pedido::get_contador_pedidos() {
    return contador_pedidos;
}

int Pedido::get_total_itens() {
    return total_itens;
}

int main() {
    Pedido pedido1("Gustavo", 2);
    pedido1.set_item(0, "Carro");
    pedido1.set_item(1, "Guitarra");
    
    Pedido pedido2("Hugo", 1);
    pedido2.set_item(0, "Computador");

    cout << "id: " << pedido1.get_id() << endl;
    cout << "nome: " << pedido1.get_nome() << endl;
    cout << "num_itens: " << pedido1.get_num_itens() << endl;
    cout << "item 1: " << pedido1.get_item(0) << endl;
    cout << "item 2: " << pedido1.get_item(1) << endl;

    cout << "\n";

    cout << "id: " << pedido2.get_id() << endl;
    cout << "nome: " << pedido2.get_nome() << endl;
    cout << "num_itens: " << pedido2.get_num_itens() << endl;
    cout << "item 1: " << pedido2.get_item(0) << endl;
    
    cout << "\n";
    
    cout << "contador_pedidos: " << Pedido::get_contador_pedidos() << endl;
    cout << "total_itens: " << Pedido::get_total_itens() << endl;

    return 0;
}