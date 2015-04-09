#include <iostream>
#include <vector>
using namespace std;
 
typedef vector< vector<bool> > Matriz;
 
struct Punto {
    int y;
    int x;
};
 
int numero_de_bacterias_alrededor(const Matriz& mapeado, int fila_casilla, int columna_casilla, int n) {
    Punto a, b, c;
    a.y = fila_casilla;
    a.x = columna_casilla;
    b = c = a;
    if (a.y > 0) {
        --a.y;
        b.y = a.y;
    }
    if (a.x > 0) --a.x;
    if (b.x < n - 1) {
        ++b.x;
        c.x = b.x;
    }
    if (c.y < n - 1) ++c.y;
    int encontrados = 0;
    for (int i = a.y; i <= c.y; ++i) {
            for (int j = a.x; j <= b.x; ++j) {
                if (mapeado[i][j]) {
                    ++encontrados;
                }
            }
        }
    if (mapeado[fila_casilla][columna_casilla]) return encontrados - 1;
    else return encontrados;
}
 
// PRE: Entrada de una matriz con o sin bacterias y un entero n que pertenece al orden de la matriz.
// POS: Modifica la matriz según las condiciones del enunciado para vaciar una casilla o no y además
//      pasa por pantalla la matriz una vez se da una vuelta completa
void futura_matriz(Matriz& mapeado, int n) {
    bool cambio = false;
    for (int i = 0; i < n; ++i) {
    // Existen dos casos, que haciendo el ziga zaga vaya hacia arriba o hacia abajo, así que hago algo así como
    // un interruptor con el booleano "cambio" que vaya alternando el procedimiento.
        if (not cambio) {
            for (int j = 0; j < n; ++j) {
                if (not mapeado[j][i] and numero_de_bacterias_alrededor(mapeado, j, i, n) == 3) mapeado[j][i] = true;
                else if (mapeado[j][i] and numero_de_bacterias_alrededor(mapeado, j, i, n) >= 2) mapeado[j][i] = true;
                else mapeado[j][i] = false;
            }
            cambio = true;
        }
        else {
            for (int j = n - 1; j >= 0; --j) {
                if (not mapeado[j][i] and numero_de_bacterias_alrededor(mapeado, j, i, n) == 3) mapeado[j][i] = true;
                else if (mapeado[j][i] and numero_de_bacterias_alrededor(mapeado, j, i, n) >= 2) mapeado[j][i] = true;
                else mapeado[j][i] = false;
 
            }
            cambio = false;
        }
    }
    // Printo el mapeado
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mapeado[i][j]) cout << 'B';
            else cout << '.';
        }
        cout << endl;
    }
}
 
// PRE: Entrada de dos matrices
// POS: Devuelve un booleano acerca de si son iguales o no
bool igual(const Matriz& matriz1, const Matriz& matriz2) {
    for (int i = 0; i < matriz1.size(); ++i) {
        for (int j = 0; j < matriz2.size(); ++j) {
            if (matriz1[i][j] != matriz2[i][j]) return false;
        }
    }
    return true;
}
 
int main(){
    int n, v;
    cin >> n >> v;
    Matriz mapeado_original(n, vector<bool>(n));
    int fila, columna;
    // Voy llenando la matriz según los datos que me están entrando. Suponiendo
    // que nunca se va a exceder ese límite o la memoria hará "pof" y morirá.
    while (cin >> fila >> columna) mapeado_original[fila][columna] = true;
    // Imprimo la matriz resultante de poner en su sitio todas las bacterias
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mapeado_original[i][j]) cout << 'B';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
    Matriz mapeado(n, vector<bool>(n));
    mapeado = mapeado_original;
    futura_matriz(mapeado, n);
    cout << endl;
    --v;    // Ya que he dado una vuelta
    // Hay mejores formas de poner el cout sin booleanos? seguro, será productivo perder algo de tiempo? Ahora mismo no, así se queda.
    bool primer = true;
    bool ultimo_espacio = false;
    while (v > 0 and not igual(mapeado_original, mapeado)) {
        if (not primer)cout << endl;
        mapeado_original = mapeado;
        futura_matriz(mapeado, n);
        primer = false;
        --v;
        ultimo_espacio = true;
    }
    if (ultimo_espacio)cout << endl;
}