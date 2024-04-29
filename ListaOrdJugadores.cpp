#include "ListaOrdJugadores.h"

ListaOrdJugadores::ListaOrdJugadores()
{
	this->cont = 0;
}

ListaOrdJugadores::~ListaOrdJugadores()
{
}

bool ListaOrdJugadores::insertar_ord(Jugador* jug, int& pos)
{
	bool existe = false;
	int i = 0;
	while ( i < cont &&!existe)
	{
		if (jugadores[i]==jug)
		{
			existe = true;
			pos = i;
		}
	}
	if (i==cont && !existe)
	{
		jugadores[i] = jug;
		cont++;
	}
	return existe;
}

void ListaOrdJugadores::eliminar(int pos)
{
	for (int i = pos; i < cont - 1; i++)
	{
		jugadores[i] = jugadores[i + 1];
	}
	cont--;
}

int ListaOrdJugadores::valor_cont() const
{
	return cont;
}

Jugador* ListaOrdJugadores::valor_jugador(int i) const
{
	return this->jugadores[i];
}

bool ListaOrdJugadores::no_tiene_juegos(int p) const
{
	return (jugadores[p]->valor_cont() == 0);
}

bool ListaOrdJugadores::no_tiene_jugadores() const
{
	return (cont == 0);
}

void ListaOrdJugadores::eliminar_final()
{
	cont--;
}
