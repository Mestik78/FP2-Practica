#include "tablero.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


int Tablero::valor_num_filas() const {
  return filas;
}

int Tablero::valor_num_columnas() const {
  return columnas;
}

bool Tablero::esta_celda_en_tablero(int f, int c) const {
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


void Tablero::generar_paso(int& f, int& c) {
    int dir, nf, nc;
    int posDir[NUMDIR];
    int numPosDir = 0;

    for (int i = 0; i < NUMDIR; i++)
    {
        nf = DIRS[i][0];
        nc = DIRS[i][1];

        if (
            esta_celda_en_tablero(f + 2*nf, c + 2*nc) &&
            valor_celda(f + nf, c + nc) != FICHA &&
            valor_celda(f + 2*nf, c + 2*nc) != FICHA
        ) {
            posDir[numPosDir] = i;
            numPosDir++;
        }
    }

    cout << "posDir:" << endl;
    for (int i = 0; i < numPosDir; i++)
    {
        cout << posDir[i] << ",";
    }
    cout << endl;
    

    if (numPosDir > 0) {
        dir = posDir[rand() % numPosDir];
        cout << "dir: " << dirToString(static_cast<Direccion>(dir)) << endl;

        nf = DIRS[dir][0];
        nc = DIRS[dir][1];

        cout << f + 2*nf << "," << c + 2*nc << endl;
        
        fijar_valor_celda(f,c, VACIA);
        fijar_valor_celda(f+nf,c+nc, FICHA);
        fijar_valor_celda(f+2*nf,c+2*nc, FICHA);

        f+=2*nf;
        c+=2*nc;
    }
}

void Tablero::generar_tablero(int filas, int columnas, int pasos) {
    srand(time(nullptr));

    int f = filas/2;
    int c = columnas/2;

    fijar_valor_celda(f, c, VACIA);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            fijar_valor_celda(i, j, NULA);
        }
    }

    
    for (int i = 0; i < pasos; i++)
    {
        generar_paso(f, c);
    }
    
}

Tablero::Tablero() {
    filas = 5;
    columnas = 5;
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            celdas[i][j] = VACIA;/*
            if (j%2 == 0) {
                celdas[i][j] = NULA;
            } else if (i == 2 or i == 1) {
                celdas[i][j] = FICHA;
            }*/
            if (i==1 && j == 1) {
                celdas[i][j] = FICHA;
            }
            if (i==2 && j == 1) {
                celdas[i][j] = FICHA;
            }
        }
        
    }
}

Tablero::Tablero(int pasos) {
    filas = 6;
    columnas = 6;
    generar_tablero(filas, columnas, pasos);
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