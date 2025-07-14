#include "Personaje.cpp"
#include <iostream>
using namespace std;

int main() 
{
  cout << "Hello World"<< endl;
  Personaje guerrero1(150, 150, 10, 2);
  Personaje mago1(100, 100, 25, 1);
  guerrero1.imprimeBarra();
  mago1.atacar(guerrero1);
  mago1.imprimir();
  guerrero1.imprimir();
  return 0;
}



