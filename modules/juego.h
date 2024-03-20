#pragma once
#include <istream>
#include "constantes.h"
#include "tablero.h"
#include "movimiento.h"
using namespace std;

class Juego {
    private:
        Tablero tablero;
        int f_meta, c_meta;
        Estado estado;
        int n_fichas;
        void ejecuta_movimiento(const Jugada& mov);
        void nuevo_estado();
        bool hay_ganador() const;
        bool hay_movimientos() const;
    public:
        Juego();
        Juego(int movimientos);
        void cargar(ifstream& entrada);
        bool es_posicion_valida(int f, int c) const;
        void cargar_posibles_direcciones(Jugada& mov) const;    //posibles_movimientos
        Estado valor_estado() const;
        void jugar(const Jugada& mov);
        void mostrar() const;
};