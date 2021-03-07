#include "baraja.h"

Carta* Baraja::añadeCartaMazo(Carta* carta, Carta * actual) {
	if (actual == NULL) {
		mazo = carta;
	} else {
		carta->asignarAnterior(actual);
		actual->asignarSiguiente(carta);
	}
	numeroCartasMazo++;
	return carta;
}

Baraja::Baraja() {
	Carta* Actual = NULL;
	/*Actual = añadeCartaMazo(new Carta("0", 0, 0), Actual);
	Actual = añadeCartaMazo(new Carta("1", 0, 0), Actual);
	Actual = añadeCartaMazo(new Carta("2", 0, 0), Actual);
	/**/


	for (int i = 0; i < 4; i++) { //Añadimos cartas Normales para cada color
		Actual = añadeCartaMazo(new Carta(nombresCartas[i], 0, 0), Actual);
		for (int j = 1; j <= 9; j++) {
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], j, 0), Actual);
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], j, 0), Actual);
		}
	}
	for (int i = 0; i < 4; i++) { //Añadimos cartas especiales para cada color
		for (int j = 0; j < 2; j++) {
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], -1, 0), Actual);
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], -2, 0), Actual);
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], -3, 2), Actual);
		}
	}
	for (int i = 0; i < 4; i++) { //Añadimos los comodines negros
		Actual = añadeCartaMazo(new Carta(nombresCartas[4], -3, 4), Actual);
		Actual = añadeCartaMazo(new Carta(nombresCartas[4], -4, 0), Actual);

	}/**/
	barajar(2);
}

void Baraja::pintarMazo(bool todo) {
	int num=mazo->pintar(todo);
	std::cout << "Cartas "<<num<<std::endl;

}

void Baraja::pintarMonton(bool todo) {
	monton->pintar(todo);
}

void Baraja::barajar(int numeroPases) {
	for (int i = 0; i < numeroPases; i++) {
		for (int j = 0; j < numeroCartasMazo; j++) {
			Carta * carta=robar();
			int pos = rand() % numeroCartasMazo;
			incluir(carta, pos);
		}
	}
}

void Baraja::cartaJugada(Carta*) {
   
}

Carta* Baraja::robar() {
	Carta* carta = mazo;
	if (mazo) {
		mazo = mazo->siguiente;
		mazo->asignarAnterior(NULL);
	}
	carta->asignarSiguiente(NULL);
	numeroCartasMazo--;
	return carta;
}

void Baraja::incluir(Carta* carta, int posicion) {
	if (posicion <= 0) {
		carta->asignarSiguiente(mazo);
		mazo->asignarAnterior(carta);
		mazo = carta;
	} else{
		Carta* c = mazo;
		int i = 0;
		while (c->siguiente!=NULL && i<posicion){
			c = c->siguiente;
			i++;
		}
		carta->asignarAnterior(carta);
		carta->asignarSiguiente(c->siguiente);
		c->asignarSiguiente(carta);

	}
	numeroCartasMazo++;

}

int Carta::pintar(bool todo ) {
	std::cout << nombre << " ";
	switch (valor) {
		case -1:
			std::cout << "cambio de sentido";
			break;
		case -2:
			std::cout << "salto";
			break;
		case -3:
			std::cout << "+"<<cartasRobar;
			break;
		case -4:
			std::cout << "cambio de color";
			break;
		default:
			std::cout << valor;
			break;
	}
	/*if (siguiente) {
		std::cout << " SIG: " << siguiente->nombre;
	} else {
		std::cout << " SIG: NULL";
	}
	if (anterior) {
		std::cout << " ANT: " << anterior->nombre;
	} else {
		std::cout << " ANT: NULL";
	}*/
	std::cout << std::endl;
	if (todo) {
		if (siguiente != NULL) {
			return 1+(siguiente->pintar(todo));
		}

	}
	return 1;
}
