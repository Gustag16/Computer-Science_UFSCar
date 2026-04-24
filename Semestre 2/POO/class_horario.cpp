#include <iostream>

using namespace std;

class horario {
    
    public:
        horario(int = 0, int = 0, int = 0); // constructor
        void print_universal();
        void print_standard();
        // funções get
        int get_hora();
        int get_minuto();
        int get_segundo();
        //funções set
        void set_horario(int, int, int);
        void set_hora(int);
        void set_minuto(int);
        void set_segundo(int);
    
    private:
        int hora;
        int minuto;
        int segundo;
    
};

horario::horario(int h, int m, int s) {
    set_hora(h);
    set_minuto(m);
    set_segundo(s);
}

void horario::set_hora(int h) {
    hora = ( h >= 0 && h < 24 ) ? h : 0;
}

void horario::set_minuto(int m) {
    minuto = ( m >= 0 && m < 60 ) ? m : 0;
}

void horario::set_segundo(int s) {
    segundo = ( s >= 0 && s < 60 ) ? s : 0;
}

void horario::set_horario(int h, int m, int s) {
    set_hora(h);
    set_minuto(m);
    set_segundo(s);
}

int horario::get_hora() {
    return hora;
}

int horario::get_minuto() {
    return minuto;
}

int horario::get_segundo() {
    return segundo;
}

void horario::print_universal() {
    cout << get_hora() << get_minuto() << get_segundo() << endl;
}

void horario::print_standard() {
    string am_pm;
    int hora_std;
    
    if (get_hora() <= 12) {
        am_pm = "AM";
        hora_std = get_hora();
    }
    else {
        am_pm = "PM";
        hora_std = get_hora() - 12;
    }
    
    cout << hora_std << am_pm << get_minuto() << get_segundo() << endl;
}

int main() {
    horario acordar(8,30,30);
    horario comer(12,0,0);
    horario dormir(23,0,15);
    
    acordar.print_standard();
    comer.print_standard();
    dormir.print_standard();
    
    return 0;
}
