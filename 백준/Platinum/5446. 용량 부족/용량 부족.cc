#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> child;
    bool isEnd;
    int cnt[2];
} nodepool[40005];
TrieNode* ROOT = &nodepool[1];
int nodeCnt = 2;

int T, N1, N2, ans;
string str;

void insert(string& s, int state) {
    TrieNode* cur = ROOT;

    for (char c : s) {
        if (cur->child.find(c) == cur->child.end()) {
            cur->child[c] = &nodepool[nodeCnt++];
            cur->child[c]->child.clear();
            cur->child[c]->isEnd = false;
            cur->child[c]->cnt[0] = 0;
            cur->child[c]->cnt[1] = 0;
        }

        ++(cur->cnt[state]);
        cur = cur->child[c];
    }

    ++(cur->cnt[state]);
    cur->isEnd = true;
}

void dfs(TrieNode* cur) {
    if (!cur->cnt[0] || cur->isEnd) {
        ++ans;

        if (!cur->cnt[0]) return;
    }

    for (auto it = cur->child.begin(); it != cur->child.end(); ++it) {
        dfs(it->second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        nodeCnt = 2;
        ans = 0;
		ROOT->child.clear();
		ROOT->isEnd = false;
		ROOT->cnt[0] = 0;
		ROOT->cnt[1] = 0;

        cin >> N1;
        while (N1--) {
            cin >> str;
            insert(str, 1);
        }

        cin >> N2;
        for(int i = 0; i < N2; ++i) {
            cin >> str;
            insert(str, 0);
        }

        dfs(ROOT);
        cout << ans - N2 << '\n';
    }

    return 0;
}