#include "tablero.h"

Tablero::Tablero() {
    filas = 5;
    columnas = 5;
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            celdas[i][j] = FICHA;
            if (j%2 == 0) {
                celdas[i][j] = NULA;
            }
        }
        
    }
}

Celda Tablero::valor_celda(int f, int c) const {
    Celda celda = NULA;

    if (f >= 0 && f < filas && c>=0 && c < columnas) {
        celda = celdas[f][c];
    }

    return celda;
}

int Tablero::valor_num_filas() const {
    return this->filas;
}

int Tablero::valor_num_columnas() const {
    return this->columnas;
}