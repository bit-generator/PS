#include <iostream>
using namespace std;

constexpr int LEFT = 0;
constexpr int RIGHT = 1;
int N, a, b, c, ans, cnt;
int tree[100001][2];

void inorder(int x) {
	if (tree[x][LEFT] != -1) {
		ans++;
		inorder(tree[x][LEFT]);
		if (cnt == N) return;
		ans++;
	}

	if (++cnt == N) return;

	if (tree[x][RIGHT] != -1) {
		ans++;
		inorder(tree[x][RIGHT]);
		if (cnt == N) return;
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		tree[a][LEFT] = b;
		tree[a][RIGHT] = c;
	}

	inorder(1);
	cout << ans;
	return 0;
}