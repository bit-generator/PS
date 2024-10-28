#include <iostream>
#include <map>
#include <string>
using namespace std;

struct TrieNode {
	bool is_terminal;
	map<string, TrieNode*> child;
} nodepool[15001];

constexpr int ROOT_IDX = 0;
int node_cnt = 1;
TrieNode* root = &nodepool[ROOT_IDX];

int N, K;
string str;

TrieNode* insert(string& s, TrieNode* cur) {
	if (cur->child.find(s) == cur->child.end()) {
		cur->child.emplace(s, &nodepool[node_cnt++]);
	}

	return cur->child[s];
}

void printNode(TrieNode* cur, int indent) {
	for (auto& p : cur->child) {
		for (int i = 0; i < indent; i++) cout << "--";
		cout << p.first << '\n';
		printNode(p.second, indent + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	while (N--) {
		cin >> K;
		TrieNode* cur = root;

		while (K--) {
			cin >> str;
			cur = insert(str, cur);
		}

		cur->is_terminal = true;
	}

	printNode(root, 0);
	return 0;
}