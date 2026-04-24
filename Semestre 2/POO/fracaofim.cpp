#include <iostream>

using namespace std;

class Fracao
{
public:
    Fracao();
    Fracao(int n, int d);
    Fracao(int n);

    void SetNum(int n);
    void SetDen(int d);
    int GetNum() const;
    int GetDen() const;

    void Mostrar() const;

    const Fracao operator+(const Fracao &f2) const;
    const Fracao operator-(const Fracao &f2) const;
    const Fracao operator+(int num) const;
    const Fracao operator-(int num) const;
    friend const Fracao operator+(int num, const Fracao &o1);
    friend const Fracao operator-(int num, const Fracao &o1);

    const Fracao operator*(const Fracao &f2) const;
    const Fracao operator*(int num) const;
    friend const Fracao operator*(int num, const Fracao &o1);

    Fracao operator++(int);
    Fracao &operator++();

    Fracao operator--(int);
    Fracao &operator--();

    bool operator>(const Fracao &f2) const;
    bool operator>(int num) const;
    friend bool operator>(int num, const Fracao &o1);

    bool operator>=(const Fracao &f2) const;
    bool operator>=(int num) const;
    friend bool operator>=(int num, const Fracao &o1);

    friend bool operator<(const Fracao &fe, const Fracao &fd);
    bool operator<(int num) const;
    friend bool operator<(int num, const Fracao &o1);

    bool operator<=(const Fracao &f2) const;
    bool operator<=(int num) const;
    friend bool operator<=(int num, const Fracao &o1);

    bool operator==(const Fracao &f2) const;
    bool operator==(int num) const;
    friend bool operator==(int num, const Fracao &o1);

    bool operator!=(const Fracao &f2) const;
    bool operator!=(int num) const;
    friend bool operator!=(int num, const Fracao &o1);

    friend ostream &operator<<(ostream &output, const Fracao &fracao);
    friend istream &operator>>(istream &input, Fracao &fracao);

private:
    int num;
    int den;
    int Mmc(int a, int b) const;
};

Fracao::Fracao()
{
    SetNum(0);
    SetDen(1);
}

Fracao::Fracao(int n, int d)
{
    SetNum(n);
    SetDen(d);
}

Fracao::Fracao(int n)
{
    SetNum(n);
    SetDen(1);
}

void Fracao::SetNum(int n)
{
    num = n;
}

