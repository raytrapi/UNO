#pragma once
#include <string>
#include "baraja.h"
class Jugador {
public: std::string nombre;
	char tipo = 'M';
	Carta* mano=NULL;
	Baraja* mesa;
	int numeroCartasEnMano = 0;
	void robarCartas(int numeroCartas);
	int jugarMaquina();
	int jugarHumano();
public:
	Jugador(std::string nombre, char tipo, Baraja * mesa);
	void mostrarMano();
	int jugar();
	void robarCarta();
	
};

