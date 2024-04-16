#include"constantes.h"
string dirToString(Direccion d) {
	string direccion;
	if (d == ARRIBA) direccion = "ARRIBA";
	if (d == ABAJO) direccion = "ABAJO";
	if (d == IZQUIERDA)direccion = "IZQUIERDA";
	if (d == DERECHA)direccion = "DERECHA";
	if (d == INDETERMINADA)direccion = "INDETERMINADO";
	return direccion;
}