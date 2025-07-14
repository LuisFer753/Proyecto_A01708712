#include "Barbaro.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // Para rand()
#include <ctime> // Para time()

using namespace std;

Barbaro::Barbaro(){
    Personaje();
    rabia=20;
}

Barbaro::Barbaro(int mv, int sal, int atq, int nvl, int rr){
    Personaje(mv, sal, atq, nvl);
    rabia=rr;
}

int Barbaro::get_rabia(){
    return rabia;
}

void Barbaro::set_rabia(int rr){
    rabia=rr;
}

void Barbaro::recibeAtaque(int dano){
    if (dano>rabia) dano=dano/2;
    set_salud(get_salud()-dano);
    if (get_salud()<0) set_salud(0);
}

void Barbaro::imprimir(){
    cout<<"Barbaro\nnivel: "<<get_nivel()<<"\nsalud: "<<get_salud()<<"/"<<get_maxvida()<<"\nataque: "<<get_ataque()<<"\nRabia: "<<rabia<<endl;
    imprimeBarra();
}