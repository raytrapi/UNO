#include <iostream>
#include "baraja.h"
#include "jugador.h"
void main(int narg, char* arg) {
	Baraja baraja;
	
	int cartasRoboInicial = 7;
	int numeroJugadores = 10;

	Jugador** jugadores = new Jugador*[numeroJugadores]();

	jugadores[0] = new Jugador("Ray", 'H',&baraja);
	for (int i = 1; i < numeroJugadores; i++) {
		jugadores[i] = new Jugador("Maquina "+i, 'M', &baraja);
	}

	for (int i = 0; i < cartasRoboInicial; i++) {
		for (int iJugador = 0; iJugador < numeroJugadores; iJugador++) {
			jugadores[iJugador]->robarCarta();
		}

	}

	
	//Suponemos que se levanta una por defecto
	baraja.cartaJugada(baraja.robar());

	/*std::cout << "\r\nRay" << std::endl;
	jugadores[0]->mostrarMano();
	std::cout << "\r\nMaquina 1" << std::endl;
	jugadores[1]->mostrarMano();
	std::cout << "\r\nMazo" << std::endl;
	baraja.pintarMazo(true);*/

	bool siguePartida = true;
	while(siguePartida){
		for (int iJugador = 0; iJugador < numeroJugadores && siguePartida; iJugador++) {
			std::cout << "\r\nEsta jugando "<< jugadores[iJugador]->nombre << std::endl;
			std::cout << "\r\nQuedan en mazo " << baraja.quedanMazo() << std::endl;
			int leQuedan = jugadores[iJugador]->jugar();
			if (leQuedan  == 0) {
				std::cout << "\r\nHa ganado " << jugadores[iJugador]->nombre << std::endl;
				siguePartida = false;
			} else {
				std::cout << "\r\nLe quedan  " << leQuedan << std::endl;
			};
			if (siguePartida && baraja.quedanMazo() == 0) {
				baraja.recomponer();
			}
		}
	}


	for (int i = 0; i < numeroJugadores; i++) {
		if (jugadores[i]) {
			delete jugadores[i];
		}
	}
	delete[] jugadores;
}