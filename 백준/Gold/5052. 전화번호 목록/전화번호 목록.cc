#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr size_t MX = 10000 * 10 + 5;
constexpr size_t ROOT = 1;
int trie[MX][10];
int trie_cnt = 2;
bool check[MX];
int t, n;
string telnum;
bool consistent;

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        if (trie[cur][c - '0'] == 0) {
            trie[cur][c - '0'] = trie_cnt++;
        }

        cur = trie[cur][c - '0'];
        if (check[cur]) {
            consistent = false;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (trie[cur][i] != 0) {
            consistent = false;
            break;
        }
    }
    check[cur] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;

        consistent = true;
        memset(trie, 0, sizeof(int) * MX * 10);
        memset(check, 0, sizeof(bool) * MX);
        trie_cnt = 2;

        while (n--) {
            cin >> telnum;
            insert(telnum);
        }

        if (consistent) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}