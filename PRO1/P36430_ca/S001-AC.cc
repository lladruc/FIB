#include <iostream>
#include <math.h>
using namespace std;
 
int main(){
    int a,b,c,d;
    double z,w,y;
    bool trobat=false;
    cin >> a >> b >> c >> d;
    int i=a;
    int e=c;
    while (i<=b and not trobat){
        e=c;
        while(e<=d and not trobat){
            z = sqrt(i*i+e*e);
            y = int(z);
            w = z-double(y);
            if (w==0){
                    cout << i << "^2 + " << e << "^2 = " << y << "^2" << endl;
                    trobat=true;
            }
            ++e;
        }
        ++i;
    }
    if (not trobat) cout << "Sense solucio!" << endl;
}