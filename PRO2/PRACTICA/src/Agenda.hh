/** @file Agenda.hh
 *  @brief Classe Agenda

*/

#ifndef AGENDA_HH
#define AGENDA_HH

typedef map<Rellotge,Event>::iterator Rellotge;
/** @class Agenda
 *  @brief Conte el conjunt 
 */


class Agenda{
private:
  Rellotge rTime;  //rTime short's realTime's name.
  map<Rellotge, Event> calendar;
  
public: 
  // Constructora
  Agenda(); 
  
  // Destructora
  ~Agenda();
  
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
  void modEvent(Rellotge key,string titol, string date, string hora, stack<string>& tags);
  
  /** @brief Metode de borrat de l'event
      \pre Cert
      \post Agenda conte els events excepte el marcat pel rellotge
  */
  void delEvent(Rellotge key);

  /** @brief Metode de impresió d'un event
      \pre Cert
      \post String conté "dd.mm.yy hh:mm titol #tag1 #tag2 #tagN"
  */
  string Agenda::print() const;

  /** @brief Metode de consulta per expresió regular
      \pre Vector v is "empty"
      \post v conte els elements que coincideixen en l'expresio regular
  */
  void listMatchEvents(string& tags,vector<string>& v, Rellotge ini, Rellotge end);

  /** @brief Metode de consulta generic en funció de dates, present o futur.
      \pre data inicial o data final no son buits
      \pre les dates compleixen el format dd.mm.yy [on Rellotge use method printDate and printHour];
      \post Vector v conte els elements que coincideixen en l'expresio regular
  */
  void search(vector<string>& v, string ini, string end);
  
  /** @brief Metode de consulta del rellotge
      \pre Cert
      \post retorna el rellotge amb hora i data diferents de null
  */
  Rellotge getClock() const;

  /** @brief Metode de consulta de la ultima data
      \pre calendar != null
      \post retorna la data futura mes llunyana
  */
  Rellotge getLast() const;

  /** @brief Metode per Modificar el rellotge
      \pre nuevo != null
      \post s'ha modificar el rellotge
  */
  void setRellotge(Rellotge& nuevo);
};

#endif
