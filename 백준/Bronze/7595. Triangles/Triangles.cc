#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    while(true) {
        cin >> N;
        if(N == 0) break;
        
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < i; ++j) {
                cout << '*';
            }
            cout << '\n';
        }
    }
    
    return 0;
}