#include <iostream>

using namespace std;

class vetor {
    
    public:
        vetor(int _tamanho); // construtor
        ~vetor(); // destrutor
        // métodos set
        bool set_vetor(int posicao, int valor);
        // métodos get
        bool get_vetor(int posicao, int& valor) const;
        int get_tamanho() const;
        
        void print() const;
        
    
    private:
        int tamanho;
        int* ptr_vetor;
    
};

// construtor
vetor::vetor(int _tamanho) {
    if (_tamanho < 1) {
        tamanho = 10;
    }    
    else {
        tamanho = _tamanho;
    }

    ptr_vetor = new int[_tamanho];

    for(int i = 0; i < _tamanho; i++) {
        ptr_vetor[i] = 0;
    }
}

// destrutor
vetor::~vetor() {
    delete[] ptr_vetor;
}

bool vetor::set_vetor(int posicao, int valor) {
    if (posicao > 0 && posicao < tamanho) {
        ptr_vetor[posicao] = valor;
        return true;
    }
    else {
        cout << "Posição inválida" << endl;
        return false;
    }
}

bool vetor::get_vetor(int posicao, int& valor) const {
    if (posicao >= 0 && posicao < tamanho) {
        valor = ptr_vetor[posicao];
        return true;
        
    }
    else {
        return false;
        
    }
}

int vetor::get_tamanho() const {
    return tamanho;
}

void vetor::print() const {
    for (int i = 0; i < tamanho; i++) {
        cout << ptr_vetor[i] << " ";
    }
    cout << endl;
}

int main() {
    int valor;
    
    // cria o objeto (instanciação)
    vetor vetor1(8);
    // seta ptr_vetor[4] para 42
    vetor1.set_vetor(4, 42);
        
    // verifica se o índice é válido; se sim, ele "retorna" o valor do vetor no índice (por referência)
    if (vetor1.get_vetor(9, valor)) {
        cout << "Vetor: " << valor << endl;
    }
    else {
        cout << "Índice inválido" << endl;
    }
    
    cout << "Tamanho do vetor: " << vetor1.get_tamanho() << endl;
    
    vetor1.print();
    
    return 0;
}