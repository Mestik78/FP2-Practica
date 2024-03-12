#include"Juego.h"
#include <iomanip>
#include "colores.h"
#include <iostream>
void Juego::ejecuta_movimiento(const Movimiento& mov) {
	int fil, col, dir;
	fil = mov.fila();
	col = mov.columna();
	dir = mov.valor_dir_activa();
	tablero.escribir(fil, col, VACIA);
	fil = fil + DIRS[dir][0];
	col = col + DIRS[dir][1];
	tablero.escribir(fil, col, VACIA);
	fil = fil + DIRS[dir][0];
	col = col + DIRS[dir][1];
	tablero.escribir(fil, col, FICHA);
	n_fichas--;
}
void Juego::nuevo_estado() {
	if (hay_ganador())
		estado_int = GANADOR;
	else if (hay_movimientos())
		estado_int = JUGANDO;
	else
		estado_int = BLOQUEO;
}
bool Juego::hay_ganador() const {
	return tablero.leer(f_meta, c_meta) == FICHA && n_fichas == 1;
}
bool Juego::hay_movimientos() const {
	int i = 0;
	bool mov = false;
	while (!mov && i < tablero.num_filas())
	{
		int j = 0;
		while (!mov&& j < tablero.num_columnas())
		{
			Movimiento m(i, j);
			posibles_movimientos(m);
			if (m.num_dirs() != 0)
			{
				mov = true;
			}
		}
	}
	return mov;
}
Juego::Juego() {
	Tablero t(0, 0);
	this->f_meta = 0;
	this->c_meta = 0;
	this->n_fichas = 0;
	
}
void Juego::cargar(istream& entrada) {
	this->estado_int = JUGANDO;
	int fil, col;
	entrada >> fil;
	entrada >> col;
	Tablero t(fil, col);
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int valor;
			entrada >> valor;
			t.escribir(i, j, Celda(valor));
			if (Celda(valor)==FICHA)
			{
				n_fichas++;
			}
		}
	}
	this->tablero = t;
	entrada >> f_meta;
	entrada >> c_meta;
}
bool Juego::posicion_valida(int f, int c) const {
	return tablero.leer(f, c)==FICHA;
}
void Juego::posibles_movimientos(Movimiento& mov) const {
	for (int i = 0; i < NUMDIR; i++)
	{
		int fil, col;
		fil = mov.fila();
		col = mov.columna();
		fil = fil + DIRS[i][0];
		col = col + DIRS[i][1];
		if (tablero.leer(fil,col)== FICHA && tablero.correcta(fil,col))
		{
			fil = fil + DIRS[i][0];
			col = col + DIRS[i][1];
			if (tablero.leer(fil, col) == VACIA && tablero.correcta(fil, col))
			{
				mov.insertar_dir(Direccion(i));
			}
		}
	} 
}
Estado Juego::estado() const {
	return estado_int;
}
void Juego::jugar(const Movimiento& mov) {
	ejecuta_movimiento(mov);
	nuevo_estado();
}
void Juego::color_fondo(int color) const {
	if (color == DEFAULT_COLOR)
		cout << RESET;
	else if (color == NULA)
		cout << BG_BLACK;
	else if (color == FICHA)
		cout << BG_LBLUE;
	else // color == VACIA
		cout << BG_ORANGE;
}
void Juego::pinta_cabecera() const {
	cout << setw(2) << "    "; // margen inicial
	cout << setw(5) << 1;
	for (int i = 2; i <= tablero.num_columnas(); i++) {
		cout << setw(7) << i;
	}
	cout << endl;
}
void Juego::pinta_linea(char esquinaIzda, char cruce, char esquinaDer) const {
	cout << "    "; // margen inicial
	cout << esquinaIzda;
	for (int i = 0; i < tablero.num_columnas() - 1; i++) {
		cout << string(6, char(196)) << cruce;
	}
	cout << string(6, char(196)) << esquinaDer << endl;
}
void Juego::pinta_borde_celda(int fila) const {
	cout << "    "; // margen inicial
	for (int k = 0; k < tablero.num_columnas(); k++) { // cada columna
		cout << char(179);
		color_fondo(tablero.leer(fila,k));
		cout << "      ";
		color_fondo(DEFAULT_COLOR);
	}
  	cout << char(179) << endl; // lateral derecho
}
void Juego::pinta_centro_celda(int fila) const {
	cout << "  " << setw(2) << fila + 1; // margen inicial
	for (int k = 0; k < tablero.num_columnas(); k++) { // cada columna
		cout << char(179);
		// el color de fondo depende del contenido
		color_fondo(tablero.leer(fila,k));

		if (fila == f_meta && k == c_meta) { // meta
			cout << YELLOW;
			cout << "  " << char(219) << char(219) << "  ";
		}
		else {
			cout << "      ";
		}
		color_fondo(DEFAULT_COLOR);
	}
	cout << char(179) << endl;
}


void Juego::mostrar() const {
	system("cls"); // borrar consola
	cout << RESET;

	// borde superior
	pinta_cabecera();
	pinta_linea(char(218), char(194), char(191));
	// para cada fila
	for (int fil = 0; fil < tablero.num_filas(); fil++) {
		// primera l�nea
		pinta_borde_celda(fil);
		// segunda l�nea, con la meta posiblemente
		pinta_centro_celda(fil);
		// tercera l�nea
		pinta_borde_celda(fil);
		// separaci�n entre filas
		if (fil < tablero.num_filas() - 1) {
			pinta_linea(char(195), char(197), char(180));
		}
		else {
			pinta_linea(char(192), char(193), char(217));
		}
	}
}


