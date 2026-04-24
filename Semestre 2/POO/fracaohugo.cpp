#include <iostream>

using namespace std;

class Fracao
{
public:
    Fracao()
    {
        SetNum(0);
        SetDen(1);
    }
    Fracao(int n, int d)
    {
        SetNum(n);
        SetDen(d);
    }
    Fracao(int n)
    {
        SetNum(n);
        SetDen(1);
    }
    void SetNum(int n);
    void SetDen(int d);
    int GetNum() const;
    int GetDen() const;
    void Mostrar();
    Fracao operator+(Fracao f1);
    Fracao operator-(Fracao f1);
    Fracao operator+(int num);
    Fracao operator-(int num);
    Fracao Mult(Fracao f2) const;
    Fracao operator*(int num) const
    {
        return Fracao(GetNum() * num, GetDen());
    };
    // friend Fracao operator++(Fracao o1);
    // friend Fracao operator++(Fracao o1);
    Fracao operator++(int);
    Fracao &operator++();
    bool operator>(Fracao f2) const;
    friend bool operator<(Fracao fe, Fracao fd);
    friend ostream &operator<<(ostream &, const Fracao &);
    friend istream &operator>>(istream &, Fracao &);

private:
    int num;
    int den;
};

/*Fracao Fracao::operator++(Fracao &f, int)
{
    Fracao temp(f);
    f.num += f.den;
    return temp;
}
*/
Fracao Fracao::operator++(int)
{
    Fracao temp(*this);
    num += den;
    return temp;
}

/*

Fracao& Fracao::operator++(fracao& f){
    f.num += f.den;
    return f;
}

*/

Fracao &Fracao::operator++()
{
    num += den;
    return *this;
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

void Fracao::Mostrar()
{
    cout << GetNum() << "/" << GetDen() << endl;
}

Fracao operator+(Fracao f1) 
{  
    f1.den = this->den * f1.den;
    f1.num = this->num * f1.den + this->den * f1.num;
    return f1;
}

Fracao operator-(Fracao f1) 
{
    f1.den = this->den * f1.den;
    f1.num = this->num * f1.den - this->den * f1.num;
    return f1;
}

Fracao operator+(int numero) 
{
    Fracao ftemp();
    ftemp.den = this->den;
    ftemp.num = numero * ftemp.den + this->num;
    return ftemp;
}

Fracao operator-(int numero) 
{
    Fracao ftemp();
    ftemp.den = this->den;
    ftemp.num = numero * ftemp.den + this->num;
    return ftemp;
}

Fracao Fracao::Mult(Fracao f2) const
{
    return Fracao(this->GetNum() * f2.GetNum(), this->GetDen() * f2.GetDen());
}

Fracao operator*(Fracao o1, Fracao o2)
{
    return Fracao(o1.GetNum() * o2.GetNum(), o1.GetDen() * o2.GetDen());
}

/*Fracao operator*(Fracao o1, int num)
{
    return Fracao(o1.GetNum() * num, o1.GetDen());
}*/

Fracao operator*(int num, Fracao o1)
{
    return o1 * num;
}

bool Fracao::operator>(Fracao f2) const
{
    return (this->GetNum() * f2.GetDen()) > (this->GetDen() * f2.GetNum());
}

bool operator<(Fracao fe, Fracao fd)
{
    return (fe.GetNum() * fd.GetDen()) < (fe.GetDen() * fd.GetNum());
}

ostream &operator<<(ostream &output, const Fracao &fracao)
{
    output << fracao.GetNum() << "/" << fracao.GetDen();
    return output;
}
istream &operator>>(istream &input, Fracao &fracao)
{
    int num;
    input >> num;
    fracao.SetNum(num);
    input.ignore();
    int den;
    input >> den;
    fracao.SetDen(den);

    return input;
}

int main()
{
    Fracao f1(1, 4), f2(1, 2);

    cout << "f1: ";
    f1.Mostrar();

    cout << "f2: ";
    f2.Mostrar();

    if (f1 > f2)
        cout << "F1 eh maior que F2" << endl;
    else
        cout << "F2 eh maior que F1" << endl;

    cout << f1 << endl;

    cin >> f2;

    f2.Mostrar();
    return 0;
}