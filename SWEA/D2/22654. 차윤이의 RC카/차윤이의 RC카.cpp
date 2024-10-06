#include <iostream>
#include <string>
using namespace std;

int T, N, Q, C, X, Y;
string com;
char board[5][5];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool validRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'X') {
					X = i;
					Y = j;
				}
			}
		}

		cout << '#' << tc;
		cin >> Q;
		while (Q--) {
			cin >> C >> com;
			int srcX = X;
			int srcY = Y;
			int dir = 0;

			for (char ch : com) {
				if (ch == 'A') {
					int nx = srcX + dx[dir];
					int ny = srcY + dy[dir];
					if (!validRange(nx, ny) || board[nx][ny] == 'T') continue;

					srcX = nx;
					srcY = ny;
				}
				else if (ch == 'L') {
					dir = (dir + 3) % 4;
				}
				else {
					dir = (dir + 1) % 4;
				}
			}
			
			cout << ' ';
			if (board[srcX][srcY] == 'Y') cout << 1;
			else cout << 0;
		}

		cout << '\n';
	}

	return 0;
}
