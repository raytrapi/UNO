#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
struct Carta {
	enum TIPO {NORMAL, ROBO, SALTO, CAMBIO, COMODIN};

	string nombre="SIN ASIGNAR";
	TIPO tipo;
	int valor;
	Carta* siguiente = NULL;
	Carta* anterior = NULL;
	Carta(std::string nombre, TIPO tipo, int valor) {
		asignar(nombre, tipo, valor);
	}
	Carta() {

	}
	void mostrar();
	int mostrar(bool todo, bool numerado=false);
	void asignar(std::string nombre, TIPO tipo, int valor) {
		this->nombre = nombre;
		this->valor = valor;
		this->tipo = tipo;
	}
	void asignarSiguiente(Carta* carta) {
		this->siguiente = carta;
	}
	void asignarAnterior(Carta* carta) {
		this->anterior = carta;
	}
	Carta* obtenerCarta(int);
	void sacar();
	bool coincideParte(Carta*);
	~Carta() {
		if (siguiente != NULL) {
			delete siguiente;
		} 
	}
};

class Baraja {
	int numeroCartasMazo = 0;
	int numeroCartasMonton = 0;
	Carta* mazo=NULL;
	Carta* monton = NULL;
	string nombresCartas[5] = {"AMARILLA","ROJA","VERDE", "AZUL", "NEGRO"};
	Carta* añadeCartaMazo(Carta*, Carta*);
public: 
	Baraja();
	void pintarMazo(bool todo=false);
	void pintarMonton(bool todo=false);
	void barajar(int numeroPases);
	bool cartaJugada(Carta*);
	Carta* robar();
	void incluir(Carta*, int);
	Carta* cartaEnJuego();
	~Baraja() {
		if (mazo!=NULL) {
			delete mazo;
		}
		if (monton != NULL) {
			delete monton;
		}
	}
	int quedanMazo();
	void recomponer();
};

