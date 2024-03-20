#include "tablero.h"

Tablero::Tablero() {
    filas = 5;
    columnas = 5;
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            celdas[i][j] = VACIA;
            if (j%2 == 0) {
                celdas[i][j] = NULA;
            } else if (i == 2 or i == 1) {
                celdas[i][j] = FICHA;
            }
        }
        
    }
}

Tablero::Tablero(int filas, int columnas) {
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

int Tablero::valor_num_filas() const {
  return filas;
}

int Tablero::valor_num_columnas() const {
  return columnas;
}

bool Tablero::correcta(int f, int c) const {
    return f >= 0 && f < filas && c >= 0 && c < columnas;
}

Celda Tablero::valor_celda(int f, int c) const {
    Celda celda = NULA;

    if (f >= 0 && f < filas && c>=0 && c < columnas) {
        celda = celdas[f][c];
    }

    return celda;
}

void Tablero::fijar_valor_celda(int f, int c, Celda valor) {
  celdas[f][c] = valor;
}
