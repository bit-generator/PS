#include <iostream>
using namespace std;

int a1, a2, a3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> a1 >> a2 >> a3;
        if(!a1 && !a2 && !a3) break;
        
        if(a1 + a3 == a2 * 2) {
            cout << "AP " << a3 + (a2 - a1) << '\n';
        }
        else {
            cout << "GP " << a3 * (a2 / a1) << '\n';
        }
    }
    
    return 0;
}