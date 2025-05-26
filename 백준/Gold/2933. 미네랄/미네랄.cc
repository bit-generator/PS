#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C, N, M;
int dr = 1, maxR, minC;
char board[100][100];
bool visit[100][100];
int maxBottom[100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool validRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

bool bfs(int x, int y) {
    if (!validRange(x, y) || board[x][y] != 'x') return false;

    memset(visit, 0, sizeof(visit));
    memset(maxBottom, -1, sizeof(maxBottom));
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = true;
    maxR = x;
    maxBottom[y] = x;
    minC = y;

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (!validRange(nx, ny)) continue;
            if (visit[nx][ny] || board[nx][ny] != 'x') continue;

            visit[nx][ny] = true;
            maxR = max(maxR, nx);
            maxBottom[ny] = max(maxBottom[ny], nx);
            minC = min(minC, ny);
            q.emplace(nx, ny);
        }
    }

    if (maxR == R - 1) return false;
    return true;
}

void fallingDown() {
    int minCnt = 101;
    for (int j = minC; j < C && maxBottom[j] != -1; ++j) {
        int last = maxBottom[j];
        int start = last;

        while (last >= 0) {
            while (start >= 0 && visit[start][j]) --start;
            while (start >= 0 && !visit[start][j]) --start;
            ++last;
            int cnt = 0;

            while (last + cnt < R && (board[last + cnt][j] != 'x' || visit[last + cnt][j])) {
                ++cnt;
            }

            minCnt = min(minCnt, cnt);
            last = start;
        }
    }

    for (int j = minC; j < C && maxBottom[j] != -1; ++j) {
        int last = maxBottom[j];
        int start = last;

        while (last >= 0) {
            while (start >= 0 && visit[start][j]) --start;
            for (int i = last; i > start; --i) {
                board[i + minCnt][j] = board[i][j];
                board[i][j] = '.';
            }

            while (start >= 0 && !visit[start][j]) --start;
            last = start;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }

    cin >> N;
    while (N--) {
        cin >> M;
        int curx = R - M; int cury = (dr == 1 ? 0 : C - 1);
        while (cury >= 0 && cury < C && board[curx][cury] != 'x') {
            cury += dr;
        }

        if (cury >= 0 && cury < C) {
            board[curx][cury] = '.';

            if (bfs(curx - 1, cury) || bfs(curx, cury + dr) || bfs(curx + 1, cury)) {
                fallingDown();
            }
        }

        dr *= -1;
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}