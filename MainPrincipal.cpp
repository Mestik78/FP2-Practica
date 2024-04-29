#include"Juego.h"
#include<fstream>
#include <iostream>
#include <string>

using namespace std;
// pides las posiciones para mirar si tiene posibles movimiento
Movimiento  leer_movimiento(Juego j) {
	Movimiento mov;
	int fil, col;
	while (mov.valor_dir_activa() == INDETERMINADA)
	{
		cout << "Dame una (fila, columnas): ";
		cin >> fil >> col;

		Movimiento temporal(fil-1, col-1);
		j.posibles_movimientos(temporal);
		if (temporal.num_dirs()> 1)
		{
			for (int i = 0; i < temporal.num_dirs(); i++)
			{
				cout << i + 1<< ":  " << dirToString(temporal.direccion(i)) << endl;
			}
			cout << "Elige una direccion: ";
			int num;
			cin >> num;
			num = num - 1;
			bool correcto = false;
			while (!correcto) {
				if (num < temporal.num_dirs() && num>=0)
				{
					temporal.fijar_dir_activa(temporal.direccion(num));
					correcto = true;
				}
			}
		}
		if (temporal.num_dirs() == 1)
		{
			temporal.fijar_dir_activa(temporal.direccion(0));
		}
		mov = temporal;
	}
	return mov;
}
int main() {
	Juego solitario;
	
	bool repetir = true;
	do{
		int mov;
		cout << "Elige cuantos movimientos quieres tener en el juego: ";
		cin >> mov;
		Juego j(mov);
		solitario = j;
		solitario.mostrar();
		do {
			Movimiento movimiento = leer_movimiento(solitario);

			solitario.jugar(movimiento);
			solitario.mostrar();
		} while (solitario.estado() == JUGANDO);
		if (solitario.estado()== GANADOR)
		{
			cout << "Has ganado" << endl;;
		}
		else
		{
			cout << "Juego bloqueado"<<endl;
		}
		char a;
		cout << "¿Quieres repetir S/N?" << endl;
		cin >> a;
		if (a == 'N' || a == 'n')
		{
			repetir = false;
		}
		else repetir = true;
	} while (repetir);
	return 0;
}
// sin random
/*int main() {
	Juego solitario;

	bool repetir = true;
	do
	{
		ifstream archivos;
		string archivo;
		cout << "Dame un archivo" << endl;
		//cin >> archivo;
		archivo = "tablero6x6.txt";
		archivos.open(archivo);
		if (archivos.is_open())
		{
			solitario.cargar(archivos);
		solitario.mostrar();
		do {
			Movimiento movimiento = leer_movimiento(solitario);

			solitario.jugar(movimiento);
			solitario.mostrar();
		} while (solitario.estado() == JUGANDO);
		if (solitario.estado() == GANADOR)
		{
			cout << "Has ganado" << endl;;
		}
		else
		{
			cout << "Juego bloqueado" << endl;
		}
		char a;
		cout << "¿Quieres repetir S/N?" << endl;
		cin >> a;
		if (a == 'N' || a == 'n')
		{
			repetir = false;
		}
		else repetir = true;
		}
		else
		{
			cout << "Error" << endl;
		}
	} while (repetir);
	return 0;
}*/