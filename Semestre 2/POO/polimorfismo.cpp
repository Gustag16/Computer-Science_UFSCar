#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

void DisplayRefresh(const vector<Figura*> &vetor_fig) {
    // apaga todo o terminal
    cout << "\033[2J\033[1;1H";

    for (Figura* fig : vetor_fig) {
        fig->Desenha();
    }
}

int random_posicao_X(){
    // motor de geração de números aleatórios cuja seed é o tempo
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-25, 25); // intervalo
    return dist(rng);
}
int random_posicao_Y(){
    // motor de geração de números aleatórios cuja seed é o tempo
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-25, 25); // intervalo
    return dist(rng);
}

int main() {
    // alocação de memória e criação do vetor de figuras
    vector<Figura*> vetor_figuras;
    vetor_figuras.push_back(new circulo());
    vetor_figuras.push_back(new quadrado());
    vetor_figuras.push_back(new triangulo());
    vetor_figuras.push_back(new estrela());

    while (true) {
        // atualiza as posições randomicamente
        for (Figura* fig : vetor_figuras) {
            fig->SetPosicao(random_posicao_X(),random_posicao_Y());
        }
        
        // limpa o terminal e desenha as figuras
        DisplayRefresh(vetor_figuras, vetor_figuras.size());

        // aguarda 5 segundos antes de repetir o processo
        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}