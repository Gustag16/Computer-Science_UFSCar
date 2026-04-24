#include <iostream>

using namespace std;

class Funcionario {
    private:
        string nome;
        int codigo;
        double salario;

    public:
        Funcionario(string _nome, int _codigo, double _salario);
        Funcionario();
        void set_nome(string _nome) {
            nome = _nome;
        }
        void set_codigo(int _codigo) {
            codigo = _codigo;
        }
        void set_salario(double _salario) {
            salario = _salario;
        }
        string get_nome() const {
            return nome;
        }
        int get_codigo() const {
            return codigo;
        }
        double get_salario()const {
            return salario;
        }
        double remuneracao() const {
            return get_salario();
        }
};

class Gerente : public Funcionario {
    private:
        int sob_supervisao;

    public:
        Gerente(string _nome, int _codigo, double _salario, int _sob_supervisao);
        Gerente();

        void set_supervisao(int _sob_supervisao) {
            sob_supervisao = _sob_supervisao;
        }
        int get_supervisao() const {
            return sob_supervisao;
        }
        double remuneracao() const {
            return Funcionario::get_salario() + (0.01 * Funcionario::get_salario() * get_supervisao());
        }        
};

Funcionario::Funcionario(string _nome, int _codigo, double _salario) {
    set_nome(_nome);
    set_codigo(_codigo);
    set_salario(_salario);
}

Funcionario::Funcionario() {
    set_nome("desconhecido");
    set_codigo(0);
    set_salario(0.0);
}

Gerente::Gerente(string _nome, int _codigo, double _salario, int _sob_supervisao) 
    : Funcionario(_nome, _codigo, _salario) 
{
        set_supervisao(_sob_supervisao);
}

Gerente::Gerente() 
    : Funcionario() 
{
        set_supervisao(0);
}

int main() {
    Funcionario f1("Gustavo", 845572, 5300.00);
    Gerente g1("Nicole", 824421, 12520.00, 12);

    cout << "Funcionário 1:" << endl;
    cout << "Nome: " << f1.get_nome() << endl;
    cout << "Código: " << f1.get_codigo() << endl;
    cout << "Salário: " << f1.get_salario() << endl;
    cout << "Remuneração: " << f1.remuneracao() << endl;

    cout << "\n";

    cout << "Gerente 1:" << endl;
    cout << "Nome: " << g1.get_nome() << endl;
    cout << "Código: " << g1.get_codigo() << endl;
    cout << "Salário: " << g1.get_salario() << endl;
    cout << "Pessoas sob supervisão: " << g1.get_supervisao() << endl;
    cout << "Remuneração: " << g1.remuneracao() << endl;

    return 0;
}