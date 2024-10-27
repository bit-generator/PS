#include <iostream>
#include <string>
#include <map>
using namespace std;

constexpr int ROOT_IDX = 0;
constexpr int MAX_SIZE = 500 * 40 + 1;

struct TrieNode {
    bool is_terminal;
    map<string, TrieNode*> child;
} nodepool[MAX_SIZE];

int N;
string str;
TrieNode* root = &nodepool[ROOT_IDX];
int node_idx = 1;

void insert(string& s) {
    TrieNode* cur = root;
    int prvIdx = 0;
    int slashIdx;
    string parsed;
    
    while((slashIdx = s.find('\\', prvIdx)) != -1) {
        parsed = s.substr(prvIdx, slashIdx - prvIdx);
        if(cur->child.find(parsed) == cur->child.end()) {
            cur->child.emplace(parsed, &nodepool[node_idx++]);
        }
        
        cur = cur->child[parsed];
        prvIdx = slashIdx + 1;
    }
    
    parsed = s.substr(prvIdx);
    if(cur->child.find(parsed) == cur->child.end()) {
        cur->child.emplace(parsed, &nodepool[node_idx++]);
    }
    cur->child[parsed]->is_terminal = true;
}

void printDirectory(TrieNode* cur, int indent) {
    for(auto p : cur->child) {
        for(int i = 0; i < indent; i++) cout << ' ';
        cout << p.first << '\n';
        printDirectory(p.second, indent + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str;
        insert(str);
    }
    
    printDirectory(root, 0);
    return 0;
}