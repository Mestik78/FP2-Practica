#include "movimiento.h"

Movimiento::Movimiento(int f, int c) {
    fila = f;
    columna = c;
}

int Movimiento::valor_num_dirs() const {
    return cont;
}

void Movimiento::insertar_dir(Direccion d) {
    direcciones[cont] = d;
    cont++;
}