#include <iostream>
#include <string>
#include "modules/juego.h"
#include "modules/movimiento.h"
using namespace std;

Juego solitario;


bool cumple_formato_de_entrada(int fila, int columna,  int spacePos){
    return !(fila == 0 || columna == 0 || spacePos == string::npos);
}

Jugada pedir_movimiento(Juego juego) {
    string respuesta;
    int fila = 0;
    int columna = 0;
    int spacePos;

    do {
        cout << "Selecciona una FICHA (fila y columna): ";
        getline(cin, respuesta);
        spacePos = respuesta.find(" ");
        if (spacePos != string::npos)
        {
            fila = stoi(respuesta.substr(0,spacePos));
            columna = stoi(respuesta.substr(spacePos+1));
        }

        if (!cumple_formato_de_entrada(fila, columna, spacePos)) {
            cout << "No se cumple el formato de entrada." << endl;
        } else if (!juego.es_posicion_valida(fila-1, columna-1)) {
            cout << "La posición no es válida, selecciona una ficha." << endl;
        }
    } while (
        !cumple_formato_de_entrada(fila, columna, spacePos) || !juego.es_posicion_valida(fila-1, columna-1)
    ); 

    fila--;
    columna--;
    Jugada movimiento(fila, columna);
    return movimiento;
}

Jugada leer_movimiento(Juego juego) {
    Jugada movimiento(0, 0);
    do
    {
        movimiento = pedir_movimiento(juego);
        juego.cargar_posibles_direcciones(movimiento);
        cout << movimiento.valor_num_dirs();
    } while (movimiento.valor_num_dirs() == 0);
    
    return movimiento;
}


Jugada pedir_movimiento(Juego juego) {
    
}

Jugada get_movimiento(Juego juego) {
    do
    {
        
    } while ();
}

int main() {
    solitario.mostrar();
    do {
        Jugada movimiento = get_movimiento(solitario);
        solitario.jugar(movimiento);
        solitario.mostrar();
    } while (solitario.valor_estado() == JUGANDO);
}