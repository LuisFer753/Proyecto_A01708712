#include "Arquero.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // Para rand()
#include <ctime> // Para time()

using namespace std;

Arquero::Arquero(): Personaje(){
    presicion=25;
}

Arquero::Arquero(int mv, int sal, int atq, int nvl, int prec): Personaje(mv, sal, atq, nvl){
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

void Arquero::recibeAtaque(int dano){
    set_salud(get_salud()-dano);
    if (get_salud()<0) set_salud(0);
    estaVivo();
}

void Arquero::imprimir() const{
    cout<<"Arquero\nnivel: "<<get_nivel()<<"\nsalud: "<<get_salud()<<"/"<<get_maxvida()<<"\nataque: "<<get_ataque()<<"\nPresición: "<<presicion<<endl;
    imprimeBarra();
}

bool Arquero::estaVivo(){
    if (get_salud()>0){
        return true;
    }else{
        cout<<"El arquero ha caído en combate"<<endl;
        return false;
    }
}
