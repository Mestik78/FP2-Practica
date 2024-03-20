#include "juego.h"
#include "colores.h"
#include "constantes.h"
#include <iomanip>
#include <iostream>

using namespace std;

/*
* Esto es un ejemplo de cómo pintar un tablero constante
* con el mismo formato que aparece en el enunciado de la
* práctica.
* Las funciones que aparecen a continuación hacen uso de
* varias constantes, para el tablero y sus dimensiones,
* o la posición de la meta.
* En la práctica, esas funciones seguramente sean métodos
* de una clase con acceso a esos datos del juego.
*/

const int DEFAULT_COLOR = -1;
void color_fondo(int color) {
    if (color == DEFAULT_COLOR)
        cout << RESET;
    else if (color == NULA)
        cout << BG_BLACK;
    else if (color == FICHA)
        cout << BG_LBLUE;
    else // color == VACIA
        cout << BG_ORANGE;
}

void pinta_cabecera(int COLS) {
    cout << setw(2) << "    "; // margen inicial
    cout << setw(5) << 1;
    for (int i = 2; i <= COLS; i++) {
        cout << setw(7) << i;
    }
    cout << endl;
}

void pinta_linea(char esquinaIzda, char cruce, char esquinaDer, int COLS) {
    cout << "    "; // margen inicial
    cout << esquinaIzda;
    for (int i = 0; i < COLS - 1; i++) {
        cout << string(6, char(196)) << cruce;
    }
    cout << string(6, char(196)) << esquinaDer << endl;
}


void pinta_borde_celda(int fila, int COLS, Tablero tablero) {
    cout << "    "; // margen inicial
    for (int k = 0; k < COLS; k++) { // cada columna
        cout << char(179);
        color_fondo(tablero.valor_celda(fila, k));
        cout << "      ";
        color_fondo(DEFAULT_COLOR);
    }
    cout << char(179) << endl; // lateral derecho
}

void pinta_centro_celda(int fila, int COLS, Tablero tablero, int f_meta, int c_meta) {
    cout << "  " << setw(2) << fila + 1; // margen inicial
    for (int k = 0; k < COLS; k++) { // cada columna
        cout << char(179);
        // el color de fondo depende del contenido
        color_fondo(tablero.valor_celda(fila, k));

        if (fila == f_meta && k == c_meta) { // meta
            cout << YELLOW;
            cout << "  " << char(219) << char(219) << "  ";
        }
        else {
            cout << "      ";
        }
        color_fondo(DEFAULT_COLOR);
    }
    cout << char(179) << endl; // lateral derecho
}

void Juego::mostrar() const {
    system("clear"); // borrar consola
    cout << RESET;

    Tablero tablero = this->tablero;
    int filas = tablero.valor_num_filas();
    int columnas = tablero.valor_num_columnas();

    // borde superior
    pinta_cabecera(columnas);
    pinta_linea(char(218), char(194), char(191), columnas);
    // para cada fila
    for (int fil = 0; fil < filas; fil++) {
        // primera línea
        pinta_borde_celda(fil, columnas, tablero);
        // segunda línea, con la meta posiblemente
        pinta_centro_celda(fil, columnas, tablero, f_meta, c_meta);
        // tercera línea
        pinta_borde_celda(fil, columnas, tablero);
        // separación entre filas
        if (fil < filas - 1) {
            pinta_linea(char(195), char(197), char(180), columnas);
        }
        else {
            pinta_linea(char(192), char(193), char(217), columnas);
        }
    }

}