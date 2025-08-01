#include "Personaje.hpp"
#include "Arquero.hpp"
#include "Barbaro.hpp"
#include "Druida.hpp"
#include <iostream>

void presentacion(Personaje *equipo[]);

int ataque(Personaje **atacante, Personaje **objetivo, int vivoAt, int vivoDef);