#pragma once
#include"Tablero.h"
#include"Movimiento.h"
#include <fstream>
using namespace std;
class Juego {
private:
	Tablero tablero;
	int f_meta, c_meta;
	Estado estado_int;
	int n_fichas;
	void ejecuta_movimiento(const Movimiento& mov);
	void nuevo_estado();
	bool hay_ganador() const;
	bool hay_movimientos() const;
	void color_fondo(int color) const;
	void pinta_cabecera() const;
	void pinta_linea(char esquinaIzda, char cruce, char esquinaDer) const;
	void pinta_borde_celda(int fila) const;
	void pinta_centro_celda(int fila) const;
<<<<<<< Updated upstream
public:
	Juego();
=======
	bool mov_inverso(int movimientos);
	bool elegir_mov_inverso(int movimientos);
public:
	Juego();
	Juego(int mavimientos);
>>>>>>> Stashed changes
	void cargar(istream& entrada);
	bool posicion_valida(int f, int c) const;
	void posibles_movimientos(Movimiento & mov) const;
	Estado estado() const;
	void jugar(const Movimiento& mov);
	void mostrar() const;
};
