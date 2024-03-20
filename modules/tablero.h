#pragma once
#include "constantes.h"

class Tablero {
    private:
        int filas, columnas;
        Celda celdas[MAXDIM][MAXDIM];

        void generar_paso(int& f, int& c);
        void generar_tablero(int filas, int columnas, int pasos);
    public:
        Tablero();
        Tablero(int fil, int col);
        Tablero(int pasos);
        int valor_num_filas() const;
        int valor_num_columnas() const;
        bool esta_celda_en_tablero(int f, int c) const;
        Celda valor_celda(int f, int c) const;
        void fijar_valor_celda(int f, int c, Celda valor);
};