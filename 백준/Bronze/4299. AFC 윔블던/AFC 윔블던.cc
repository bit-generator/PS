#include <iostream>
using namespace std;

int a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b;
    c = (a + b) / 2;
    d = (a - b) / 2;
    if(c + d != a || c < 0 || d < 0) {
        cout << -1;
        return 0;
    }
    
    if(c > d) cout << c << ' ' << d;
    else cout << d << ' ' << c;
    return 0;
}