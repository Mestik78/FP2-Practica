#pragma once
#include<iostream>
using namespace std;
const int DIMENSION = 100;
const int NUMDIR = 4;
const int DIM = 2;
const int DIRS[NUMDIR][DIM] = { -1,0,1,0,0,-1,0,1 };
const int MAXDIM = 10;
const int DEFAULT_COLOR = -1;
const int NUM_JUEGOS = 10;
consr int NUM_JUGADORES = 10;
typedef enum { ARRIBA, ABAJO, IZQUIERDA, DERECHA, INDETERMINADA } Direccion;
typedef enum { JUGANDO, GANADOR, BLOQUEO } Estado;
typedef enum { NULA, VACIA, FICHA } Celda;
string dirToString(Direccion d);