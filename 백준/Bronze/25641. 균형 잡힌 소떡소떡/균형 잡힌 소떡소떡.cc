#include <iostream>
using namespace std;

int N, S, T;
char stst[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> stst[i];
        if(stst[i] == 's') ++S;
        else ++T;
    }
    
    int i;
    for(i = 0; i < N && S != T; ++i) {
        if(stst[i] == 's') --S;
        else --T;
    }
    
    cout << stst + i;
    return 0;
}