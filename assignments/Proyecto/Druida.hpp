#ifndef DRUIDA_H
#define DRUIDA_H

#include "Personaje.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Druida: public Personaje{
    private:
        string especie;
    public:
        Druida();
        Druida(int, int, int, int, string);

        string get_especie();
        void set_especie(string);

        void recibeAtaque(int);
        void atacar(Personaje &objetivo);
        void imprimir();
};


#endif
