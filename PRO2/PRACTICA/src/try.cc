#include <iostream>
#include <string>
using namespace std;

/*	Pre:	Cert[Pre de consulta: conte una expressio correcte]
	Post:	i_search retorna si s'ha trobat la formula [a and b] or [a or b]
*/
bool i_search(string s){
	// For Debug Only!
	cout << "Entra: " << s << endl;
	bool reg_expr = false;
	int par = 0;
	int i;
	for(i = s.length()-2; i >= 0 and not reg_expr;--i){
		if(s[i]== ')') ++par;
		else if(s[i]== '(') --par;
		if((s[i]== '.' or s[i] == ',') and par == 0) reg_expr = true;
	}
	if(not reg_expr) return true; // aqui va la funcio de busqueda de la clase
	else{
		string s1, s2;
		char op = s[i+1];
		s1 = s.substr(1,i);
		s2 = s.substr(i+2,s.length()-i-3);
		// For Debug Only!
		cout << "S1: " << s1 << endl << "op: " << op << endl << "S2: " << s2 << endl;

		if(op == '.') return (i_search(s1) and i_search(s2));
		else return (i_search(s1) or i_search(s2));
	}
}

int main(){
	string s = "(((#recerca.#docencia),#art).#forum)";
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "((#tagA.#tagB).(#tagD,#tagE))";
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "#aloneTag";
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "(#t1.#t2)";
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;
}