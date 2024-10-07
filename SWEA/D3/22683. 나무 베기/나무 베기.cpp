#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int T, N, K, X, Y, ans;
string com;
char board[10][10];
int visit[6][4][10][10];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool validRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void bfs() {
	queue<tuple<int, int, int, int>> q;
	q.emplace(0, 0, X, Y);
	visit[0][0][X][Y] = 1;

	while (!q.empty()) {
		int curx, cury, cutCnt, dir;
		tie(cutCnt, dir, curx, cury) = q.front();
		q.pop();

		for (int i = 1; i <= 3; i += 2) {
			int ndir = (dir + i) % 4;
			if (visit[cutCnt][ndir][curx][cury] == 0) {
				visit[cutCnt][ndir][curx][cury] = visit[cutCnt][dir][curx][cury] + 1;
				q.emplace(cutCnt, ndir, curx, cury);
			}
		}

		int nx = curx + dx[dir];
		int ny = cury + dy[dir];
		int ncutCnt = cutCnt;
		if (!validRange(nx, ny)) continue;
		if (board[nx][ny] == 'T') {
			if (cutCnt == K) continue;
			else ncutCnt++;
		}
		else if (board[nx][ny] == 'Y') {
			ans = visit[cutCnt][dir][curx][cury];
			return;
		}
		
		if (visit[ncutCnt][dir][nx][ny] > 0) continue;
		visit[ncutCnt][dir][nx][ny] = visit[cutCnt][dir][curx][cury] + 1;
		q.emplace(ncutCnt, dir, nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'X') {
					X = i;
					Y = j;
				}
			}
		}
		
		memset(visit, 0, sizeof(int) * 10 * 10 * 6 * 4);
        ans = -1;
		bfs();
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
