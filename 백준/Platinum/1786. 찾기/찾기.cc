#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
int F[1'000'001];
int ans;
vector<int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    getline(cin, T);
    getline(cin, P);
    
    int j = 0;
    for(int i = 1; i < P.length(); ++i) {
        while(j > 0 && P[i] != P[j]) j = F[j - 1];
        if(P[i] == P[j]) F[i] = ++j;
    }
    
    j = 0;
    for(int i = 0; i < T.length(); ++i) {
        while(j > 0 && T[i] != P[j]) j = F[j - 1];
        if(T[i] == P[j]) ++j;
        if(j == P.length()) {
            ++ans;
            pos.push_back(i - j + 2);
        }
    }
    
    cout << ans << '\n';
    for(int n : pos) cout << n << ' ';
    return 0;
}