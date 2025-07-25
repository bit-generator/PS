#include <iostream>
using namespace std;

int x, y, ansx, ansy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) {
        cin >> x >> y;
        ansx ^= x;
        ansy ^= y;
    }
    
    cout << ansx << ' ' << ansy;
    return 0;
}