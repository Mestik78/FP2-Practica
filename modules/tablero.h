#pragma once
#include "constantes.h"

class Tablero {
    private:
        int filas, columnas;
        Celda celdas[MAXDIM][MAXDIM];
    public:
        Tablero();
        Tablero(int fil, int col);
        int valor_num_filas() const;
        int valor_num_columnas() const;
        bool correcta(int f, int c) const;
        Celda valor_celda(int f, int c) const;
        void fijar_valor_celda(int f, int c, Celda valor);
};