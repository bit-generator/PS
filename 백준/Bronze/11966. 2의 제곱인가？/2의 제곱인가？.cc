#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N > 1) {
        if(N % 2 == 1) {
            cout << 0;
            return 0;
        }
        
        N /= 2;
    }
    
    cout << 1;
    return 0;
}