#include "jugador.h"

void Jugador::robarCartas(int numeroCartas) {
	for (int i = 0; i < numeroCartas; i++) {
		Carta* carta = mazo->robar();
		carta->asignarSiguiente(mano);
		if (mano) {
			mano->asignarAnterior(carta);
		}
		mano = carta;
	}
}

Jugador::Jugador(std::string nombre, char tipo, Baraja * mazo) {
	this->nombre = nombre;
	this->tipo = tipo;
	this->mazo = mazo;
	robarCartas(7);
}

void Jugador::mostrarMano() {
	int num = 0;
	if (mano) {
		num = mano->pintar(true);
	}
	std::cout << "Cartas " << num << std::endl;
}

void Jugador::jugar() {
	switch (tipo) 	{
		case 'M':
			jugarCarta();
			break;
		case 'H':
			mostrarMano();
			break;
	}
}
