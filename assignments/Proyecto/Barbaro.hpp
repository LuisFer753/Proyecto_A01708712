#ifndef BARBARO_H
#define BARBARO_H

#include "Personaje.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Barbaro: public Personaje{
    private:
        int rabia;
    public:
        Barbaro();
        Barbaro(int, int, int, int, int);

        int get_rabia();
        void set_rabia(int);

        void recibeAtaque(int);
        void imprimir();
        bool estaVivo();
};


#endif
