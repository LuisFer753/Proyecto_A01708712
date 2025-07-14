#include "Arquero.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // Para rand()
#include <ctime> // Para time()

using namespace std;

Arquero::Arquero(){
    Personaje();
    presicion=25;
}

Arquero::Arquero(int mv, int sal, int atq, int nvl, int prec){
    Personaje(mv, sal, atq, nvl);
    presicion=prec;
}

int Arquero::get_presicion(){
    return presicion;
}

void Arquero::set_presicion(int prec){
    presicion=prec;
}

void Arquero::atacar(Personaje &objetivo){
    // Inicializar aleatoriedad
    srand(time(0));

    int dano=0;
    if (objetivo.get_nivel()>get_nivel()){
        dano=(rand() % (get_ataque()/2))+1; // Entre 1 y ataque/2
    } else {
        dano=(rand() % (get_ataque()-(get_ataque()/2)+1))+(get_ataque()/2); // Entre ataque/2 y ataque
    }
    
    int probabilidad_critico=rand() % 100;
    if (probabilidad_critico<presicion) {
        dano=dano*1.5;
        cout<<"Daño crítico!";
    }

    objetivo.recibeAtaque(dano);
    cout<< dano << " de daño inflinjido"<<endl;
}

void Arquero::imprimir(){
    cout<<"Arquero\nnivel: "<<get_nivel()<<"\nsalud: "<<get_salud()<<"/"<<get_maxvida()<<"\nataque: "<<get_ataque()<<"\nPresición: "<<presicion<<endl;
    imprimeBarra();
}