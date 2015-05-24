#include <iostream>
#include <vector>
#include <stack>
#include "agenda.hh"
#include "comanda.hh"
#include "rellotge.hh"

using namespace std;

/** @brief Metode de insercio
    \pre c != NULL, a != NULL;
    \post Si la informació es correcte es guarda l'event
	  Si la informació no es correcte mostra per consola "No s'ha realitzat"
 */
void insercio(Comanda&c , Agenda& a,stack<string>& tags){

    if (c.te_titol() and c.te_hora()) { // pre del sistema
        if (c.nombre_dates() == 0) { // aqui la data es posara per defecte (la del rellotge)
            a.addEvent(c.titol(), a.getClock().printDate(), c.hora(), tags);
        } else if (c.nombre_dates() == 1) {
            a.addEvent(c.titol(), c.data(1), c.hora(), tags);
        }
    }else cout << "No s'ha realitzat" << endl;
}

/** @brief Metode de consulta 
    \pre c != NULL, a != NULL;
    \post Es retorna per consola un llistat 
          amb els elements seleccionats segons la comanda
 */
void consulta(Comanda& c, Agenda& a) {

    Rellotge rAuxIni;
    Rellotge rAuxEnd = a.getClock();
    string tag = "";
    
    if(c.nombre_etiquetes()==1) tag = c.etiqueta(1);

    if(c.es_passat()){
        a.pass_search(rAuxIni, rAuxEnd,tag);
    }else{

        if(c.nombre_dates() == 0){
                rAuxIni = a.getClock();
                rAuxEnd = Rellotge("31.12.99","23:59");
            }else if(c.nombre_dates() == 1){
                rAuxIni.setDate(rAuxIni.rollBack(c.data(1)));
                rAuxIni.setTime("00:00");
                if(rAuxIni < a.getClock()) rAuxIni = a.getClock();
                rAuxEnd.setDate(rAuxEnd.rollBack(c.data(1)));
                rAuxEnd.setTime("23:59");
            }else{ // nombre dates == 2
                rAuxIni.setDate(rAuxIni.rollBack(c.data(1)));
                if(rAuxIni < a.getClock()) rAuxIni = a.getClock();
                rAuxEnd.setDate(rAuxEnd.rollBack(c.data(2)));
                rAuxEnd.setTime("23:59");
            }
            // no importa si es passat o present+futur. Busca.

            //if(rAuxIni >= a.getClock() or rAuxEnd >= a.getClock()){
                if(c.te_expressio()){
                    if((not(rAuxIni < a.getClock())) or (not(rAuxEnd < a.getClock()))){
                        a.listMatchEvents(c.expressio(), rAuxIni, rAuxEnd); // SI!
                    }
                }else{
                    if((not(rAuxIni < a.getClock())) or (not(rAuxEnd < a.getClock()))){
                        a.search(rAuxIni, rAuxEnd,tag);
                    }
                }
            //}
    }
}

/** @brief Metode de modificació
    \pre c != NULL, a != NULL;
    \post Si la informació es correcte modifica la tasca seleccionada
          Si la informació es incorrecte mostra per consola "No s'ha realitzat"
 */
void modifica(Comanda& c, Agenda& a, stack<string>& tags) {
    if (a.resultsSize() >= c.tasca() and c.tasca() > 0 and a.vRe(c.tasca())) {
        string Titol = "";
        Rellotge rAux = a.vRi(c.tasca());
        if (c.te_titol()) Titol = c.titol();
        if (c.te_hora()) rAux.setTime(c.hora());
        if (c.nombre_dates() == 1) rAux.setDate(rAux.rollBack(c.data(1)));
        if(c.te_hora() and c.nombre_dates() == 1 and rAux == a.vRi(c.tasca())) cout << "No s'ha realitzat" << endl;
        else a.modEvent(c.tasca(),a.vRi(c.tasca()), Titol, rAux.printDate(), rAux.getTime(), tags);
    } else {
        cout << "No s'ha realitzat" << endl;
    }
}

/** @brief Metode per eliminar
    \pre c != NULL, a != NULL
    \post Segons la opció seleccionada 
          "etiqueta"  s'ha eliminat la etiqueta seleccionada de la tasca 
          "etiquetes" s'han eliminat totes les etiquetes de la tasca 
          "tasca"     s'ha eliminat la tasca seleccionada de la tasca 	  
 */
void elimina(Comanda& c, Agenda& a) {
    if(a.resultsSize() >= c.tasca() and c.tasca() > 0 and a.vRe(c.tasca())){
        if (c.tipus_esborrat() == "etiqueta") {
            //obtenir etiqueta
            a.delTag(a.vRi(c.tasca()),c.etiqueta(1));
            //no encuentro funcion para llegar hasta los tags del evento con el relog
    		//v[c.tasca()-1]; 
        } else if ((c.tipus_esborrat() == "etiquetes")) {
            a.delTags(a.vRi(c.tasca()));
            // Dru rules
          	//c.tasca()-1;
        } else if ((c.tipus_esborrat() == "tasca")) {
            Rellotge rAux(a.vRi(c.tasca()).printDate(), a.vRi(c.tasca()).getTime());
            a.delEvent(rAux,c.tasca());

        }
    }else{
        cout << "No s'ha realitzat" << endl;
    }
}
/** @brief Metode de consulta i modificació de rellotge
    \Pre La comanda conté la ordre entrada per consola
    \Post Segons la opció seleccionada es realitza 
          una (consulta, modificació, inserció o eliminació) de les tasques
 */
void rellotge(Comanda& c, Agenda& a){
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
}

/** @brief Menu de control del sistema
    \Pre La comanda conté la ordre entrada per consola
    \Post Segons la opció seleccionada es realitza 
          una (consulta, modificació, inserció o eliminació) de les tasques
 */
void menu(Comanda& c, Agenda& a) {
    stack<string> tags;
    if (c.nombre_etiquetes() > 0) { //omplim el stack de tags
        for (int i = 1; i <= c.nombre_etiquetes(); ++i) tags.push(c.etiqueta(i));
    }
    if(c.es_rellotge()){
        rellotge(c,a);
    }else if (c.es_consulta()) { // case ? or data,data
        if(not a.esBuit()) consulta(c, a);
    } else if (c.es_insercio()) { // case "add" +
        insercio(c,a,tags);
    } else if (c.es_modificacio()) { //case "mod"
        modifica(c, a, tags);
    } else if (c.es_esborrat()) { //case "del" -
        elimina(c, a);
    }
}

int main() {
    // Arrancar l'agenda i el rellotge intern
    Agenda a;
    // Crear llista/vector buit de tasques
    Comanda c;
    // bucle lectura dades
    bool be = false;
    bool exe = true;
    while (exe){
        exe = c.llegir(be);
        if (be) menu(c, a);
    }
}