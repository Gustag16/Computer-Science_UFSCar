#include <iostream>

using namespace std;

template<class T>
class Lista {

    private:
        T *lista_ptr;

    public:
        Lista(int = 1);
        ~Lista();
        void set_elemento(T data, int posicao);
        T get_elemento(int posicao) const;

};

template<class T>
Lista<T>::Lista(int tamanho) {
    lista_ptr = new T[tamanho];
}

template<class T>
Lista<T>::~Lista() {
    delete[] lista_ptr;
}

template<class T>
void Lista<T>::set_elemento(T data, int posicao) {
    lista_ptr[posicao] = data;
}

template<class T>
T Lista<T>::get_elemento(int posicao) const {
    return lista_ptr[posicao];
}

int main() {
    Lista<int> lista1;
    Lista<string> lista2(4);

    lista1.set_elemento(12, 0);
    lista2.set_elemento("rafael", 0);
    lista2.set_elemento("leonardo", 1);
    lista2.set_elemento("michelangelo", 2);
    lista2.set_elemento("donatello", 3);

    cout << "Lista 1: " << lista1.get_elemento(0) << endl;
    cout << "Lista 2: " << lista2.get_elemento(2) << endl;

    return 0;
}