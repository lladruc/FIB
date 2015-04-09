
#include <iostream>
#include <vector>
using namespace std;
//this one took forever
typedef vector < vector <int> > Tauler;
struct Punt {
  int x;
  int y;
};
struct Jugador {
    Punt pos;
    int punts;
    int caselles;
    bool sentit;
};
Tauler llegeix_tauler() {
    int llargada, amplada;
    cin >> llargada >> amplada;
    Tauler t(llargada, vector <int> (amplada));
    for(int i1 = 0; i1 < llargada; i1++) {
        for(int i2 = 0; i2 < amplada; i2++) {
            cin >> t[i1][i2];
        }
    }
    return t;
}
int valor_casella(const Punt& p, const Tauler& t) {
    return t[p.x][p.y];
}
void suma_punts(Jugador& J, const Tauler& t) {
    int valorCasella = valor_casella(J.pos, t);
    if(valorCasella >= 0) J.punts += valorCasella;
}
//PRE: introducimos ambos jugadores
//POS: inicializamos la puntuacion de cada jugador a el valor de su casilla inicial (en caso de que esta fuera positiva) y las casillas atravesadas de cada jugador a 1
//(ya que tenemos en cuenta que la casilla inicial también cuenta), también intoducimos las posiciones iniciales de nuestros dos jugadores y su sentido inicial de desplazamiento
void inicialitza_jugadors(Jugador& J1, Jugador& J2,const Tauler& t) {
    J1.caselles = 1;
    J2.caselles = 1;
    J1.pos.x = 0;
    J1.pos.y = 0;
    J2.pos.x = t.size() - 1;
    J2.pos.y = t[0].size() - 1;
    J1.punts = 0;
    J2.punts = 0;
    suma_punts(J1, t);
    suma_punts(J2, t);
    //sentit = true: va hacia la derecha
    //sentit = false: va hacia la izquierda
    J1.sentit = true;
    J2.sentit = false;
}
//he creado dos funciones diferentes, y cada una de ellas mueve el jugador 1 o el dos respectivamente. Lo he hecho con dos funciones porque el movimiento de ambos no es el mismo.
void moure_jugador_1(Jugador& J, const Tauler& t) {
    //aquí el jugador avanza. sentido = true significa que el jugador 1 va hacia la derecha, por lo tanto aumentamos x al llegar
    //al extremo derecho de la matriz
    if(J.sentit) {
        if(J.pos.y < t[0].size() -1) {
            J.pos.y += 1;
        }else {
            J.pos.x += 1;
            J.sentit = false;
        }
    //sentido = false significa que el jugador 1 va hacia la izquierda, por lo tanto aumentamos x al llegar
    //al extremo izquierdo de la matriz
    }else {
        if(J.pos.y > 0) {
            J.pos.y -= 1;
        }else {
            J.pos.x += 1;
            J.sentit = true;
        }
    }
}
void moure_jugador_2(Jugador& J, const Tauler& t) {
    //aquí el jugador avanza. sentido = true significa que el jugador 2 va hacia la derecha, por lo tanto decrementamos x al llegar
    //al extremo derecho de la matriz
    if(J.sentit) {
        if(J.pos.y < t[0].size() -1) {
            J.pos.y += 1;
        }else {
            J.pos.x -= 1;
            J.sentit = false;
        }
    //sentido = false significa que el jugador 2 va hacia la izquierda, por lo tanto decrementamos x al llegar
    //al extremo izquierdo de la matriz
    }else {
        if(J.pos.y > 0) {
            J.pos.y -= 1;
        }else {
            J.pos.x -= 1;
            J.sentit = true;
        }
    }
}
int turns_parat(Jugador& J, const Tauler& t) {
    int valorCasella = valor_casella(J.pos, t);
    if(valorCasella < 0) return valorCasella * -1 + 1;
    else return 0;
}
bool es_xoquen (const Jugador& J1,const Jugador& J2) {
    if(J1.pos.x == J2.pos.x and J1.pos.y == J2.pos.y){
        return true;
    }
    else return false;
}
//
void jugada(const Tauler& t) {
    Jugador Jugador_1, Jugador_2;
    inicialitza_jugadors(Jugador_1, Jugador_2, t);
    //inicializamos los turnos iniciales que los jugadores deberían permanecer parados (en caso de que hubiese)
    int pausa_1 = turns_parat(Jugador_1, t);
    int pausa_2 = turns_parat(Jugador_2, t);
    //variables que controlan el choque, una booleana para saber si se ha chocado, y otra, integrer, para determinar quien se ha chocado con quien
    bool esXoquen = false;
    int culpable_xoc = -1;
    while(!esXoquen) {
        //si hay turnos de pausa, ni sumamos puntos ni se mueve el jugador
        if(pausa_1 == 0){
            //movemos el jugador y comprobamos si se chocan
            moure_jugador_1(Jugador_1, t);
            esXoquen = es_xoquen(Jugador_1, Jugador_2);
            //si no se chocan, aumenta las casillas recorridas, aumenta los puntos (si es el caso) y declara los turnos de pausa (si es el caso)
            if(!esXoquen){
                ++ Jugador_1.caselles;
                suma_punts(Jugador_1, t);
                pausa_1 = turns_parat(Jugador_1, t);
            //si se han chocado, sabemos que el "culpable" ha sido el 1, que ha invadido al 2, por lo tanto, sería el ganador en caso de empate.
            }else culpable_xoc = 1;
        }
        //si hay turnos de pausa, ni sumamos puntos ni se mueve el jugador
        if(pausa_2 == 0 and !esXoquen){
            //ídem
            moure_jugador_2(Jugador_2, t);
            esXoquen = es_xoquen(Jugador_1, Jugador_2);
            //ídem
            if(!esXoquen){
                ++ Jugador_2.caselles;
                suma_punts(Jugador_2, t);
                pausa_2 = turns_parat(Jugador_2, t);
            //si se han chocado, sabemos que el "culpable" ha sido el 2, que ha invadido al 1, por lo tanto, sería el ganador en caso de empate.
            }else culpable_xoc = 2;
        }
        if(pausa_1 > 0) --pausa_1;
        if(pausa_2 > 0) --pausa_2;
    }
    //hacemos COUT dependiendo de las condiciones que nos han impuesto
    //Effectus huius pretiosa fuerit.
    if(Jugador_1.punts > Jugador_2.punts) {
        cout << "1: " << Jugador_1.punts << ' ' << Jugador_1.caselles << endl;
    }else if(Jugador_1.punts < Jugador_2.punts) {
        cout << "2: " << Jugador_2.punts << ' ' << Jugador_2.caselles << endl;
    }else if(Jugador_1.caselles > Jugador_2.caselles) {
        cout << "1: " << Jugador_1.punts << ' ' << Jugador_1.caselles << endl;
    }else if(Jugador_1.caselles < Jugador_2.caselles) {
        cout << "2: " << Jugador_2.punts << ' ' << Jugador_2.caselles << endl;
    }else if(culpable_xoc == 1) {
        cout << "1: " << Jugador_1.punts << ' ' << Jugador_1.caselles << endl;
    }else if(culpable_xoc == 2) {
        cout << "2: " << Jugador_2.punts << ' ' << Jugador_2.caselles << endl;
    }
}
int main() {    
    int numero_de_configuracions;
    cin >> numero_de_configuracions;
    for(int i = 0; i < numero_de_configuracions; i++) {
        Tauler t = llegeix_tauler();
        jugada(t);
    }
}