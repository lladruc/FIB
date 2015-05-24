#include <iostream>
#include <string>
using namespace std;


bool trobat(string s){
	cout << "s: " << s << endl;
	return true; 
}


void iRs(const string & s, int & i, bool& ok){ //const??
    char op;
    //cout << s[i]; //*******
    if (s[i] == '#') { //direct
        int j = 0;
        while((s[i + j] != '.' and s[i + j] != ',' 
            and s[i + j] != ')' and i+j != s.size())) ++j;
        ok = trobat(s.substr(i, j));
      //  cout << s.substr(i+1, j); //***********
        i += j;
    }else{ //inmersive
        ++i;
        iRs(s, i, ok);
        //H.I. ok conte el resultat del primer element de l'expressio
        bool okAux = ok;
        op = s[i];
        //cout << s[i]; //************
        ++i;
        if((ok and op == '.') or (not ok and op == ',')){
            iRs (s, i, ok);
            if(op == '.') ok = ok and okAux;
            else if(op == ',') ok = ok or okAux;
            ++i; 
        }else{
            while(s[i] != ')'){
          //    cout << s[i]; //*******
              ++i;
            }
            ++i;
        }
    }
}

/*
bool Activitat::te_etiqueta(const string& etiqueta) const {
    return etiquetes.find(etiqueta) != etiquetes.end();
}

*/


void i_rec(const string & s, int & i, bool & ok){
	//directe
	if(s[i] == '#'){
		int j = 0; //# necesita al menos una letra.
		while((s[i + j] != '.' and s[i + j] != ',' and s[i + j] != ')' and i+j != s.size())) ++j;
		ok = trobat(s.substr(i, j));
		i += j;
	}else{ //recursive
		char op = s[i];
		++i;
		i_rec(s, i, ok);
		bool ok1 = ok;
		++i;
		if((ok and op == '.') or (not ok and op == ',')){
			i_rec (s, i, ok);
			if(op == '.') ok = ok and ok1;
			else if(op == ',') ok = ok or ok1;
			++i; //equival al close parentesi
		}else{
			while(s[i] != ')') ++i;
			++i;
		}
	}
}


int main(){
	int i = 0;
	bool ok = false;
	string s = "((#tag1,#tag2).#tag3)";
	iRs(s,i,ok);
}