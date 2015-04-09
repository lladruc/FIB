#include<iostream>
using namespace std;
 
int valencia(int n){
        int senars = 0;
        int parells = 0;
        while (n > 0){
                senars = senars + n%10;
                n = n/10;
                parells = parells + n%10;
                n = n/10;
        }
        if ((senars - parells) < 0) return (parells - senars);
        else return (senars - parells);
 
}
 
 
int main(){
        int n;
        bool trobat = false;  
        int max = 0;  
        while (not trobat and cin >> n ){
                if (valencia(n) == 0) trobat = true;
                else if (max < valencia(n)) max = valencia(n);
        }
        if (trobat) cout << "El primer nombre equilibrat es "
                << n << "." << endl;
        else cout << "La valencia maxima es " << max << "." << endl;          
}