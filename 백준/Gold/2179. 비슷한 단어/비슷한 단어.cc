#include <iostream>
#include <map>
#include <string>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> child;
    int idx;
    bool isTerminal;
} nodepool[20000 * 100 + 5];

TrieNode* ROOT = &nodepool[0];
int N, idx1, idx2, maxCnt;
string str[20001];
int nodeCnt = 1;

void insert(string& s, int idx) {
    TrieNode* cur = ROOT;
    int sameCnt = 0;
    int sameIdx = 0;
    
    for(char c : s) {
        if(cur->child.find(c) == cur->child.end()) {
            cur->child[c] = &nodepool[nodeCnt++];
            cur->child[c]->idx = idx;
        }
        else {
            ++sameCnt;
            sameIdx = cur->child[c]->idx;
        }
        
        cur = cur->child[c];
    }
    
    if(cur->isTerminal) return;
    cur->isTerminal = true;
    
    if(sameCnt > maxCnt || (sameCnt == maxCnt && sameIdx < idx1)) {
        maxCnt = sameCnt;
        idx1 = sameIdx;
        idx2 = idx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> str[i];
        insert(str[i], i);
    }
    
    cout << str[idx1] << '\n' << str[idx2];
    return 0;
}