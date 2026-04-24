#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Dados {
    int id;
    char nome[50];
    double divida;
};

int main() {

    /* ESCRITA */
    ofstream fout; // instancia o objeto fout
    fout.open("arquivo.bin", ios::out | ios::binary); // abre o arquivo.bin em modo binário

    if (!fout) {
        cout << "Erro ao abrir arquivo.bin" << endl;
        return 1;
    }

    int qtde_inputs = 3;
    vector<Dados> pessoas(qtde_inputs);

    for (int i = 0; i < qtde_inputs; i++) {
        pessoas[i].id = i + 1;
        cout << "Insira o nome: "; cin >> pessoas[i].nome;
        cout << "Insira a dívida: "; cin >> pessoas[i].divida;
        // sintaxe: converter o endereço de memória de pessoas[i] para char* e informar o tamanho da estrutura (sizeof)
        fout.write((char*)&pessoas[i], sizeof(Dados));
    }

    fout.close();
    cout << "Dados gravados no arquivo binário" << endl;
    cout << "\n";

    /* LEITURA */
    ifstream fin;
    fin.open("arquivo.bin", ios::in | ios::binary);

    if (!fin) {
        cout << "Erro ao abrir arquivo.bin" << endl;
        return 1;
    }

    Dados temp;

    int i = 0;
    while (fin.read((char*)&temp, sizeof(Dados))) {
        cout << "ID: " << temp.id << " | Nome: " << temp.nome << " | Dívida: " << temp.divida << endl;
        i++;
    }    

    cout << "Fim da leitura" << endl;

    /* LEITURA VIA ACESSO DIRETO */
    int id_busca;
    cout << "\nDigite o id para busca: "; cin >> id_busca;

    fin.clear(); // rewind para sair do EOF

    long posicao = (id_busca - 1) * sizeof(Dados); // posição do byte do id desejado
    fin.seekg(posicao, ios::beg); // beg -> calcular a partir do inicio do arquivo

    Dados reg_buscado;
    if (fin.read((char*)&reg_buscado, sizeof(Dados))) {
        cout << "ID: " << reg_buscado.id << " | Nome: " << reg_buscado.nome << " | Divida: " << reg_buscado.divida << endl;
    } 
    else {
        cout << "\nErro: registro não encontrado ou ID inválido." << endl;
    }

    fin.close();
    
    return 0;
}