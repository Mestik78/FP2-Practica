#include"Juego.h"
#include <iomanip>
#include "colores.h"
#include <iostream>
void Juego::ejecuta_movimiento(const Movimiento& mov) {
	int fil, col, dir;
	fil = mov.fila();
	col = mov.columna();
	dir = mov.valor_dir_activa();
	tablero.escribir(fil, col, VACIA);
	fil = fil + DIRS[dir][0];
	col = col + DIRS[dir][1];
	tablero.escribir(fil, col, VACIA);
	fil = fil + DIRS[dir][0];
	col = col + DIRS[dir][1];
	tablero.escribir(fil, col, FICHA);
	n_fichas--;
}
void Juego::nuevo_estado() {
	if (hay_ganador())
		estado_int = GANADOR;
	else if (hay_movimientos())
		estado_int = JUGANDO;
	else
		estado_int = BLOQUEO;
}
bool Juego::hay_ganador() const {
	return tablero.leer(f_meta, c_meta) == FICHA && n_fichas == 1;
}
bool Juego::hay_movimientos() const {
	int i = 0;
	bool mov = false;
	while (!mov && i < tablero.num_filas())
	{
		int j = 0;
		while (!mov&& j < tablero.num_columnas())
		{
			Movimiento m(i, j);
			posibles_movimientos(m);
			if (m.num_dirs() != 0)
			{
				mov = true;
			}
			j++;
		}
		i++;
	}
	return mov;
}
Juego::Juego() {
	Tablero t(0, 0);
	this->f_meta = 0;
	this->c_meta = 0;
	this->n_fichas = 0;
	this->estado_int = JUGANDO;
}

