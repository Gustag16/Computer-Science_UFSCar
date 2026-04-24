#include <iostream>

using namespace std;

class Animal {

    private:
        string nome;
        int localizacao;

    public:
        Animal(string _nome, int _localizacao) {
            set_nome(_nome);
            set_localizacao(_localizacao);
        }
        virtual ~Animal() {}

        void set_nome(string _nome) {
            nome = _nome;
        }
        void set_localizacao(int _localizacao) {
            if (_localizacao > 0) {
                localizacao = _localizacao;
            }    
            else {
                cout << "Localização inválida" << endl;
            }
        }
        string get_nome() const {
            return nome;
        }
        int get_localizacao() const {
            return localizacao;
        }
        virtual int mover(int dist) {
            return 0;
        }

};

class Peixe : public Animal {

    private:
        int profundidade_max;

    public:
        Peixe(int prof_max, string _nome, int _localizacao) : Animal(_nome, _localizacao) {
            profundidade_max = prof_max;
        }
        virtual ~Peixe() {}
        int mover(int dist) override {
            if (dist >= 0 && dist <= 10) {
                return get_localizacao() + dist;
            }
            else {
                cout << "O peixe não consegue nadar mais de 10 metros." << endl;
                return 0;
            }
        }
        int get_profmax() const {
            return profundidade_max;
        }

};

class Tartaruga : public Animal {

    private:
        string tipo;

    public:
        Tartaruga(string _tipo, string _nome, int _localizacao) : Animal(_nome, _localizacao) {
            tipo = _tipo;
        }
        virtual ~Tartaruga() {}
        int mover(int dist) override {
            if (dist >= 0 && dist <= 1) {
                return get_localizacao() + dist;
            }
            else {
                cout << "Tartaruga não anda mais de 1 metro." << endl;
                return 0;
            }
        }
        string get_tipo() {
            return tipo;
        }

};

int main() {

    Animal *generico1;
    Animal *generico2;
    generico1 = new Peixe(20, "Nicole", 42);
    generico2 = new Tartaruga("Ninja", "Gustavo", 42);

    cout << "Antes de se movimentar:" << endl;
    cout << generico1->get_localizacao() << endl;
    cout << generico2->get_localizacao() << endl;

    cout << "\n";

    cout << "Depois de se movimentar:" << endl;
    cout << generico1->mover(5) << endl;
    cout << generico2->mover(1) << endl;

    return 0;
}
