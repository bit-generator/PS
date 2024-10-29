#include <iostream>
#include <string>
using namespace std;

constexpr int MAX_SIZE = 100000 * 10 + 1;
constexpr int ROOT = 0;

struct TrieNode {
    int is_terminal;
    TrieNode* child[26];
} nodepool[MAX_SIZE];

int N;
string str;
TrieNode* root = &nodepool[ROOT];
int node_cnt = 1;

void insert(string& s) {
    bool flag = false;
    TrieNode* cur = root;
    
    for(char c : s) {
        if(!flag) cout << c;
        if(cur->child[c - 'a'] == nullptr) {
            cur->child[c - 'a'] = &nodepool[node_cnt++];
            flag = true;
        }
        
        cur = cur->child[c - 'a'];
    }
    
    if(!flag && ++(cur->is_terminal) > 1) {
        cout << cur->is_terminal;
    }
    else {
        cur->is_terminal = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> str;
        insert(str);
        cout << '\n';
    }
    
    return 0;
}