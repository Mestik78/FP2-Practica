#pragma once
#include"Jugador.h"
class ListaOrdJugadores {
private:
	Jugador* jugadores[NUM_JUGADORES];
	int cont;
public:
	ListaOrdJugadores();
	~ListaOrdJugadores();
	bool insertar_ord(Jugador* jug, int& pos);
	void eliminar(int pos);
	int valor_cont() const;
	Jugador* valor_jugador(int i) const;
	bool no_tiene_juegos(int p) const;
	bool no_tiene_jugadores() const;
	void eliminar_final();
};
