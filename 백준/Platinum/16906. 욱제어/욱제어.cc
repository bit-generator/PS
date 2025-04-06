#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
pair<int, int> L[1000];
char words[1000][1001];
int trie[1005][2];
bool endNode[1005];
const int ROOT = 1;
int trieCnt = 2;

bool insert(int len, int idx1, int idx2, int cur) {
    if(len == idx2) {
        endNode[cur] = true;
        words[idx1][idx2] = '\0';
        return true;
    }
    
    for(int j = 0; j < 2; ++j) {
        if(endNode[trie[cur][j]]) continue;
        if(!trie[cur][j]) {
            trie[cur][j] = trieCnt++;
        }
        
        words[idx1][idx2] = j + '0';
        if(insert(len, idx1, idx2 + 1, trie[cur][j])) return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> L[i].first;
        L[i].second = i;
    }
    
    sort(L, L + N);
    
    for(int i = 0; i < N; ++i) {
        if(!insert(L[i].first, L[i].second, 0, ROOT)) {
            cout << -1;
            return 0;
        }
    }
    
    cout << 1 << '\n';
    for(int i = 0; i < N; ++i) {
        cout << words[i] << '\n';
    }
    return 0;
}