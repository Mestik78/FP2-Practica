#include "juego.h"
#include <iostream>

using namespace std;

Juego::Juego() {
    
}

Juego::Juego(int movimientos) {

}

Estado Juego::valor_estado() const {
    return JUGANDO;
}

void Juego::jugar(const Jugada& mov) {
    
}

bool Juego::es_posicion_valida(int fila, int columna) const{
    return tablero.valor_celda(fila, columna) == FICHA;
}

void Juego::cargar_posibles_direcciones(Jugada& mov) const {
    for (int dir = 0; dir < NUMDIR; dir++)
    {
        if (tablero.valor_celda(DIRS[dir][0], DIRS[dir][1])) {
            Direccion direccion = Direccion(dir);
            mov.insertar_dir(ARRIBA);
        }
    }
    
}