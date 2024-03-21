#include "juego.h"
#include <iostream>

using namespace std;

Juego::Juego() {
    new (this) Juego(DEFMOVS, MAXDIM, MAXDIM);
}

Juego::Juego(int jugadas) {
    new (this) Juego(jugadas, MAXDIM, MAXDIM);
}

Juego::Juego(int filas, int columnas) {
    new (this) Juego(DEFMOVS, filas, columnas);
}

Juego::Juego(int jugadas, int filas, int columnas) {
    estado = JUGANDO;

    filas = filas % (MAXDIM+1);
    columnas = columnas % (MAXDIM+1);

    f_meta = filas/2;
    c_meta = columnas/2;

    Tablero t(jugadas, filas, columnas , n_fichas, f_meta, c_meta);
    tablero = t;
}

Estado Juego::valor_estado() const {
    return estado;
}

void Juego::jugar(const Jugada& jug) {
    int f = jug.valor_fila();
    int c = jug.valor_columna();

    Direccion dir = jug.valor_direccion(jug.valor_dir_activa());
    int df = DIRS[dir][0];
    int dc = DIRS[dir][1];

    tablero.fijar_valor_celda(f, c, VACIA);
    if (tablero.valor_celda(f + df, c + dc) == FICHA) {
        tablero.fijar_valor_celda(f + df, c + dc, VACIA);
        n_fichas--;
    }
    tablero.fijar_valor_celda(f + 2 * df, c + 2 * dc, FICHA);
}

bool Juego::es_posicion_valida(int fila, int columna) const{
    return tablero.valor_celda(fila, columna) == FICHA;
}

void Juego::cargar_posibles_direcciones(Jugada& jug) const {
    for (int dir = 0; dir < NUMDIR; dir++)
    {
        int nf = jug.valor_fila() ;
        int nc = jug.valor_columna();

        nf += DIRS[dir][0];
        nc += DIRS[dir][1];

        if (tablero.valor_celda(nf, nc) == FICHA) {
            nf += DIRS[dir][0];
            nc += DIRS[dir][1];

            if (tablero.valor_celda(nf, nc) == VACIA) {
                Direccion direccion = static_cast<Direccion>(dir);
                jug.insertar_dir(direccion);
            }
        }
    }
    
}

void Juego::check_estado() {
    if (n_fichas <= 1) {
        int f,c;
        for (int i = 0; i < tablero.valor_num_filas(); i++)
        {
            for (int j = 0; j < tablero.valor_num_columnas(); j++)
            {
                if (tablero.valor_celda(i, j) == FICHA) {
                    f = i;
                    c = j;
                }
            }
        }
        Jugada jug(f,c);
        cargar_posibles_direcciones(jug);
        
        if (jug.get_num_dirs() == 0) {
            estado = BLOQUEO;
        }

        if (f == f_meta && c == c_meta) {
            estado = GANADOR;
        }
    }
}

int Juego::get_n_fichas() {
    return n_fichas;
}