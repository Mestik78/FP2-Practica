#include"Juego.h"


using namespace std;
// pides las posiciones para mirar si tiene posibles movimiento
Movimiento  leer_movimiento(int fil, int col, Juego j) {
	int i = 0;
	while (i < NUMDIR)
	{
		fil = fil + DIRS[i][0];
		col = col + DIRS[i][1];
		if (tablero.leer(fil, col) == FICHA && tablero.correcta(fil, col))
		{
			fil = fil + DIRS[i][0];
			col = col + DIRS[i][1];
			if (tablero.leer(fil, col) == VACIA && tablero.correcta(fil, col))
			{
				mov.insertar_dir(Direccion(i));
			}
	}
	
}

int main() {
	Juego solitario;
	
	bool repetir = true;
	do
	{
		ifstream archivos;
		string archivo;
		cout << "Dame un archivo" << endl;
		//cin >> archivo;
		archivo = "tablero_enunciado.txt";
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
			if (solitario.estado()== GANADOR)
			{
				cout << "Has ganado";
			}
			else
			{
				cout << "Juego bloqueado";
			}
		}
		else
		{
			cout << "Error" << endl;
		}
	} while (repetir);
	return 0;
}
