#include <iostream>
using namespace std;

int T, A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> A >> B;
        cout << (A * A) / (B * B) << '\n';
    }
    
    return 0;
}