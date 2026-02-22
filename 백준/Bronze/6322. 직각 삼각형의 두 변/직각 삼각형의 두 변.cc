#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int tc = 1; ; ++tc) {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        
        cout << "Triangle #" << tc << '\n';
        if(a == -1) {
            if(b >= c) cout << "Impossible.\n";
            else {
                cout << "a = " << fixed;
                cout.precision(3);
                cout << sqrt((double)c * c - b * b) << '\n';
            }
        }
        else if(b == -1) {
            if(a >= c) cout << "Impossible.\n";
            else {
                cout << "b = " << fixed;
                cout.precision(3);
                cout << sqrt((double)c * c - a * a) << '\n';
            }
        }
        else {
            cout << "c = " << fixed;
            cout.precision(3);
            cout << sqrt((double)a * a + b * b) << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}