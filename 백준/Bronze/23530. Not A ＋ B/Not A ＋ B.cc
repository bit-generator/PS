#include <iostream>
using namespace std;

int t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a + b != 50) cout << 50;
        else cout << 49;
        cout << '\n';
    }
    
    return 0;
}