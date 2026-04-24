#include <iostream>

using namespace std;

class vendedor {

    public:
        vendedor(int cnpj, string nome, string loja_afiliada, double salario, int numero_vendas); // constructor
        // metodos set
        void SetCNPJ(int cnpj);
        void SetNome(string nome);
        void SetLoja_afiliada(string loja_afiliada);
        void SetSalario(double salario);
        void SetRenda(int numero_vendas, double salario);
        void SetNumeroVendas(int numero_vendas);
        // metodos get
        int GetCNPJ();
        string GetNome();
        string GetLoja_afiliada();
        double GetRenda();
        double GetSalario();
        int GetNumeroVendas();

    private:
        int CNPJ;
        int Numero_vendas;
        string Nome;
        string Loja_afiliada;
        double Renda;
        double Salario;
        double comissao;
        bool ValidaCNPJ(int cnpj);
        double Comissao(int numero_vendas, double salario);
        
};

vendedor::vendedor(int cnpj, string nome, string loja_afiliada, double salario, int numero_vendas) {
    SetCNPJ(cnpj);
    SetNome(nome);
    SetLoja_afiliada(loja_afiliada);
    SetSalario(salario);
    SetNumeroVendas(numero_vendas);
    SetRenda(numero_vendas, salario);
}

bool vendedor::ValidaCNPJ(int cnpj) {
    return cnpj > 0;
}

void vendedor::SetCNPJ(int cnpj) {
    if (ValidaCNPJ(cnpj))
        CNPJ = cnpj;
    else 
        CNPJ = 0;
}

void vendedor::SetNome(string nome) {
    Nome = nome;
}

void vendedor::SetLoja_afiliada(string loja_afiliada) {
    Loja_afiliada = loja_afiliada;
}

void vendedor::SetSalario(double salario) {
    Salario = salario;
}

void vendedor::SetNumeroVendas(int numero_vendas) {
    Numero_vendas = numero_vendas;
}

double vendedor::Comissao(int numero_vendas, double salario) {
    if (numero_vendas < 100)
        return salario * 0.05;
    else if (numero_vendas < 500)
        return salario * 0.1;
    else
        return salario * 0.15;
}

void vendedor::SetRenda(int numero_vendas, double salario) {
    comissao = Comissao(numero_vendas, salario);
    Renda = comissao + salario;
}

int vendedor::GetCNPJ() {
    return CNPJ;
}

string vendedor::GetNome() {
    return Nome;
}

string vendedor::GetLoja_afiliada() {
    return Loja_afiliada;
}

int vendedor::GetNumeroVendas() {
    return Numero_vendas;
}

double vendedor::GetSalario() {
    return Salario;
}

double vendedor::GetRenda() {
    return Renda;
}

int main() {
    vendedor vendedor1(123456789, "joao da silva", "loja A", 2000.00, 135);
    cout << "Salario: " << vendedor1.GetSalario() << endl;
    cout << "Numero de vendas: " << vendedor1.GetNumeroVendas() << endl;
    cout << "Renda com comissao: " << vendedor1.GetRenda() << endl;

    return 0;
}
