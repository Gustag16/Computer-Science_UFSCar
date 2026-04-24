// Arthur Henrique Braz 832132
// Gustavo Amadeu Mancuzo de Sylos 845572
// Gustavo Gomes Nielsen, 847560
// Hugo Aparecido Gregorio de almeida 844917

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib>

using namespace std;

#define ROW 5
#define COL 9

template <size_t R, size_t C> // necessário para manipular matrizes
// printa no terminal a matriz
void printMatriz(const string (&matriz)[R][C])
{
    cout << "   ";
    for (size_t i = 0; i < C; i++)
    {
        cout << " " << i << " ";
    }

    cout << "\n";

    for (size_t i = 0; i < R; i++)
    {
        cout << " " << i << " ";
        for (size_t j = 0; j < C; j++)
        {
            cout << "[" << matriz[i][j] << "]";
        }
        cout << "\n";
    }

    cout << "\n <======================>\n\n";
};

class Figura
{
public:
    virtual void Desenha(string (&matriz)[ROW][COL]) const = 0;
    virtual double GetArea() const = 0;
    virtual double GetPerimetro() const = 0;

    int GetX() const { return x; }
    int GetY() const { return y; }

    string GetPosicao() const
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    void SetPosicao(int x, int y)
    {
        if (isValidCoordinates(x, y))
        {
            this->x = x;
            this->y = y;
        }
        else
        {
            cout << "Coordenadas inválidas, setando em (0,0)" << endl;
            this->x = 0;
            this->y = 0;
        }
    }

    bool isValidCoordinates(int x, int y)
    {
        return x >= 0 && x < ROW && y >= 0 && y < COL;
    }

protected:
    int x;
    int y;
};

// ============================================================================
// COMO ADICIONAR UMA NOVA FIGURA
// ============================================================================
/*
    Para criar um novo tipo de figura (ex: Hexagono, Elipse), siga este modelo:

    1. Declare a classe herdando publicamente de Figura:
        class NovaForma : public Figura { ... }

    2. Crie os atributos privados específicos da forma (ex: raio_maior, angulo).

    3. No construtor, receba X e Y (se fixos) ou inicie em (0,0) + atributos:
        NovaForma(int atributo) {
            SetPosicao(0, 0);      // Configura a base
            this->atributo = atributo; // Configura o específico
        }

    4. Implemente os métodos abaixo obrigatoriamente (assinatura exata):
        void Desenha(string (&matriz)[ROW][COL]) const override {
             // Apenas atualiza a matriz, não chame printMatriz aqui
             matriz[GetX()][GetY()] = "X";
        }

        double GetArea() const override {
            // Retorne o cálculo da área
            return 0.0;
        }

        double GetPerimetro() const override {
            // Retorne o cálculo do perímetro
            return 0.0;
        }

    Exemplo Rápido de Template:

    class Losango : public Figura
    {
    public:
        Losango(int diagMaior, int diagMenor) {
            SetPosicao(0, 0);
            this->d1 = diagMaior;
            this->d2 = diagMenor;
        }

        void Desenha(string (&matriz)[ROW][COL]) const override {
                // Define o caractere que representa a figura
                matriz[GetX()][GetY()] = "<>";
        }

        double GetArea() const override { return (d1 * d2) / 2.0; }
        double GetPerimetro() const override { return 4.0 * sqrt(pow(d1/2.0, 2) + pow(d2/2.0, 2)); }

    private:
        int d1, d2;
    };
*/
// ============================================================================

class Estrela : public Figura
{
public:
    Estrela()
    {
        SetPosicao(0, 0);
    }

    void Desenha(string (&matriz)[ROW][COL]) const override
    {
        matriz[GetX()][GetY()] = "*";
    }

    double GetArea() const override
    {
        return 10.0;
    }

    double GetPerimetro() const override
    {
        return 15.0;
    }
};

class Circulo : public Figura
{
public:
    Circulo(int raio)
    {
        SetPosicao(0, 0);
        this->raio = raio;
    }

    void Desenha(string (&matriz)[ROW][COL]) const override
    {
        matriz[GetX()][GetY()] = "O";
    }

    double GetArea() const override
    {
        return 3.14 * raio * raio;
    }

    double GetPerimetro() const override
    {
        return 2 * 3.14 * raio;
    }

private:
    int raio;
};

class Quadrado : public Figura
{
public:
    Quadrado(int lado)
    {
        SetPosicao(0, 0);
        this->lado = lado;
    }

    void Desenha(string (&matriz)[ROW][COL]) const override
    {
        matriz[GetX()][GetY()] = "#";
    }

    double GetArea() const override
    {
        return lado * lado;
    }

    double GetPerimetro() const override
    {
        return 4 * lado;
    }

private:
    int lado;
};

class Triangulo : public Figura
{
public:
    Triangulo(int base, int altura)
    {
        SetPosicao(0, 0);
        this->base = base;
        this->altura = altura;
    }

    void Desenha(string (&matriz)[ROW][COL]) const override
    {
        matriz[GetX()][GetY()] = "A";
    }

    double GetArea() const override
    {
        return (base * altura) / 2;
    }

    double GetPerimetro() const override
    {
        double hipotenusa = sqrt(pow(base, 2) + pow(altura, 2));
        return base + 2 * hipotenusa;
    }

private:
    int base;
    int altura;
};

void DisplayRefresh(const vector<Figura *> &vetor_fig, string (&matriz)[ROW][COL])
{
// apaga todo o terminal
#ifdef _WIN32
    system("cls"); // se windows
#else
    system("clear"); // se linux ou outro SO
#endif

    for (Figura *fig : vetor_fig)
    {
        fig->Desenha(matriz);
    }

    printMatriz(matriz);

    cout << "Legenda: * (Estrela), O (Circulo), # (Quadrado), A (Triangulo)" << endl;
}

int random_posicao_X()
{
    // motor de geração de números aleatórios cuja seed é o tempo
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, ROW - 1); // intervalo
    return dist(rng);
}
int random_posicao_Y()
{
    // motor de geração de números aleatórios cuja seed é o tempo
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, COL - 1); // intervalo
    return dist(rng);
}

int main()
{
    string map[ROW][COL];

    // preenche a matriz com vazio
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            map[i][j] = " ";
        }
    }

    // alocação de memória e criação do vetor de figuras
    vector<Figura *> vetor_figuras;
    vetor_figuras.push_back(new Circulo(1));
    vetor_figuras.push_back(new Quadrado(1));
    vetor_figuras.push_back(new Triangulo(1, 1));
    vetor_figuras.push_back(new Estrela());

    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                map[i][j] = " ";

        // atualiza as posições randomicamente
        for (Figura *fig : vetor_figuras)
            fig->SetPosicao(random_posicao_X(), random_posicao_Y());

        // limpa o terminal e desenha as figuras
        DisplayRefresh(vetor_figuras, map);

        // aguarda 2 segundos antes de repetir o processo
        this_thread::sleep_for(chrono::seconds(2));
    }

    for (auto f : vetor_figuras)
        delete f;

    cout << "Fim dos desenhos" << endl;

    return 0;
}