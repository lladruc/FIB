/** @file Event.hh
    @brief Classe Event.hh*/

#ifndef EVENT_HH
#define EVENT_HH

#include <iostream>
#include <string>
#include <stack>
#include "tag.hh"
/** @class Event 
    @brief Conté un únic event
 */

class Event{
private:
    string titol;
    Tag tagList;
    //array tags; // hay que perfilar esto ._.¡
public:
    //Constructora per defecte
    Event();
    //Constructora custom
    Event(string titol,stack<string> nTags);

    bool operator==(const Event& e)const ;
    //Destructora
    //~Event();

    /** @brief retorna el titol de l'event.
    	\pre Cert
    	\post retorna el titol de l'event.
    */
    string getTitol() const;
    
    /** @brief Metode que retorna un string amb tots 
               els tags de l'event separats per espais.
        \pre Cert
        \post Retorna un string amb tots els tags separats per espais 
              "#tag1 #tag2 #tagN"
    */
    string getTags() const;

    /** @brief Metode per assignar un nou titol
    	\pre Cert
    	\post Titol pren per valor el rebut per parametre
    */
    void setTitol(string titol);

    /** @brief Metode per assignar un nou tag a l'event
    	\pre Cert
    	\post Tags incloura el nou tag
    */
    void setTags(stack<string>& tags);

    /** @brief Metode de cerca d'una expresio regular de tags
        \pre Cert
        \post Retorna si l'event de l'agenda compleix la expresio regular
    */
    bool sRe(string s)const;
    
    /** @brief Funció de cerca de tags
    	\pre Cert
    	\post retorna true si es troba el tag
    */
    bool teTags()const;
    
    /** @brief Funció de cerca de tags
        \pre Cert
        \post retorna true si es troba el tag
    */
    bool findTag(string& tag)const;

    /** @brief Metode d'esborrat de tags de l'event
    	\pre Cert
    	\post tags conte tots els tags menys els rebuts
    */
    void delTag(string& tags);

    /** @brief Metode per esborrar tots els tags 
               [mes rapid que delTag [nomes per esborrar tots]]
    	\pre Cert
    	\post L'event no contindra cap tag
    */
    void delAllTags();
};

#endif
