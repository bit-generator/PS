#include <iostream>
using namespace std;

int T, N, M, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N >> M >> K;
        if(N - (M * K) <= 0) {
            cout << 1 << '\n';
            continue;
        }
        
        if(M * K - 1 <= 0) {
            cout << -1 << '\n';
            continue;
        }
        
        int mod = (N - (M * K)) % (M * K - 1);
        cout << ((N - (M * K)) / (M * K - 1) + (mod != 0)) * 2 + 1 << '\n';
    }
    
    return 0;
}