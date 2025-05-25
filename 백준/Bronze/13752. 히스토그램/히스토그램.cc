#include <iostream>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while(n--) {
        cin >> k;
        while(k--) cout << '=';
        cout << '\n';
    }
    
    return 0;
}