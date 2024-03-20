#include "movimiento.h"

Jugada::Jugada(int f, int c) {
    fila = f;
    columna = c;
}

int Jugada::valor_num_dirs() const {
    return cont;
}

void Jugada::insertar_dir(Direccion d) {
    direcciones[cont] = d;
    cont++;
}