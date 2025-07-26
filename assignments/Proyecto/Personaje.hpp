// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Personaje{
    private:
        int maxvida;
        int salud;
        int ataque;
        int nivel;

    public:
        Personaje(): maxvida(100), salud(100), ataque(10), nivel(0){};
        Personaje(int mv, int sal, int atq, int nvl): maxvida(mv), salud(sal), ataque(atq), nivel(nvl){};
        
        int get_maxvida() const {return maxvida;}
        int get_salud() const {return salud;}
        int get_ataque() const {return ataque;}
        int get_nivel() const {return nivel;}
        void set_maxvida(int mv) {maxvida=mv;}
        void set_salud(int sal) {salud=sal;}
        void set_ataque(int atq) {ataque=atq;}
        void set_nivel(int nvl) {nivel=nvl;}

        int porcentajeSalud() const; //este método debe devolver un int entre 0 y 100. Se calcula usando los valores de vida (que son los puntos máximos de vida que puede tener) y la salud (puntos de vida actual que tiene)
        void imprimeBarra() const; //imprima su barra de vida. Su barra de vida, en realidad son 20 caracteres que indican el % de vida que tiene el personaje. Por ejemplo puedes poner un % para indicar vida y un = o un . o cualquier otro caracter que tu decidas el cual indicará lo perdido. Así un 80% de vida pudiera mostrarse como: %%%%%%%%%%%%%%%%====
        virtual void recibeAtaque(int); //Este método recibe una cantidad de puntos que debe descontar a la salud actual de la unidad. Nunca debe quedar en negativo, si al descontar queda negativo haz que quede en 0 los puntos de salud.
        virtual void atacar(Personaje &objetivo); //este método calcula los puntos con que dañarás al objetivo de la siguiente manera: Si el objetivo tiene un nivel más alto que esta unidad, sólo se podrá atacar con un número aleatorio entre 1 y la mitad de los puntos de ataque. Si el objetivo es de nivel más bajo o igual, se ataca con un número aleatorio entre la mitad de los puntos de ataque y el total de los puntos de ataque. Este método debe también llamar al método recibeAtaque del objetivo para que se le descuente los puntos de salud al objetivo
        virtual void imprimir() const=0; //despliega en pantalla características del personaje y su barra de vida
        virtual bool estaVivo();
};

#endif
