#include "Druida.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // Para rand()
#include <ctime> // Para time()

using namespace std;

Druida::Druida(): Personaje(){
    especie="humano"; //puede ser un humano, un oso o una pantera
}

Druida::Druida(int mv, int sal, int atq, int nvl, string esp): Personaje(mv, sal, atq, nvl){
    especie=esp;
}

string Druida::get_especie(){
    return especie;
}

void Druida::set_especie(string esp){
    especie=esp;
}

void Druida::recibeAtaque(int dano){
    if (especie=="pantera"){
        dano=dano*0.8;
    }else if (especie=="oso"){
        dano=dano*0.3;
    }
    set_salud(get_salud()-dano);
    if (get_salud()<0) set_salud(0);
    estaVivo();
}

void Druida::atacar(Personaje &objetivo){
    // Inicializar aleatoriedad
    srand(time(0));

    int dano=0;
    if (objetivo.get_nivel()>get_nivel()){
        dano=(rand() % (get_ataque()/2))+1; // Entre 1 y ataque/2
    } else {
        dano=(rand() % (get_ataque()-(get_ataque()/2)+1))+(get_ataque()/2); // Entre ataque/2 y ataque
    }

    if (especie=="pantera"){
        dano=dano*2.5;
    }else if (especie=="oso"){
        dano=dano*1.2;
    }

    objetivo.recibeAtaque(dano);
    cout<< dano << " de daño inflinjido"<<endl;
}

void Druida::imprimir() const{
    cout<<"Druida\nnivel: "<<get_nivel()<<"\nsalud: "<<get_salud()<<"/"<<get_maxvida()<<"\nataque: "<<get_ataque()<<"\nEspecie: "<<especie<<endl;
    imprimeBarra();
}

bool Druida::estaVivo(){
    if (get_salud()>0){
        return true;
    }else if (get_salud()<=0 && especie!="humano"){
        set_salud(1);
        set_especie("humano");
        cout<<"El druida se ha levantado gracias a su instinto animal"<<endl;
        return true;
    }else{
        cout<<"El druida ha caído en combate"<<endl;
        return false;
    }
}