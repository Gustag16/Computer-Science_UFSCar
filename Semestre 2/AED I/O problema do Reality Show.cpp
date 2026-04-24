#include <iostream>

using namespace std;

int josephus(int n, int k) {
    if (n == 1) // se houver apenas um participante, ele é o vencedor (caso base)
        return 0;
    else 
        return (k + 1 + josephus(n - 1, k)) % n; // considerando índice zero atrelado ao operador módulo
}

int main() {
    int n, k;
    cout << "Número de participantes: ";
    cin >> n;
    cout << "Passo de eliminação: ";
    cin >> k;
    int indice_vencedor = josephus(n, k) + 1; // convertendo para índice um, como no problema
    
    cout << "Índice do vencedor: " << indice_vencedor << endl;
    
    return 0;
}