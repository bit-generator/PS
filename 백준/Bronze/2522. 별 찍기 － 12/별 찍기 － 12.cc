#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N - 1; ++i) {
        for(int j = 0; j < N - i; ++j) cout << ' ';
        for(int j = 0; j < i; ++j) cout << '*';
        cout << '\n';
    }
    for(int i = 0; i < N; ++i) cout << '*';
    cout << '\n';
    for(int i = 1; i <= N - 1; ++i) {
        for(int j = 0; j < i; ++j) cout << ' ';
        for(int j = 0; j < N - i; ++j) cout << '*';
        cout << '\n';
    }
    
    return 0;
}