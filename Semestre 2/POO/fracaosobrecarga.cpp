#include <iostream>

using namespace std;

class Fracao {

public:
    friend ostream &operator<<(ostream &output, const Fracao &fracao);

    friend istream &operator>>(istream &input, Fracao &fracao);

    Fracao() {
        SetNum(0);
        SetDen(1);
    }
    Fracao(int n, int d) {
        SetNum(n);
        SetDen(d);
    }
    Fracao(int n) {
        SetNum(n);
        SetDen(1);
    }
    void SetNum(int n);
    void SetDen(int d);
    int GetNum() const;
    int GetDen() const;
    void Mostrar();
    Fracao Mult(Fracao f2) const;
    Fracao operator*(int num) const {
        return Fracao(GetNum() * num, GetDen());
    };

private:
    int num;
    int den;
};

ostream &operator<<(ostream &output, const Fracao &fracao) {
    output << fracao.GetNum() << "/" << fracao.GetDen();
    return output;
}

istream &operator>>(istream &input, Fracao &fracao) {
    int num, den;
    input >> num;
    input.ignore();
    input >> den;
    fracao.SetNum(num);
    fracao.SetDen(den);
    return input;
}

void Fracao::SetNum(int n) {
    num = n;
}

void Fracao::SetDen(int d) {
    den = (d != 0) ? d : 1;
}

int Fracao::GetNum() const
{
    return num;
}

int Fracao::GetDen() const
{
    return den;
}

void Fracao::Mostrar()
{
    cout << GetNum() << "/" << GetDen() << endl;
}

Fracao Fracao::Mult(Fracao f2) const
{
    return Fracao(this->GetNum() * f2.GetNum(), this->GetDen() * f2.GetDen());
}

Fracao operator*(Fracao o1, Fracao o2)
{
    return Fracao(o1.GetNum() * o2.GetNum(), o1.GetDen() * o2.GetDen());
}

/*Fracao operator(Fracao o1, int num)
{
    return Fracao(o1.GetNum() * num, o1.GetDen());
}*/

Fracao operator*(int num, Fracao o1)
{
    return o1 * num;
}

bool operator>(Fracao f1, Fracao f2)
{
    if ((double)f1.GetNum() / (double)f1.GetDen() > (double)f2.GetNum() / (double)f2.GetDen())
        return true;
    else
        return false;
}

int main()
{
    Fracao f1(2, 3);
    Fracao f2(5, 6);
    Fracao multi = f1 * f2;
    cout << "f1 * f2 = ";
    multi.Mostrar();
    cout << "f2 = ";
    f2.Mostrar();

    Fracao f3(8, 6);
    multi = f3.Mult(f2);
    cout << "f3 = ";
    f3.Mostrar();
    cout << "f3 * f2 = ";
    multi.Mostrar();

    multi = f1 * 7;
    cout << "f1 * 7 = ";
    multi.Mostrar();

    multi = 12 * f2;
    cout << "12 * f2 = ";
    multi.Mostrar();

    bool maior = operator>(f3, f2);
    cout << "f3 é maior que f2? " << (maior ? "Sim" : "Nao") << endl;

    cin >> f1;
    cout << "f1 = " << f1 << endl;
}