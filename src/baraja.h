#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
struct Carta {
	string nombre="SIN ASIGNAR";
	int valor;
	int cartasRobar;
	Carta* siguiente = NULL;
	Carta* anterior = NULL;
	Carta(std::string nombre, int valor, int cartasRobar) {
		asignar(nombre, valor, cartasRobar);
	}
	Carta() {

	}
	int pintar(bool todo=false);
	void asignar(std::string nombre, int valor, int cartasRobar) {
		this->nombre = nombre;
		this->valor = valor;
		this->cartasRobar = cartasRobar;
	}
	void asignarSiguiente(Carta* carta) {
		this->siguiente = carta;
	}
	void asignarAnterior(Carta* carta) {
		this->anterior = carta;
	}

	~Carta() {
		if (siguiente != NULL) {
			delete siguiente;
		} 
	}
};

class Baraja {
	int numeroCartasMazo = 0;
	int numroCartasMonton = 0;
	Carta* mazo=NULL;
	Carta* monton = NULL;
	string nombresCartas[5] = {"AMARILLA","ROJA","VERDE", "AZUL", "NEGRO"};
	Carta* añadeCartaMazo(Carta*, Carta*);
public: 
	Baraja();
	void pintarMazo(bool todo=false);
	void pintarMonton(bool todo=false);
	void barajar(int numeroPases);
	void cartaJugada(Carta*);
	Carta* robar();
	void incluir(Carta*, int);
	~Baraja() {
		if (mazo!=NULL) {
			delete mazo;
		}
		if (monton != NULL) {
			delete monton;
		}
	}
};

