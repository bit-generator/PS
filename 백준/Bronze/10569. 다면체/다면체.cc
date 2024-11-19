#include <iostream>
using namespace std;

int T, V, E;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> V >> E;
        cout << E + 2 - V << '\n';
    }
    
    return 0;
}