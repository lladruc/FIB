#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
typedef vector< vector<bool> > Tablero;
 
struct Casilla {
    int fila, columna;
};
 
/** Lee y escribe en el tablero los barcos
 *  @param Tablero a escribir */
void readMap(Tablero& map) {
    for (int i = 0; i < 10; ++i) {
        string pos;
        int q, fila, columna;
        char vh;
        cin >> pos >> q >> vh;
        fila = int(pos[0]) - int('a');
        columna = int(pos[1]) - int('0');
        // Comprobamos si es la posición 10
        if (pos.length() > 2) columna *= 10;
        // Restamos uno ya que las posiciones que nos pasan no empiezan por (0,0)
        --columna;
        for (int j = 0; j < q; ++j) {
            if (vh == 'v') // Vertical
                map[fila + j][columna] = true;
            else // Horizontal
                map[fila][columna + j] = true;
        }
    }
}
 
/** Lee y imprime el tablero
 *  @param Tablero con los barcos ya puestos */
void printMap(const Tablero& map) {
    cout << "  12345678910" << endl;
    char lletra = 'a';
    for (int i = 0; i < map.size(); ++i) {
        cout << lletra << " ";
        for (int j = 0; j < map[0].size(); ++j) {
            if (map[i][j]) cout << 'X';
            else cout << '.';
        }
        ++lletra;
        cout << endl;
    }
    cout << endl;
}
 
/** Calcula la casilla siguiente para comprobar
 *  @param Casilla actual
 *  @param direction de la casilla siguiente
 *  @return Casilla siguiente (con fila y columna ya cambiada) */
Casilla nextPosition(Casilla& pos, int direction) {
    if (direction == 1) // Hacia derecha
        ++pos.columna;
    else if (direction == 2) // Hacia abajo
        ++pos.fila;
    else if (direction == 3) // Hacia izquierda
        --pos.columna;
    else // Hacia arriba
        --pos.fila;
    return pos;
}
/** Calcula la distancia con el barco más cercano
 *  @param Tablero con los barcos ya puestos
 *  @param fila de la casilla con agua
 *  @param columna de la casilla con agua
 *  @return la distancia entre la casilla con agua y el barco más próximo */
int dist(const Tablero& map, int fila, int columna) {
    bool encontrado = false;
    int squareSize = 1;
    Casilla pos, fin;
    while (not encontrado) {
        // Los tamaños de los cuadrados serán 3, 5, 7 y 9
        squareSize += 2;
        pos.fila = fila - squareSize/2;
        pos.columna = columna - squareSize/2;
        fin = pos;
        int direction = 1, checked_positions = 0;
        // Buscaremos un barco en un cuadrado, recorrido en espiral
        // hasta volver a la casilla inicial o hasta encontrar una casilla con barco
        while (not encontrado and
            (direction != 4 or (pos.fila != fin.fila or pos.columna != fin.columna))) {
            // Si la casilla no está fuera del tablero
            if (not(pos.fila > 9 or pos.fila < 0 or pos.columna > 9 or pos.columna < 0))
                encontrado = map[pos.fila][pos.columna];
            ++checked_positions;
            // Comprobamos si hay que cambiar de dirección
            if (checked_positions >= squareSize) {
                ++direction;
                checked_positions = 1;
            }
            nextPosition(pos, direction);
        }
    }
    // El valor entero del tamaño del cuadrado entre 2 será la distancia encontrada
    return squareSize/2;
}
/** Lee cada uno de los disparos y escribe si ha tocado un barco.
 *  En caso contrario escribe la distancia con el barco más cercano.
 *  @param Tablero con los barcos ya puestos */
void shots(Tablero& map) {
    string pos;
    while (cin >> pos) {
        int fila = int(pos[0]) - int('a');
        int columna = int(pos[1]) - int('0');
        // Comprobamos si es la posición 10
        if (pos.length() > 2) columna *= 10;
        // Restamos uno ya que las posiciones que nos pasan no empiezan por (0,0)
        --columna;
        if (map[fila][columna])
            cout << pos << " tocat!" << endl;
        else
            cout << pos << " aigua! vaixell mes proper a distancia "
                << dist(map, fila, columna) << endl;
    }
}
 
int main() {
    Tablero map(10, vector<bool> (10, false));
    readMap(map);
    printMap(map);
    shots(map);
}
