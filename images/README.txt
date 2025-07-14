Folder para colocar imagenes del repositorio

classDiagram
direction TB
    class Druida {
	    -especie: string
	    +atacar(Personaje &objetivo) void
	    +recibeAtaque(int) void
	    +imprimir() void
    }

    class Arquero {
	    -presicion: int
	    +atacar(Personaje &objetivo) void
	    +imprimir() void
    }

    class Barbaro {
	    -rabia: int
	    +recibeAtaque(int) void
	    +imprimir() void
    }

    class Persoanje {
	    -maxvida: int
	    -salud: int
	    -ataque: int
	    -nivel: int
	    +porcentajeSalud() int
	    +imprimeBarra() string
	    +recibeAtaque(int) void
	    +atacar(Persoanje &objetivo) void
	    +imprimir() string
    }

    Arquero --|> Persoanje
    Barbaro --|> Persoanje
    Druida --|> Persoanje
