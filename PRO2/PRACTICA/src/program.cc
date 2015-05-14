#include <iostream>
#include <vector>
#include <stack>
#include "Agenda.hh"
#include "Comanda.hh"
#include "Rellotge.hh"

using namespace std;


void insercio(Comanda&c , Agenda& a,stack<string>& tags){

    if (c.te_titol() and c.te_hora()) { // pre del sistema
        if (c.nombre_dates() == 0) { // aqui la data es posara per defecte (la del rellotge)
            a.addEvent(c.titol(), a.getClock().printDate(), c.hora(), tags);
        } else if (c.nombre_dates() == 1) {
            a.addEvent(c.titol(), c.data(1), c.hora(), tags);
        }
    }else cout << "No s'ha realitzat" << endl;
}

/** @brief accio 
	\pre c != NULL, a != NULL, v != NULL;
    \post es retorna per consola un llistat amb els elements seleccionats segons la comanda
 */
void consulta(Comanda& c, Agenda& a, stack<string> tags) {

    Rellotge rAuxIni;
    Rellotge rAuxEnd = a.getClock();
    if (c.es_passat()) { //cerca elements inmediatament inferiors al present.
        a.search(v, rAuxIni, rAuxEnd);
    } else { //cerca present i events futurs
        if(c.nombre_dates() == 0){
            rAuxIni = a.getClock();
            rAuxEnd = Rellotge("31.12.99","23:59");
        }else if(c.nombre_dates() == 1){
            rAuxIni.setDate(c.data(1));
            rAuxEnd.setDate(c.data(1));
            rAuxEnd.setTime("23:59");
            /*
            if(rAuxIni < a.getClock()){
                rAuxIni.setDate(a.getClock().printDate());
                rAuxEnd.setDate(a.getClock().printDate());
            }
            */
        }else{
            rAuxIni.setDate(c.data(1));
            if(rAuxIni < a.getClock()) rAuxIni = a.getClock();
            rAuxEnd.setDate(c.data(2));
            rAuxEnd.setTime("23:59");
        }
        //if(rAuxIni >= a.getClock() or rAuxEnd >= a.getClock()){
            if(c.te_expressio()){
                a.listMatchEvents(c.expressio(), rAuxIni, rAuxEnd); // SI!
            }else if(c.nombre_etiquetes()==1){
                a.listMatchEvents(c.etiqueta(1),rAuxIni,rAuxEnd);
            }else{
                a.search(v, rAuxIni, rAuxEnd);
            
            }
        //}
    }
}

/** @brief
    \pre c != NULL, a != NULL, v != NULL;
    \post es modifica la tasca seleccionada
 */
void modifica(Comanda& c, Agenda& a, stack<string>& tags) {
    if (v.size() > c.tasca() - 1) {
        string Titol = "";
        Rellotge rAux(v[c.tasca() - 1].printDate(), v[c.tasca() - 1].getTime());
        if (c.te_titol()) Titol = c.titol();
        if (c.te_hora()) rAux.setTime(c.hora());
        if (c.nombre_dates() == 1) rAux.setDate(c.data(1));
       
        a.modEvent(v[c.tasca() - 1], Titol, rAux.printDate(), rAux.getTime(), tags);
    } else {
        cout << "No s'ha realitzat." << endl;
    }
}

/** @brief
    \pre c != NULL, a != NULL
    \post segons la opció seleccionada "etiqueta"  s'ha eliminat la etiqueta seleccionada de la tasca 
                           		       "etiquetes" s'han eliminat totes les etiquetes de la tasca 
                               		   "tasca"     s'ha eliminat la tasca seleccionada de la tasca 	  
 */
void elimina(Comanda& c, Agenda& a) {
    if(v.size() > c.tasca() -1){
        if (c.tipus_esborrat() == "etiqueta") {
            //obtenir etiqueta
            a.delTag(v[c.tasca()-1],c.etiqueta(1));
            //no encuentro funcion para llegar hasta los tags del evento con el relog
    		//v[c.tasca()-1]; 
        } else if ((c.tipus_esborrat() == "etiquetes")) {
            // Dru rules
          	//c.tasca()-1;
        } else if ((c.tipus_esborrat() == "tasca")) {
            Rellotge rAux(v[c.tasca() - 1].printDate(), v[c.tasca() - 1].getTime());
            a.delEvent(rAux);

        }
    }
}

/** @brief Menu de control del sistema
    \Pre La comanda conté la ordre entrada per consola
    \Post 
 */

void menu(Comanda& c, Agenda& a) {
    stack<string> tags;
    if (c.es_rellotge()) { // vol veure/modificar el rellotge
        //case "consulta" ?
        if (c.es_consulta()) { //consulta el rellotge
            cout << a.getClock().printDateAndTime() << endl;
        } else {//modificar el rellotge
            Rellotge rAux;
            if (c.nombre_dates() == 1 and c.te_hora()) { // hi ha hora i data
                rAux.setTimeAndDate(c.data(1), c.hora());
            } else if (c.te_hora()) {// hi ha hora
                rAux.setTimeAndDate(a.getClock().printDate(),c.hora());
            } else if (c.nombre_dates() == 1) { // hi ha data
                rAux.setTimeAndDate(c.data(1),a.getClock().getTime());
            }
            if (rAux < a.getClock()) cout << "No s'ha realitzat" << endl;
            else a.setClock(rAux);
        }
    } else {
        if (c.nombre_etiquetes() > 0) { //omplim el stack de tags
            for (int i = 1; i <= c.nombre_etiquetes(); ++i) tags.push(c.etiqueta(i));
        }
        if (c.es_consulta()) { // case ? or data,data
            if(not a.esBuit()) consulta(c, a, tags);
        } else if (c.es_insercio()) { // case "add" +
            insercio(c,a,tags);
        } else if (c.es_modificacio()) { //case "mod"
            modifica(c, a, tags);
        } else if (c.es_esborrat()) { //case "del" -
            elimina(c, a);
        }
    }
}

int main() {
    // Arrancar l'agenda i el rellotge intern
    Agenda a;
    // Crear llista/vector buit de tasques
    Comanda c;
    // Crear un vector vuit.
    // bucle lectura dades
    bool be = false;
    while (c.llegir(be)) {
        if (be) menu(c, a);
    }
}