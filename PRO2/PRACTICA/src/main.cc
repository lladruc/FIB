#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include "Agenda.hh"
#include "Comanda.hh"
#include "token.hh"
#include "Event.hh"
#include "Rellotge.hh"
#include "Tag.hh"

using namespace std;

/** @brief Menu de control del sistema
    \Pre La comanda conté la ordre entrada per consola
    \Post 
 */
void menu(Comanda& c, Agenda& a, vector<Rellotge>& v) {
    stack<string> tags;
    if (c.es_rellotge()) { // vol modificar el rellotge
        //case "consulta" ?
        if (c.es_consulta()) { //consulta el rellotge

            a.getClock().printDateAndTime();

        } else {//modificar el rellotge
            Rellotge rAux;            
	    if (c.nombre_dates() == 1 and c.te_hora()) { // hi ha hora i data
            
                rAux.setTimeAndDate(c.data(1), c.hora());

            } else if (c.te_hora()) {// hi ha hora

                rAux.setTime(c.hora());

            } else if (c.nombre_dates() == 1) { // hi ha data

                rAux.setDate(c.data(1));
		
            }
            
            if(a.getClock().getDate() < rAux.getDate() ){
	       a.setClock(rAux);
	    }else if(a.getClock().getDate() == rAux.getDate()){
	        if(a.getClock().getTime() < rAux.getTime()){
		  a.setClock(rAux);
		}
	    }
        }

    } else {

        if (c.nombre_etiquetes() > 0) { //omplim el stack de tags

            for (int i = 1; i <= c.nombre_etiquetes(); ++i) tags.push(c.etiqueta(i));

        }

        if (c.es_consulta()) {
	  
            Rellotge rAuxIni;
	        Rellotge rAuxEnd = a.getLast();
	      
            if (c.es_passat()) { //cerca elements inmediatament inferiors al present.
	      
	        a.listMatchEvents(c.expressio(), v, rAuxIni,  a.getClock()); 
                
            } else { //cerca present i events futurs

                if (c.nombre_dates() == 0) { // cerca sense dates

		    if (c.te_expressio()) { // cerca segons la expressio
		      
			a.listMatchEvents(c.expressio(), v, a.getClock(),  rAuxEnd);     
		      
		    }
		  
		} else if (c.nombre_dates() == 1) {
                    rAuxIni.setDate(c.data(1));
		            rAuxEnd.setDate(c.data(1));
		            rAuxEnd.setTime("00:00");
                    a.listMatchEvents(c.expressio(), v, rAuxIni, rAuxEnd); 

                } else if (c.nombre_dates() == 2) {
                   rAuxEnd = a.getLast();
		   a.listMatchEvents(c.expressio(), v, rAuxIni, rAuxEnd);
		   
                }

            }
            //case "add" +
        } else if (c.es_insercio()) {

            v = vector<Rellotge>();

            if (c.te_titol() and c.te_hora()) {


                if (c.nombre_dates() == 0) { // aqui la data es posara per defecte (la del rellotge)

                    a.addEvent(c.titol(), a.getClock().printDate(), c.hora(), tags); 

                } else if (c.nombre_dates() == 1) {
                    a.addEvent(c.titol(), c.data(1), c.hora(), tags);
                }

            }


        } else if (c.es_modificacio()) { //case "mod"
                                   
	   if( v.size() > c.tasca()-1){
	   string Titol = "";
	   Rellotge rAux(v[c.tasca()-1].printDate(),v[c.tasca()-1].getTime());
	  
	   if(c.te_titol()) Titol= c.titol();
	   
	   if(c.te_hora()) rAux.setTime(c.hora());
	   
	   if(c.nombre_dates() == 1) rAux.setDate(c.data(1));
	   
	   a.modEvent(v[c.tasca()-1], Titol, rAux.printDate(),rAux.getTime(),tags);
	   }else{
	     cout << "No s'ha realitzat." << endl;
	   }

        } else if (c.es_esborrat()) { //case "del" -

            if (c.tipus_esborrat() == "etiqueta") { 
                // Dru rules
                //v[c.tasca()-1].delTags(tags); 

            } else if ((c.tipus_esborrat() == "etiquetes")) {
                // Dru rules
                //v[c.tasca()-1].Tag(); 

            } else if ((c.tipus_esborrat() == "tasca")) {
                Rellotge rAux(v[c.tasca()-1].printDate(),v[c.tasca()-1].getTime());
                a.delEvent(rAux);  

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
    while (c.llegir(be)){
        if(be) menu(c, a, v);
    }
}
