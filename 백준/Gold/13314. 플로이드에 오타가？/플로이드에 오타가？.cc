#include <iostream>
using namespace std;

const int N = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << N << '\n';
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i == j) cout << 0;
            else if(i != N - 1 && j != N - 1) cout << 10000;
            else cout << 4999;
            cout << ' ';
        }
        
        cout << '\n';
    }
    
    return 0;
}