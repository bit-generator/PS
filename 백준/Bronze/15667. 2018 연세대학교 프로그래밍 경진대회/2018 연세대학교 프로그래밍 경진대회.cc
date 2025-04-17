#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= 100; ++i) {
        if(i * i + i + 1 == N) {
            cout << i;
            break;
        }
    }
    
    return 0;
}