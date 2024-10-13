#include <iostream>
#include <string>
using namespace std;

constexpr size_t MX = 10000 * 500 + 1;
constexpr size_t ROOT = 1;
int trie[MX][26];
int check[MX];
int string_cnt = 2;
int N, M, ans;
string str;

void insert(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(trie[cur][c - 'a'] == 0) {
            trie[cur][c - 'a'] = string_cnt++;
        }
        
        cur = trie[cur][c - 'a'];
    }
    
    check[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(trie[cur][c - 'a'] == 0) {
            return false;
        }
        
        cur = trie[cur][c - 'a'];
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(N--) {
        cin >> str;
        insert(str);
    }
    
    while(M--) {
        cin >> str;
        if(find(str)) ans++;
    }
    
    cout << ans;
    return 0;
}