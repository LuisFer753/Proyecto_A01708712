#include "Personaje.hpp"
#include "Arquero.hpp"
#include "Barbaro.hpp"
#include "Druida.hpp"
#include "funciones_adicionales.h"
#include <iostream>
using namespace std;

int main() 
{
  Personaje *equipo1[5];
  Personaje *equipo2[5];
  equipo1[0]=new Arquero(100, 100, 20, 1, 30);
  equipo1[1]=new Barbaro(150, 150, 25, 1, 40);
  equipo1[2]=new Druida(150, 120, 30, 1, "oso");
  equipo1[3]=new Arquero(100, 100, 25, 1, 33);
  equipo1[4]=new Barbaro(160, 160, 28, 1, 37);

  equipo2[0]=new Arquero(100, 100, 20, 1, 30);
  equipo2[1]=new Barbaro(150, 150, 25, 1, 40);
  equipo2[2]=new Druida(120, 120, 35, 1, "pantera");
  equipo2[3]=new Arquero(100, 100, 25, 1, 33);
  equipo2[4]=new Barbaro(160, 160, 28, 1, 37);

  cout<<"EQUIPO 1:"<<endl;
  presentacion(equipo1);
  cout<<"EQUIPO 2:"<<endl;
  presentacion(equipo2);

  int vivos1=4;
  int vivos2=4;
  int ganador=0;

  while (ganador==0){
    vivos2=ataque(equipo1, equipo2, vivos1, vivos2);
    if (vivos2<0){
      ganador=1;
      cout<<"El equipo 1 gana!\nSobrevivientes:\n"<<endl;
      for (int i=0; i<5; i++){
        if (equipo1[i]->estaVivo()==true){
          equipo1[i]->imprimir();
        }
      }

      break;
    }
    vivos1=ataque(equipo2, equipo1, vivos2, vivos1);
    if (vivos1<0){
      ganador=2;
      cout<<"El equipo 2 gana!\nSobrevivientes:\n"<<endl;
      for (int i=0; i<5; i++){
        if (equipo2[i]->estaVivo()==true){
          equipo2[i]->imprimir();
        }
      }
    }
  }
  return 0;
}



//  g++ Arquero.cpp Barbaro.cpp Druida.cpp Personaje.cpp funciones_adicionales.cpp exercise.cpp -o gud