Juego::Juego(int movimientos)
{
	//crea el tablero nulo con la meta como una ficha
	int fil, col;
	fil = 4 + rand() % 6;
	col = 4 + rand() % 6;
	Tablero t(fil, col);
	tablero = t;
	estado_int = JUGANDO;
	n_fichas = 1;
	srand(time(NULL));
	f_meta = rand() % fil;
	c_meta = rand() % col;
	///////////////////////////////
	bool mov_ok = true;
	tablero.escribir(f_meta, c_meta, FICHA);// hacer el tablero al reves
	while (n_fichas <= movimientos && mov_ok) // el numero max de fichas es mov +1
	{
		mov_ok = mov_inverso(fil, col);
	}
}
// mov_inverso: es el que busca una ficha y mira sus posibles movimientos. parametros fil y col
// elegir_mov_inverso: es aquel que elige una direccion rand() 
// de las que estan disponibles y lo dibuja directamente.
void Juego::cargar(istream& entrada) {
	this->estado_int = JUGANDO;
	int fil, col;
	entrada >> fil;
	entrada >> col;
	Tablero t(fil, col);
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int valor;
			entrada >> valor;
			t.escribir(i, j, Celda(valor));
			if (Celda(valor)==FICHA)
			{
				n_fichas++;
			}
		}
	}
	this->tablero = t;
	entrada >> f_meta;
	entrada >> c_meta;
}
bool Juego::posicion_valida(int f, int c) const {
	return tablero.leer(f, c)==FICHA;
}
void Juego::posibles_movimientos(Movimiento& mov) const {
	int fil, col;
	fil = mov.fila();
	col = mov.columna();
	if (posicion_valida(fil,col))
	{
		for (int i = 0; i < NUMDIR; i++)
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
			fil = mov.fila();
			col = mov.columna();
		}
	}
	
}
Estado Juego::estado() const {
	return estado_int;
}
void Juego::jugar(const Movimiento& mov) {
	ejecuta_movimiento(mov);
	nuevo_estado();
}
void Juego::color_fondo(int color) const {
	if (color == DEFAULT_COLOR)
		cout << RESET;
	else if (color == NULA)
		cout << BG_BLACK;
	else if (color == FICHA)
		cout << BG_LBLUE;
	else // color == VACIA
		cout << BG_ORANGE;
}
void Juego::pinta_cabecera() const {
	cout << setw(2) << "    "; // margen inicial
	cout << setw(5) << 1;
	for (int i = 2; i <= tablero.num_columnas(); i++) {
		cout << setw(7) << i;
	}
	cout << endl;
}
void Juego::pinta_linea(char esquinaIzda, char cruce, char esquinaDer) const {
	cout << "    "; // margen inicial
	cout << esquinaIzda;
	for (int i = 0; i < tablero.num_columnas() - 1; i++) {
		cout << string(6, char(196)) << cruce;
	}
	cout << string(6, char(196)) << esquinaDer << endl;
}
void Juego::pinta_borde_celda(int fila) const {
	cout << "    "; // margen inicial
	for (int k = 0; k < tablero.num_columnas(); k++) { // cada columna
		cout << char(179);
		color_fondo(tablero.leer(fila,k));
		cout << "      ";
		color_fondo(DEFAULT_COLOR);
	}
  	cout << char(179) << endl; // lateral derecho
}
void Juego::pinta_centro_celda(int fila) const {
	cout << "  " << setw(2) << fila + 1; // margen inicial
	for (int k = 0; k < tablero.num_columnas(); k++) { // cada columna
		cout << char(179);
		// el color de fondo depende del contenido
		color_fondo(tablero.leer(fila,k));

		if (fila == f_meta && k == c_meta) { // meta
			cout << YELLOW;
			cout << "  " << char(219) << char(219) << "  ";
		}
		else {
			cout << "      ";
		}
		color_fondo(DEFAULT_COLOR);
	}
	cout << char(179) << endl;
}
bool Juego::mov_inverso(int fil, int col)
{
	bool pos_mov= true;
	int array[DIMENSION][DIM];// DIM ->(0,0) pos de la ficha
	int cont = 0; 
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (tablero.leer(i,j)==FICHA)
			{
				array[cont][0] = i;// fila
				array[cont][1] = j;//columna
				cont++;
			}
		}
	}
	Movimiento m;
	do
	{
		int f, c, posF;
		posF = rand() % cont; // elijo una de las fichas
		f = array[posF][0];
		c = array[posF][1];
		Movimiento mov(f, c);
		posibles_movimientos_inverso(mov);
		if (mov.num_dirs() >= 1)
		{
			int num = rand() % mov.num_dirs();
			bool correcto = false;
			while (!correcto) {
				if (num >= 0)
				{
					mov.fijar_dir_activa(mov.direccion(num));
					correcto = true;
				}
			}
		}
		if (mov.num_dirs() == 0)
		{
			eliminar(array, cont, posF);
			if (cont == 0)
			{
				pos_mov = false;
			}
		}
		m = mov;
	} while (!pos_mov);
	dibujar_mov_inverso(m); // dibuja en el tablero
	return pos_mov;
}
void Juego::dibujar_mov_inverso(const Movimiento& mov)
{
	int fil, col, dir;
	fil = mov.fila();
	col = mov.columna();
	dir = mov.valor_dir_activa();
	tablero.escribir(fil, col, VACIA);
	fil = fil + DIRS[dir][0];
	col = col + DIRS[dir][1];
	tablero.escribir(fil, col, FICHA);
	fil = fil + DIRS[dir][0];
	col = col + DIRS[dir][1];
	tablero.escribir(fil, col, FICHA);
	n_fichas++;
}
void Juego::posibles_movimientos_inverso(Movimiento& mov) const // te da el array posibles direcciones
{
	int fil, col;
	fil = mov.fila();
	col = mov.columna();
	if (posicion_valida(fil, col))
	{
		for (int i = 0; i < NUMDIR; i++)
		{
			fil = fil + DIRS[i][0];
			col = col + DIRS[i][1];
			if (tablero.leer(fil, col) != FICHA && tablero.correcta(fil, col))
			{
				fil = fil + DIRS[i][0];
				col = col + DIRS[i][1];
				if (tablero.leer(fil, col) != FICHA && tablero.correcta(fil, col))
				{
					mov.insertar_dir(Direccion(i));
				}
			}
			fil = mov.fila();
			col = mov.columna();
		}
	}
}
void Juego::eliminar(int arr[DIMENSION][DIM], int& cont, int pos)
{
	if (pos < cont) {
		for (int i = pos + 1; i < cont - 1; i++)
		{
			arr[i][0] = arr[i + 1][0];
			arr[i][1] = arr[i + 1][1];
		}
		cont--;
	}
}

void Juego::mostrar() const {
	system("cls"); // borrar consola
	cout << RESET;

	// borde superior
	pinta_cabecera();
	pinta_linea(char(218), char(194), char(191));
	// para cada fila
	for (int fil = 0; fil < tablero.num_filas(); fil++) {
		// primera línea
		pinta_borde_celda(fil);
		// segunda línea, con la meta posiblemente
		pinta_centro_celda(fil);
		// tercera línea
		pinta_borde_celda(fil);
		// separación entre filas
		if (fil < tablero.num_filas() - 1) {
			pinta_linea(char(195), char(197), char(180));
		}
		else {
			pinta_linea(char(192), char(193), char(217));
		}
	}
}