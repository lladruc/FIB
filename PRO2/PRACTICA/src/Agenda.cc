#include "Agenda.hh"
using namespace std;

typedef map<Rellotge,Event>::iterator evIt;

//Constructora per defecte
Agenda::Agenda(){
	Rellotge rTime;
	map<Rellotge,Event> calendar;
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
		calendar.insert(make_pair(rAux,eAux));

	}else{
		cout << "No s'ha realitzat" << endl;
	}
	
	//a.insert(make_pair(,));

}


void Agenda::modEvent(Rellotge key,string titol, string date, string hora, stack<string>& tags){}


void Agenda::delEvent(Rellotge key){}

string Agenda::escriure(const pair<Rellotge,Event>& e)const {
	return e.first.printDateAndTime() + " " + e.second.getTitol() + " " + e.second.getTags();
}

void Agenda::listMatchEvents(string hashtags,vector<Rellotge>& v,Rellotge ini, Rellotge end){
    map<Rellotge,Event>::const_iterator it = calendar.begin();
    int i = 1;
    while(it != calendar.end()){
      if(it->second.sRe(hashtags)){
		v.push_back(it->first);
      	cout << i << escriure((*it)) << endl;
      	++i;
      }
      ++it;
    }
  }

void Agenda::search(vector<Rellotge>& v, string ini, string end){
}
Rellotge Agenda::getClock() const{
	return rTime;
}
Rellotge Agenda::getLast() const{
	map<Rellotge,Event>::const_iterator it = calendar.end();
	--it;
	return (*it).first;
}
void Agenda::setClock(Rellotge& nuevo){
	rTime = nuevo;
}