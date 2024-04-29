#include "Jugador.h"

Jugador::Jugador(string idUs)
{
	this->cont = 0;
	this->idJugador = idus;
}

Jugador::~Jugador()
{
}

void Jugador::insertar_final(Juego* j)
{
	this->partidas[this->cont] = j;
	this->cont++;
}

string Jugador::valor_idJugador() const
{
	return this->idJugador;
}

int Jugador::valor_cont() const
{
	return this->cont;
}

Juego* Jugador::valor_juego(int i) const
{
	return this->partidas[i];
}

bool Jugador::no_tiene_juegos() const
{
	return (this->cont == 0);
}

void Jugador::eliminar(int p)
{
	for (int i = p ; i < cont - 1; i++)
	{
		partidas[i] = paridas[i + 1];
	}
	cont--;
}
