#include <iostream>
using namespace std;

int a1, a0, c, n0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a1 >> a0 >> c >> n0;
    if(a1 > c) cout << 0;
    else if(a1 == c) {
        if(a0 <= 0) cout << 1;
        else cout << 0;
    }
    else {
        if(a0 <= n0 * (c - a1)) cout << 1;
        else cout << 0;
    }
    
    return 0;
}