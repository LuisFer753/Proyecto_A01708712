#include "Personaje.hpp"
#include "Arquero.hpp"
#include "Barbaro.hpp"
#include "Druida.hpp"
#include "funciones_adicionales.h"
#include <iostream>

void presentacion(Personaje *equipo[]){
    for (int i=0; i<5; i++){
        equipo[i]->imprimir();
    }
}

int ataque(Personaje **atacante, Personaje **objetivo, int vivoAt, int vivoDef){
    *atacante[vivoAt]> *objetivo[vivoDef];
    if (objetivo[vivoDef]->estaVivo()==false){
        return vivoDef-1;
    }
    return vivoDef;
}