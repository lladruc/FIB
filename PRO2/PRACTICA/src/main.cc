#include <iostream>
#include <vector> // -> rly don't necessary.
#include <list>
#include <stack>
#include "Comanda.hh"
#include "Rellotge.hh"
#include "Tag.hh"

using namespace std;

/** @brief Menu de control del sistema
    \Pre La comanda conté la ordre entrada per consola
    \Post 
 */
void menu(Comanda& c, Agenda& a, vector<string>& v) {
    stack<string> tags;
    if (c.es_rellotge()) { // vol modificar el rellotge
        //case "consulta" ?
        if (c.es_consulta()) { //consulta el rellotge

            a.getClock().printDateAndTime();

        } else {//modificar el rellotge
            Rellotge raux;            
	    if (c.nombre_dates() == 1 and c.te_hora()) { // hi ha hora i data
            
                raux.setTimeAndDate(c.data(1), c.hora());

            } else if (c.te_hora()) {// hi ha hora

                raux.setTime(c.hora());

            } else if (c.nombre_dates() == 1) { // hi ha data

                raux.setDate(c.data(1));
		
            }
            
            if(a.getClock().getDate() < raux.getDate() ){
	       a.setClock(raux);
	    }else if(a.getClock().getDate() == raux.getDate()){
	        if(a.getClock().getTime() < raux.getTime()){
		  a.setClock(raux);
		}
	    }
        }

    } else {

        if (c.nombre_etiquetes() > 0) { //omplim el stack de tags

            for (int i = 1; i <= c.nombre_etiquetes(); ++i) tags.push(c.etiqueta(i));

        }

        if (c.es_consulta()) {
	  
            Rellotge rAuxIni();
	    Rellotge rAuxEnd();
	      
            if (c.es_passat()) { //cerca elements inmediatament inferiors al present.
	      
	        listMatchEvents(c.expressio(), v, rAuxIni,  a.getClock()); 
                
            } else { //cerca present i events futurs

                if (c.nombre_dates() == 0) { // cerca sense dates

		    if (c.te_expressio()) { // cerca segons la expressio
		      
			listMatchEvents(c.expressio(), v, rAuxIni,  rAuxEnd());     
		      
		    }
		  
		} else if (c.nombre_dates() == 1) {
                    rAuxIni.setDate(c.data(1));
		    rAuxEnd.setDate(c.data(1));
		    rAuxEnd.setTime("00:00");
                    listMatchEvents(c.expressio(), v, rAuxIni, rAuxEnd); 

                } else if (c.nombre_dates() == 2) {
                   rAuxEnd = a.getLast();
		   listMatchEvents(c.expressio(), v, rAuxIni, rAuxEnd);
		   
                }

            }
            //case "add" +
        } else if (c.es_insercio()) {

            v = new vector<string>(0);

            if (c.te_titol() and c.te_hora()) {


                if (c.nombre_dates() == 0) { // aqui la data es posara per defecte (la del rellotge)

                    addEvent(c.titol(), a.printdate(), c.hora(), tags); 

                } else if (c.nombre_dates() == 1) {
                    addEvent(c.titol(), c.data(), c.hora(), tags);
                }

            }


        } else if (c.es_modificacio()) { //case "mod"
                                   
	   if( v.size() < c.tasca()-1){
	   String Titol = "";
	   Rellotge rAux(v[c.tasca()-1].getDate,v[c.tasca()-1]);
	  
	   if(c.te_titol()) Titol= c.titol();
	   
	   if(c.te_hora()) rAux.setTime(c.hora())
	   
	   if(c.nombre_dates() == 1) rAux.setDate(c.data(1));
	   
	   a.modEvent(v[tasca()-1], rAux.printDate,raux.printTime(),tags);
	   }else{
	     cout << "No s'ha realitzat." << endl;
	   }

        } else if (c.es_esborrat()) { //case "del" -

            if (c.tipus_esborrat() == "etiqueta") { 

                v[c.tasca()-1].delTags(tags); 

            } else if ((c.tipus_esborrat() == "etiquetes")) {

                v[c.tasca()-1].Tag(); 

            } else if ((c.tipus_esborrat() == "tasca")) {

                a.delEvent(v[c.tasca()-1]);  

            }
        }
    }
}

int main() {
    // Arrancar l'agenda i el rellotge intern
    Agenda a;
    // Crear llista/vector buit de tasques
    Comanda c;
    // Crear un vector vuit.
    vector<Rellotge> v;
    // bucle lectura dades
    bool be = false;
    while (c.llegir(be)) {
        if (be) menu(c, a, v, r)
        }
}
