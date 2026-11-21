#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K, ans;
string s;
int bits[50];
int basebit = 1 | (1 << ('c' - 'a')) | (1 << ('i' - 'a'))
        | (1 << ('n' - 'a')) | (1 << ('t' - 'a'));
int totalbit, cmbbit;

inline int countbit(int mask) {
    int cnt = 0;
    for(int i = 0; i < 32; ++i)
        if(mask & (1 << i)) ++cnt;
    
    return cnt;
}

void backtrack(int idx, int st) {
    if(idx == K - 5) {
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            if((bits[i] & cmbbit) == bits[i])
                ++cnt;
        }
        
        ans = max(ans, cnt);
        return;
    }
    
    for(int i = st; i < 26; ++i) {
        if(totalbit & (1 << i)) {
            cmbbit |= (1 << i);
            backtrack(idx + 1, i + 1);
            cmbbit &= ~(1 << i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> s;
        for(char c : s) {
            int idx = c - 'a';
            if((basebit & (1 << idx)) == 0) {
                bits[i] |= (1 << idx);
                totalbit |= (1 << idx);
            }
        }
    }
    
    if(K < 5) {
        cout << 0;
        return 0;
    }
    
    if(countbit(totalbit) + 5 <= K) {
        cout << N;
        return 0;
    }
    
    backtrack(0, 0);
    cout << ans;
    return 0;
}