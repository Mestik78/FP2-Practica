#pragma once
#include <string>
using namespace std;

const int NUMDIR = 4;
const int DIM = 2;
const int DIRS[NUMDIR][DIM] = { -1,0,1,0,0,-1,0,1 };
const int MAXDIM = 10;

typedef enum { ARRIBA, ABAJO, IZQUIERDA, DERECHA, INDETERMINADA } Direccion;
typedef enum { JUGANDO, GANADOR, BLOQUEO } Estado;
typedef enum { NULA, VACIA, FICHA } Celda;

/*
string dirToString(Direccion d) {
    string dir;

    if (d = ARRIBA)
    {
        dir = "arriba";
    } else if (d = ABAJO)
    {
        dir = "abajo";
    } else if (d = IZQUIERDA)
    {
        dir = "izquierda";
    } else if (d = DERECHA)
    {
        dir = "derecha";
    }
    
    return dir;
}
*/