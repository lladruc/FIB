#include <iostream>
using namespace std;
 
int main() {
        int pre, pic, post;
        cin >> pre >> pic >> post;
        bool found = false;
 
        while (not found and post != 0) {
                if (pic > 3143 and pic > pre and pic > post) found = true;
                pre = pic;
                pic = post;
                cin >> post;
        }
        if (found) cout << "SI" << endl;
        else cout << "NO" << endl;
}