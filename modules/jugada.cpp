#include "jugada.h"

Jugada::Jugada(int f, int c) {
    fila = f;
    columna = c;
}

int Jugada::get_num_dirs() const {
    return cont;
}

void Jugada::insertar_dir(Direccion d) {
    direcciones[cont] = d;
    cont++;
}

Direccion Jugada::valor_dir_activa() const {
    return dir_activa;
}

Direccion Jugada::valor_direccion(int i) const{
    return direcciones[i];
}