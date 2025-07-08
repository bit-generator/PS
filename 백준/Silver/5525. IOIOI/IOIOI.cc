#include <iostream>
#include <string>
using namespace std;

int N, M, ans;
string S, T;
int F[2'000'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> S;
    for(int i = 0; i < N; ++i) {
        T += "IO";
    }
    T += 'I';
    
    int j = 0;
    for(int i = 1; i < 2 * N + 1; ++i) {
        while(j > 0 && T[i] != T[j]) j = F[j - 1];
        if(T[i] == T[j]) F[i] = ++j;
    }
    
    j = 0;
    for(int i = 0; i < M; ++i) {
        while(j > 0 && S[i] != T[j]) j = F[j - 1];
        if(S[i] == T[j]) ++j;
        if(j == 2 * N + 1) {
            ++ans;
            j = F[j - 1];
        }
    }
    
    cout << ans;
    return 0;
}