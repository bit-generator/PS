#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, K, ansmn, ansmx;
string W;
vector<int> cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> W >> K;
        for(int i = 0; i < 26; ++i) cnt[i].clear();
        ansmn = 10001; ansmx = 0;
        
        for(int i = 0; i < W.length(); ++i) {
            cnt[W[i] - 'a'].push_back(i);
        }
        
        for(int i = 0; i < 26; ++i) {
            if(cnt[i].size() < K) continue;
            for(int j = 0; j < cnt[i].size() - K + 1; ++j) {
                int len = cnt[i][j + K - 1] - cnt[i][j] + 1;
                ansmn = min(ansmn, len);
                ansmx = max(ansmx, len);
            }
        }
        
        if(ansmn == 10001 || ansmx == 0) cout << -1 << '\n';
        else cout << ansmn << ' ' << ansmx << '\n';
    }
    
    return 0;
}