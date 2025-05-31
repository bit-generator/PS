#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 2; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            if(N == i || N == j || N == i * j) {
                cout << 1;
                return 0;
            }
        }
    }
    
    cout << 0;
    return 0;
}