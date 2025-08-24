#include <iostream>
using namespace std;

int N, D, P;
char ch;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> ch;
        if(ch == 'D') ++D;
        else ++P;
        
        if(D == P + 2 || P == D + 2) break;
    }
    
    cout << D << ':' << P;
    return 0;
}