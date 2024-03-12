#include "Movimiento.h"
Movimiento::Movimiento(int f, int c) {
	fil = f;
	col = c;
	this->cont = 0;
	dir_activa = INDETERMINADA;
}
int Movimiento::fila() const {
	return fil;
}
int Movimiento::columna() const {
	return col;
}
Direccion Movimiento::valor_dir_activa() const {
	return dir_activa;
}
void Movimiento::fijar_dir_activa(Direccion d) {
	dir_activa = d;
}
void Movimiento::insertar_dir(Direccion d) {
	direcciones[cont] = d;
	cont++;
}
int Movimiento::num_dirs() const {
	return cont;
}
Direccion Movimiento::direccion(int i) const {
	return direcciones[i];
}