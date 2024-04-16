#include"Juego.h"


using namespace std;
// pides las posiciones para mirar si tiene posibles movimiento
Movimiento  leer_movimiento(Juego j) {
	Movimiento mov;
	int fil, col;
	while (mov.valor_dir_activa() == INDETERMINADA)
	{
		// pegar la parte de pedir filas y columnas.
		cin >> fil;
		cin >> col;
		Movimiento temporal(fil-1, col-1);
		j.posibles_movimientos(temporal);
		if (temporal.num_dirs()> 1)
		{
			for (int i = 0; i < temporal.num_dirs(); i++)
			{
				cout << i + 1<< ":  " << temporal.direccion(i) << endl;
			}
			cout << "Elige una direccion: ";
			int num;
			cin >> num;
			cout << endl;
			num = num - 1;
			bool correcto = false;
			while (!correcto) {
				if (num < temporal.num_dirs() && num>=0)
				{
					mov.fijar_dir_activa(temporal.direccion(num));
					correcto = true;
				}
			}
		}
		if (temporal.num_dirs() == 1)
		{
			mov.fijar_dir_activa(temporal.valor_dir_activa());
		}
	}
	return mov;
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
