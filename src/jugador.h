#pragma once
#include <string>
#include "baraja.h"
class Jugador {
	std::string nombre;
	char tipo = 'M';
	Carta* mano=NULL;
	Baraja* mazo;
	void robarCartas(int numeroCartas);
	void jugarCarta();
public:
	Jugador(std::string nombre, char tipo, Baraja * mazo);
	void mostrarMano();
	void jugar();

	
};

