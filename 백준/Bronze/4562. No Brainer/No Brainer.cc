#include <iostream>
using namespace std;

int n, X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while(n--) {
        cin >> X >> Y;
        if(X >= Y) cout << "MMM BRAINS\n";
        else cout << "NO BRAINS\n";
    }
    
    return 0;
}