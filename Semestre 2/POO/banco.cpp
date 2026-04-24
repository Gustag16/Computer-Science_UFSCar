#include <iostream>

using namespace std;

class Conta {
    private:
        double saldo;

    public:
        Conta(double _saldo) {
            set_saldo(_saldo);
        }
        void set_saldo(double _saldo) {
            saldo = _saldo;
        }
        double get_saldo() const {
            return saldo;
        }
        bool debitar(double dinheiro) {
            if (dinheiro > 0) {
                saldo -= dinheiro;
                return true;
            }
            return false;
        }
        bool creditar(double dinheiro) {
            if (dinheiro > 0) {
                saldo += dinheiro;
                return true;
            }
            return false;
        }

};

class Poupanca : public Conta {
    private:
        double juros;
    
    public:
        Poupanca(double _saldo, double _juros);
        void set_juros(double _juros) {
            if (_juros >= 0) {
                juros = _juros;
            }
        }
        double get_juros() const {
            return juros;
        }
        double juros_auferidos() {
            return Conta::get_saldo() * get_juros();
        }
        
};

class ContaCorrente : public Poupanca {
    private:
        double taxa;

    public:
        ContaCorrente(double _saldo, double _juros, double _taxa);
        void set_taxa(double _taxa) {
            taxa = _taxa;
        }
        double get_taxa() const {
            return taxa;
        }
        bool creditar(double dinheiro) {
            if (dinheiro > 0) {
                double novo_saldo = Conta::get_saldo() - dinheiro * get_taxa();
                Conta::set_saldo(novo_saldo);
                return true;
            }
            return false;
        }
        bool debitar(double dinheiro) {
            if (dinheiro > 0) {
                double novo_saldo = Conta::get_saldo() - dinheiro * get_taxa();
                Conta::set_saldo(novo_saldo);
                return true;
            }
            return false;
        }

};

Poupanca::Poupanca(double _saldo, double _juros) : Conta(_saldo) {
    set_juros(_juros);
}

ContaCorrente::ContaCorrente(double _saldo, double _juros, double _taxa) 
    : Poupanca(_saldo, _juros)
{
        set_taxa(_taxa);
}

int main() {
    Conta c1(2530.45);
    Poupanca p1(27300.30, 0.5);
    ContaCorrente cc1(4000, 0.1, 0.01);

    cout << "c1: " << endl;
    cout << "Saldo anterior: " << c1.get_saldo() << endl;
    c1.debitar(530.45);
    cout << "Novo saldo: " << c1.get_saldo() << endl;

    cout << "\n";

    cout << "p1: " << endl;
    cout << "Saldo: " << p1.get_saldo() << endl;
    cout << "Juros: " << p1.get_juros() << endl;
    cout << "Juros auferidos: " << p1.juros_auferidos() << endl;

    cout << "\n";

    cout << "cc1: " << endl;
    cout << "Saldo antigo: " << cc1.get_saldo() << endl;
    cout << "Juros: " << cc1.get_juros() << endl;
    cout << "Juros auferidos: " << cc1.juros_auferidos() << endl;
    cc1.creditar(100);
    cout << "Novo saldo (com taxa): " << cc1.get_saldo() << endl;

    return 0;
}