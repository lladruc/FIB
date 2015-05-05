/** @file Rellotge.hh
*  @brief Classe Rellotge

*/

#ifndef RELLOTGE_HH
#define RELLOTGE_HH
#include <string>
#include <iostream>
/** @class Rellotge
*  @brief Controla el pas del temps actualitzable per l'usuari. Aquest s'inicialitza a 20.04.15 00:00
*/


class Rellotge{

  public: 
  // Constructora
  Rellotge(); // inicialitze at: 20.04.15 00:00
  Rellotge(string date, string hora);
  bool operator<(const Rellotge& r) const;
  // Destructora
  ~Rellotge();

  //Consultores

  /** @brief Retorna un string del tipus dd.mm.yy
  * \pre Cert
  * \post Retorna la data completa en string "dd.mm.yy"
  */
  string getDate() const;

  /** @brief Retorna una string del tipus hh:mm
  * \pre Cert
  * \post Retorna l'hora completa en string "hh:mm"
  */
  string getTime() const;

  /** @brief Retorna una string del tipus dd.mm.yy hh:mm
  * \pre Cert
  * \post Retorna la data completa en string "dd.mm.yy hh:mm"
  */
  string getDateAndTime() const;

  /** @brief Escriu la data en format desitjat per l'usuari
  \pre Cert
  \post Retorna la data completa en string "dd.mm.yy hh:mm"
  */
  string printDateAndTime() const;

  /** @brief actualitza la data del sistema amb l'obtinguda
  * \pre el format de la data es correcte
  * \post si dataIn >= dataActual el rellotge s'actualitza amb la nova data.
  */
  void setDate(string date);

  /** @brief actualitza la hora del sistema amb l'obtinguda
  * \pre el formata de l'hora es correcte.
  * \post si horaIN >= horaActual del rellotge s'actualitza amb la nova data.
  */
  void setTime(string hora);

  /** @brief Actualitza la data del sistema amb l'obtinguda
  * \pre El format de la data completa es correcte.
  * \post Si la data >= dataActual || data=dataActual && hora >= horaActual, l'actualiza amb la nova data completa
  */
  void setTimeAndDate(string date, string hora);

  /** @brief Mostra torna la data en el format correcte dd.mm.yy
      \pre Cert
      \post la funcio retorna l'string amb el format de data dd.mm.yy
  */
  string printDate() const;

  /** @brief camiba yy <-> dd sobre el string.
    \pre El fotmat de data es: dd.mm.yy or yy.mm.dd
    \post retorna l'invers del dels pre dd <-> yy  el [.mm.] es mante estatic
  */
  string rollBack(string date) const;


  private:

  string date;
  string hora;
};

#endif