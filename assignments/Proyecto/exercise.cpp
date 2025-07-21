#include "Personaje.cpp"
#include "Arquero.cpp"
#include "Barbaro.cpp"
#include "Druida.cpp"
#include <iostream>
using namespace std;

int main() 
{
  Personaje *personajes[3];
  personajes[0] = new Arquero(100, 100, 20, 1, 30);
  personajes[1] = new Barbaro(150, 150, 25, 1, 40);
  personajes[2] = new Druida(150, 120, 30, 1, "oso");

  personajes[0]->atacar(*personajes[1]);
  personajes[1]->atacar(*personajes[2]);
  personajes[2]->atacar(*personajes[0]);

  for (int i = 0; i < 3; i++) {
    personajes[i]->imprimir();
  }
  return 0;
}



