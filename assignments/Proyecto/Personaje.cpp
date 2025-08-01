//GEnera la implementación de la clase base Personaje

#include "Personaje.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // Para rand()
#include <ctime> // Para time()

using namespace std;


int Personaje::porcentajeSalud() const{
    return salud*100/maxvida;
}

void Personaje::imprimeBarra() const{
    int vida=porcentajeSalud();
    int puntos=vida*20/100;
    for(int i=0; i<puntos; i++) cout<<'-';
    for(int i=puntos; i<20; i++) cout<<'.';
    cout<<vida<<'%'<<endl;
}

void Personaje::recibeAtaque(int dano){
    salud=salud-dano;
    if (salud<0) salud=0;
}

void Personaje::atacar(Personaje &objetivo){
    // Inicializar aleatoriedad
    srand(time(0));

    int dano=0;
    if (objetivo.get_nivel()>nivel){
        dano=(rand() % (ataque/2))+1; // Entre 1 y ataque/2
    }else{
        dano=(rand() % (ataque-(ataque/2)+1))+(ataque/2); // Entre ataque/2 y ataque
    }
    objetivo.recibeAtaque(dano);
    cout<< dano << " de daño inflinjido"<<endl;
}

bool Personaje::estaVivo(){
    return salud>0;
}

void Personaje::operator>(Personaje &objetivo){
    atacar(objetivo);
}