void Fracao::SetDen(int d)
{
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

void Fracao::Mostrar() const
{
    cout << GetNum() << "/" << GetDen() << endl;
}

int Fracao::Mmc(int a, int b) const
{
    int temp, a_ = a, b_ = b;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return (a_ / a) * b_;
}

const Fracao Fracao::operator+(const Fracao &f2) const
{
    int novo_den = Mmc(this->den, f2.den);
    int novo_num = (this->num * (novo_den / this->den)) + (f2.num * (novo_den / f2.den));
    return Fracao(novo_num, novo_den);
}

const Fracao Fracao::operator-(const Fracao &f2) const
{
    int novo_den = Mmc(this->den, f2.den);
    int novo_num = (this->num * (novo_den / this->den)) - (f2.num * (novo_den / f2.den));
    return Fracao(novo_num, novo_den);
}

const Fracao Fracao::operator*(const Fracao &f2) const
{
    return Fracao(this->GetNum() * f2.GetNum(), this->GetDen() * f2.GetDen());
}

const Fracao Fracao::operator+(int numero) const
{
    return *this + Fracao(numero);
}

const Fracao Fracao::operator-(int numero) const
{
    return *this - Fracao(numero);
}

const Fracao Fracao::operator*(int num) const
{
    return Fracao(GetNum() * num, GetDen());
}

Fracao &Fracao::operator++()
{
    num += den;
    return *this;
}

Fracao Fracao::operator++(int)
{
    Fracao temp(*this);
    num += den;
    return temp;
}

Fracao Fracao::operator--(int)
{
    Fracao temp(*this);
    num -= den;
    return temp;
}

Fracao &Fracao::operator--()
{
    num -= den;
    return *this;
}

const Fracao operator+(int num, const Fracao &o1)
{
    return o1 + num;
}

const Fracao operator-(int num, const Fracao &o1)
{
    return Fracao(num) - o1;
}

const Fracao operator*(int num, const Fracao &o1)
{
    return o1 * num;
}

bool Fracao::operator>(const Fracao &f2) const
{
    return (this->GetNum() * f2.GetDen()) > (this->GetDen() * f2.GetNum());
}

bool Fracao::operator>(int num) const
{
    return *this > Fracao(num);
}

bool operator>(int num, const Fracao &o1)
{
    return Fracao(num) > o1;
}

bool Fracao::operator>=(const Fracao &f2) const
{
    return (this->GetNum() * f2.GetDen()) >= (this->GetDen() * f2.GetNum());
}

bool Fracao::operator>=(int num) const
{
    return *this >= Fracao(num);
}

bool operator>=(int num, const Fracao &o1)
{
    return Fracao(num) >= o1;
}

bool operator<(const Fracao &fe, const Fracao &fd)
{
    return (fe.GetNum() * fd.GetDen()) < (fe.GetDen() * fd.GetNum());
}

bool Fracao::operator<(int num) const
{
    return *this < Fracao(num);
}

bool operator<(int num, const Fracao &o1)
{
    return Fracao(num) < o1;
}

bool Fracao::operator<=(const Fracao &f2) const
{
    return (this->GetNum() * f2.GetDen()) <= (this->GetDen() * f2.GetNum());
}

bool Fracao::operator<=(int num) const
{
    return *this <= Fracao(num);
}

bool operator<=(int num, const Fracao &o1)
{
    return Fracao(num) <= o1;
}

bool Fracao::operator==(const Fracao &f2) const
{
    return (this->GetNum() * f2.GetDen()) == (this->GetDen() * f2.GetNum());
}

bool Fracao::operator==(int num) const
{
    return *this == Fracao(num);
}

bool operator==(int num, const Fracao &o1)
{
    return Fracao(num) == o1;
}

bool Fracao::operator!=(const Fracao &f2) const
{
    return !(*this == f2);
}

bool Fracao::operator!=(int num) const
{
    return !(*this == num);
}

bool operator!=(int num, const Fracao &o1)
{
    return !(Fracao(num) == o1);
}

ostream &operator<<(ostream &output, const Fracao &fracao)
{
    output << fracao.GetNum() << "/" << fracao.GetDen();
    return output;
}

istream &operator>>(istream &input, Fracao &fracao)
{
    int num, den;
    cout << "Numerador: ";
    input >> num;
    cout << "Denominador: ";
    input >> den;

    fracao.SetNum(num);
    fracao.SetDen(den);

    return input;
}

int main()
{
    Fracao f_a(1, 4), f_b(1, 2);
    Fracao f_c(3);
    Fracao f_d;

    cout << f_a << endl;
    cout << f_b << endl;
    cout << f_c << endl;
    cout << f_d << endl;
    cout << endl;

    Fracao soma = f_a + f_b;
    cout << soma << endl;

    Fracao sub = f_b - f_a;
    cout << sub << endl;

    Fracao mult = f_a * f_b;
    cout << mult << endl;
    cout << endl;

    int k = 2;

    Fracao soma_int = f_a + k;
    cout << soma_int << endl;

    Fracao mult_int_esq = k * f_a;
    cout << mult_int_esq << endl;

    Fracao mult_int_dir = f_b * 3;
    cout << mult_int_dir << endl;
    cout << endl;

    Fracao f_maior(3, 5);
    Fracao f_menor(1, 2);
    Fracao f_igual(6, 10);
    int i = 1;

    // Testes de comparação adicionais para cobrir todos os operadores
    cout << "(3/5 > 1/2)? " << (f_maior > f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << "(1/2 < 3/5)? " << (f_menor < f_maior ? "Verdadeiro" : "Falso") << endl;
    cout << "(3/5 >= 1/2)? " << (f_maior >= f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << "(3/5 >= 6/10)? " << (f_maior >= f_igual ? "Verdadeiro" : "Falso") << endl;
    cout << "(3/5 == 6/10)? " << (f_maior == f_igual ? "Verdadeiro" : "Falso") << endl;
    cout << "(3/5 != 1/2)? " << (f_maior != f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << "(3/5 <= 1)? " << (f_maior <= i ? "Verdadeiro" : "Falso") << endl;
    cout << "(1 > 1/2)? " << (i > f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << "(1 >= 1/2)? " << (i >= f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << "(0 < 1/2)? " << (0 < f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << endl;

    Fracao f_inc(5, 4);

    Fracao pre_inc = ++f_inc;
    cout << f_inc << endl;

    Fracao pos_inc = f_inc++;
    cout << f_inc << endl;
    cout << pos_inc << endl;
    cout << endl;

    Fracao f_dec(5, 4);
    Fracao pre_dec = --f_dec;
    cout << f_dec << endl;
    Fracao pos_dec = f_dec--;
    cout << f_dec << endl;
    cout << pos_dec << endl;
    cout << endl;

    Fracao f_io;
    cin >> f_io;
    cout << f_io << endl;

    return 0;
}