#include "Agenda.hh"
using namespace std;

typedef map<Rellotge,Event>::iterator evIt;

//Constructora per defecte
Agenda::Agenda(){
	Rellotge rTime;
	map<Rellotge,Event> calendar;
	vector<Rellotge> v();
}

//Constructora personalitzada [posible delete.]
//Agenda::Agenda(){
//}

//Destructora
//Agenda::~Agenda();


//deveria ser una función privada que dependa de otra función de la clse basada en el control y esta si deberia ser pública.
//Dada la cantidad de errores a gestionar, vale la pena una función pública o una clase con metodos públicos de gestión de errores? O.o¡
void Agenda::addEvent(string titol, string date, string hora, stack<string>& tags){
	Rellotge rAux(date,hora);
	if(rTime < rAux){ //no estamos viajando al pasado
		Event eAux(titol,tags);
		evIt it = calendar.find(rAux);
		if(it == calendar.end()) calendar.insert(make_pair(rAux,eAux));
		else cout << "No s'ha realitzat" << endl;

	}else{
		cout << "No s'ha realitzat" << endl;
	}
}


void Agenda::modEvent(int i,string titol, string date, string hora, stack<string>& tags){
	map<Rellotge,Event>::iterator it = calendar.find(key);
	Rellotge rAux(date,hora);
	if(it->first < rAux){
		if(titol != "") it->second.setTitol(titol);
		if(not tags.empty()) it->second.setTags(tags);	
		calendar.erase(it);
		calendar.insert(make_pair(rAux,it->second));
	}else{
		cout << "No s'ha realitzat" << endl;
	}
}


void Agenda::delEvent(int i){
	if(calendar.erase(calendar.find(key)->first) == 0) cout << "No s'ha realitzat" << endl;
}

string Agenda::escriure(const pair<Rellotge,Event>& e)const {
	return e.first.printDateAndTime() + " " + e.second.getTitol() + " " + e.second.getTags();
}

/** @brief Funció de busqueda per expresió regular
	\pre Cert [Pre: Expresió correca definida per comanda]
	\post v[] conté
*/
void Agenda::listMatchEvents(string hashtags,Rellotge& ini, Rellotge& end){
    map<Rellotge,Event>::const_iterator it = calendar.begin();
    int i = 1;
    while(it != calendar.end()){
      if(it->second.sRe(hashtags)){
		v.push_back(it->first);
      	cout << i << " " << escriure((*it)) << endl;
      	++i;
      }
      ++it;
    }
  }

void Agenda::search(Rellotge& ini, Rellotge& end){
  map<Rellotge,Event>::const_iterator it = calendar.lower_bound(ini);
  map<Rellotge,Event>::const_iterator itEnd = calendar.upper_bound(end);
    int i = 1;
    while(it != calendar.end()){
      if(it->second.sRe(hashtags)){
		v.push_back(it->first);
      	cout << i << " " << escriure((*it)) << endl;
      	++i;
      }
      ++it;
    }
  }
  
}

void Agenda::delTag(int i, string tag){
	evIt it = calendar.find(key);
	it->second.delTag(tag);
}

void Agenda::delTags(Rellotge& key){
	evIt it = calendar.find(key);
	it->second.delAllTags();
}


Rellotge Agenda::getClock() const{
	return rTime;
}

void Agenda::setClock(Rellotge& nuevo){
	rTime = nuevo;
}

int Agenda::resultsSize(){
	return v.size();
}

bool Agenda::esBuit() const{
	return calendar.empty();
}