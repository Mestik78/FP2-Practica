#pragma once
#include "constantes.h"

class Tablero {
    private:
        int filas, columnas;
        Celda celdas[MAXDIM][MAXDIM];

        void generar_paso(int fichas[MAXDIM*MAXDIM][DIM], int& num_fichas);
        void generar_tablero(int filas, int columnas, int f_meta, int c_meta, int pasos, int& num_fichas);
    public:
        Tablero();
        Tablero(int pasos, int& fichas, int f_meta, int c_meta);
        int valor_num_filas() const;
        int valor_num_columnas() const;
        bool esta_celda_en_tablero(int f, int c) const;
        Celda valor_celda(int f, int c) const;
        void fijar_valor_celda(int f, int c, Celda valor);
};