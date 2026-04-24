#include <iostream>

using namespace std;

class fracao {
    private:
        int numerador;
        int denominador;

    public:
        fracao(int _numerador, int _denominador);
        void set_num(int _numerador);
        void set_den(int _denominador);
        int get_num() const;
        int get_den() const;
};

fracao::fracao(int _numerador, int _denominador) {
    numerador = _numerador;
    if (denominador == 0) {
        cerr << "Denominador inválido" << endl;
        denominador = 1;
    }
    else {
        denominador = _denominador;
    }
}

void fracao::set_num(int _numerador) {
    numerador = _numerador;
}

void fracao::set_den(int _denominador) {
    if (_denominador == 0) {
        cerr << "Denominador inválido" << endl;
        denominador = 1;
    }
    else {
        denominador = _denominador;
    }
}

int fracao::get_num() const {
    return numerador;
}

int fracao::get_den() const {
    return denominador;
}

int main() {
    fracao f(3, 4);
    cout << "Numerador: " << f.get_num() << ", Denominador: " << f.get_den() << endl;

    return 0;
}