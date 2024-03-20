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


void Tablero::generar_paso(int fichas[MAXDIM*MAXDIM][DIM], int& num_fichas) {
    int f,c;

    if (num_fichas == 1)
    {
        f = filas/2;
        c = columnas/2;
    } else {
        int id_ficha = rand()%num_fichas;
        f = fichas[id_ficha][0];
        c = fichas[id_ficha][1];
    }


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


    if (numPosDir > 0) {
        dir = posDir[rand() % numPosDir];

        nf = DIRS[dir][0];
        nc = DIRS[dir][1];

        
        fijar_valor_celda(f,c, VACIA);

        f+=nf;
        c+=nc;
        fijar_valor_celda(f,c, FICHA);
        fichas[num_fichas][0] = f;
        fichas[num_fichas][1] = c;
        num_fichas++;

        f+=nf;
        c+=nc;
        fijar_valor_celda(f,c, FICHA);
        fichas[num_fichas][0] = f;
        fichas[num_fichas][1] = c;
        num_fichas++;
    }
}

void Tablero::generar_tablero(int filas, int columnas, int f_meta, int c_meta, int pasos, int& num_fichas) {
    srand(time(nullptr));

    int f = f_meta;
    int c = c_meta;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            fijar_valor_celda(i, j, NULA);
        }
    }

    
    int fichas[filas*columnas][DIM];
    num_fichas = 1;

    for (int i = 0; i < pasos; i++)
    {
        generar_paso(fichas, num_fichas);
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

Tablero::Tablero(int pasos, int& fichas, int f_meta, int c_meta) {
    filas = 6;
    columnas = 6;
    generar_tablero(filas, columnas, f_meta, c_meta, pasos, fichas);
}