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
		Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::NORMAL, 0), Actual);
		for (int j = 1; j <= 9; j++) {
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::NORMAL, j), Actual);
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::NORMAL, j), Actual);
		}
	}
	for (int i = 0; i < 4; i++) { //Añadimos cartas especiales para cada color
		for (int j = 0; j < 2; j++) {
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::CAMBIO , 0), Actual);
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::SALTO, 0), Actual);
			Actual = añadeCartaMazo(new Carta(nombresCartas[i], Carta::TIPO::ROBO, 2), Actual);
		}
	}
	for (int i = 0; i < 4; i++) { //Añadimos los comodines negros
		Actual = añadeCartaMazo(new Carta(nombresCartas[4], Carta::TIPO::ROBO, 4), Actual);
		Actual = añadeCartaMazo(new Carta(nombresCartas[4], Carta::TIPO::COMODIN, 0), Actual);

	}/**/
	barajar(2);
}

void Baraja::pintarMazo(bool todo) {
	int num=mazo->mostrar(todo);
	std::cout << "Cartas "<<num<<std::endl;

}

void Baraja::pintarMonton(bool todo) {
	monton->mostrar(todo);
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

bool Baraja::cartaJugada(Carta* carta) {
	
	if (monton) {
		if (!monton->coincideParte(carta)) {
			return false;
		}
		carta->asignarSiguiente(monton);
		monton->asignarAnterior(carta);
	}
	std::cout << "Carta jugada ";
	carta->mostrar();
	monton = carta;
	numeroCartasMonton++;
	return true;
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

Carta* Baraja::cartaEnJuego() {
	return monton;
}

int Baraja::quedanMazo() {
	return numeroCartasMazo;
}

void Baraja::recomponer() {
	mazo = monton->siguiente;
	mazo->asignarAnterior(NULL);
	monton->asignarSiguiente(NULL);
	barajar(2);
}

void Carta::mostrar() {
	std::cout << nombre << " ";
	switch (tipo) {
	case Carta::TIPO::CAMBIO:
		std::cout << "cambio de sentido";
		break;
	case Carta::TIPO::SALTO:
		std::cout << "salto";
		break;
	case Carta::TIPO::ROBO:
		std::cout << "+" << valor;
		break;
	case Carta::TIPO::COMODIN:
		std::cout << "cambio de color";
		break;
	default:
		std::cout << valor;
		break;
	}
	
	std::cout << std::endl;
}

int Carta::mostrar(bool mostrarTodas, bool numerado) {
	int idCarta = 0;
	if (mostrarTodas) {
		Carta* cartaActual = this;
		while (cartaActual) {
			idCarta++;
			if (numerado) {
				std::cout << idCarta << " - ";
			}
			cartaActual->mostrar();
			cartaActual = cartaActual->siguiente;
		}
	} else {
		
		idCarta++;
		mostrar();
	}
	
	return idCarta;
}

Carta* Carta::obtenerCarta(int pos) {
	int i = 0;
	Carta* cartaActual = this;
	while(i < pos && cartaActual) {
		i++;
		cartaActual = cartaActual->siguiente;
	}
	return cartaActual;
}

void Carta::sacar() {
	if (anterior) {
		anterior->asignarSiguiente(siguiente);
	}
	if (siguiente) {
		siguiente->asignarAnterior(anterior);
	}
}

bool Carta::coincideParte(Carta*carta) {

	return carta->valor==valor || (carta->tipo==tipo && tipo!=TIPO::NORMAL) || carta->nombre==nombre ;
}
