#include <iostream>
using namespace std;

int main(){
  int n;
  for(cin >> n;n>0;--n){
    int n1,n2,contador=0;
    cin >> n1;
    if(n1!=0){
      cin >> n2;
    }
    while(n2 !=0){
      if(n1<n2){
	++contador;
      }
    n1=n2;
    cin >> n2;
    }
    cout << contador << endl;
    contador=0;
  } //end for
}
 
