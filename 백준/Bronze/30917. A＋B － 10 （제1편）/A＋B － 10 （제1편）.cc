#include <iostream>
using namespace std;

int A, B, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(!x) {
        cout << "? A " << ++A << endl;
        cin >> x;
    }
    
    x = 0;
    while(!x) {
        cout << "? B " << ++B << endl;
        cin >> x;
    }
    
    cout << "! " << A + B;
    return 0;
}