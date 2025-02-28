#include <iostream>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while(n--) {
        cin >> m;
        cout << m << ' ' << m << '\n';
    }
    
    return 0;
}