#ifndef ARQUERO_H
#define ARQUERO_H

#include "Personaje.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Arquero: public Personaje{
    private:
        int presicion;
    public:
        Arquero();
        Arquero(int, int, int, int, int);

        int get_presicion();
        void set_presicion(int);

        void atacar(Personaje &objetivo);
        void recibeAtaque(int);
        void imprimir() const override;
        bool estaVivo();
};


#endif
