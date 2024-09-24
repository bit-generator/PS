#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr size_t ROOT = 1;
constexpr size_t MX = 10000 * 500 + 1;
int node_cnt = 2;

int trie[MX][26];
bool chk[MX];

int N, M, ans;
string str;

void insert(string& s) {
	int cur = ROOT;
	for (auto c : s) {
		if (trie[cur][c - 'a'] == -1) {
			trie[cur][c - 'a'] = node_cnt++;
		}

		cur = trie[cur][c - 'a'];
	}

	chk[cur] = true;
}

bool find(string& s) {
	int cur = ROOT;
	for (auto c : s) {
		if (trie[cur][c - 'a'] == -1) {
			return false;
		}

		cur = trie[cur][c - 'a'];
	}

	return chk[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < MX; i++) {
		memset(trie[i], -1, sizeof(int) * 26);
	}

	while (N--) {
		cin >> str;
		insert(str);
	}

	while (M--) {
		cin >> str;
		if (find(str)) ans++;
	}

	cout << ans;
	return 0;
}