#include <iostream>
using namespace std;

int A, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> T;
    int P = 10 + 2 * (25 - A + T);
    cout << (P < 0 ? 0 : P);
    return 0;
}