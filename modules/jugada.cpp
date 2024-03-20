#include "jugada.h"
#include <iostream>

Jugada::Jugada(int f, int c) {
    fila = f;
    columna = c;
    cont = 0;
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

int Jugada::valor_fila() const {
    return fila;
}

int Jugada::valor_columna() const {
    return columna;
}

void Jugada::fijar_dir_activa(Direccion d) {
    dir_activa = d;
}