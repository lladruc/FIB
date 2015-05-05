/** @file Event.hh
	@brief Classe Event.hh*/

#ifndef EVENT_HH
#define EVENT_HH

/** @class Event
	@brief Conté un únic event
 */

class Event{
private:
    string titol;
    Tag tags;
    //array tags; // hay que perfilar esto ._.¡
public:
    //Constructora per defecte
    Event();
    //Constructora custom
    Event(string titol,stack<string> tags);
    //Destructora
    ~Event();

    /** @brief retorna el titol de l'event.
    	\pre Cert
    	\post retorna el titol de l'event.
    */
    string getTitol() const;
    
    /** @brief Retorna un string amb tots els tags de l'event separats per espais.
		\pre Cert
		\post Retorna un string amb tots els tags separats per espais "#tag1 #tag2 #tagN"
    */
    string getTags() const;

    /** @brief Assigna un nou titol
    	\pre Cert
    	\post Titol pren per valor el rebut per parametre
    */
    void setTitol(string titol);

    /** @brief Assigna un nou tag a l'event
    	\pre Cert
    	\post Tags incloura el nou tag
    */
    void setTags(stack<string> tags);

    /** @brief Metode d'esborrat de tags de l'event
    	\pre Cert
    	\post tags conte tots els tags menys els rebuts
    */
    void delTag(stack<string> tags);

    /** @brief esborra tots els tags [mes rapid que delTag [nomes per esborrar tots]]
    	\pre Cert
    	\post L'event no contindra cap tag
    */
    void delAllTags();
};

#endif