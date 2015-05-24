/** @file Agenda.hh
 *  @brief Classe Agenda

*/

#ifndef AGENDA_HH
#define AGENDA_HH

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>
#include "rellotge.hh"
#include "tag.hh"
#include "event.hh"

using namespace std;

typedef map<Rellotge,Event>::iterator evIt;
/** @class Agenda
 *  @brief Conte el conjunt 
 */


class Agenda{
private:
  Rellotge rTime;  //rTime short's realTime's name.
  map<Rellotge, Event> calendar;
  vector<pair<Rellotge,bool> > v;
  
public: 
  // Constructora
  Agenda(); 
  
  // Destructora
  //~Agenda();
  
  //Consultores
  
  /** @brief Metode universal per agregar un event
   * \pre Els camps no poden ser "empty", excepte tags
   * \post si l'event no es passat i no existeix un altre event en la mateixa data i hora exactes, s'haura agregat a l'agenda.
   */
  void addEvent(string titol, string date, string hora, stack<string>& tags);

  /** @Brief Metode universal per modificar un event
      \pre Almenys un dels camps no pot ser "empty"
      \post Si no viatja al passat, l'event s'ha modificat
  */
  void modEvent(int i,Rellotge key,string titol, string date, string hora,stack<string>& tags);
  
  /** @brief Metode de borrat de l'event
      \pre Cert
      \post Agenda conte els events excepte el marcat pel rellotge
  */
  void delEvent(Rellotge key, int i);

  /** @brief Metode de impresió d'un event
      \pre Cert
      \post String conté "dd.mm.yy hh:mm titol #tag1 #tag2 #tagN"
  */
  string escriure(const pair<Rellotge,Event>& e) const;

  /** @brief Metode de consulta per expresió regular
      \pre Vector v is "empty"
      \post v conte els elements que coincideixen en l'expresio regular
  */
  void listMatchEvents(string hashtags,Rellotge& ini, Rellotge& end);

  /** @brief Metode de consulta generic en funció de dates, passat.
      \pre Data inicial o data final no son buits
           Les dates compleixen el format dd.mm.yy 
           [on Rellotge use method printDate and printHour];
      \post Vector v conte els elements que coincideixen en l'expresio regular
  */
  void pass_search(Rellotge ini, Rellotge& end,string& tag);
  
  /** @brief Metode de consulta generic en funció de dates, present o futur.
      \pre Data inicial o data final no son buits
           Les dates compleixen el format dd.mm.yy 
           [on Rellotge use method printDate and printHour];
      \post Vector v conte els elements que coincideixen en l'expresio regular
  */
  void search(Rellotge ini, Rellotge& end,string& tag);
  
  /** @brief Metode per borrar un tag segons el rellotge
      \pre key != NULL , tag != NULL
      \post Elimina el tag del event amb aquest rellotge 
            com identificador
  */
  void delTag(Rellotge key, string tag);
  
  /** @brief Metode per borrar tots els tags segons el rellotge
      \pre key != NULL
      \post Elimina tots els tag del event amb aquest rellotge 
            com identificador
  */
  void delTags(Rellotge key);

  /** @brief Metode de consulta del rellotge
      \pre Cert
      \post Retorna el rellotge amb hora i data diferents de null
  */
  Rellotge getClock() const;

  /** @brief Metode per Modificar el rellotge
      \pre Cert
      \post Si nuevo es >= que rTime es modifica
  */
  void setClock(Rellotge& nuevo);

  /** @brief Metode que retorna l'iesim rellotge del vector de rellotges
      \pre Cert
      \post Retorna el Rellotge de la iesima posició
   */
  Rellotge vRi(int i);

  /** @brief Metode que si l'iesim event si existeix i no es passat
      \pre Cert
      \post Retorna true si existeix i no es passat
   */
  bool vRe(int i);

  /** @brief Metode que retorna el tamany del vector de rellotges
      \pre Cert
      \post Retorna el tamany de vector de rellotges
   */
  int resultsSize();
  
  /** @brief Metode que indica si el calendar esta buit
      \pre Cert
      \post Retorna true si el calendar es buit 
   */
  bool esBuit()const;
};

#endif
