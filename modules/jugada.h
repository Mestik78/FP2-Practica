#pragma once
#include "constantes.h"

class Jugada {  //jugada
    private:
        int fila;
        int columna;
        Direccion dir_activa;
        // array parcialmente completo de direcciones a las
        // que nos podríamos mover desde (fila,columna)
        int cont;
        Direccion direcciones[NUMDIR];
    public:
        Jugada(int f, int c);
        int valor_fila() const;
        int valor_columna() const;
        Direccion valor_dir_activa() const;
        void fijar_dir_activa(Direccion d);
        void insertar_dir(Direccion d);
        int get_num_dirs() const;
        Direccion valor_direccion(int i) const;
};
