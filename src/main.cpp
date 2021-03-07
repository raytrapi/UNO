#include <iostream>
#include "baraja.h"
#include "jugador.h"
void main(int narg, char* arg) {
	Baraja baraja;
	
	
	int numeroJugadores = 2;
	Jugador** jugadores = new Jugador*[numeroJugadores]();

	jugadores[0] = new Jugador("Ray", 'H',&baraja);
	jugadores[1] = new Jugador("Maquina 1", 'M',&baraja);
	std::cout << "Ray" << std::endl;
	jugadores[0]->mostrarMano();
	std::cout << "Maquina 1" << std::endl;
	jugadores[1]->mostrarMano();
	std::cout << "Mazo" << std::endl;
	baraja.pintarMazo(true);
	for (int i = 0; i < numeroJugadores; i++) {
		if (jugadores[i]) {
			delete jugadores[i];
		}
	}
	delete[] jugadores;
}