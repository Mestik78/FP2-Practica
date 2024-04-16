#pragma once
#include"constantes.h"
class Movimiento {
private:
	int fil;
	int col;
	Direccion dir_activa;
	int cont;
	Direccion direcciones[NUMDIR];
public:
	Movimiento();
	Movimiento(int f, int c);
	int fila() const;
	int columna() const;
	Direccion valor_dir_activa() const;
	void fijar_dir_activa(Direccion d);
	void insertar_dir(Direccion d);
	int num_dirs() const;
	Direccion direccion(int i) const;
};