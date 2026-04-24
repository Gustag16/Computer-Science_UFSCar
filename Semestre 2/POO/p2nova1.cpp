#include <iostream>

using namespace std;

class Ponto2D {
    friend ostream & operator<<(ostream &output, const Ponto2D &ponto);

    private:
        int X;
        int Y;

    public:
        Ponto2D() {
            X = Y = 0;
        }
        Ponto2D(int vX, int vY) {
            X = vX;
            Y = vY;
        }
        void set_x(int vX) {
            X = vX;
        }
        void set_y(int vY) {
            Y = vY;
        }
        int get_x() const {
            return X;
        }
        int get_y() const {
            return Y;
        }
        const Ponto2D operator+(const Ponto2D &ponto) const;
        const Ponto2D operator+(int z) const;
        const Ponto2D& operator=(const Ponto2D &ponto);
        Ponto2D& operator++();
        bool operator==(const Ponto2D &ponto) const;

};

class Ponto3D : public Ponto2D {
    friend ostream& operator<<(ostream &output, const Ponto3D &ponto);

    private:
        int Z;

    public:
        Ponto3D() : Ponto2D() {
            Z = 0;
        }
        Ponto3D(int vX, int vY, int vZ) : Ponto2D(vX, vY) {
            Z = vZ;
        }
        void set_z(int vZ) {
            Z = vZ;
        }
        int get_z() const {
            return Z;
        }
        const Ponto3D operator++(int fantasma);

};

// sobrecarga do cout Ponto2D
ostream& operator<<(ostream &output, const Ponto2D &ponto) {
    output << "(" << ponto.get_x() << "," << ponto.get_y() << ")";
    return output;
}

// sobrecarga ponto + ponto
const Ponto2D Ponto2D::operator+(const Ponto2D &ponto) const {
    Ponto2D ptemp;
    ptemp.X = this->X + ponto.X;
    ptemp.Y = this->Y + ponto.Y;
    return ptemp;
}

// sobrecarga ponto + int
const Ponto2D Ponto2D::operator+(const int z) const {
    Ponto2D ptemp;
    ptemp.X = this->X + z;
    ptemp.Y = this->Y + z;
    return ptemp;
}

// sobrecarga =
const Ponto2D& Ponto2D::operator=(const Ponto2D &ponto) {
    this->X = ponto.X;
    this->Y = ponto.Y;
    return *this;
}

// sobrecarga ++p
Ponto2D& Ponto2D::operator++() {
    this->X++;
    this->Y++;
    return *this;
}

// sobrecarga ==
bool Ponto2D::operator==(const Ponto2D &ponto) const {
    return (this->X == ponto.X) && (this->Y == ponto.Y);
}

// sobrecarga cout Ponto3D
ostream& operator<<(ostream &output, const Ponto3D &ponto) {
    output << "(" << ponto.get_x() << "," << ponto.get_y() << "," << ponto.get_z() << ")";
    return output;
}

// sobrecarga ++ pós-fixado
const Ponto3D Ponto3D::operator++(int fantasma) {
    Ponto3D ptemp(*this);
    this->set_x(get_x() + 1);
    this->set_y(get_y() + 1);
    this->Z++;
    return ptemp;
}

int main() {

    Ponto2D p1(1,1), p2(3,4), p3;

    // necessário sobrecarregar cout
    cout << "p1 = " << p1 << endl << "p2 = " << p2 << endl;

    // necessário sobrecarregar + e =
    p3 = p1 + p2;
    cout << "p3 = p1 + p2 = " << p3 << endl;

    // necessário sobrecarregar + com inteiro
    p3 = p2 + 4;
    cout << "p3 = p2 + 4 = " << p3 << endl;

    // necessário sobrecarregar ++ pré-fixado
    p2 = ++p3;

    // necessário sobrecarregar ==
    if (p2 == p3) {
        cout << "p2 eh igual p3" << endl;
    }

    Ponto3D p(1,2,3);

    // necessário sobrecarregar ++ pós-fixado
    // p++;
    // necessário sobrecarregar cout para Ponto3D
    cout << "Ponto p = " << p++ << endl;
}