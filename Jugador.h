#pragma once
#include "Juego.h"
class Jugador {
private:
	string idJugador;
	int cont;
	Juego* partidas[NUM_JUEGOS]; // array de punteros
public:
	Jugador(string idUs);
	~Jugador();
	void insertar_final(Juego* j);
	string valor_idJugador() const;
	int valor_cont() const;
	Juego* valor_juego(int i) const;
	bool no_tiene_juegos() const;
	void eliminar(int p);
};