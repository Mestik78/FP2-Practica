#include <iostream>
#include <string>
#include "modules/juego.h"
#include "modules/jugada.h"
using namespace std;

Juego solitario;


bool cumple_formato_de_entrada(int fila, int columna,  int spacePos){
    return !(fila == 0 || columna == 0 || spacePos == string::npos);
}

Jugada pedir_jugada(Juego juego) {
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
    Jugada jugada(fila, columna);
    return jugada;
}

Jugada leer_jugada(Juego juego) {
    Jugada jugada(0, 0);
    do
    {
        jugada = pedir_jugada(juego);
        juego.cargar_posibles_direcciones(jugada);
        cout << jugada.valor_num_dirs();
    } while (jugada.valor_num_dirs() == 0);
    
    return jugada;
}


/*Jugada pedir_jugada(Juego juego) {
    
}

Jugada get_jugada(Juego juego) {
    do
    {
        
    } while ();
}*/

int main() {
    solitario.mostrar();
    do {
        Jugada jugada = leer_jugada(solitario);
        solitario.jugar(jugada);
        solitario.mostrar();
    } while (solitario.valor_estado() == JUGANDO);
}