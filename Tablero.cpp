#include "Tablero.h"


Tablero::Tablero() {
	this->filas = 0;
	this->columnas = 0;
	for (int i = 0; i < MAXDIM; i++)
	{
		for (int j = 0; j < MAXDIM; j++)
		{
			celdas[i][j] = VACIA;
		}
	}
}
Tablero::Tablero(int fil, int col) {
	filas = fil;
	columnas = col;
	for (int i = 0; i < MAXDIM; i++)
	{
		for (int j = 0; j < MAXDIM; j++)
		{
			celdas[i][j] = NULA;
		}
	}
}
int Tablero::num_filas() const {
	return filas;
}
int Tablero::num_columnas() const {
	return columnas;
}
bool Tablero::correcta(int f, int c) const {
	return f < filas && f >= 0 && c < columnas && c >= 0;
}
Celda Tablero::leer(int f, int c) const {
	return celdas[f][c];
}
void Tablero::escribir(int f, int c, Celda valor) {
	celdas[f][c] = valor;
}