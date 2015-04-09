 #include <iostream>
using namespace std;

int main (){
    int sonA = 0, sonB = 0, sonC = 0, entrades, i;
    char entra;
    cin >> entrades;
    for ( i=0 ; i < entrades ; i++ ){
        cin >> entra;
        if( entra == 'a' ){
            ++sonA;
        }else if( entra == 'b' ){
            ++sonB;
        }else if( entra == 'c' ){
            ++sonC;
        }
    }
    cout << "majoria de ";
    if ( sonA >= sonB and sonA >=sonC ) {
        cout << "a" << endl << sonA;
    }else if ( sonB >= sonC ){
        cout << "b"<< endl << sonB;
    }else{
        cout << "c" << endl << sonC;
    }
    cout << " repeticio(ns)" << endl;
}
