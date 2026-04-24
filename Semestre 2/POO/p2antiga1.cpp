#include <iostream>

using namespace std;

class Complexo {

    friend ostream & operator<<(ostream &output, const Complexo &complexo);
    friend const Complexo operator+(int z, const Complexo &complexo);

    private:
        double real;
        double imag;

    public:
        Complexo() {
            real = imag = 0;
        }
        Complexo(double R, double I) {
            real = R;
            imag = I;
        }
        void set_real(double R) {
            real = R;
        }
        void set_imag(double I) {
            imag = I;
        }
        double get_real() const {
            return real;
        }
        double get_imag() const {
            return imag;
        }
        const Complexo operator+(const Complexo &complexo) const;
        bool operator==(const Complexo &complexo) const;
        const Complexo& operator=(const Complexo &complexo);
        const Complexo operator++(int fantasma);
};

// para satisfazer cout << A << B
ostream & operator<<(ostream &output, const Complexo &complexo) {
    output << complexo.get_real() << "+" << complexo.get_imag() << "i";
    return output;
}

// para satisfazer C == A
bool Complexo::operator==(const Complexo &complexo) const {
    return (this->real == complexo.real) && (this->imag == complexo.imag);
}

// para satisfazer qualquer atribuição
const Complexo& Complexo::operator=(const Complexo &complexo) {
    if (!(*this == complexo)) {
        this->real = complexo.real; 
        this->imag = complexo.imag;
    }
    return *this;
}

// para satisfazer A = 4.0 + A. Vale lembrar que não é membro da classe, então não possui Complexo::
const Complexo operator+(int z, const Complexo &complexo) {
    Complexo c;
    c.real = complexo.real + z;
    c.imag = complexo.imag;
    return c;
}

// para satisfazer C = A + B
const Complexo Complexo::operator+(const Complexo &complexo) const {
    Complexo c;
    c.real = this->real + complexo.real;
    c.imag = this->imag + complexo.imag;
    return c;
}

// para satisfazer A++ (pós fixado)
Complexo Complexo::operator++(int fantasma) {
    Complexo temp;
    temp = *this;
    this->real += 1;
    return temp;
}

int main () {
    Complexo A(3,4), B(5,0), C;

    cout << "A = " << A << endl << "B = " << B << endl;

    C = A + B;

    cout << "C = A + B = " << C << endl;

    A = 4.0 + A;

    cout << "A = 4.0 + A = " << A << endl;

    cout << "A++ (incrementa 1 na parte real): " << A++ << endl;
    
    if(C == A) {
        cout << "C e A são iguais"<< endl;
    }

    return 0;

}