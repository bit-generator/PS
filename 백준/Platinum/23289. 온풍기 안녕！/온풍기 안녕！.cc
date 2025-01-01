#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#define RIGHT    1
#define LEFT    5
#define UP    7
#define DOWN    3
using namespace std;

int R, C, K, W, x, y, t;
int board[20][20];
int visit[20][20];
int temptemp[20][20];
bool vWall[20][20], hWall[20][20];
vector<pair<pair<int, int>, int>> heater;
vector<pair<int, int>> examineCell;
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int didx[] = { 0, RIGHT, LEFT, UP, DOWN };

bool validRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

bool isBlocked(int x, int y, int dir, int route) {
    if (dir == RIGHT) {
        if (route == 0 && vWall[x][y]) return true;
        if (route == -1 && (hWall[x][y] || vWall[x - 1][y])) return true;
        if (route == 1 && (hWall[x + 1][y] || vWall[x + 1][y])) return true;
    }

    if (dir == LEFT) {
        if (route == 0 && vWall[x][y - 1]) return true;
        if (route == -1 && (hWall[x + 1][y] || vWall[x + 1][y - 1])) return true;
        if (route == 1 && (hWall[x][y] || vWall[x - 1][y - 1])) return true;
    }

    if (dir == UP) {
        if (route == 0 && hWall[x][y]) return true;
        if (route == -1 && (vWall[x][y - 1] || hWall[x][y - 1])) return true;
        if (route == 1 && (vWall[x][y] || hWall[x][y + 1])) return true;
    }

    if (dir == DOWN) {
        if (route == 0 && hWall[x + 1][y]) return true;
        if (route == -1 && (vWall[x][y] || hWall[x + 1][y + 1])) return true;
        if (route == 1 && (vWall[x][y - 1] || hWall[x + 1][y - 1])) return true;
    }

    return false;
}

void bfs(int x, int y, int dir) {
    queue<pair<int, int>> q;
    memset(visit, 0, sizeof(visit));
    int idx = didx[dir];
    q.emplace(x + dx[idx], y + dy[idx]);
    visit[x + dx[idx]][y + dy[idx]] = 5;
    board[x + dx[idx]][y + dy[idx]] += visit[x + dx[idx]][y + dy[idx]];

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        if (visit[curx][cury] == 1) continue;

        for (int i = -1; i <= 1; ++i) {
            int nx = curx + dx[(idx + i) % 8];
            int ny = cury + dy[(idx + i) % 8];
            if (!validRange(nx, ny) || visit[nx][ny]) continue;
            if (isBlocked(curx, cury, idx, i)) continue;

            visit[nx][ny] = visit[curx][cury] - 1;
            board[nx][ny] += visit[nx][ny];
            q.emplace(nx, ny);
        }
    }
}

void spreadWind() {
    for (auto h : heater) {
        bfs(h.first.first, h.first.second, h.second);
    }
}

void adjustTemp() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (i < R - 1 && !hWall[i + 1][j]) {
                temptemp[i][j] += ((board[i + 1][j] - board[i][j]) / 4);
                temptemp[i + 1][j] += ((board[i][j] - board[i + 1][j]) / 4);
            }

            if (j < C - 1 && !vWall[i][j]) {
                temptemp[i][j] += ((board[i][j + 1] - board[i][j]) / 4);
                temptemp[i][j + 1] += ((board[i][j] - board[i][j + 1]) / 4);
            }

			board[i][j] += temptemp[i][j];
			temptemp[i][j] = 0;
        }
    }
}

void decreaseBorderTemp() {
    for (int i = 0; i < C; ++i) {
        board[0][i] -= (board[0][i] ? 1 : 0);
        board[R - 1][i] -= (board[R - 1][i] ? 1 : 0);
    }

    for (int i = 1; i < R - 1; ++i) {
        board[i][0] -= (board[i][0] ? 1 : 0);
        board[i][C - 1] -= (board[i][C - 1] ? 1 : 0);
    }
}

bool examineTemp() {
    for (auto p : examineCell) {
        if (board[p.first][p.second] < K) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 5) {
                examineCell.emplace_back(i, j);
                board[i][j] = 0;
            }
            else if (board[i][j] > 0) {
                heater.emplace_back(make_pair(i, j), board[i][j]);
                board[i][j] = 0;
            }
        }
    }

    cin >> W;
    while (W--) {
        cin >> x >> y >> t;
        if (t) {
            vWall[x - 1][y - 1] = true;
        }
        else {
            hWall[x - 1][y - 1] = true;
        }
    }

    int cnt = 0;
    while (cnt <= 100) {
        spreadWind();
        adjustTemp();
        decreaseBorderTemp();
        ++cnt;
        if (examineTemp()) break;
    }

    cout << cnt;
    return 0;
}