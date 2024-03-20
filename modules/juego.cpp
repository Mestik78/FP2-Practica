#include "juego.h"
#include <iostream>

using namespace std;

Juego::Juego() {
    
}

Juego::Juego(int jugadas) {

}

Estado Juego::valor_estado() const {
    return JUGANDO;
}

void Juego::jugar(const Jugada& mov) {
    int f = mov.valor_fila();
    int c = mov.valor_columna();

    Direccion dir = mov.valor_direccion(mov.valor_dir_activa());
    int df = DIRS[dir][0];
    int dc = DIRS[dir][1];
    cout << "mov.valor_dir_activa(): " << mov.valor_dir_activa() << endl;
    cout << "int(mov.valor_dir_activa()): " << int(mov.valor_dir_activa()) << endl;
    cout << "df: " << df << endl;
    cout << "dc: " << dc << endl;

    tablero.fijar_valor_celda(f, c, VACIA);
    if (tablero.valor_celda(f + df, c + dc) == FICHA) {
        tablero.fijar_valor_celda(f + df, c + dc, VACIA);
    }
    tablero.fijar_valor_celda(f + 2 * df, c + 2 * dc, FICHA);
}

bool Juego::es_posicion_valida(int fila, int columna) const{
    return tablero.valor_celda(fila, columna) == FICHA;
}

void Juego::cargar_posibles_direcciones(Jugada& mov) const {
    for (int dir = 0; dir < NUMDIR; dir++)
    {
        int nf = mov.valor_fila() + 2 * DIRS[dir][0];
        int nc = mov.valor_columna() + 2 * DIRS[dir][1];
        if (tablero.valor_celda(nf, nc) == VACIA) {
            Direccion direccion = static_cast<Direccion>(dir);
            mov.insertar_dir(direccion);
        }
    }
    
}