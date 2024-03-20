#include <iostream>
#include <string>
#include "modules/constantes.h"
#include "modules/juego.h"
#include "modules/jugada.h"
using namespace std;

Juego solitario(1);


bool cumple_formato_de_entrada(int fila, int columna,  int spacePos){
	return !(fila == 0 || columna == 0 || spacePos == string::npos);
}

Jugada pedir_jugada(Juego juego) {
	string respuesta;
	int fila = 0;
	int columna = 0;
	int spacePos;

	do {
		cout << "Selecciona una FICHA (fila y columna): ";
		getline(cin, respuesta);
		spacePos = respuesta.find(" ");
		if (spacePos != string::npos)
		{
			fila = stoi(respuesta.substr(0,spacePos));
			columna = stoi(respuesta.substr(spacePos+1));
		}

		if (!cumple_formato_de_entrada(fila, columna, spacePos)) {
			cout << "No se cumple el formato de entrada." << endl;
		} else if (!juego.es_posicion_valida(fila-1, columna-1)) {
			cout << "La posición no es válida, selecciona una ficha." << endl;
		}
	} while (
		!cumple_formato_de_entrada(fila, columna, spacePos) || !juego.es_posicion_valida(fila-1, columna-1)
	); 

	fila--;
	columna--;
	Jugada jugada(fila, columna);
	return jugada;
}

void mostrar_posibles_direcciones(Jugada jugada) {
	cout << "Posibles direcciones:" << endl;
	for (int dir = 0; dir < jugada.get_num_dirs(); dir++)
	{
		cout << "\t" << dir+1 << ". " << dirToString(jugada.valor_direccion(dir)) << endl;
	}
}

void pedir_direccion(Jugada& jugada) {
	string respuesta;
	int dir = 0;

	do {
		cout << "Selecciona una dirección para mover la ficha (1-" << jugada.get_num_dirs() << "): ";
		cin >> respuesta;
		dir = stoi(respuesta);

		if (!(dir > 0 && dir <= jugada.get_num_dirs())) {
			cout << "La dirección no es válida." << endl;
		}
	} while (!(dir > 0 && dir <= jugada.get_num_dirs())); 

	jugada.fijar_dir_activa(static_cast<Direccion>(dir-1));
}

Jugada leer_jugada(Juego juego) {
	Jugada jugada(0, 0);
	do
	{
		jugada = pedir_jugada(juego);
		juego.cargar_posibles_direcciones(jugada);
	} while (jugada.get_num_dirs() == 0);

	mostrar_posibles_direcciones(jugada);
	pedir_direccion(jugada);
	
	return jugada;
}

int main() {
/*
	bool seguirJugando = false;
	string respuesta;
	do
	{*/
		solitario.mostrar();
		do {
			Jugada jugada = leer_jugada(solitario);
			solitario.jugar(jugada);
			solitario.mostrar();
			solitario.check_estado();
		} while (solitario.valor_estado() == JUGANDO);

		if (solitario.valor_estado() == BLOQUEO) {
			cout << "BLOQUEADO" << endl;
		}
		if (solitario.valor_estado() == GANADOR) {
			cout << "GANADOR" << endl;
		}

	/*	cout << "¿Quieres volver a jugar? (s/n): ";
		cin >> respuesta;
		if (respuesta == "s") seguirJugando = true;
	} while (seguirJugando);*/
	

}
