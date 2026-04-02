#include <iostream>
#include <string>
using namespace std;

string S;
int q, l, r;
char a;
int cnt[26][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> S >> q;
    int idx = S[0] - 'a';
    cnt[idx][1] = 1;
    
    for(int i = 2; i <= S.length(); ++i) {
        idx = S[i - 1] - 'a';
        for(int j = 0; j < 26; ++j) {
            cnt[j][i] += cnt[j][i - 1];
        }
        
        ++cnt[idx][i];
    }
    
    while(q--) {
        cin >> a >> l >> r;
        idx = a - 'a';
        cout << cnt[idx][r + 1] - cnt[idx][l] << '\n';
    }
    
    return 0;
}