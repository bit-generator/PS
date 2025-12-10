#include <iostream>
#include <numeric>
using namespace std;

int N, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
    
    return 0;
}